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
