#include "mapgen.h"

// Function to set to the color normals
void SetPixelColorsToColorNormals(void)
{
    for (int y = 0; y < IMG_HEIGHT; y++)
    {
        for (int x = 0; x < IMG_WIDTH; x++)
        {
            pixels[x][y].red = pixels[x][y].redNormal * 255;
            pixels[x][y].green = pixels[x][y].greenNormal * 255;
            pixels[x][y].blue = pixels[x][y].blueNormal * 255;
        }
    }
}

// Function to normalize the pixel red channels
void NormalizePixelRed(void)
{
    // Grab the largest distance for all pixels
    int highestRed = 0;
    for (int y = 0; y < IMG_HEIGHT; y++)
    {
        for (int x = 0; x < IMG_WIDTH; x++)
        {
            if (pixels[x][y].red > highestRed)
                highestRed = pixels[x][y].red;
        }
    }

    // Normalize
    for (int y = 0; y < IMG_HEIGHT; y++)
    {
        for (int x = 0; x < IMG_WIDTH; x++)
        {
            pixels[x][y].redNormal = (float)pixels[x][y].red / (float)highestRed;
        }
    }
}

// Function to normalize the pixel green channels
void NormalizePixelGreen(void)
{
    // Grab the largest distance for all pixels
    int highestGreen = 0;
    for (int y = 0; y < IMG_HEIGHT; y++)
    {
        for (int x = 0; x < IMG_WIDTH; x++)
        {
            if (pixels[x][y].green > highestGreen)
                highestGreen = pixels[x][y].green;
        }
    }

    // Normalize
    for (int y = 0; y < IMG_HEIGHT; y++)
    {
        for (int x = 0; x < IMG_WIDTH; x++)
        {
            pixels[x][y].greenNormal = (float)pixels[x][y].green / (float)highestGreen;
        }
    }
}

// Function to normalize the pixel blue channels
void NormalizePixelBlue(void)
{
    // Grab the largest distance for all pixels
    int highestBlue = 0;
    for (int y = 0; y < IMG_HEIGHT; y++)
    {
        for (int x = 0; x < IMG_WIDTH; x++)
        {
            if (pixels[x][y].blue > highestBlue)
                highestBlue = pixels[x][y].blue;
        }
    }

    // Normalize
    for (int y = 0; y < IMG_HEIGHT; y++)
    {
        for (int x = 0; x < IMG_WIDTH; x++)
        {
            pixels[x][y].blueNormal = (float)pixels[x][y].blue / (float)highestBlue;
        }
    }
}

// Function to set the average to all 3 channels
void SetPixelColorsToAverage(void)
{
    for (int y = 0; y < IMG_HEIGHT; y++)
    {
        for (int x = 0; x < IMG_WIDTH; x++)
        {
            pixels[x][y].red = pixels[x][y].average;
            pixels[x][y].green = pixels[x][y].average;
            pixels[x][y].blue = pixels[x][y].average;
        }
    }
}

// Function to set the red channel to the average

// Function to average the all 3 channels
void AveragePixelColors(void)
{
    for (int y = 0; y < IMG_HEIGHT; y++)
    {
        for (int x = 0; x < IMG_WIDTH; x++)
        {
            pixels[x][y].average = pixels[x][y].red + pixels[x][y].blue + pixels[x][y].green;
            pixels[x][y].average = pixels[x][y].average / 3.0f;
        }
    }
}

// Function to set all pixels blue channel to the normal
void SetPixelBlueToNormal(void)
{
    for (int y = 0; y < IMG_HEIGHT; y++)
    {
        for (int x = 0; x < IMG_WIDTH; x++)
        {
            pixels[x][y].blue = pixels[x][y].normalized * 255;
        }
    }
}

// Function to set all pixels green channel to the normal
void SetPixelGreenToNormal(void)
{
    for (int y = 0; y < IMG_HEIGHT; y++)
    {
        for (int x = 0; x < IMG_WIDTH; x++)
        {
            pixels[x][y].green = pixels[x][y].normalized * 255;
        }
    }
}

// Function to set all pixels red channel to the normal
void SetPixelRedToNormal(void)
{
    for (int y = 0; y < IMG_HEIGHT; y++)
    {
        for (int x = 0; x < IMG_WIDTH; x++)
        {
            pixels[x][y].red = pixels[x][y].normalized * 255;
        }
    }
}

// Function to set all channels to the normal
void SetPixelColorToNormal(void)
{
    for (int y = 0; y < IMG_HEIGHT; y++)
    {
        for (int x = 0; x < IMG_WIDTH; x++)
        {
            pixels[x][y].red = pixels[x][y].normalized * 255;
            pixels[x][y].green = pixels[x][y].normalized * 255;
            pixels[x][y].blue = pixels[x][y].normalized * 255;
        }
    }
}

// Function to print the pixel data
void PrintPixelData(void)
{
    for (int y = 0; y < IMG_HEIGHT; y++)
    {
        for (int x = 0; x < IMG_WIDTH; x++)
        {
            printf("%d %d %d ", pixels[x][y].red, pixels[x][y].green, pixels[x][y].blue);
        }
    }
}

// Function to normalize the pixel distances
void NormalizePixelDistance(void)
{
    // Grab the largest distance for all pixels
    int longestDistance = 0;
    for (int y = 0; y < IMG_HEIGHT; y++)
    {
        for (int x = 0; x < IMG_WIDTH; x++)
        {
            if (pixels[x][y].distance > longestDistance)
                longestDistance = pixels[x][y].distance;
        }
    }

    // Normalize
    for (int y = 0; y < IMG_HEIGHT; y++)
    {
        for (int x = 0; x < IMG_WIDTH; x++)
        {
            pixels[x][y].normalized = (float)pixels[x][y].distance / (float)longestDistance;
        }
    }
}

// Function to calculate the distance for all pixels
void SetPixelDistance(void)
{
    for (int y = 0; y < IMG_HEIGHT; y++)
    {
        for (int x = 0; x < IMG_WIDTH; x++)
        {
            pixels[x][y].distance = CalculateDistance(x, y);
        }
    }
}
// Init Function
void Init(void)
{
    printf("P3\n%d %d\n255\n", IMG_WIDTH, IMG_HEIGHT); // PPM header
    srand(time(NULL));                                 // Init srand
}

// Function to randomie bump positions
void SetBumpsPos(void)
{
    for (int i = 0; i < MAX_BUMPS; i++) // Loop through all bumps
    {
        bumps[i].x = rand() % IMG_WIDTH;  // Set the x position to a random value
        bumps[i].y = rand() % IMG_HEIGHT; // Set the y position to a random value
    }
}

// Function to return the distance to the nearest bump
int CalculateDistance(int x, int y)
{
    int tmp;                                                     // Temp int
    int returned = sqrt(pow(IMG_HEIGHT, 2) + pow(IMG_WIDTH, 2)); // longest possible to distance
    for (int i = 0; i < MAX_BUMPS; i++)                          // Loop through all bumps
    {
        tmp = sqrt(pow(bumps[i].x - x, 2) + pow(bumps[i].y - y, 2)); // Calculate the distance to the current bump
        if (tmp < returned)                                          // Check if the distance to the nearest bump is shorter
            returned = tmp;                                          // Set it
    }
    return returned; // return the value
}