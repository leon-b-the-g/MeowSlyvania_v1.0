# Assets flagged for review

Sheets that work in the game but need another pass. Re-generate with the prompt file named, drop the raw over the old
one in `art/`, and re-run its pack script.

| Asset | Where it shows | Issue | Raw / prompt |
|---|---|---|---|
| `prop-pine.png` (pine tree) | the mountain map's scenery, woods battle rooms | Flagged by Leon 20 Oct while playtesting the map: rework the tree and its sway. Its idle row should read as one smooth sway played forwards then backwards (pingpong); until 20 Oct the game also mirrored every other sway, which flipped the tree's shading and shadow, so judge it again now that this is gone. | `art/props/pine-raw-v1.png`, `docs/prompts/assets-v3.md` section 4 |

How the game plays a prop's idle row: frames 1-8 forwards, then 7-2 backwards, on the music's beat (`prop.json`
`idle.pingpong`). Never mirrored. Draw the idle loop so that going back over the same frames looks natural.

## Missing art

| Asset | Where it shows | Prompt (prop family, `docs/prompts/assets-v4.md` STYLE + prop SHEET line) |
|---|---|---|
| `prop-dehydrator.png` | the café: a store for waffle cones (canvas stand-in for now) | **dehydrator:** a tall slatted wooden drying cabinet on short legs, three wire racks with golden waffle cones drying on them, a little round vent with a cat-paw grille on top. Idle: warm air shimmers out of the vent. Active: the door swings open, a waffle cone slides onto a rack, the door shuts. Save as `art/props/dehydrator-raw-v1.png`. |
