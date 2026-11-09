# Meowsylvania: asset prompts v3 (a living café and a living Pinewhisker Woods)

> **Landed 18 Oct:** every sheet below came back and is in the game (packed by `tools/packv3.sh`). Re-generate one
> with the same lines, drop it over its raw in `art/`, and run the script again.
> **Still open (19 Oct):** coldbox, bin, smoker, velvet and waffle from section 5 moved to `assets-v4.md` with the
> next round.

How to use: paste **STYLE**, then the **SHEET** block for the family, then one **SUBJECT** line. Generate one subject
per image and save the raw file to `art/<family>/<name>-raw-v1.png`. Then run the pack command for that family. The
game reads `public/assets/<family>/`, so a new sheet replaces the stand-in on the next reload.

## STYLE (paste this verbatim at the top of every prompt)

```
2D game sprite sheet, Cult of the Lamb style. Thick uniform dark outline #2a1a2e on every shape, flat fills with
one darker shade per colour, no gradients, no texture, no painterly shading. Chunky, rounded, cute-but-mischievous.
Palette: wood #b8763f/#7a4a26, cream #f3e6cf, moss #7fcf6a/#4f8f43, slate #8d93a6/#5b6075, straw #e9c86a,
crimson #c0243a (accents only), lavender #d8c9ee (magic only). 3/4 top-down view, light from the top left.
Fully transparent background, nothing crossing a cell edge, no text, no frame, no shadow box, no watermark.
Every frame the same scale, feet on one baseline per row, and every row loops back into its first frame.
```

## SHEET blocks (one per family)

| Family | SHEET line to paste | Pack |
|---|---|---|
| **critter** (enemies) | `8 columns x 4 rows. Row 1 idle (breathing, blink). Row 2 walk/hover loop. Row 3 attack: 3 frames wind-up (clear anticipation pose), 2 frames strike, 3 frames recover. Row 4: 3 frames hurt (flinch, eyes X), then 5 frames defeat (topple, then a dust-puff poof). Facing right.` | `python3 tools/packsheet.py art/enemies/NAME-raw-v1.png public/assets/enemies/enemy-NAME.png --grid 8x4 --cell 216x260` (boss: `--cell 432x480`) |
| **prop** (animated scenery) | `8 columns x 2 rows. Row 1 idle loop: subtle life (sway, flicker, bob, drip). Row 2 active loop: the big moment (it is used, triggered, or it is night). One object, centred.` | `python3 tools/packsheet.py art/props/NAME-raw-v1.png public/assets/props/prop-NAME.png --grid 8x2 --cell 256x400` |
| **ambient** (small wandering life) | `8 columns x 2 rows. Row 1 idle loop (pecking, grooming, wings resting). Row 2 move loop (walking, hopping or flying), facing right.` | `python3 tools/packsheet.py art/ambient/NAME-raw-v1.png public/assets/ambient/ambient-NAME.png --grid 8x2 --cell 192x192` |
| **cat rows** (player moves) | `Same cat, face and proportions as the reference sheet (attach art/cats/cat-orange-raw-v1.png). 4 columns x 4 rows, feet on one baseline.` | `python3 tools/packsheet.py art/cats/cat-orange-moves-raw-v1.png public/assets/cats/cat-orange-moves.png --cols 4 --rows 4,4,4,4 --cell 320x352` |
| **fx** | `17 columns x 1 row of separate effect sprites, each centred in its cell, no ground, in the order listed in section 7.` | `python3 tools/packsheet.py art/fx/fx-raw-v1.png public/assets/fx/fx.png --grid 17x1 --cell 128x128`, then add the three new names to `fx.json` |

## SUBJECT lines, in priority order

### 1. The raccoons
- **binrat:** a scrappy little raccoon grunt, grey with a black bandit mask, ringed tail, a red rag bandana. Attack: it crouches, then lunges with a wide open bite.
- **slinger:** a lanky raccoon in a leaf cap with a wooden Y-slingshot. Attack: it pulls the band back for three frames, then lets fly and wobbles.
- **shield:** a chunky raccoon in a dented bucket helmet, holding a round trash-can lid in front. Attack: it braces behind the lid, then charges forward lid first.
- **squirrel:** a tiny orange squirrel lookout with a huge curled tail and buck teeth. Attack: it chatters, then darts in for a nip.
- **rummage (boss, 432x480):** Boss Rummage, King of the Bins: a fat old raccoon in a bent gold crown, with a bulging black trash sack over one shoulder and a gold tooth. Attack row frames 1–4: he hoists the sack overhead. Frames 5–8: he charges head-down with dust behind him.

### 2. The special critters
- **wickling:** a living candle stub with stubby legs and a purple-orange flame for a head. Attack: the flame swells and spits out a purple fireball.
- **bonerat:** a skeleton rat held together by twine. Row 4 defeat ends as a neat pile of bones, so the pile can lie there before it gets back up.
- **bellbat:** a small crimson bat carrying a brass bell. Attack: it rings the bell (sound lines), then dives with its wings folded.
- **digger:** a mole miner in a brass helmet with a lamp and a little shovel. The walk row is a dirt mound moving along with the helmet peeking out. Attack: it bursts out of the ground.
- **gloom:** a purple slime blob with several eyes and two tentacles. Attack: it rears up and slams down. Defeat: it splits into two small blobs.

### 3. The cat's moves (one sheet, rows in this order)
1. **roll:** tuck into a ball and roll forward, 4 frames.
2. **pounce:** the third roll of a chain, a high forward flip with the tail streaming, 4 frames.
3. **claw:** a 3-hit combo: left swipe, right swipe, then a big two-paw heavy slash, 4 frames.
4. **hurt and stagger:** 4 frames.

### 4. Pinewhisker Woods, alive (props)
- **raccoontent:** a patched tent with a lantern. Idle: the flap breathes in the wind. Active: a raccoon peeks out.
- **trashheap:** a heap of bins and bags. Idle: flies buzz and a can rolls off. Active: it rumbles and a lid pops off.
- **campfire:** a log ring with a spit. Idle: the flames dance. Active: embers burst up.
- **woodsbanner:** a raccoon war flag on a crooked pole. Idle: it waves. Active: it snaps in a gust.
- **lanternstring:** paper lanterns strung between two posts. Idle: they sway. Active: they glow brighter at night.
- **mushroomring:** a ring of toadstools. Idle: spores drift up. Active: the caps glow.
- **pine:** a tall pine tree. Idle: it sways gently. Active: it shakes and drops needles. Also an **oak** with falling leaves, and a **stump** with a woodpecker.
- **arena gates (battle doors):** six arched hedge gates, one sheet each, each with a sign: crossed claws (fight), skull (elite), chest (treasure), campfire (rest), crown (boss), sun (exit). Idle: closed with the leaves rustling. Active: the gate swings open.
- **obstacles:** stump, mossy rock, and a short pine, each with an idle loop only (sway or moss twitch).

### 5. The summit café, alive (props)
- **sprinkleshaker** (save it as `topping`, so it packs to `prop-topping.png`): a counter-top shaker station with a jar of rainbow sprinkles. Idle: the jar wobbles. Active: the shaker shakes and sprinkles rain down.
- **coldbox** (packs to `prop-coldbox.png`): a small wooden ice chest with frosted blue sides and a cat-paw latch, cones of fish-cream peeking from crushed ice. Idle: frosty mist curls off the lid. Active: the lid pops open, a cold puff and sparkles, then it shuts.
- **bin** (packs to `prop-bin.png`): a dented tin scrap bin with a fish-bone sticker and a flip lid. Idle: a fly circles it. Active: the lid flips, a melted cone drops in with a splat, the bin wobbles.
- **smoker** (packs to `prop-smoker.png`, tier 2): a squat brick smokehouse with a little chimney and a hatch, fish hanging inside. Idle: a thin ribbon of smoke. Active: the hatch swings open, a puff of smoke, a bronzed fish slides out.
- **velvet** (packs to `prop-velvet.png`, tier 2): an ornate churn of dark wood and brass with a violet glass drum, a bat-wing crank. Idle: the drum glows softly. Active: the crank spins, violet cream swirls, a sparkle pops.
- **waffle** (packs to `prop-waffle.png`, tier 2): a cast-iron waffle iron on a stand, cat-paw pattern plates, a stack of waffle cones beside it. Idle: steam curls up. Active: the lid clamps shut, steam bursts, a golden waffle cone pops onto the stack.
- **bunting:** crimson and cream pennant bunting. Idle: it ripples. Active: it flaps hard in a gust.
- **flowerbox:** a window box of lavender and catnip. Idle: the plants bob. Active: a butterfly lands on them.
- **fishpond:** a small stone pond. Idle: ripples and lily pads. Active: a fish leaps out.
- **chimney:** a café chimney stack. Idle: soft smoke. Active: a puff ring and sparks.
- **weathervane:** a cat-shaped weathervane. Idle: it creaks round. Active: it spins.
- **marketstall:** the merchant's striped cart. Idle: the awning flutters. Active: coins flip and goods bounce.

### 6. Ambient life (wanders the shop and the woods)
- **pigeon** and **sparrow:** peck about, then hop and fly off.
- **butterfly:** lavender wings; idle is open and shut, move is fluttering.
- **firefly:** a glowing dot with tiny wings, for night in the woods.
- **frog:** a little green frog that sits and hops, for puddles.
- **sleepycat:** a fat grey cat loafing on a wall. Idle: it breathes. Move: it stretches.

### 7. FX (replace `public/assets/fx/fx.png`, same names and order as `fx.json`)
dust, dust2, slash, impact, acorn, bag, lid, spark, stars, ring, flame, goo, mound, bones, then three new ones:
leafburst, emberburst, splash.

## What hooks up by itself

These load automatically as soon as the sheet is in place: critters, FX, and the props for café machines (barrel,
churn, counter, topping, tipjar, menuboard, coldbox, bin, smoker, velvet, waffle). The cat-moves sheet, the scenery props and the ambient life need a few
lines of code to place and play them. Drop the sheets in and I'll wire them up.
