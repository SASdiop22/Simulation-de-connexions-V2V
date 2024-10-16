#ifndef POINT_H
#define POINT_H

#include<iosfwd>


class point {
public:
  point();

  point(double x, double y);

  double x()  const;

  double y()  const;

  double distance(const point& p) const;

  void deplaceEn(double x, double y);

  void deplaceDe(double dx, double dy);

  point& operator+=(const point& p);

//Multiplier par scalaire
  point& operator*=(double val);

//Diviser par scalaire
  point& operator/=(double val);

//Comparer deux points (égaux)
  bool operator==(const point& p)   const;

//Comparer deux points (différents)
  bool operator!=(const point& p)   const;

private:
  double d_x,d_y;
};

#endif
