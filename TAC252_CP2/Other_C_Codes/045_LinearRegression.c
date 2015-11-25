/*
Program to implement linear regression.


INTRODUCTION:
While doing some experiments, we need to take some readings say (xi, yi).
Based on that reading, we may need to derive an approximate relation between
y and x, in the form of y = mx + c

here, m and c are the values that are able to represent the "BEST GUESS"
of y value, for a given x value.

for example:

xi = 12    13    12.5    11.5    12.9

yi = 21    22    23.1    20.1    22.5

then 

n = 5
Sx = sigma(x) = 12 + 13 + 12.5 + 11.5 + 12.9
Sy = sigma(y) = 21 + 22 + 23.1 + 20.1 + 22.5
Sxx = sigma(x^2) = 144 + 169 + .... // complete this as an exercise
Sxy = sigma(x*y)
Syy = sigma(y^2)

and 

we can form an approximate relation between x and y, given by the formula

y = mx + c, where

m = (n.Sxy - Sx.Sy) / (n.Sxx - (Sx)^2) and
c = (Sy - m.Sx) / n

Reference:
http://en.wikipedia.org/wiki/Simple_linear_regression

*/

# include <stdio.h>

struct Point
{
    double x, y;
};


void CalculateRegressionValues(struct Point *points, int count, double *m, double *c)
{
    double Sx = 0.0;
    double Sy = 0.0;
    double Sxx = 0.0;
    double Sxy = 0.0;
    double Syy = 0.0;

    int loop;

    for(loop = 0; loop < count; loop++)
    {
        double x = points[loop].x;
        double y = points[loop].y;

        Sx += x;
        Sy += y;
        Sxx += x*x;
        Sxy += x*y;
        Syy += y*y;
    }

    *m = (count*Sxy - Sx*Sy) / (count*Sxx - Sx*Sx);
    *c = (Sy - (*m)*Sx) / count;

    printf("m = %lf, c = %lf\n", *m, *c);
}


void main()
{
    struct Point points[10];
    int count = 10;
    int loop;
    double x = 12.45;
    double y;
    double m, c;

    for(loop = 0; loop < count; loop++)
    {
        points[loop].x = loop*3;
        // y = 2x - 1
        points[loop].y = points[loop].x*2 - 1;             
    }

    CalculateRegressionValues(points, count, &m, &c);

    y = m*x + c;
    printf("The calculated value for x = %lf is... y = %lf\n", x, y);    
}
