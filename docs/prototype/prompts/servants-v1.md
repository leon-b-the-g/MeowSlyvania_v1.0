# Servant cats (caped design) — regeneration prompt v1

Decided 2026-10-16: the caped, sleek-fur, yellow-eyed design is the servant look (cats who joined the household).
Fixes art/cats-caped-backdrop-a/b-raw-v1.png and art/collage3-backdrop-raw-v1.png, which were rendered semi-transparent
over a dark backdrop. One sheet per fur per prompt (4 furs x 3 sheets = 12 generations). Attach
art/cat-tuxedo-work-raw-v1.png as the style/character reference.

```
2D game sprite sheet, Cult of the Lamb style: thick uniform dark outline #2a1a2e, flat colour fills, one shade tone per
colour, no gradients, no glow, no painterly texture. SUBJECT: the same caped servant cat as the reference image —
{FUR} — sleek short fur, big yellow eyes, small pink nose, no fangs, short crimson cape with a high collar, gold
crescent-moon pendant. Identical proportions, face, cape and outline weight in every frame.
LAYOUT: exactly 4 rows x 4 columns, 16 equal cells, wide empty gaps between all cells, one cat per cell, same scale
everywhere, feet on one baseline per row, nothing crossing a cell edge. Each row is a seamless 4-frame loop.
BACKGROUND: fully transparent PNG. No backdrop, no vignette, no glow, no shadow box, no floor, no frame, no text.
ROWS: {ROWS}
```

Replace {FUR} with one of: orange tabby with white chest / calico (white, orange and black patches) /
black-and-white tuxedo / grey tabby. Replace {ROWS} with one of the three sets:

- **Sheet A (move):** 1 idle facing the camera (gentle breathing) · 2 walk toward the camera · 3 walk away from the camera (back view, cape visible) · 4 walk facing right
- **Sheet B (work):** 1 use facing the camera (both paws press down, body squashes on frame 2) · 2 use facing right · 3 carry a round bundle overhead walking toward the camera · 4 same carry walking right
- **Sheet C (moods):** 1 sleep curled up, breathing · 2 hurt: flinch back, ears flat, eyes shut · 3 cheer: hop with paws up · 4 sad: ears down, tail dragging, slow sway

Save as art/servant-{fur}-{a|b|c}-raw-v1.png (fur = orange, calico, tuxedo, grey).
QA before handing over: open the PNG over a bright colour — the background must vanish completely, with only the cats left.
