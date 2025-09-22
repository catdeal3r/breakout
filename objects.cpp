#include "objects.hpp"
#include <iostream>
#include <raylib.h>

void Ball::set_accel(int a)
{
  accely = a;
  accelx = a;
}

void Ball::move()
{
  if (accely == 0 && accelx == 0)
    return;
  
  y += accely;
  x += accelx;
}


void Ball::check_wall_collisions(const int screen_w, const int screen_h)
{
  if (y + radius > screen_h || y - radius < 0)
    accely *= -1;

  if (x + radius > screen_w || x - radius < 0)
    accelx *= -1;
}

void Ball::check_paddle_collisions(int px, int py, int pwidth, int pheight)
{
   if (y + radius > py && x + radius > px && x - radius < px + pwidth && y + radius < py + pheight)
     accely *= -1;

   if (x + radius > px && y > py && y < py + pheight && x - radius < px + pwidth)
     accelx *= -1;
}

void Paddle::set_accel(int a)
{
  accel = a;
}

void Paddle::check_input_and_move(const int screen_w, const int screen_h)
{
  if (IsKeyDown(KEY_LEFT))
    x -= accel;

  if (x < 0)
    x = 0;

  if (IsKeyDown(KEY_RIGHT))
    x += accel;

  if (x + width > screen_w)
    x = screen_w - width;
}
