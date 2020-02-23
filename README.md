# HeightMapGenerator
A simple height map generator\
Not the best or the fastest, but it works

Use viewMap.c to view it!
## Compiling
To compile the generator run\
`gcc main.c mapgen.c -o mapgen -lm`
To compile the viewer run\
`gcc viewMap.c -o viewMap -lraylib`

## How to generate an image
`./mapgen > mapgen.ppm`\
This will generate a ppm image that then needs to be converted\
`pnmtopng mapgen.ppm > mapgen.png`\
will convert it
