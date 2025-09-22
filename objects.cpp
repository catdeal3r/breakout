#include "objects.hpp"
#include <iostream>
#include <raylib.h>
#include <vector>

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

void Ball::check_bricks_collisions(Bricks& br)
{
  for (int c = 0; c < br.brick_col_count; c++)
  {
    for (int r = 0; r < br.brick_row_count; r++)
    {
      Brick b = br[c][r];
      if (b.visible == false)
        continue;

      if (x + radius > b.x && x + radius < b.x + br.brick_width && y + radius > b.y && y - radius < b.y + br.brick_height)
        accely *= -1;
    }
  }
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


void Bricks::setup_bricks()
{
  for (int c = 0; c < brick_col_count; c++)
  {
    std::vector<Brick> buf;
    for (int r = 0; r < brick_row_count; r++)
    {
      buf.push_back(Brick(0, 0, true));
    }
    bricks.push_back(buf);
  }
}

void Bricks::draw_bricks()
{
  for (int c = 0; c < brick_col_count; c++)
  {
    for (int r = 0; r < brick_row_count; r++)
    {
      if (bricks[c][r].visible == false)
        continue;

      const int brick_x = c * (brick_width + brick_padding) + brick_offset_left;
      const int brick_y = r * (brick_height + brick_padding) + brick_offset_top;

      bricks[c][r].x = brick_x;
      bricks[c][r].y = brick_y;

      DrawRectangle(brick_x, brick_y, brick_width, brick_height, GREEN);
    }
  }
}
