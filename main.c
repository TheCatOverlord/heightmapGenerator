
#include "mapgen.h"

// Main function
int main(void)
{
    Init(); // Init everything

    // Calculate the red
    SetBumpsPos();            // Get some random postitions for the bumps
    SetPixelDistance();       // Calculate the distance for all pixels to the nearest bump
    NormalizePixelDistance(); // Normalize all pixels
    SetPixelRedToNormal();    // Set the red channel to the normal

    // Calculate the green
    SetBumpsPos();            // Get some random postitions for the bumps
    SetPixelDistance();       // Calculate the distance to the new bumps for all pixels
    NormalizePixelDistance(); // Normalize the distances
    SetPixelGreenToNormal();  // Set the green channel for all pixels to the normal

    // Calculate the blue
    SetBumpsPos(); // Get some random postitions for the bumps
    SetPixelDistance();
    NormalizePixelDistance();
    SetPixelBlueToNormal();

    // Average everything
    AveragePixelColors();
    SetPixelColorsToAverage();

    for (int i = 0; i < 3; i++)
    {
        // Calculate the red
        SetBumpsPos();            // Get some random postitions for the bumps
        SetPixelDistance();       // Calculate the distance for all pixels to the nearest bump
        NormalizePixelDistance(); // Normalize all pixels
        SetPixelRedToNormal();    // Set the red channel to the normal

        // Calculate the green
        SetBumpsPos();            // Get some random postitions for the bumps
        SetPixelDistance();       // Calculate the distance to the new bumps for all pixels
        NormalizePixelDistance(); // Normalize the distances
        SetPixelGreenToNormal();  // Set the green channel for all pixels to the normal

        NormalizePixelBlue();
        NormalizePixelGreen();
        NormalizePixelRed();
        SetPixelColorsToColorNormals();

        // Average everything
        AveragePixelColors();
        SetPixelColorsToAverage();
    }

    NormalizePixelBlue();
    NormalizePixelGreen();
    NormalizePixelRed();
    SetPixelColorsToColorNormals();
    PrintPixelData(); // Print all pixel data
    return 0;
}
