# Meowsylvania (UE 5.8)

Cute kitten by day, dark lord by night: a café-builder / conquest game. Run a fish-cream café on the summit of Mount Meowtterhorn, fight Cult-of-the-Lamb-style dungeon runs down the mountain, turn each region's cats into vampire servants, open a branch shop per conquered region. Flat-vector art, 112 BPM world. Design: `docs/prototype/GDD.md`. Everything decided so far: `docs/decisions.md` (read it before touching gameplay).

## Memory system — do this every session
1. Start: read `docs/decisions.md` Part 2 and the newest file in `docs/dev-log/`.
2. Work. Keep tunables in data assets / DataTables, never in code (prototype rule that paid off).
3. End: append `docs/dev-log/YYYY-MM-DD.md` (sections: `## What changed`, `## Decisions`, `## Next`). The Stop hook (`.claude/hooks/devlog.js`) will not let a session that changed files end without it. Any decision that outlives the session also goes into `docs/decisions.md` Part 2 as one dated bullet.
4. Commit with a short imperative subject; one logical change per commit.

## Engine & stack
- Unreal Engine 5.8 (Launcher build) + Visual Studio 2026, C++ game module + Blueprints for content wiring. Started from the Top Down template (see `docs/ue57-upgrade-and-project-setup.md`).
- Enhanced Input for controls; Gameplay Ability System for claws, rolls, spells and blessings; DataTables/DataAssets for machines, recipes, critters, regions (port from `docs/prototype/data/*.json`).
- Git LFS for `.uasset/.umap` and media (`.gitattributes`). Run `git lfs install` once per clone.
- Never commit `Binaries/`, `Intermediate/`, `Saved/`, `DerivedDataCache/`.

## Skills (`.claude/skills`)
- `gamedev-router` first for any game-dev question; UE C++ → `ue-cpp-foundations`, `unreal-engine-cpp-pro`, `ue-gameplay-framework`, `ue-actor-component-architecture`; combat → `ue-gameplay-abilities`; input → `ue-input-system`; data → `ue-data-assets-tables`, `ue-serialization-savegames`; UI → `ue-ui-umg-slate`; build/debug → `ue-module-build-system`, `ue-testing-debugging`, `ue5-development-debugging`; perf → `performance-optimization`, `cli-anything-unrealinsights` (CLI in `tools/cli-anything-unrealinsights`, `pip install -e` it once).
- Design skills: `game-feel`, `save-systems`, `game-ai`, `camera-systems`, `game-ui-ux`, `level-design`, `roguelike`, `rpg`, `steam-publish`.

## Conventions
- Classes `AMw…` / `UMw…` / `FMw…`; Blueprints `BP_`, DataTables `DT_`, DataAssets `DA_`, Input Actions `IA_`, Mapping Contexts `IMC_`, Gameplay Effects `GE_`, Abilities `GA_`, Widgets `WBP_`.
- Content folders: `Content/Mw/{Cafe,Battle,Map,Cats,Critters,UI,FX,Audio,Data}`.
- Headless-testable gameplay: sim logic in plain C++ classes/subsystems with automation tests; seeded RNG for runs.
- UE 5.8 target; when a skill's advice is for an older version, prefer the 5.8 API and note it in the dev-log.
