# UE 5.6.1 → 5.8 and the Meowsylvania project (Windows, gremlin-grube)

Written 2026-11-09, corrected the same day: the Launcher's newest build was **5.8**, which needs **Visual Studio 2026** (MSVC v14.50+; UBT bans 14.40–14.43). Done: 5.8 installed, VS 2026 installed, project created at the repo root (UE nests `<Location>\<Name>` — we moved it up), compiled, Source Code Editor = VS 2026. Sections A–D are kept for reference; continue at E.

## A. Install Unreal Engine 5.7 next to 5.6.1 (do not uninstall 5.6.1 yet)
1. Epic Games Launcher → **Unreal Engine → Library**. Click the **+** next to *Engine Versions*, pick **5.7.x** (newest hotfix), click **Install**.
2. In the install dialog click **Options**: keep *Starter Content* and *Templates and Feature Packs*; untick *Editor symbols for debugging* (saves ~40 GB; add later only if you need engine call stacks). Choose a drive with ≥ 60 GB free.
3. Let it finish, then launch 5.7 once from the Launcher so it registers file associations and compiles core shaders (first start takes several minutes).
4. Keep 5.6.1 until the 5.7 project builds and packages once; then remove it from the Library to free the disk (your 5.6 projects are not deleted, they just need "Switch Unreal Engine version" to open).

## B. Visual Studio for C++ in 5.7
UE 5.8: **Visual Studio 2026** (`winget install Microsoft.VisualStudio.2026.Community`); VS 2022 cannot open its solutions and its 14.4x toolchains are banned by UnrealBuildTool.
1. Run the **Visual Studio Installer** → *Modify* on your VS → **Workloads**: tick **Game development with C++** and **Desktop development with C++**.
2. In the right-hand *Installation details* of "Game development with C++" make sure these are ticked: **Unreal Engine installer**, **Unreal Engine uproject support**, **Windows 11 SDK** (any recent 10.0.22621+), **MSVC v143 x64/x86 build tools (latest)**, **C++ profiling tools**, **.NET desktop development** is not needed but **.NET 8.0 Runtime / SDK** is (UBT runs on .NET 8; the UE component usually pulls it in — if `dotnet --list-sdks` shows no 8.x after install, add *".NET SDK"* under *Individual components*).
3. *Individual components* → tick **Windows Universal C Runtime** and **C++ AddressSanitizer** (optional).
4. Install, reboot. Verify: open "x64 Native Tools Command Prompt" and run `cl` (shows the MSVC version) and `dotnet --list-sdks`.
5. In UE 5.7 editor: **Edit → Editor Preferences → General → Source Code → Source Code Editor = Visual Studio 2022** (or 2026). Also **Rider** works if you prefer it: set it here instead.

## C. Git LFS (once per machine, once per clone)
1. Install Git LFS: `winget install GitHub.GitLFS` (or git-lfs.com), then in any shell `git lfs install`.
2. In `Y:\Workspaces\Projects\Mvania`: `git lfs install` (per repo) — the `.gitattributes` in this repo already routes `.uasset .umap .png .wav .fbx …` through LFS.

## D. Create the Top Down C++ project INTO this repo
The repo already has `CLAUDE.md`, `.claude/`, `docs/`, `tools/`, `.gitignore`, `.gitattributes`. The UE project goes in the same folder so one `git` tracks both.
1. Launch **UE 5.7** → *Unreal Project Browser* → **Games** → **Top Down**.
2. Right side: **Project Defaults = C++**, **Target Platform = Desktop**, **Quality Preset = Scalable** (our art is flat vector; Lumen/Nanite off is right), **Starter Content = off**, **Raytracing = off**.
3. **Project Location** = `Y:\Workspaces\Projects` and **Project Name** = `Mvania` → it will ask to use the existing (non-empty) folder: **confirm**. UE creates `Mvania.uproject`, `Source/Mvania/…`, `Config/`, `Content/` alongside our files.
   - If the browser refuses the non-empty folder: create it as `Y:\Workspaces\Projects\Mvania_tmp`, close the editor, move everything from `Mvania_tmp` into `Mvania`, delete `Mvania_tmp`.
4. UE generates the VS solution and opens it; let it build once (`Development Editor | Win64`). First build ≈ 5–15 min.
5. Back in the editor the Top Down map runs with the template character. Quit, then in the repo:
   ```
   git add -A
   git commit -m "UE 5.7 Top Down C++ project"
   git push -u origin main
   ```
   `.gitignore` keeps `Binaries/ Intermediate/ Saved/ DerivedDataCache/ *.sln` out.

## E. First-session settings (Claude Code does the rest)
1. **Edit → Project Settings → Maps & Modes**: Default GameMode = the template's TopDown game mode for now; we replace it with `AMwGameMode` in the first code session.
2. **Project Settings → Engine → Input**: confirm Enhanced Input is the default (it is in 5.7 templates).
3. **Edit → Plugins**: enable **Gameplay Abilities**, **Gameplay Tags Editor**, **Modeling Tools** (off by default in Games templates), **Python Editor Script Plugin** (needed later for UnrealClaude and asset-import scripts). Restart.
4. Open a terminal in the repo and start Claude Code: `claude`. Say *"read CLAUDE.md and docs/decisions.md, then plan session 1"*.

## F. UnrealClaude (editor plugin + MCP) — after D
Prereqs: Claude Code CLI (`npm install -g @anthropic-ai/claude-code`, `claude auth login`), Node 22+, the project from D.
1. `git clone --recurse-submodules https://github.com/Natfii/UnrealClaude.git Y:\Workspaces\Tools\UnrealClaude`
2. Build the plugin for our engine (adjust the 5.7 path):
   `"C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat" BuildPlugin -Plugin="Y:\Workspaces\Tools\UnrealClaude\UnrealClaude\UnrealClaude.uplugin" -Package="Y:\Workspaces\Tools\UnrealClaude\Build" -TargetPlatforms=Win64`
3. Copy `Y:\Workspaces\Tools\UnrealClaude\Build` to `Y:\Workspaces\Projects\Mvania\Plugins\UnrealClaude`.
4. `cd Y:\Workspaces\Projects\Mvania\Plugins\UnrealClaude\Resources\mcp-bridge && npm install`
5. Open the editor → **Tools → Claude Assistant**. The MCP server listens on port 3000; add it to Claude Code with `claude mcp add unreal --transport http http://localhost:3000` (check the plugin README for the exact endpoint of your build).
6. Commit `Plugins/UnrealClaude` (binaries are ignored; the plugin source is small).

## G. Unreal Insights CLI (perf skill)
`cd Y:\Workspaces\Projects\Mvania\tools\cli-anything-unrealinsights && pip install -e .` then set `UNREALINSIGHTS_EXE="C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealInsights.exe"` in your user environment. `cli-anything-unrealinsights --json backend info` must answer before the skill is useful.
