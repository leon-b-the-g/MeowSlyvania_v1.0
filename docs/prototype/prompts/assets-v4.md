# Meowsylvania: asset prompts v4 (tier-2 café, spells, Purrgatory village)

> **Landed 20 Oct:** all 82 sheets (sections 1-6) are in the game, packed by `tools/packv4.sh` from `art/`. Re-generate
> one with the same lines, drop it over its raw, and run the script again.

How to use: paste **STYLE**, then the **SHEET** line for the family, then one **SUBJECT** line. One subject per image.
Save each raw as `art/<family>/<name>-raw-v1.png` (or drop the lot in one folder and tell me: I file, pack and wire
them). Sections are in priority order: 1 and 2 load the moment they are packed; 3 to 5 need a little code from me.

## STYLE (paste this verbatim at the top of every prompt)

```
2D game sprite sheet, Cult of the Lamb style. Thick uniform dark outline #2a1a2e on every shape, flat fills with
one darker shade per colour, no gradients, no texture, no painterly shading. Chunky, rounded, cute-but-mischievous.
Palette: wood #b8763f/#7a4a26, cream #f3e6cf, moss #7fcf6a/#4f8f43, slate #8d93a6/#5b6075, straw #e9c86a,
crimson #c0243a (accents only), lavender #d8c9ee (magic only). 3/4 top-down view, light from the top left.
Fully transparent background. Even grid: every frame centred in its own equal cell, nothing crossing a cell edge.
No text, no frame, no shadow box, no watermark. Every frame the same scale, feet on one baseline per row.
```

## SHEET lines

| Family | SHEET line to paste | Saved as |
|---|---|---|
| **prop** | `8 columns x 2 rows. Row 1 idle loop: subtle life (sway, flicker, bob, steam). Row 2 active: the big moment (it is used or triggered), looping back into frame 1. One object, centred.` | `art/props/NAME-raw-v1.png` |
| **landmark** (map) | `8 columns x 2 rows, a small toy-diorama model. Row 1 idle loop. Row 2 the conquest: frames 1-5 the change happens, frames 6-8 hold the new look (do not loop back to the old one).` | `art/map/prop-map-NAME-raw-v1.png` |
| **critter** | `8 columns x 4 rows, facing right. Row 1 idle (breathing, blink). Row 2 walk loop. Row 3 attack: 3 frames wind-up (a clear tell), 2 frames strike, 3 frames recover. Row 4: 3 frames hurt (flinch, eyes X), then 5 frames defeat (topple, dust puff, last frame empty).` | `art/enemies/NAME-raw-v1.png` |
| **icons** | `4 columns x 4 rows of separate icons in reading order (left to right, top to bottom), each centred in its square cell with even margins, in the order listed.` | `art/items/NAME-raw-v1.png` |
| **fx strip** | `4 columns x 2 rows, one effect animating in reading order (left to right, top to bottom), centred in each square cell, no ground, nothing else in the image.` | `art/fx/NAME-raw-v1.png` |
| **overlay** | `The same 4 x 4 grid, poses and scale as the attached cat sheet (attach art/cats/cat-orange-raw-v1.png). Draw ONLY the accessory, exactly where it sits on the cat in each frame; everything else transparent.` | `art/cats/acc-NAME-raw-v1.png` |

## SUBJECT lines

### 1. The café, second tier (props; they replace the canvas stand-ins as soon as they are packed)
- **smoker:** a squat brick smokehouse with a little chimney and a hatch, fish hanging inside. Idle: a thin ribbon of smoke. Active: the hatch swings open, a puff of smoke, a bronzed fish slides out.
- **velvet:** an ornate churn of dark wood and brass with a violet glass drum and a bat-wing crank. Idle: the drum glows softly. Active: the crank spins, violet cream swirls, a sparkle pops.
- **waffle:** a cast-iron waffle iron on a stand with cat-paw pattern plates and a stack of waffle cones beside it. Idle: steam curls up. Active: the lid clamps shut, steam bursts, a golden waffle cone pops onto the stack.
- **coldbox:** a small wooden ice chest with frosted blue sides and a cat-paw latch, cones peeking out of crushed ice. Idle: frosty mist curls off the lid. Active: the lid pops open with a cold puff and sparkles, then shuts.
- **bin:** a dented tin scrap bin with a fish-bone sticker and a flip lid. Idle: a fly circles it. Active: the lid flips, a melted cone drops in with a splat, the bin wobbles.

### 2. New icons (two icon rows; they show in hands, on the floor and in the HUD)
- **items2**, in this order: smoked fish (bronze, a curl of smoke) · velvet base (a tub of deep violet cream) · waffle cone (empty, golden, criss-cross) · sprinkles jar · plain velvet cone · catnip velvet cone · nightberry velvet cone · plain cone in a waffle · catnip cone in a waffle · nightberry cone in a waffle · plain velvet cone in a waffle · catnip velvet cone in a waffle · nightberry velvet cone in a waffle · a tiny gold crown (special customer) · a gold star (skill point) · a violet gem (xp). Cones: plain = cream scoop, catnip = green, nightberry = purple; velvet = a violet swirl through the scoop.
- **skills**, in this order, drawn as round medallions with a crimson rim: Moonbeam (a crescent shooting a beam) · Blood Frenzy (crossed claws dripping red) · Shadow Step (a cat silhouette in purple smoke) · Bat Swarm (three bats) · Heart of the Night (a crimson heart with a fang-moon) · Thin Blood (a blood drop) · Blood Moon (a red full moon) · Sharp Fangs (two fangs) · Rend (three claw slashes) · Nine Lives (a cat face with a halo) · Mist Form (a wisp of fog) · Silver Tongue (a coin on a cat tongue) · Night Shift (a servant cape and a clock) · a locked medallion (grey, a padlock) · an empty slot (a dashed ring) · a blood drop for the spell bar.

### 3. Spell effects (fx strips)
- **fx-moonbeam:** a horizontal beam of pale blue moonlight crossing the whole cell, left to right, with crescent sparkles; it flares up, holds, and thins out.
- **fx-bat:** one small purple bat flying right, a full wing-flap loop.
- **fx-shadowburst:** a ring of purple smoke bursting outward from the centre and fading.
- **fx-frenzy:** a red aura flickering round an empty centre, with little blood drops spinning, looping.
- **fx-cast:** a quick swirl of lavender sparks spiralling in to the centre and popping.

### 4. Special customers (overlay)
- **acc-vip:** a tiny black top hat tilted on one ear and a gold monocle on a chain, so special customers stand out in the queue.

### 5. Purrgatory village (the next region: the dogs)
Critters:
- **pup:** a scruffy little terrier puppy in a spiked collar, too much energy. Attack: it crouches, wiggles its rear, then lunges with a snap.
- **hound:** a long-eared bloodhound with a droopy face and a bandolier of bones. Attack: it plants its feet and barks a visible shockwave ring forward.
- **bulldog:** a squat bulldog in a dented iron dog-bowl helmet, holding a round bowl like a shield. Attack: it braces behind the bowl, then barrels forward.
- **barkley (boss, draw it big):** Baron Barkley, a huge old mastiff in a crimson admiral coat with gold epaulettes and a chewed bone sceptre. Attack frames 1-4: he rears back and inhales; frames 5-8: he lets out a roaring bark with a shockwave.

Props (one prop sheet each):
- **doghouse:** a wooden kennel with a crooked roof and a nameplate. Idle: a tail wags in the doorway. Active: a pup pokes its head out and barks.
- **bonepile:** a heap of gnawed bones. Idle: a fly circles. Active: a bone tumbles off the top.
- **laundryline:** a washing line between two posts with socks and a tiny cat-sized vest. Idle: it sways. Active: a sock blows off and back.
- **dogbanner:** the dogs' war flag (brown and cream, a bone-and-paw emblem) on a pole. Idle: it waves. Active: it snaps in a gust.
- **foodbowl:** a big dented dog bowl full of kibble. Idle: a kibble rolls. Active: it spins and rattles.
- **cottage:** a small village house with a red roof and a round window, for the rim of battle rooms. Idle: a curtain twitches. Active: a lamp lights in the window.
- **picketfence:** a short run of white picket fence. Idle only: a loose picket wobbles.
- **crate** and **barrel:** a wooden crate and a water barrel, obstacles. Idle only: a tiny wobble.
- **village gates (battle doors):** six arched wooden garden gates with a hedge on top, one sheet each, each with a sign: crossed claws (fight), skull (elite), chest (treasure), campfire (rest), crown (boss), sun (exit). Idle: closed, the sign creaks. Active: the gate swings open.

Map landmarks (landmark sheet):
- **battle-village:** a stake with the dogs' flag (brown and cream, bone-and-paw emblem). Idle: it flaps. Conquest: the flag is yanked down and a crimson fang-moon flag unfurls.
- **boss-village:** a fortified kennel with a bone fence and a crooked crown on the roof. Idle: a dog's eyes blink in the doorway. Conquest: the roof caves in with a dust puff and a crimson banner rises.

### 6. Later regions (same SHEET lines; generate when you want to run ahead)
- **Squeakmoor fields (mice and rats):** mouse (a farmhand mouse with a pitchfork), rat (a fat grain-thief rat with a sack), mole (a farmer mole popping out of furrows), baron (Rat Baron, boss, in a straw hat and a cape of corn husks). Props: haystack, scarecrow, windmill, grain sacks, fields gates, map flag and a barn fort.
- **Croaking Fens (frogs and toads):** frog (a spear frog with a leaf shield), toad (a warty toad that spits), newt (a fast orange newt), toadstool (boss: a giant toad wearing a mushroom cap). Props: reeds, dead tree, lily pond, rickety jetty, fens gates, map flag and a stilt-hut fort.
- **Gullport harbour (seagulls and crabs):** gull (a thieving seagull), crab (a crab with a bottle-cap shield), pelican (a pelican that swallows and spits fish), gullbert (boss: a captain gull in a tricorn hat). Props: crates, a beached boat, rope coils, a lighthouse, harbour gates, map flag and a shipwreck fort.

## What happens when they land

Section 1 and the icons of section 2 load as soon as I pack them. The spell effects, the special-customer overlay
and the village need a few lines each: the dogs move into the village's battles and map, the village room theme
switches from canvas stand-ins to these props, and its doors use the village gates. Drop the files in and I'll take
it from there.
