#include <iostream>
#include <raylib.h>

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
