/*
The math tutorials are not uploaded to my site while this program is created.

For time being, the reader is suggested to have a good idea on interpolation.


Newton-Gregory forward interpolation:

suppose that "k" no. of points are collected for interpolation.

(x1, y1), (x2, y2), ...., (xk, yk)

then, the interpolated value for a given x where (x1 <= x < x2 and x = x1 + a) is given by...

y = y1 + q.d1 + q.(q-1).d2/2! + q.(q-1).(q-2).d3/3! +...+ q.(q-1).(q-2)..(q-k+1).d(k-1)/(k-1)!

where.......

--> di stands for delta of order i
--> q = (x - x1)/h
--> h = (x2 - x1) = (x3 - x2) = ..... = (xk - x(k-1))


Reference:
http://mathworld.wolfram.com/NewtonsForwardDifferenceFormula.html
*/

# include <stdio.h>

# define MaxValues 10

double deltas[MaxValues][MaxValues];

struct Point
{
    double x, y;
};

void CalculateDeltas(struct Point* points, int count)
{
    int loop1, loop2;
    int order = 0;

    for(loop1 = 0; loop1 < count; loop1++) 
        deltas[order][loop1] = points[loop1].y;

    for(loop1 = 1; loop1 < count; loop1++)
        for(loop2 = 0; loop2 < count; loop2++) 
            deltas[loop1][loop2] = 0.0;

    for(loop1 = count - 1; loop1; loop1--)
    {
        for(loop2 = 0; loop2 < loop1; loop2++)
        {
            deltas[order+1][loop2] = deltas[order][loop2+1] - deltas[order][loop2];
        }
        order++;
    }

    printf("\nThe calculated deltas are...\n");

    for(loop1 = 0; loop1 < count; loop1++)
    {
        for(loop2 = 0; loop2 < count; loop2++)
        {
            printf("%9.4lf   ", deltas[loop2][loop1]);
        }
        printf("\n");
    }
}


double Interpolate(double q, double limit)
{
    int order = 0;
    double y = deltas[0][0];
    double numerator = 1.0, denominator = 1.0;

    for(order = 1; order < limit; order++)
    {
        numerator *= q--;
        denominator *= order;

        y += deltas[order][0]*numerator/denominator;
    }

    return y;
}

void main()
{
    //NOTE: this program interpolates a polynomical of degree 4
    //Hence, only 5 points are taken
    //for a polynomial of degree 'n', 'n+1' points should be taken
    struct Point points[5];
    int limit = 5;
    double y, x = 15.0;
    double x1 = 0.0;
    double h = 0.1;
    double q = (x-x1)/h;
    int loop;

    for(loop = 0; loop < limit; loop++)
    {
        double temp = x1 + h*loop;
        points[loop].x = temp;
        // y = x^4
        points[loop].y = temp*temp*temp*temp;
    }

    CalculateDeltas(points, limit);
    y = Interpolate(q, limit);

    //verify if y == x^4
    printf("\nThe caluclated value for x = %lf is...y = %lf\n", x, y);    
}


/*
EXERCISE:

re-write this interpolation code, using a dynamic limit, 
based on the no. of points. 

Right now, the deltas is a two dimensional array with size n x n

Replace it with a single dimensional memory of size n(n-1)/2

hint: 
0 - (n-2) repersents the order 1
(n-1) - (2n-4) represents the order 2
(2n-3) - (3n-7) represents the order 3
and so on

eg. for 5 points
0 - 3 stands for order 1
4 - 6 stands for order 2
7 - 8 stands for order 3
9 - 9 stands for order 4
*/
