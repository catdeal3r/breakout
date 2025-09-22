#include <iostream>
#include <raylib.h>
#include <vector>

class Brick
{
  public:
    int x;
    int y;
    bool visible;

    Brick(int ix, int iy, bool ivisible) : x(ix), y(iy), visible(ivisible) {}
};

class Bricks
{
  private:
    const int brick_padding = 20;
    const int brick_offset_top = 30;
    const int brick_offset_bottom = 30;
    const int brick_offset_left = 35;
    const int brick_offset_right = 30;

  public:
    std::vector<std::vector<Brick>> bricks = {};
    const int brick_row_count = 4;
    const int brick_col_count = 5;
    const int brick_width = 170;
    const int brick_height = 40;

    void setup_bricks();
    void draw_bricks();
};

class Ball
{
  private:
    int accely = 0;
    int accelx = 0;

  public:
    int x;
    int y;
    int radius;
    Color colour;
    
    void set_accel(int);
    void move();
    void check_wall_collisions(const int, const int);
    void check_paddle_collisions(int, int, int, int);
    void check_bricks_collisions(Bricks&);

    Ball(int ix, int iy, int iradius, Color icolour) : x(ix), y(iy), radius(iradius), colour(icolour) {}
};


class Paddle
{
  private:
    int accel = 0;
    
  public:
    int x;
    int y;
    int width;
    int height;
    Color colour;

    void set_accel(int);
    void check_input_and_move(const int, const int);

    Paddle(int ix, int iy, int iwidth, int iheight, Color icolour) : x(ix), y(iy), width(iwidth), height(iheight), colour(icolour) {}
};
