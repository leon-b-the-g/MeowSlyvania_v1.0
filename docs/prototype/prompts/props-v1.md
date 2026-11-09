# Meowsylvania — environment props + ground textures (prompt v1)

How to use: paste **MASTER** once, then for each line of the **PROP MANIFEST** replace `{PROP}` and generate one sheet per prop
(one prop per image keeps the model from drifting between props and keeps every cell the same size).
Generate the **GROUND MAP** with its own prompt at the bottom. Save raw output to `art/prop-<name>-raw-v1.png` and `art/ground-raw-v1.png`;
`tools/packsheet.py` does the rest.

Why 8 frames everywhere: the engine will retime every loop to the music. An 8-frame loop plays over exactly 2 beats
(fps = BPM / 60 × 4), so every prop in the yard bobs on the same bar whatever the BPM. Frame 1 is always the "rest" pose on the beat.

---

## MASTER (paste first, keep verbatim)

```
2D hand-drawn game sprite sheet for a cozy cat-village shop sim, Cult of the Lamb art style.
STYLE (must match my cat sheets): thick uniform dark outline #2a1a2e on every shape, flat vector fills, exactly one darker
shade tone per colour for shadow, no gradients, no textures, no painterly rendering, no soft shading, simple rounded
cartoon shapes, slightly chunky proportions, readable silhouette at 64 px tall. Palette: cozy pastoral — warm wood
#b8763f / #7a4a26, cream #f3e6cf, moss green #7fcf6a / #4f8f43, slate stone #8d93a6 / #5b6075, straw #e9c86a,
one crimson accent #c0243a used sparingly, pale lavender highlights #d8c9ee for anything magical.
VIEW: 3/4 top-down, camera tilted about 50°, so tops of objects are visible and fronts face down-screen. Light from top-left.
Each prop sits on the ground; its contact point with the ground is the bottom-centre of the cell. Small flat elliptical
contact shadow in the shade tone directly under it, nothing else on the ground.
SHEET LAYOUT (strict): plain fully transparent background (no checkerboard, no paper, no frame, no text, no labels,
no watermark). 2 rows × 8 columns = 16 equal cells with wide clear gaps between cells. Same object scale in every cell,
same ground contact line across the whole row, nothing crossing a cell boundary.
ROW 1 = IDLE LOOP, 8 frames, a seamless loop that returns to frame 1: a gentle rhythmic motion as if nodding to music
(bob / sway / flicker / ripple as described per prop), amplitude small, frame 1 is the resting pose.
ROW 2 = ACTIVE LOOP, 8 frames, seamless loop, the prop being used / reacting, bigger exaggerated squash-and-stretch
motion as described per prop, frame 1 is the moment of impact.
Keep the outline weight identical to the cat sprites, no extra detail inside shapes, no gradient, no blur, no motion blur,
no speed lines, no particles outside the cell.
PROP: {PROP}
```

## PROP MANIFEST (one generation each; the text after the colon replaces `{PROP}`)

Shop stations (these are gameplay, do them first)
1. **barrel**: wooden fish barrel full of water, three silver fish visible, cat-paw sign nailed on the front. IDLE: water surface bobs, a fish tail flicks up on frame 5. ACTIVE: a fish leaps straight up out of the barrel with a splash ring, lands back on frame 8.
2. **churn**: tall wooden fish-cream churn with iron bands, a crank handle on top, cream dripping over the rim. IDLE: lid rattles slightly, one small steam puff rises and fades. ACTIVE: crank spins a full turn across the 8 frames, barrel wobbles side to side, cream sloshes, two steam puffs.
3. **counter**: shop counter made of planks with a striped cream-and-crimson cloth, a stack of waffle cones, a round scoop, a small brass bell, a hanging "FISH CREAM" board with a fish-moon glyph instead of letters. IDLE: cone stack sways, bell swings a little. ACTIVE: scoop lifts and spins once, a cone fills with cream and a cherry pops on top at frame 6, bell rings with two curved lines.
4. **tipjar**: glass jar with a cork lid and a few gold coins. IDLE: coins settle, jar tilts gently. ACTIVE: a coin drops in from above, jar bounces, coins jump.
5. **menuboard**: standing chalkboard A-frame with doodled fish cone and three prices as dots. IDLE: sways on its legs. ACTIVE: wobbles hard and chalk dust puffs off it.
6. **bell**: small brass counter bell on a wooden block. IDLE: tiny glint moves across it. ACTIVE: pressed down flat, rings with two arcs, springs back.

Shop dressing
7. **shopsign**: hanging wooden sign on two chains from a bracket, carved cat head with one fang, crimson ribbon. IDLE: swings slowly on the chains. ACTIVE: swings wide and the ribbon flaps.
8. **awning**: striped cream-and-crimson stall canopy on two posts, open front. IDLE: fabric edge ripples. ACTIVE: whole canopy flaps as if a gust hits it, scallops bounce.
9. **lantern**: iron lantern on a crooked wooden post, warm flame. IDLE: flame flickers, lantern sways. ACTIVE: lantern swings wide, flame doubles in size, two sparks.
10. **candle**: trio of stubby candles on a plate with dripping wax. IDLE: flames flicker out of sync. ACTIVE: flames flare tall then shrink.
11. **crate**: wooden crate with the fish-moon glyph burned on the side. IDLE: breathes (tiny squash and stretch). ACTIVE: jumps up, lands with a hard squash, lid pops open to show fish.
12. **milkjug**: ceramic cream jug, cat-ear handles, cream dripping. IDLE: cream surface sloshes. ACTIVE: jug tips and pours a stream, bounces back upright.
13. **fishbasket**: woven basket piled with fish. IDLE: a fish tail twitches. ACTIVE: all fish flop at once, basket hops.
14. **stool**: round three-legged wooden stool with a cushion. IDLE: cushion breathes. ACTIVE: cushion squashes flat as if sat on and puffs back.
15. **flowerbox**: window box with pink, white and lavender flowers. IDLE: flowers sway left-right. ACTIVE: flowers shake and three petals pop off upward.

Farm
16. **fencepost**: one short wooden fence post with two horizontal rails extending to the right edge of the cell (so it tiles). IDLE: almost still, one tiny creak lean. ACTIVE: rails wobble as if bumped.
17. **gate**: double wooden garden gate between two stone pillars, each pillar topped with a small cat statue. IDLE: gate rattles slightly. ACTIVE: both doors swing open toward the camera and bounce.
18. **well**: round stone well with a wooden roof and a bucket on a rope. IDLE: bucket swings. ACTIVE: crank turns, bucket rises dripping water.
19. **haybale**: round hay bale with straws sticking out. IDLE: straws twitch. ACTIVE: rolls a quarter turn and settles with a squash.
20. **scarecrow**: scarecrow shaped like a stuffed cat on a pole, button eyes, straw paws. IDLE: sways in the wind, straw flutters. ACTIVE: spins once around the pole.
21. **wateringcan**: tin watering can with a rose spout. IDLE: a drip forms and falls from the spout. ACTIVE: tilts and pours a fan of water drops.
22. **seedbag**: burlap sack of seeds with a sprout drawn on it, open top. IDLE: breathes. ACTIVE: jumps and a few seeds fly out.
23. **pumpkin**: fat orange pumpkin with a curly vine. IDLE: vine curls and uncurls. ACTIVE: wobbles and squashes like jelly.
24. **beehive**: straw skep beehive on a stump with three bees. IDLE: bees circle, hive hums (tiny vibration). ACTIVE: hive shakes, bees burst outward.
25. **mailbox**: wooden mailbox on a post with a crimson flag. IDLE: flag twitches. ACTIVE: flag springs up, lid opens, a letter pops out.

Garden & nature
26. **tree**: round-canopied oak, chunky trunk, two canopy blobs. IDLE: canopy sways left-right. ACTIVE: whole tree shakes hard, three leaves fall.
27. **willow**: weeping willow with hanging fronds. IDLE: fronds sway like a slow wave. ACTIVE: fronds whip sideways.
28. **deadtree**: bare twisted dead tree with a crow on a branch. IDLE: crow bobs its head. ACTIVE: branches rattle, crow flaps wings twice.
29. **bush**: round flowering bush. IDLE: sways. ACTIVE: rustles violently and a butterfly flies out.
30. **mushrooms**: cluster of three lavender-capped mushrooms with pale spots. IDLE: caps bob at different rates. ACTIVE: caps bounce high and release a spore puff.
31. **pond**: small oval pond with two lily pads and a reed. IDLE: concentric ripple expands from the centre and fades. ACTIVE: a fish jumps out and splashes, lily pads rock.
32. **rock**: mossy boulder. IDLE: still except moss tufts twitch. ACTIVE: cracks, a cat face appears on it, cracks close (easter egg).
33. **stump**: tree stump with rings and an axe. IDLE: axe handle wobbles. ACTIVE: axe lifts and chops, chips fly.

Castle & night flavour
34. **gravestone**: three different leaning gravestones in one cell (round, cross-less tablet, cracked), with a small drop glyph carved on each. IDLE: faint fog wisps drift across the base. ACTIVE: stones shake, one tilts further, a lavender glow pulses from the cracks.
35. **castlewall**: one straight segment of dark stone castle wall with battlements, ivy, one arrow slit, built to tile left-right (edges straight and flush). IDLE: ivy leaves twitch, a bat silhouette flits past the slit on frame 5. ACTIVE: wall shakes with dust puffs from the mortar.
36. **castledoor**: tall arched iron-banded castle door in a stone frame with two torches. IDLE: torches flicker. ACTIVE: door swings open inward to black with a lavender glow, torches flare.
37. **tower**: tall stone corner tower with a conical crimson-shingled roof and one glowing attic window. IDLE: window glow pulses softly. ACTIVE: roof shingles rattle, window flashes lavender, a bat flies out.
38. **statue**: stone statue of a regal cat on a pedestal holding a pendant. IDLE: pendant glint moves. ACTIVE: statue's eyes glow crimson, pendant swings.
39. **cauldron**: iron cauldron on a fire with lavender liquid. IDLE: liquid bubbles, flames flicker, one steam curl. ACTIVE: boils over with big bubbles bursting and three steam curls.
40. **bed**: wooden bed with a patched quilt and a pillow, seen from the front-top. IDLE: quilt rises and falls like breathing. ACTIVE: a cat-shaped lump under the quilt rolls over and three "z" shapes rise.
```

## GROUND MAP (separate generation)

```
Seamless tileable ground texture atlas for a 2D top-down game, Cult of the Lamb art style: flat vector fills, thick
dark outline #2a1a2e on individual shapes (stones, clods, planks), one darker shade tone per colour, no gradients,
no noise, no photo texture, no lighting, cozy pastoral palette.
STRICT LAYOUT: a 4 × 3 grid of 12 square tiles, each tile exactly 512 × 512 px, tiles separated by a 32 px pure white
gutter, no labels, no text. Every tile must tile seamlessly with itself on all four edges (left edge continues the right
edge, top continues the bottom). Pattern elements are small, around 24–48 px, so the tile repeats without visible seams
or an obvious focal point. Top-down view, no perspective.
Tiles in reading order:
1 grass, moss green #7fcf6a with a few darker blade tufts #4f8f43
2 grass with scattered tiny white and pink flowers
3 grass with fallen leaves and twigs, slightly darker
4 dirt path, warm tan #c9a06a with a few pebbles and darker clods
5 cobblestone, rounded grey stones #8d93a6 with dark mortar lines #5b6075
6 tilled soil DRY, brown furrows #8a5a3a running left-right, lighter ridges
7 tilled soil WET, same furrows darker #5e3a24 with small shine spots
8 crimson soil, same furrows in deep crimson-brown #5a1e28 with faint lavender veins
9 wooden deck planks, warm wood #b8763f with plank gaps #7a4a26 running top-bottom
10 castle flagstone, large dark slate slabs #5b6075 with lavender moss in the cracks
11 still water, pale blue #9fd0e8 with a few flat white ripple arcs
12 straw / hay floor, #e9c86a with scattered straws
```

## QA checklist before packing
- Outline weight matches `art/cat-raw-v1.png` side by side; if thinner, add "outline 6 px wide" to STYLE.
- Idle row frame 1 == frame 8 pose (loop closes); if the model gives a one-way motion, regenerate with "ping-pong loop".
- Cells don't touch; if sprites merge, add "cells at least 60 px apart" to SHEET LAYOUT.
- Ground tiles: drag one across itself in any image editor and look for a seam; regenerate the single tile if it shows.
