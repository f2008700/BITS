/* File Name: sqrt.c
 * implementation of sqrt function is available here
*/
float sqrt1(int m)
{
	
	float R,err;
	if(m>0)
	{
		R=(float)m/2;
		err=(R*R-m)/m;
		while(err>0.0001)
		{
			R=(R+m/R)/2;
			err=(R*R-m)/m;
		}
			return R;
	}
	else
		return (float)-1;
}
