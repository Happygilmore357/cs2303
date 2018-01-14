//triaengle.c -- Isaiah Fleischer CS2303 C18-01

#include <math.h>
#include <stdio.h>

int main(void) {

  double Ax, Ay, Bx, By, Cx, Cy;
  double lengthAB, lengthBC, lengthCA;
  double circumference, s, area;

  printf("Enter the x- and y-coordinates of point A:- ");
  scanf("%lf %lf", &Ax, &Ay);
  printf("Enter the x- and y-coordinates of B:- ");
  scanf("%lf %lf", &Bx, &By);
  printf("Enter the x- and y-coordinates of point C:- ");
  scanf("%lf %lf", &Cx, &Cy);

  lengthAB = sqrt(pow(Ax-Bx, 2) + pow(Ay-By, 2));
  lengthBC = sqrt(pow(Bx-Cx, 2) + pow(By-Cy, 2));
  lengthCA = sqrt(pow(Cx-Ax, 2) + pow(Cy-Ay, 2));

  printf("Length of AB is %.3f\n", lengthAB);
  printf("Length of BC is %.3f\n", lengthBC);
  printf("Length of CA is %.3f\n", lengthCA);

  circumference = (lengthAB + lengthBC + lengthCA);

  printf("circumference is %.3f\n", circumference);

  s = circumference/2;

  area = sqrt(s*(s-lengthAB)*(s-lengthBC)*(s-lengthCA));

  printf("Area is %.3f\n", area);

  return 0;
}
