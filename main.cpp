#include <raylib.h>
#include "objects.hpp"

void main_loop(Ball b)
{
    
    BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawCircle(b.x, b.y, b.radius, b.colour);

    EndDrawing();
}

int main()
{
    const int screen_w = 1000;
    const int screen_h = 650;

    InitWindow(screen_w, screen_h, "Breakout");

    SetTargetFPS(60);

    Ball b = { screen_w / 2, screen_h / 2, 1, 20, BLUE };

    // Main game loop
    while (!WindowShouldClose())
    {
        main_loop(b);
    }
    
    CloseWindow(); 

    return 0;
}
