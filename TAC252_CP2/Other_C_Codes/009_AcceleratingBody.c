/*
This program is to find the distance travelled by an object

with some initial velocity and constant acceleration.

The position of the object at each interval of time is 

computed for the required no. of times.

EQUATION: distance = ut + (at^2)/2
*/
# include <stdio.h>

void main()
{
	double u, t, a;
	double distance;
	double limit, time;

	printf("Enter time slice and the time limit..");
	scanf("%lf%lf", &t, &limit);

	printf("Enter the values of u and a...");
	scanf("%lf%lf", &u, &a);

	for(time = 0.0f; time <= limit; time += t)
	{
		distance = u*time + 0.5*a*time*time;
		printf("At time = %lf, the distance travelled = %lf\n", time, distance);		
	}
}