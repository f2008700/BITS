/*

Trapezoidal Method:

It is a method to find the approximate value of a definite integral.


Integral( f(x) dx) from a to b is given by...

((b-a)/2n) * ( f(x0) + 2f(x1) + 2f(x2) +.....+ 2f(x(n-1)) + f(xn) )


where

the interval [a, b] is divided into n equal intervals
*/


# include <stdio.h>


double xPlusOne_square(double x)
{
    // f(x) = (x+1)^2
    x++;
    return x*x;
}

typedef double (*function) (double);


double Integrate(function f, double a, double b, int intervals)
{
    int loop;
    double area = 0.0;
    double h = (b-a)/intervals;

    for(loop = 1; loop < intervals; loop++)
    {
        area += f(a + h*loop);
    }

    area *= 2.0;
    area += f(a) + f(b);
    area *= h/2.0;

    return area;   
}


void main()
{
    printf("area -> %lf\n", Integrate(xPlusOne_square, 0.0, 12.0, 12));
}


