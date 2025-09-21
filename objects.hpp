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

    Ball(int ix, int iy, int iradius, Color icolour) : x(ix), y(iy), radius(iradius), colour(icolour) {}
};
