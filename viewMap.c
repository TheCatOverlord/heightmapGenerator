#include <raylib.h>

int main(void)
{
    const int screenWidth = 600;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Map Gen Viewer");
    Camera camera = {{18.0f, 18.0f, 18.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, 45.0f, 0};

    Image image = LoadImage("mapgen.png");
    ImageColorInvert(&image);
    Texture2D texture = LoadTextureFromImage(image);

    Mesh mesh = GenMeshHeightmap(image, (Vector3){32, 8, 32});
    Model model = LoadModelFromMesh(mesh);

    model.materials[0].maps[MAP_DIFFUSE].texture = texture;
    Vector3 mapPosition = {-16.0f, 0.0f, -16.0f};

    UnloadImage(image);

    SetCameraMode(camera, CAMERA_ORBITAL);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // Update
        UpdateCamera(&camera);
        // Draw
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode3D(camera);
        DrawModel(model, mapPosition, 1.0f, GRAY);
        DrawGrid(20, 1.0f);
        EndMode3D();
        //DrawTexture(texture, screenWidth - texture.width, 0, WHITE);
        EndDrawing();
    }
    UnloadTexture(texture);
    UnloadModel(model);
    CloseWindow();
    return 0;
}