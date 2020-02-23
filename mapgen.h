#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define IMG_WIDTH 600
#define IMG_HEIGHT 600
#define MAX_BUMPS 50

// Struct for bumps
typedef struct Bump
{
    int x;
    int y;
} Bump;

// Struct for each pixel
typedef struct Pixel
{
    int red;
    int green;
    int blue;
    int distance;
    float redNormal;
    float greenNormal;
    float blueNormal;
    float normalized;
    float average;
} Pixel;

// Global varibles
Pixel pixels[IMG_WIDTH][IMG_HEIGHT];
Bump bumps[MAX_BUMPS];

// Our functions
int CalculateDistance(int x, int y);     // Returns the distance to the nearest bump
void Init(void);                         // Init
void SetBumpsPos(void);                  // Randomizes the bumps position
void SetPixelDistance(void);             // Calculate the distance for all pixels
void PrintPixelData(void);               // Prints the pixel data
void SetPixelColorToNormal(void);        // Sets all 3 channels to the normal
void NormalizePixelDistance(void);       // Normalizes the distance for all pixels
void SetPixelBlueToNormal(void);         // Sets the blue channel for all pixels to the normal
void SetPixelGreenToNormal(void);        // Sets the green channel for all pixels to the normal
void SetPixelRedToNormal(void);          // Sets the red channel for all pixels to the normal
void AveragePixelColors(void);           // Calculate the average for all pixels
void SetPixelColorsToAverage(void);      // Sets all channels to the average
void NormalizePixelRed(void);            // Set the Red normals
void NormalizePixelGreen(void);          // Set the Green Normals
void NormalizePixelBlue(void);           // Set the blue normals
void SetPixelColorsToColorNormals(void); // Set the colors to their own normals