#include<cmath>
#include<stdexcept>

#include<Exercise_1/InverseNormCDF.h>

double Exercise_1::InverseNormalCDF(const double u)
{
	if (u < 0 || u > 1)
	{
		throw std::invalid_argument("Please be sure 0 < u < 1");
	}

	static const double a[] = {
        2.50662823884, 
        -18.61500062529, 
		41.39119773534, 
        -25.44106049637
    };
	
	static const double b[] = {
        -8.47351093090,
        23.08336743743, 
		-21.06224101826,
        3.13082909833
    };
	
	static double c[] = {
        0.3374754822726147, 
        0.9761690190917186,
		0.1607979714918209, 
        0.0276438810333863,
		0.0038405729373609, 
        0.0003951896511919,
		0.0000321767881768, 
        0.0000002888167364,
		0.0000003960315187
    };

	double x;
	double r, y = u - 0.5;

	if (std::abs(y) < 0.42)
	{
		r = y * y;
		x = y * (((a[3] * r + a[2]) * r + a[1]) * r + a[0]) / 
			((((b[3] * r + b[2]) * r + b[1]) * r + b[0]) * r + 1);
	}
	else
	{
		r = u;
		if (y > 0) 
		{
			r = 1 - u;
		}

		r = std::log(-std::log(r));
		x = c[0] + r * (c[1] + r * (c[2] + r * (c[3] + r * ( c[4] 
			+ r * (c[5] + r * (c[6] + r * (c[7] + r * c[8])))))));
		
		if (y < 0) 
		{
			x = -x;
		}
	}
	return x;
}