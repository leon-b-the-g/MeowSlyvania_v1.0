# Meowsylvania — asset prompts v2 (everything after the first props)

Same rules as `props-v1.md`: paste the MASTER for the family, swap the `{ITEM}` line, one subject per generation,
save raw output to `art/<family>-<name>-raw-v1.png`. Pack with the command listed under each family; the engine
reads `public/assets/`. Priority order is the order of the sections: A unlocks the castle moment, B the cat feel,
C new content, G the conquest map and region 1, the rest after.

Style block, identical for every family (keep verbatim at the top of each prompt):

```
STYLE: 2D hand-drawn game sprite in the style of Cult of the Lamb. Thick uniform dark outline #2a1a2e on every
shape, flat vector fills, exactly one darker shade tone per colour, no gradients, no textures, no painterly
rendering, simple rounded chunky shapes, readable at 64 px. Palette: warm wood #b8763f/#7a4a26, cream #f3e6cf,
moss #7fcf6a/#4f8f43, slate #8d93a6/#5b6075, straw #e9c86a, crimson accent #c0243a (sparingly), lavender
#d8c9ee for anything magical. View: 3/4 top-down, camera tilted about 50°, light from top-left, small flat
elliptical contact shadow under anything that stands on the ground. Plain fully transparent background, no
checkerboard, no backdrop, no vignette, no glow, no paper, no frame, no text, no labels, no watermark, nothing crossing a cell boundary.
```

---

## A. Castle set (props-v1 layout: 2 rows × 8, idle / active) — generate these FIRST

Pack: `python3 tools/packsheet.py art/prop-NAME-raw-v1.png public/assets/prop-KIND.png --grid 8x2 --cell 256x400 --pad 16`
(tall pieces: `--cell 256x520`). These are v1 manifest items 34–38 plus two new ones; the exact wording below
replaces `{PROP}` in the v1 MASTER.

1. **castledoor** (tall, cell 256x520): tall pointed-arch castle door of dark iron-banded oak in a stone frame, a fang-moon glyph carved above the arch, two wall torches. IDLE: torches flicker, a faint lavender seam glows between the doors. ACTIVE: both doors swing open inward onto black, lavender light pours out, torches flare, three bats fly out.
2. **castlewall** (straight segment, edges flush so it tiles left-right): dark stone wall with battlements and ivy, one arrow slit. IDLE: ivy leaves twitch, a bat silhouette crosses the slit on frame 5. ACTIVE: wall shakes, mortar dust puffs.
3. **castlecorner** (tall, cell 256x520): square corner tower with a conical crimson-shingled roof and one glowing round attic window. IDLE: window glow pulses. ACTIVE: shingles rattle, window flashes, a bat flies out.
4. **gate**: double wooden garden gate between two low stone pillars topped with small cat statues, a hanging "OPEN" board with a fish-cone glyph. IDLE: board swings. ACTIVE: gates swing open toward the camera and bounce, board flips.
5. **gravestones**: three leaning gravestones in one cell (round, tablet, cracked), a small drop glyph on each. IDLE: fog wisps drift across the base. ACTIVE: stones shake, lavender glow from the cracks.
6. **statue**: stone cat on a pedestal holding a pendant. IDLE: pendant glint moves. ACTIVE: eyes glow crimson, pendant swings.
7. **lamppost**: iron lantern on a crooked post, warm flame. IDLE: flame flicker, sway. ACTIVE: wide swing, flame doubles, sparks.
8. **well**: round stone well, wooden roof, bucket on a rope. IDLE: bucket swings. ACTIVE: crank turns, bucket rises dripping.

## B. Player and customer cats — extra animation rows

The cats so far are 4 × 4 cells (idle_down 2, walk_down 4, walk_up 4, walk_right 4 — left is mirrored). Each
new sheet is drawn on the same canvas scale as `art/cat-raw-v1.png` and packed to the same 320x352 cells:
`python3 tools/packsheet.py art/cat-FUR-work-raw-v1.png public/assets/cat-FUR-work.png --cols 4 --rows 4,4,4,4 --cell 320x352`.

```
STYLE (above). SUBJECT: the same cat as the reference sheet — {FUR} — same proportions, same face, same outline.
SHEET: 4 rows × 4 columns, 16 equal cells with wide clear gaps, feet on one baseline per row, same scale in
every cell, each row a seamless loop that returns to frame 1.
ROW 1 use_down: facing the camera, both paws reach down-forward and press/grab, body squashes on frame 2, recovers.
ROW 2 use_right: same action facing right.
ROW 3 carry_down: walking toward the camera holding a round bundle over the head with both paws, head tilted back.
ROW 4 carry_right: same walk facing right.
```

Generate for FUR = orange tabby with white chest (player), calico, tuxedo, grey. Then two more sheets per fur, same
layout, rows: `sleep` (4: curled, breathing), `hurt` (4: flinch back, ears flat, eyes shut), `cheer` (4: hop with
paws up), `sad` (4: ears down, tail drag, slow sway) — packed as `cat-FUR-mood.png`.

**Customer variants without fangs:** regenerate calico, tuxedo and grey base sheets with "a normal cat mouth, no
fangs" — the player is the only vampire. Filenames stay; pack over the existing ones.

**Vampire stage overlays** (same canvas as the cat, packed `--like art/cat-raw-v1.png` like the accessories):
`acc-cape` (short crimson cape with a high collar, flutters with the walk), `acc-pendant` (fang-moon pendant on a
chain), `acc-vampeyes` (red-glint eyes only, everything else transparent), `acc-crown` (small bone crown).

## C. Tier-2 machines and alternates (props-v1 layout)

1. **infuser**: copper flavour infuser on a brass stand — a glass dome over a bowl, a leafy sprig poking out, a small crank. IDLE: dome fogs and clears, sprig sways. ACTIVE: crank spins, lavender swirl inside the dome, a puff from the valve on frame 6.
2. **oven**: squat stone cone oven with an iron door and a chimney, a tray of waffle cones in front. IDLE: chimney smoke curls, door glows faint orange through the slot. ACTIVE: door flips open, three cones hop out onto the tray, flame flare, smoke puffs.
3. **still**: iron blood still — a bulbous kettle with a coiled copper pipe into a small crimson flask, a drop glyph on the kettle. IDLE: pipe drips once, flask liquid sloshes. ACTIVE: kettle shakes, pipe bubbles, flask fills with a crimson glow, steam.
4. **barrel-lvl2**: the fish barrel with iron bands, a brass tap and a second tier of fish stacked on a shelf (an upgrade). IDLE/ACTIVE as the barrel.
5. **churn-lvl2**: the churn with two cranks and a cream pipe to a small cream jug (an upgrade). IDLE/ACTIVE as the churn.
6. **counter-lvl2**: the counter with a second cone tower, a brass sundae bell and striped lavender cloth. IDLE/ACTIVE as the counter.
7. **bed**: wooden bed with a patched quilt and pillow seen front-top. IDLE: quilt breathes. ACTIVE: a cat-shaped lump rolls over, three "z" rise.
8. **cage**: iron cat cage on a chain hook with a sad cat silhouette inside (for the delve). IDLE: sways. ACTIVE: door bursts open, lock falls, cat silhouette leaps out.

## D. Items and icons (one sheet, static)

Used over the player's head when carried, in the inventory card and in customer order bubbles.
Pack: `python3 tools/packsheet.py art/items-raw-v1.png public/assets/items.png --grid 8x2 --cell 160x160 --pad 8`.

```
STYLE (above). SHEET: 2 rows × 8 columns of equal cells with wide gaps, one object centred per cell, every
object the same visual weight (about 110 px wide), seen slightly from above, no ground shadow.
ROW 1: raw silver fish · tub of fish-cream base (cream with a fish tail poking out) · plain cone · catnip cone
(green swirl, leaf on top) · nightberry cone (purple swirl, berry on top) · catnip sprig · nightberry cluster ·
gold coin with a cat face.
ROW 2: crimson blood drop · white bone · fang-moon pendant · wrench (for jams) · hammer (build mode) · cream heart
(favour) · small cat head (servant count) · an empty cream circle (blank slot).
```

## E. UI kit (static, dark-and-cream panel pieces)

```
STYLE (above) but FLAT 2D, no perspective. SHEET: one row of 8 cells, 192 px square each, wide gaps.
1 a rounded cream panel #fff3dc with a 6 px ink border and a hard 4 px ink drop shadow, drawn as a 9-slice: plain
corners and edges, nothing inside (we stretch the middle) · 2 the same panel in night lavender #d8c9ee · 3 a
keycap: rounded ink square with a cream face · 4 a round cream button with an ink rim · 5 a progress ring: ink
ring with a crimson filled wedge from 12 o'clock to 3 o'clock on a cream disc · 6 a speech-bubble tail piece ·
7 a small cream star · 8 a small crimson fang-moon glyph (a crescent moon with two fangs) — this is the game's
sigil, used on signs, the pendant and the title.
```

## F. Effects (8-frame one-row sheets, transparent)

Pack each: `--grid 8x1 --cell 192x192`. One prompt each; `{FX}` replaces the last line.

```
STYLE (above). SHEET: 1 row × 8 columns, equal cells with wide gaps, a seamless 8-frame effect loop, same centre
in every cell, flat fills, outlined shapes, no glow, no blur.
FX: {FX}
```
splash (water ring + 5 droplets rising and falling) · steam (three cream puffs rising and fading) · sparkle (four
gold four-point stars popping in sequence) · hearts (three cream hearts rising and fading) · zzz (three "z" rising,
growing) · dust (a brown puff spreading flat) · coinburst (six coins arcing outward) · jam (grey smoke + a crimson
"!" bouncing) · beat (a thin cream ring expanding and fading — fires on every beat) · blooddrop (one crimson drop
falling, landing as a small crimson stain).

## G. Conquest set: the mountain map + region 1 "Pinewhisker Woods" — generate NEXT

Decided 2026-10-16: no castle delves. The player starts with one café on the summit of Mount Meowtterhorn and conquers
the regions below from the critters who hold them, on a Cuphead / Overcooked-style map. The map is built in-engine
like the forecourt (ground tiles + standing landmarks), so everything here uses the families that already pack.
Region 1 is Pinewhisker Woods, held by raccoons (bin bandits). Later regions repeat G3–G6 with their own critters:
dogs (Purrgatory village), mice and rats (Squeakmoor fields), frogs and toads (Croaking Fens), seagulls and crabs
(Gullport harbour).

**G1. Map ground atlas** — same STRICT LAYOUT text as the props-v1 GROUND MAP (4 × 3 seamless 512 px tiles, 32 px
white gutters), but seen from high above as a toy diorama, pattern elements 16–32 px. Every region comes in two
states: HELD (muted, scruffy, the critters' colours) and CONQUERED (tidy, lavender moss and crimson accents).
1 summit snow with blue-grey rock specks · 2 dirt path, warm tan, pebbles (the token walks on this) ·
3 pine forest floor HELD: needles, tipped-over litter, grey-brown · 4 pine forest floor CONQUERED: needles, lavender
moss, tiny crimson mushrooms · 5 village cobbles HELD: blue-grey with dog paw prints · 6 village cobbles CONQUERED:
same stones, lavender moss in the joints · 7 wheat field HELD: straw rows with nibbled gaps · 8 wheat field CONQUERED:
straw rows with crimson poppies · 9 fen water HELD: murky green with lily pads · 10 fen water CONQUERED: dark
lavender water with pale lily pads · 11 harbour boards HELD: weathered planks with gull droppings · 12 harbour boards
CONQUERED: same planks, clean, crimson rope coils.
Save `art/map-ground-raw-v1.png`.

**G2. Map landmarks** (props-v1 layout: 2 rows × 8, row 1 IDLE loop, row 2 ACTIVE plays once when triggered; cells
256x400; drawn as small toy-diorama models, about half the detail of a forecourt prop):
- `map-cafe`: the summit castle with a tiny fish-cream kiosk. IDLE chimney puffs on the beat. ACTIVE crimson
  fang-moon flag shoots up the tower, three tiny fireworks.
- `map-battle`: a battle node, a stake with the raccoon faction flag (grey-black stripes, a bin-lid emblem). IDLE flag
  flaps. ACTIVE the flag is yanked down and a crimson fang-moon flag unfurls in its place.
- `map-boss`: the raccoon fort, a heap of bins, crates and a tarp with a crooked crown on top. IDLE bins rattle, eyes
  blink in the gaps. ACTIVE the heap collapses in a dust puff, a crimson banner rises out of it.
- `map-lot`: an empty shop plot with a wooden "for rent" sign shaped like a paw. IDLE sign sways. ACTIVE a small
  fish-cream kiosk with a striped awning pops up out of the ground (no smoke behind it).
- `map-pines`: a cluster of three round pine trees. IDLE sway. ACTIVE a raccoon flees out of it.
- `map-signpost`: a crooked signpost with three arrow boards. IDLE boards wobble. ACTIVE boards spin and settle.
- `map-bridge`: a short wooden rope bridge. IDLE ropes sag and bounce. ACTIVE planks drop into place one by one.
- `map-cloud`: a fat cartoon cloud (the fog over unexplored regions). IDLE slow drift and squash. ACTIVE puffs apart
  and vanishes (last frame empty).
Save `art/prop-map-<name>-raw-v1.png`. Pack like any prop: `--grid 8x2 --cell 256x400`.

**G3. Region 1 enemies** — each a 4 × 8 sheet: row 1 idle 8, row 2 move 8, row 3 attack 8, row 4 hurt + die 8
(hurt frames 1–3, die 4–8 ending on an empty frame). Cute first, scary second (Cult of the Lamb rule). Same outline
weight as the cats; each raccoon about 1.1 × the height of a cat, the boss 2 ×.
- `enemy-binrat`: a scrappy raccoon in a dented bin-lid helmet. Attack: lid swipe.
- `enemy-slinger`: a skinny raccoon with a slingshot and a bandana. Attack: acorn shot (draw the acorn leaving the
  sling on frames 5–6; the projectile itself is a separate FX).
- `enemy-shield`: a chubby raccoon behind a trash-can-lid shield. Attack: shield bash with a short charge.
- `enemy-squirrel`: a tiny squirrel lackey with a too-big helmet. Attack: nut lunge. Comes in swarms.
- `boss-rummage`: Boss Rummage, a huge raccoon king with a crown made of a tin can, a cape made of a garbage bag,
  riding a bin with wheels. Attack: garbage-bag slam.
Pack `--grid 8x4 --cell 216x260` (boss: `--cell 432x480`). Save `art/enemy-<name>-raw-v1.png`.

**G4. Battle ground atlas, Pinewhisker Woods** — props-v1 GROUND MAP layout and rules, normal top-down scale:
1 forest floor, pine needles · 2 needles with roots · 3 moss patch · 4 dirt path · 5 trash-strewn ground (cans,
peels) · 6 spilled garbage puddle · 7 rain puddle with ripples · 8 campfire ash ring · 9 log planks · 10 leaf pile ·
11 mud with paw prints · 12 lavender-moss floor (the same ground after victory).
Save `art/battle-woods-ground-raw-v1.png`.

**G5. Arena edge pieces** (props-v1 layout, tall cells 256x520, IDLE / ACTIVE):
pine trunk wall (IDLE sway, ACTIVE shakes and drops a pinecone) · dumpster (ACTIVE lid bangs open, a raccoon
peeks) · log fence (ACTIVE splinters) · mossy rock pile · raccoon tent (ACTIVE flap opens and closes) · bin
barricade (ACTIVE knocked over) · crimson victory banner on a pole (IDLE furled, ACTIVE unfurls).
Save `art/prop-woods-<name>-raw-v1.png`.

**G6. Pickups** (items layout, one row of 16 icons, 96 px cells, static): coin pile · acorn · nightberry · heart ·
fish · trash bag (breakable) · crate closed · crate open · catnip · bone · key · raccoon mask (trophy) · shop deed
scroll · crimson flag · cat cage (free a cat) · mushroom. Save `art/items-woods-raw-v1.png`.

## H. Title and sigil

```
STYLE (above) but as a logo on a transparent background. The word "MEOWSYLVANIA" in chunky rounded hand-lettered
capitals, cream fill with the ink outline and a hard crimson drop shadow, the M's two peaks shaped like cat ears,
the V's two points like fangs, a small crescent moon dotting the A's crossbar. Below it, centred, the fang-moon
sigil in crimson. No other elements, no scene, no sparkles.
```
Also: the same wordmark in one colour (ink) for the Steam capsule, and the sigil alone at 512 px.

## I. Music (for a text-to-music model) — the game moves to this

Everything in the game loops on 2 beats, so the tempo is fixed: **112 BPM, 4/4**, every stem must start on
beat 1 and loop cleanly at bar boundaries. Ask for stems (drums / bass / melody / pad) where the tool allows.

1. **Day — the shop** (loop, 32 bars): "Cozy upbeat chiptune-folk at exactly 112 BPM in 4/4, ukulele and glockenspiel
   melody, soft brushed drums with a clear snare on 2 and 4, warm bass, a music-box counter-melody, a little
   accordion, cheerful and slightly mischievous like a cat café, seamless loop, no vocals, no tempo changes."
2. **Day — rush** (same key and tempo, 16 bars): "Same instruments, busier: double-time hi-hats, hand claps on 2 and
   4, a kazoo lead, playful and frantic, seamless loop, 112 BPM."
3. **Dusk — closing** (8-bar transition): "Same key, the day theme slowing to half-time feel at 112 BPM, a church bell
   on beat 1, melody drops an octave onto a harpsichord, a low organ pad fades in, ends on a held organ chord."
4. **Night — the crypt** (loop, 32 bars): "Dark playful gothic at exactly 112 BPM in 4/4 with a half-time feel, harpsichord
   and pipe organ, pizzicato strings, a theremin-like whistle, deep taiko on beat 1 and 3, creaking and dripping
   textures, mischievous not terrifying, like a haunted toy shop, seamless loop, no vocals."
5. **Night — combat** (16 bars): "Same instruments, double-time drums, organ stabs on the off-beats, surf-rock guitar
   lead, 112 BPM, seamless loop."
6. **Festival** (loop, 32 bars): "Day theme as a village fair: brass band, tuba on the downbeats, tambourine, crowd
   handclaps, 112 BPM, seamless loop."
7. **Stingers** (one-shots, each under 3 s, same key): shop open (bell + glockenspiel rise) · perfect serve (three-note
   kazoo fanfare) · machine jam (a sad trombone with a clank) · cat joins the household (organ chord + choir "ah") ·
   dawn return (bird chirps over a soft harp roll) · death (a music box winding down).

## J. Sound effects (for a text-to-sfx model, or freesound searches)

Each a short mono WAV, no reverb unless noted. cat paw step on stone (soft tap) · fish slap · churn crank
(wooden ratchet, loop) · cream scoop (wet squelch) · cone crunch · coin drop into glass · coin pop (bright
"ting") · bell ring (small brass) · customer mew happy · customer mew annoyed · customer leaves (huff + steps
fading) · machine jam (metal clank + hiss) · wrench fix (two clinks + a click) · build place (wood thunk) ·
build denied (hollow knock) · door creak open (long, castle reverb) · torch whoosh · bat flutter · splash ·
steam hiss · heartbeat (for the dark mass later) · UI hover (soft click) · UI confirm (two-note pop) · UI back
(low pop) · beat tick (very short wood tick — used to debug the beat clock, not shipped).

## QA before packing (all families)
- Outline weight matches `art/cat-raw-v1.png` side by side.
- Loop closes: frame 8 leads back into frame 1.
- No baked shadow or smoke behind the subject (the awning had one: add "no shadow or smoke behind" and regenerate).
- Cells don't touch; a subject that needs more room gets a taller `--cell`, not a smaller drawing.
