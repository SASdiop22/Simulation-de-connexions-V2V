#include<iostream>
#include<cmath>
#include"point.h"

point::point() : d_x(0.0), d_y(0.0)
{}

point::point(double x, double y) : d_x(x), d_y(y)
{}


double point::x() const
{
  return d_x;
}

double point::y() const
{
  return d_y;
}

double point::distance(const point& p) const
{
  double dx = p.d_x-d_x, dy = p.d_y-d_y;
  return std::sqrt(dx*dx + dy*dy);
}

void point::deplaceEn(double x, double y)
{
  d_x = x; d_y = y;
}

void point::deplaceDe(double dx, double dy)
{
  d_x += dx; d_y += dy;
}

point& point::operator*=(double val)
{
  d_x *= val; d_y *= val;
  return *this;
}


point& point::operator/=(double val)
{
  d_x /= val; d_y /= val;
  return *this;
}

point& point::operator+=(const point& p)
{
  d_x += p.d_x; d_y += p.d_y;
  return *this;
}

bool point::operator==(const point& p) const
{
  return (d_x == p.d_x) && (d_y == p.d_y);
}

bool point::operator!=(const point& p) const
{
  return (d_x != p.d_x) || (d_y != p.d_y);
}
