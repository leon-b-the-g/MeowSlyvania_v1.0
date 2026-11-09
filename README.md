# Meowsylvania

Cute kitten by day, dark lord by night. Café-builder + Cult-of-the-Lamb-style conquest, Unreal Engine 5.7.

- `CLAUDE.md` — how we work with Claude Code here (memory system, skills, conventions).
- `docs/decisions.md` — every durable decision and milestone, prototype included.
- `docs/dev-log/` — one file per working session.
- `docs/prototype/` — the TypeScript prototype's GDD, asset prompts, balance data (`data/*.json`) and notes.
- `docs/ue57-upgrade-and-project-setup.md` — engine install, Visual Studio, Git LFS, creating the UE project in this folder.
- `.claude/skills/` — 30 committed agent skills (Unreal C++, GAS, debugging, game design); `.claude/hooks/devlog.js` — Stop hook that insists on a dev-log entry.
- `tools/cli-anything-unrealinsights/` — Unreal Insights CLI harness used by its skill.

Setup: `git lfs install`, then follow `docs/ue57-upgrade-and-project-setup.md`.
