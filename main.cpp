#include <raylib.h>
#include "objects.hpp"

void main_loop
(
    Ball& b,
    Paddle& p,
    const int screen_w,
    const int screen_h
)
{
    BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawCircle(b.x, b.y, b.radius, b.colour);
        DrawRectangle(p.x, p.y, p.width, p.height, p.colour);

    EndDrawing();

    // Update variables before next draw
    b.move();
    b.check_wall_collisions(screen_w, screen_h);

    p.check_input_and_move(screen_w, screen_h);

    b.check_paddle_collisions(p.x, p.y, p.width, p.height);
}

int main()
{
    const int screen_w = 1000;
    const int screen_h = 650;

    InitWindow(screen_w, screen_h, "Breakout");

    SetTargetFPS(60);

    Ball b = Ball(screen_w / 2, screen_h / 2, 20, BLUE);
    b.set_accel(4);

    Paddle p = Paddle(screen_w / 2 - (200 / 2), screen_h - (25 + 20), 200, 25, RED);
    p.set_accel(8);

    // Main game loop
    while (!WindowShouldClose())
    {
        main_loop(b, p, screen_w, screen_h);
    }
    
    CloseWindow(); 

    return 0;
}
