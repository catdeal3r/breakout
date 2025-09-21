#include <raylib.h>
#include "objects.hpp"

void main_loop(Ball& b, const int screen_w, const int screen_h)
{
    BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawCircle(b.x, b.y, b.radius, b.colour);

    EndDrawing();

    // Update variables before next draw
    b.move();
    b.check_wall_collisions(screen_w, screen_h);
}

int main()
{
    const int screen_w = 1000;
    const int screen_h = 650;

    InitWindow(screen_w, screen_h, "Breakout");

    SetTargetFPS(60);

    Ball b = Ball(screen_w / 2, screen_h / 2, 20, BLUE);
    b.set_accel(4);

    // Main game loop
    while (!WindowShouldClose())
    {
        main_loop(b, screen_w, screen_h);
    }
    
    CloseWindow(); 

    return 0;
}
