# Meowsylvania — Game Design Document & Milestones

Oct 12, 2026 · Leon Breitenborn · living copy: https://claude.ai/code/artifact/7b0e2763-49bb-44df-b31f-9e7dfc9a0ab1

## Amendment 16 Oct 2026: the conquest of Meowsylvania

**The castle delves are cut. Meowsylvania is now a conquest game:** you start with one small fish-cream shop on the summit of Mount Meowtterhorn (working name), and fight your way down the mountain, region by region, kicking out the critters who rule each one, turning its cats into vampires and opening a new fish-cream branch there. This section overrides Night mode, the four deeds and the progression meters below wherever they disagree.

**Goal.** Every cat in Meowsylvania a vampire, every critter faction driven out, and the biggest fish-cream chain in the world.

**The loop.** The café and its production lines stay exactly as built: machines, servants, wear and jams. Servants are what free your time. Every hour you spend fighting is an hour the café runs without you, so a small staff keeps you behind the counter and a big one lets you march. Battles cost in-game time; the clock keeps running, unstaffed machines idle and unserved customers leave.

**The map** (inspiration: the Cuphead overworld and the Overcooked map). From the café gate you open a diorama of the mountain and walk a little cat token along its paths between nodes: battle flags, a boss gate per region and empty shop lots. Conquered land flips tile by tile from the critters' colours to castle crimson, Overcooked-style. In-engine it is built like the forecourt: a tile atlas for the ground plus billboard landmarks.

**Regions, top to bottom** (names and factions are a first pass):

| Order | Region | Held by | Boss | Conquering it gives |
| --- | --- | --- | --- | --- |
| 0 | Summit café, Mount Meowtterhorn | you | — | the first shop; a small daily fish catch from the mountain stream |
| 1 | Pinewhisker Woods | raccoons (bin bandits) | Boss Rummage, on a trash-heap throne | branch shop 2, nightberries |
| 2 | Purrgatory village | dogs (the Barkguard) | Constable Barkley | branch shop 3, the most cats to turn |
| 3 | Squeakmoor fields | mice and rats | the Rat Baron | branch shop 4, grain for the cone oven |
| 4 | Croaking Fens | frogs and toads | Queen Toadstool | branch shop 5, catnip |
| 5 | Gullport harbour | seagulls and crabs | Admiral Gullbert | branch shop 6, fish at scale; final victory |

**Battles.** Each region has 2–3 battle nodes and a boss gate. A battle is the real-time Cult of the Lamb-style arena fight already prototyped for the delve (claw, roll, five hearts), reskinned per region. Wins drop ingredients and coin; a loss sends you home with nothing, and the time is gone.

**Turning cats.** A conquered region's cats start visiting your shops. Serve one Perfectly enough times and it becomes a vampire servant (the caped look). Servants staff the summit café or a branch.

**Branch shops.** Clearing a region's boss unlocks its shop lot: build machines with the same build mode, staff it with servants, and it earns every day it runs. Slice: managed from the map (assign servants, see takings); walking into it comes later.

**Progress meters** (replacing the four deeds): Land (regions conquered, 5 of 5), Vampires (cats turned out of all cats in Meowsylvania), Chain (shops open, 6 of 6). All three full ends the game.

**Kept:** café, production lines, servants, build mode, beat clock, combat code. **Dropped:** descending into the castle at night, crypt biomes, prophecy deeds. The castle stays as HQ and backdrop.

**Open questions:** the mountain's name (Meowtterhorn, Purrnassus, Clawmore Peak?) and Meowsylvania vs Catsylvania for the land · do branch servants need visits (jams) or run hands-off · what night means now (shop closed only, or harder battles with better loot).

## Vision

Meowsylvania is a single-player 2.5D game where a cute kitten runs a fish-cream parlour by day and raids its own haunted castle by night, to fulfil the Prophecy of the Bloodless One and become Nosfer-cat-tu, dark lord of the Earth. One cat, one castle, one clock: the day/night cycle is the only mode switch, so the shop, the farm and the dungeon feel like one life rather than three games.

**Elevator pitch:** Cult of the Lamb's look and dungeon loop, Overcooked's shift pressure, Stardew's farm-and-renovate calm, Rogue Legacy's permanent upgrades between runs. Every mode feeds the other two.

**Target:** PC via Steam (Windows first, Steam Deck verified), console port after alpha. Solo development with AI tooling; vertical slice in 6 months.

**Design pillars**

1. **The clock is the game.** Every choice is a trade of daylight for night or night for daylight. Shop longer and earn more, or close early and delve deeper. Nothing pauses the sun except sleep.
2. **Cute on the outside, cursed on the inside.** Round eyes, pastel fur, soft shapes; blood sacrifices, bone furniture and customers who are slowly becoming your cult. Horror is always played for a smile.
3. **Everything compounds.** Catalysts farm, farms feed the shop, the shop buys castle upgrades, upgrades make delves survivable, delves bring effigies and Catalysts. No system is a dead end.
4. **Short loops, long goals.** A full day lasts 12 to 15 minutes of real time. Four prophecy goals give a 15 to 25 hour campaign a clear end, with a visible meter for each.

**Core fantasy in one line:** You are the nicest little monster in town, and everyone is going to love you right up until the end of the world.

## World and narrative

The player cat wanders into the attic of old Nosferatu's castle, a crumbling vampire fortress on a hill above the sleepy village of Purrgatory, finds a strange pendant shaped like a mouse, and eats it. It wakes as the earliest stage of Nosfer-cat-tu: the same kitten, now with two tiny fangs. The Prophecy of the Bloodless One, carved into the crypt wall, names four deeds that will crown a new dark lord. The castle's previous master, Count Clawdric, the last Nosfer-cat-tu, failed at the fourth and is now a talking skull on the mantelpiece who serves as tutorial voice and comic foil.

**Tone.** Wholesome surface, gothic undertow. The villagers are sweet, gullible and delighted by ice cream; the castle is full of coffins, candles and a basement that goes down further than it should. Jokes come from the gap between the kitten's ambitions and its size.

**Becoming the vampire.** The cat's look changes as the prophecy meters fill: tiny fangs from the pendant, slit pupils and a faint red eye-glow after the first effigy, pointed ears and a grey muzzle after the second, bat-wing ears and a widow's peak after the third, the Cape and a permanent shadow after the fourth. The creator's choices stay underneath as an automatic overlay layer, so the player always recognises their own cat while it slowly turns into something the village should be worried about.

**The four deeds of the prophecy** (each is a campaign act and a progress meter on the HUD):

| Deed | What the player does | Mode that drives it | Gate it unlocks |
| --- | --- | --- | --- |
| 1. Favour of the Population | Serve customers at the fish-cream shop; cats with full favour become Catalysts | Day (shop) | Catalysts unlock the farm and castle renovation |
| 2. Cape of the Impaler | Clear the castle depths and beat four guardian bosses; the cape drops from the last | Night (delve) | Cape unlocks the final delve biome and the Dark Mass altar |
| 3. Feeding the Masses | Grow the farm until the shop can serve a full village in one day; the village names the cat Messiah | Castle (farm) | Messiah status doubles Catalyst devotion and unlocks the final shop tier |
| 4. The Dark Mass | Place the four boss effigies on the altar with enough devoted Catalysts present; perform the ritual | All three | Ending |

**Key characters**

- **Count Clawdric**, a skull. Mentor, narrator of the prophecy, sells nothing and knows everything.
- **Mayor Whiskerton**, the village's beaming leader and the shop's most demanding regular. Favour meter personified.
- **The Bloodless One**, never seen. The voice in the crypt that comments after each delve. Who or what it is becomes the ending twist.
- **Four guardians**, one per delve biome: the Bat Matron (bell tower), the Ratcatcher (sewers), the Lady of the Lake (flooded cellars), the Hollow Knight-Cat (the crypt). Each drops an effigy.

**Endings.** Completing the Dark Mass with maximum favour gives the Benevolent Dark Lord ending (the village cheers as the sun goes out). Completing it with low favour gives the Feared Dark Lord ending. Both roll credits; a post-game mode keeps the castle open for players who want to finish the farm.

## Core loop: the day/night cycle

One in-game day is 12 to 15 real minutes and has three phases the player moves through in order; the sun is the only timer and it never pauses outside menus.

&#91;embedded content: core loop · 3 phases, 1 weekly festival\]

Morning output becomes the day's stock, the shift's earnings buy the night's gear, and the delve's loot is what the next morning builds with.

| Phase | Real time | Where | What the player does | Ends when |
| --- | --- | --- | --- | --- |
| Morning | 2–3 min | Castle grounds | Harvest, water, assign Catalysts, build, cook stock for the shop | Player opens the shop or the bell rings at 10:00 |
| Day shift | 5–6 min | Shop yard | Overcooked-style service; customers arrive in waves | Player closes or the sun sets at 18:00 |
| Night | 4–6 min | Castle depths | Rogue-lite delve; pre-equipped run, one life | Player dies or exits by the stairwell; dawn at 06:00 is a warning, not an exit |

**The three resources that cross the phases**

- **Coin** comes from the shop, buys renovations, seeds and run equipment.
- **Devotion** comes from happy customers and fed Catalysts; it is spent to assign Catalyst jobs and is required for the Dark Mass.
- **Blood and bone** come only from delves; blood fertilises the farm, bone is the building material for castle rooms and shop stations.

**Pressure and choice.** Opening late means more farm work done but fewer customers. Closing early means an earlier, longer delve. Dawn does not end a delve: the cat may keep going, but a bell rings at 09:00 as an early warning and the shop's first customers start queueing at 10:00. Every cat that leaves unserved costs village Favour, so a long night is paid for in reputation and lost shop progress rather than a forced exit. Dying in the delve forfeits the night's loot except effigies and costs the next morning (the cat wakes at 09:00, hungry). Skipping a delve is always allowed; the castle just doesn't grow.

**Energy** is a single bar shared across all three phases. Shop stations and farm chores drain it slowly, dungeon dodge-rolls drain it fast, sleeping refills it. Energy left at dawn carries over as a small Devotion bonus, so a careful player is rewarded without a hard penalty for a greedy one.

**Weekly rhythm.** Day 7 is Festival Day: no delve, a double-length shop shift with a themed menu, and the Mayor's favour review. Boss doors in the castle open only after a Festival, which paces the four Cape-of-the-Impaler bosses to roughly one per in-game week.

## Day mode: the Fish Cream Shop

The shop is a single-player Overcooked shift: customers queue at the yard counter with an order and a patience bar, and the cat runs between stations to assemble it before patience runs out. It is played from the same 3/4 camera as the rest of the game, so the shop is literally the castle's front yard with stations placed on the renovation grid.

**Stations** (each is a buildable castle object, so the shop grows with the renovation system):

| Station | Action | Input | Output | Unlock |
| --- | --- | --- | --- | --- |
| Fish barrel | Grab | Farm or delve fish | Raw fish | Start |
| Churn | Hold 1.5 s | Raw fish + milk | Fish cream base | Start |
| Scoop counter | Tap per scoop | Base + flavour | Cone (1–3 scoops) | Start |
| Topping rack | Tap | Cone + topping | Finished cone | 10 Catalysts |
| Freezer | Store | Any base | Keeps 3 bases for later | Renovation tier 2 |
| Sundae press | Hold 3 s | 2 bases + 2 toppings | Sundae (high value) | Renovation tier 3 |
| Blood fountain | Tap | Delve blood | Crimson swirl, cult customers only | Deed 2 progress |

**Customers.** The customers are the cats of Purrgatory: each is a named regular with a face, a favourite order and a personal favour bar that persists across days. They arrive in waves whose size and speed scale with village Favour, each with an order card, a patience bar and a mood face. Served in time: coin and village Favour. Served with a Perfect (right order, before the patience bar drops below half): the same plus one step on that cat's own favour bar. Left unserved: Favour loss and the cat leaves grumbling. When a cat's favour bar is full the player can invite it up the hill as a Catalyst; it walks to the castle that evening.

**Catalyst helpers.** From Deed 1 onward the player can assign up to two Catalysts to the shop as helpers who run one fixed station each (Overcooked's second player, automated). They are slow and occasionally drop things; levelling them up through Devotion is the main mid-game shop investment.

**Difficulty curve.** Wave size, recipe complexity and patience are driven by a single Shop Tier derived from renovation level, and by the day of the week (Festival doubles everything). The player can always keep the shop small; the Favour meter only requires total happy customers, not peak throughput.

**Feel targets.** Carry one item at a time, dash with a short cooldown, no inventory UI during the shift. Every action has a chunky sound and a squash-stretch. A perfect order triggers a small heart burst and the customer's eyes briefly glow red.

**Scope for the slice:** three stations, two flavours, one topping, waves of 1 to 4 customers, no helpers.

## Night mode: Castle Delves

**Superseded 16 Oct 2026** by the conquest amendment at the top: no castle delves; combat happens at battle nodes on the region map. The combat feel targets below still apply.

At dusk the cat descends the crypt stairs into a procedurally assembled run of hand-made rooms, played exactly like a Cult of the Lamb dungeon: 3/4 top-down, 2D sprites in a lit 3D world, dodge-roll, light and heavy attacks, one life per run. The "metroidvania" part is the castle itself: each boss effigy grants a permanent traversal ability (bat-glide, wall-cling, water-walk, phase-through-mist) that opens new rooms in the castle grounds and new biomes below, so the map grows around a persistent hub rather than resetting.

**Run structure.** A delve is 8 to 14 rooms across one biome, laid out as a rail with short optional branches. Room types: combat (60%), treasure (10%), shrine (10%, trade blood for a buff), cat cage (10%, free a kidnapped villager cat, it joins the castle as a Catalyst), and a mid-run merchant run by Count Clawdric's cousin. The biome's guardian door is at the end and opens only after a Festival Day. Dawn does not end the run: the player can keep delving into the morning while the shop queue builds and village Favour drains, so leaving is always a choice and the price of a long night is reputation, never loot.

**Biomes and bosses**

| Order | Biome | Guardian | Effigy ability | Signature hazard |
| --- | --- | --- | --- | --- |
| 1 | Bell tower | Bat Matron | Bat-glide: cross gaps | Swinging bells, dark pockets |
| 2 | Sewers | Ratcatcher | Wall-cling: climb marked walls | Rising sludge, rat swarms |
| 3 | Flooded cellars | Lady of the Lake | Water-walk: cross flooded tiles | Drowning timer, mirror enemies |
| 4 | The crypt | Hollow Knight-Cat | Mist-phase: pass barred doors | Shadow copies of the player's build |

**Loadout, not loot.** Runs are pre-equipped at the crypt altar before descending, Cult of the Lamb style: one weapon (claws, fish-bone sword, candelabra, umbrella), one curse (ranged spell powered by blood), one charm from the farm's garden, and three consumables. Weapons and curses are unlocked permanently with bone at the castle forge; in-run pickups are temporary tarot-style modifiers that last until dawn. Nothing found in a run is lost on death except temporary modifiers and uncollected coin.

**Combat feel.** Target 60 fps, dodge-roll with 0.4 s of invulnerability, attacks cancel into roll. Enemies telegraph for at least 0.5 s. Hit-stop of 2 frames on heavy hits, screen shake kept small so the cute art stays readable. Enemy count per room 3 to 8, bosses have three phases with a visible health bar.

**Enemy roster for the slice:** candle-wisp (ranged), bone mouse (swarm), gargoyle (shielded) plus the Bat Matron. Full game targets 16 enemies and four bosses.

**Scope for the slice:** one biome, six room layouts, 6-room runs, one boss, two weapons, no curses.

## Castle forecourt: production lines, servants and renovation

**Decided 14 Oct 2026: farming is cut.** The forecourt of the vampire castle is the café, and the game is about designing it. The grounds are one tile grid (32 × 32 in the slice) on which the player places machines, decorations and, later, castle renovations in a build mode (Q): pick a machine from the catalogue, pay coin, drop it on any free tile. Ingredients no longer grow; they come back from the night delve (Night mode below), so a better delve means a better menu.

**Production lines.** Every machine is a node in a chain: it takes one item kind from any machine that holds it and produces one item kind into its own stock, up to a cap. Hand-operated by the player at first (E takes, hold E churns or scoops), then run by a servant. The catalogue in `data/machines.json` starts small and grows with the castle:

| Machine | Cost (coin) | Takes | Makes | Cycle (s) | Stock cap | In slice |
| --- | --- | --- | --- | --- | --- | --- |
| Fish barrel | 30 | — (refilled by the delve) | fish | 6 | 6 | yes |
| Cream churn | 60 | fish | base | 7 | 4 | yes |
| Scoop counter | 80 | base + a flavour ingredient | cone, served to a customer | hand only | — | yes |
| Flavour infuser | 120 | base + ingredient | flavoured base (servants can finish cones) | 9 | 3 | tier 2 |
| Cone oven | 100 | — | cones (counter needs them) | 8 | 8 | tier 2 |
| Blood still | 200 | nightberry + a drop | crimson syrup (Dark Mass menu) | 12 | 2 | after alpha |

**Servants (Catalysts).** A customer cat served Perfectly five times joins the household and takes over the first unworked machine, running its cycle on its own; a caged cat freed in a delve joins the same way. Every cycle adds wear, and at 100% the machine jams until the player holds E on it to fix it, so a bigger café is more lines to tend, not less to do. Hands-on work shrinks as the player automates: early game you carry every fish, mid game you fix, reassign and serve the counter, late game the forecourt runs while you plan. Sermons, devotion, hunger and beds stay as designed for the tiers after the slice.

**Renovation.** The castle starts as a ruin with one usable room. Rooms are rebuilt with bone and coin in a fixed order of tiers, each tier unlocking shop stations, Catalyst beds and farm plots. Renovation tier is the single number that drives shop difficulty and customer volume, so growth is always the player's own decision.

| Tier | Cost | Unlocks |
| --- | --- | --- |
| 1 Ruin | Start | Scoop counter, churn, 4 plots, 2 beds |
| 2 Kitchen | 40 bone, 500 coin | Freezer, 8 plots, 4 beds, pond |
| 3 Great hall | 120 bone, 2,000 coin | Sundae press, 16 plots, 8 beds, forge, sermon pulpit |
| 4 Bell tower restored | 300 bone, 6,000 coin, effigy 1 | Blood fountain, 24 plots, 12 beds |
| 5 Cathedral | 600 bone, 15,000 coin, effigy 3 | Dark Mass altar, 36 plots, 20 beds, full village capacity |

**Deed 3 (Feeding the Masses)** is reached when a single day's shift serves every villager in Purrgatory (40 customers), which needs tier 5 output and at least 12 working Catalysts.

**Scope for the slice:** tiers 1 and 2, catnip and nightberry, three Catalysts with the farmer and cook jobs, placement and demolish of six object types.

## Progression and win condition

**Superseded 16 Oct 2026:** the win condition is now the three conquest meters (Land, Vampires, Chain) in the amendment at the top.

The campaign ends when all four prophecy meters are full and the Dark Mass is performed; a target playthrough is 15 to 25 hours, or roughly 80 to 100 in-game days.

**The four meters** sit on the pause screen as a stained-glass window with four panes that fill in.

| Deed | Meter | Fills by | Full at |
| --- | --- | --- | --- |
| 1 Favour | Happy customers served (lifetime) | Shop service | 1,000 happy customers |
| 2 Cape | Effigies held | Boss kills | 4 of 4, cape drops with the fourth |
| 3 Masses | Best single-day customers served | Shop throughput | 40 in one day (whole village) |
| 4 Dark Mass | Devoted Catalysts present at the altar | Catalyst devotion | 20 Catalysts at devotion 3+, all four effigies placed |

**Permanent progression between runs (Rogue Legacy layer).** Bone and coin buy permanent stat nodes at the forge: health, energy, roll distance, attack speed, curse capacity. The tree is small (about 30 nodes) and fully visible from the start. Effigy abilities are the big permanent unlocks and gate the map.

**Economy sketch (slice numbers, to be tuned).** A tier 1 shift earns 60 to 120 coin; a tier 3 shift 400 to 800. A successful delve returns 5 to 15 bone and 3 to 8 blood. Renovation tiers are priced so that each takes 4 to 7 days of mixed play, which paces the whole campaign to about one tier per in-game fortnight after the first.

**Onboarding.** Day 1 is a scripted morning with Clawdric (place one plot, open the shop with one customer), a short delve of three rooms with no death possible, and dawn. Day 2 removes the rails. The character creator runs before Day 1.

**Save system.** Autosave at each phase change and on sleep; one slot per character, three characters per profile. Dying in a delve never loses more than that night, so there is no reason to support save-scumming and no need to encrypt saves.

## Character creator

The creator is a two-minute, layered-sprite picker: the cat is drawn once as a set of swappable parts and recoloured by palette swap, so every option costs art time only once and the same rig animates every player cat.

| Layer | Options at launch | Notes |
| --- | --- | --- |
| Body shape | 3 (round, lanky, chunky) | Changes silhouette only; hitbox is identical |
| Fur pattern | 6 (solid, tabby, tuxedo, calico, siamese points, void) | Masks over the body |
| Fur colour | 12-swatch palette plus a secondary | Shader palette swap, no extra sprites |
| Eyes | 8 shapes, any colour, heterochromia toggle | Eyes glow red on perfect orders and in delves |
| Ears and tail | 4 each | Includes a bat-wing ear set unlocked after the Bat Matron |
| Accessory | 10 (bow, collar, tiny cape, monocle, bandage) | More unlock through play |
| Name and pronouns | Free text, three pronoun sets | Used in Clawdric's dialogue |

The creator can be reopened at the castle mirror after Day 1 so that no choice is permanent. Unlocked accessories and the Cape of the Impaler appear here when earned.

**Technical note.** One animation set (idle, walk, dash, carry, scoop, churn, attack light, attack heavy, roll, hurt, death, sleep) at 8 directions for the 3/4 camera, drawn for the round body and re-fitted for the other two shapes by offset tables rather than redraws. Budget: about 220 frames per body shape.

## Art direction

The look is cute-but-creepy in the Cult of the Lamb vein: flat-shaded 2D characters with thick dark outlines and big simple eyes, standing in a 3D world rendered with a tilted 3/4 camera, dynamic lighting and long soft shadows. The world is the creepy half, the characters are the cute half; the contrast does the work.

**Rendering.** 2D sprite characters and props as camera-facing billboards in a 3D scene (2.5D). Ground and walls are code-generated tile meshes with hand-painted textures so lighting can change across the day without repainting anything; large structures are layered billboards with a normal-ish shading trick (a second sprite that stores a light direction) so they take the sun too. The day/night cycle is a single global light whose colour, angle and intensity are keyed over the 24-hour clock, plus point lights for candles and shop lamps. Fixed camera pitch of about 50 degrees, orthographic-feeling perspective (long focal length), no camera rotation.

**Palette.** Day: cream, peach, mint and butter yellow with a warm sun. Dusk: lavender and rose. Night: deep indigo and teal, with candle orange and blood red as the only warm accents. Characters keep saturated, high-contrast colours in every light so they always read against the world. One shared ramp per material family so that assets from different weeks match.

**Shapes.** Everything is rounded, including gravestones and knives. Horror elements are small and matter-of-fact: a skull with a bow, a coffin used as a freezer, a customer with no reflection. Nothing is gory on screen; blood is a stylised pool of flat red.

**Animation.** Sprites at 12 fps with 8 directions; squash and stretch on every action; two-frame anticipation on attacks; idle animations for every Catalyst so the castle feels inhabited. Enemies share a four-frame death "poof" into a bone pickup.

**UI.** Stained-glass and parchment motifs, thick outlines matching the characters, a single rounded display font for headings and a clean sans for body text. Diegetic where cheap: the four prophecy meters are a window, the clock is the sun, shop orders are speech bubbles.

**Audio.** A music system with one theme per phase that cross-fades on the clock (shop: upbeat ukulele and glockenspiel; night: harpsichord and low choir; morning: soft strings). Every shop action has a distinct, layered sound so a player can run stations by ear. Catalysts chatter in short gibberish mews, Animal Crossing style.

**Asset pipeline.** Characters and props: concept in Aseprite or Procreate, generated variations with an image model where it speeds exploration, final frames cleaned by hand, exported as sprite sheets with JSON atlases. 3D: no modelling tool. The only meshes in the game are floor tiles, wall slabs, stairs, ramps and water planes, built in code from the grid and the room JSON, with one hand-painted 1024 texture atlas per biome on their faces. Anything with a silhouette (props, trees, gravestones, the castle facade, the cat) is a billboard sprite, never a model. All assets are data files under version control; the engine hot-reloads them.

**Reference board:** Cult of the Lamb (character and lighting), Stardew Valley (farm readability), Overcooked 2 (station clarity, customer UI), Hollow Knight (boss telegraphing), Don't Starve (hand-drawn creepy props).

## Tech stack and engine architecture

Meowsylvania runs on a custom TypeScript engine on WebGL: three.js is the only rendering dependency (camera, lights, shadow maps, meshes), and everything above it is our code, written as plain modules and JSON data so that an AI coding agent can read, generate, test and screenshot any part of it without an editor in the loop. The Steam build is the same code hosted in Electron, the route Vampire Survivors took to launch. Unity stays the fallback if the engine is not running the full day/night loop by the end of month 2.

**Why not C# and raylib (decided 12 Oct 2026).** The original plan. It fell at the first step: the organisation's network policy blocks nuget.org and dot.net from both development environments, so the agent could write C# but never compile or run it. npm is open, Node and Chromium are available, and a TypeScript engine can be built, tested and screenshotted headless in every session, which is the whole point of a custom engine for AI-driven development.

**Why this stack.** Plain code is what AI tooling is best at; scene files, prefabs and editor state are what it is worst at. three.js gives a 3D renderer with shadow-mapped lights, alpha-cut billboards and a 2D canvas path in one library, runs on every desktop through Electron and in any browser for playtests, and TypeScript gives fast builds, vitest for headless simulation and a language the agent writes reliably.

**Architecture.** A fixed-step simulation (60 Hz) drives a lightweight ECS; rendering interpolates between steps. Each game mode is a System set, not a separate scene, so the day/night switch is a change in which systems run over the same world.

| Layer | Contents | Owned by |
| --- | --- | --- |
| Platform | Window, WebGL, Web Audio, input, file IO | Browser / Electron, three.js |
| Core | Fixed-step loop, ECS (entities, components, systems), event bus, asset loader with hot reload, save/load | Engine |
| Render | 3/4 camera, billboard sprites, mesh tiles, day/night light keyframes, palette-swap shader, UI canvas | Engine |
| Game data | Crops, recipes, stations, enemies, rooms, bosses, dialogue, unlock trees: all JSON with schemas | Content |
| Gameplay | Clock and phases, shop sim, delve generator and combat, farm and Catalyst sim, renovation grid, prophecy meters | Game |
| Tools | Headless test harness, room editor as JSON plus live preview, balance spreadsheet importer | Tools |

**Rules that keep it AI-friendly**

- Every system has a headless unit test; the whole game can simulate a day with no window in under a second.
- Every tunable number lives in JSON under `data/`, never in code. A balance change is a data diff.
- One file per system, one folder per mode, no inheritance deeper than two levels, no reflection magic.
- Content is validated by JSON Schema on load; a bad asset is a test failure, not a runtime crash.
- Procedural rooms are hand-authored JSON tiles stitched by a seeded generator; a seed reproduces a run exactly, which makes bug reports and balance tests deterministic.

**Repository layout:** `engine/` (platform-agnostic: clock, loop, sun, `render/`), `game/` (Meowsylvania systems, `main.ts` entry), `data/` (JSON and schemas), `assets/` (sprites, audio), `tests/` (vitest), `tools/` (headless screenshot script). Built with Vite; `npm test` runs the headless simulation on every change.

**Console path.** Rendering, input and audio stay behind `engine/render`, `engine/input` and `engine/audio` from day one; gameplay and data never touch the browser directly. The port after alpha re-hosts the bundle in a console-licensed web runtime or ports the gameplay layer to a native shell; the JSON data, sprites and headless tests carry over unchanged. Target budgets from the start: 16.6 ms frame, under 1 GB RAM, under 4 GB on disk.

## Milestone roadmap

Six four-week milestones take the project from an empty repository to a vertical slice on 12 April 2027: one full day/night loop with the shop, a one-biome delve, a boss, the farm at tier 2, the character creator and final-quality art for everything in it. Each milestone ends with a playable build and a written go/no-go.

&#91;embedded content: roadmap to vertical slice · 6 milestones, 1 gate\]

The engine decision falls in week 9, early enough that a switch to Unity costs the holidays rather than the slice.

1. **M0 Engine spike (12 Oct to 8 Nov 2026).** Vite + three.js project, fixed-step loop, data-driven clock and sky, headless test harness, a billboard cat walking on a lit, code-generated tile floor under a moving sun (done 12 Oct, first day); then hot-reloading JSON assets, input mapping, save/load scaffold. Exit: a scripted 24-hour clock plays in under a second headless and at 60 fps on screen.
2. **M1 Castle and clock (9 Nov to 6 Dec).** Grid placement and demolish, two crops with growth and watering, save/load, phase transitions with the light keyframes, basic cat controller with carry. Exit: plant, sleep, harvest, repeat for seven days with saves between. **Engine go/no-go on 12 Dec:** if M0 and M1 are not stable, switch to Unity and re-plan M2 onward.
3. **M2 Fish-cream shop (7 Dec to 10 Jan 2027).** Three stations, customer queue and patience, order bubbles, waves, coin and Favour, the first Fan conversion. Exit: a five-minute shift is fun to replay three times in a row with the placeholder art.
4. **M3 Castle delve (11 Jan to 14 Feb).** Seeded room generator over six hand-made rooms, dodge-roll combat, three enemies, loadout altar, blood and bone loot, the dawn warning bell. Exit: a six-room run at 60 fps with deterministic seeds and no soft-locks across 1,000 headless runs.
5. **M4 Boss and full loop (15 Feb to 14 Mar).** Bat Matron with three phases, effigy and bat-glide, three Catalysts with two jobs, Clawdric's Day 1 tutorial, prophecy meters, Festival Day. Exit: a new player reaches the boss door unassisted within 45 minutes.
6. **M5 Slice polish (15 Mar to 12 Apr).** Final art for the slice content, music for three phases, sound pass, character creator, options and gamepad plus keyboard mapping, Steam Deck test, a two-minute trailer capture. Exit: the vertical slice build and a ten-person external playtest.

**After the slice.** Alpha (all four biomes, all stations, all tiers, both endings, placeholder-free) is planned for October 2027; the console port begins in November 2027 on the alpha codebase. Beta with full localisation and the Steam Next Fest demo in February 2028, PC launch in April 2028, console launch in the second half of 2028. These dates are re-planned at the slice review with real velocity numbers.

**Weekly cadence.** Monday: plan the week's tickets from this document. Daily: one AI-driven build session with tests green before commit. Friday: playable build, five-minute self-playtest, notes into the project. Every milestone: update this document rather than writing a new one.

## Risks, open questions and scope cuts

The biggest risk is breadth: three genres and a custom engine for one developer. The mitigation is already in the plan (one camera, one grid, one controller, one data format, a hard engine gate), and the cut list below is agreed now so that it is not argued about in March.

| Risk | Likelihood | Mitigation |
| --- | --- | --- |
| Custom engine eats the schedule | Medium | Go/no-go on 12 Dec; Unity fallback re-uses all JSON data and sprite assets unchanged |
| Shop and delve feel like two games | Medium | Shared camera, controller and art; resources cross every phase; Festival ties the week together |
| Art volume (8-direction sprites) | High | Palette swap and part layering; 4 directions for enemies and Catalysts, 8 only for the player cat |
| Solo burnout | Medium | Four-week milestones with a playable at each; Friday playtest is the only fixed ritual |
| Console port cost | Low until alpha | `engine/render` boundary from M0; no console work before alpha |
| Legal proximity to Cult of the Lamb | Low | Original characters, names and world; the style is a genre, the IP is not |

**Cut list, in order, if the slice slips:** Catalyst shop helpers, the third body shape, the second flavour, the sundae press, Festival Day, the opening tutorial with Clawdric (replaced by three text cards).

**Open questions**

- [ ] Pronoun and name input needs a profanity filter for the console port; decide the vendor at alpha.
- [ ] Localisation languages at launch: English and German are assumed, which others are worth it on Steam?
- [ ] Music: licensed library, a composer at beta, or generated and then arranged?

**Decided 12 Oct 2026:** Meowsylvania is clear as a title (trademark checked). Delves may run past dawn at a Favour cost. Blood fertiliser is shown as one drop and slightly crimson soil. No Blender: world geometry is generated in code. Engine switched to TypeScript + WebGL (three.js, Vite, Electron for Steam) because nuget.org and dot.net are blocked on the org network.
