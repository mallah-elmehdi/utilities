#include <stdio.h>

int main()
{
	float a;
	float out;

	out = 0;
	scanf("%f", &a);
	while (a)
	{
		out += (1 / a);
		a--;
	}
	printf("%.10f", out);
}
