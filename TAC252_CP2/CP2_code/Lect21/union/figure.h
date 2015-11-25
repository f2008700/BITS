/*file name: figure */

typedef struct
{
	double radius, area, circumference;
}circle_t;

typedef struct
{
	double length, width, area, perimeter;
}rectangle_t;

typedef struct
{
	double side, area, perimeter;
}square_t;

typedef union
{
	circle_t cir;
	rectangle_t rect;
	square_t sq;
}figure_data_t;


typedef struct
{
	int shape;
	figure_data_t fig;
}figure_t;

