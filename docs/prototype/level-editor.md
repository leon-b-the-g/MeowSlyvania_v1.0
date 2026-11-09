# Level editor

Run the game with `npm run dev`, walk to the area you want to lay out, and press **F2**. The world freezes. A panel
opens on the left. Press **F2** again to go back to playing.

| Area | What you can edit | Saved to |
|---|---|---|
| Café yard | Scenery props, wandering critters, castle pieces | `data/forecourt.json` |
| Conquest map | Region props, critters; move map nodes and secrets | `data/regions.json` |
| Battle room (inside a fight) | Obstacles (stump, rock, pine, crate, haystack, dead tree) and critter start spots (a fixed critter, a random one from the region, or a random special), inside the room's shape | `data/rooms.json` (the room becomes a hand-made layout for that region, room kind and shape) |

- **Place:** click a palette button, then click the ground. Hold Shift to keep placing.
- **Select and move:** click a thing, then drag it. The yellow ring marks the selection.
- **Delete** removes the selection, **C** copies it, **[** and **]** scale it, **PgUp** and **PgDn** raise or lower it.
- **T** cycles when a prop plays its second animation row: never, night, open hours, or now and then.
- **G** cycles the snap: half a tile, a quarter, or off.
- **Move the view:** WASD or the arrow keys pan, the mouse wheel zooms. Esc deselects.
- **Save:** **Ctrl+S** or the button. The dev server writes the files and the game reloads with them, with the editor still open.
- **Without a dev server** (a built copy), Save downloads the files instead. Copy them into `data/`.

Battle rooms are shapes (`shapes` in `data/battle.json`: circles and rectangles joined together). The trees, rocks and
props around a room come from the region's `room` theme in `data/regions.json`, so they are not edited here; change the
theme's lists to change the look. A saved layout keeps the shape it was made in. Keep the middle of each side of the
room clear: doors can open on any side but the one you came in by.

Battle layouts: a fight or elite room uses one of its region's layouts 60% of the time (`layoutChance` in
`data/battle.json`). A boss room always uses one when it exists. To edit a layout, play until a room is built from
it; the panel names the layout in its title. Save then updates that layout in place. Saving a random room adds a new
layout.
