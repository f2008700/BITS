/*
The math tutorials are not uploaded to my site while this program is created.

For time being, the reader is suggested to have a good idea on interpolation.


LEGRANGE interpolation:

suppose that "k" no. of points are to be interpolated.

then, the interpolated value for a given x is given by...


////////////////////////////////////////////////////////////////////////
//                                                                    //
//       y1*(x-x2)*(x-x3)*...*(x-xk)   y2*(x-x1)*(x-x3)*...*(x-xk)    //
// f(x) = --------------------------- + --------------------------- + //
//        (x1-x2)*(x1-x3)*...*(x1-xk)   (x2-x1)*(x2-x3)*...*(x2-xk)   //
//                                                                    //
//        ...                                                         //
//        ...                                                         //
//        ...                                                         //
//                                                                    //
//           yk*(x-x1)*(x-x2)*...*(x-x(k-1))                          //
//        + --------------------------------                          //
//          (xk-x1)*(xk-x2)*...*(xk-x(k-1))                           //
//                                                                    //
////////////////////////////////////////////////////////////////////////



Reference:
http://mathworld.wolfram.com/LagrangeInterpolatingPolynomial.html
*/

# include <stdio.h>

struct Point
{
    double x;
    double y;
};


double Interpolate(double x, struct Point *points, int count)
{
    int loop1, loop2;
    double y = 0.0;
    double numerator, denominator;

    for(loop1 = 0; loop1 < count; loop1++)
    {
        numerator = points[loop1].y;
        denominator = 1.0;

        for(loop2 = 0; loop2 < count; loop2++)
        {
            if(loop2 == loop1) continue;

            numerator *= (x - points[loop2].x);
            denominator *= (points[loop1].x - points[loop2].x);
        }
        y += numerator/denominator;
    }

    return y;
}


void main()
{
    // y = x^4
    struct Point points[] = {   
                               {-10.0,   10000.0},  
                               { 10.0,   10000.0},
                               { 30.0,  810000.0},
                               { 50.0, 6250000.0},
                               { 70.0,24010000.0},
                                                   };
    int count = sizeof(points)/sizeof(points[0]);

    printf("%lf\n", Interpolate(90.0, points, count));
}



