#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	int fd = open("out.txt", O_RDONLY);
	int fp = open("c_medium.in", O_RDONLY);
	char *h = malloc(1);
	char *g = malloc(1);
	int out;
	while (read(fd, h, 1) && *h != '\n')
		out = 0;
	while (read(fp, g, 1) && *g != '\n')
		out = 0;
	int o;
	int i = 0;
	int space = 0;
	while (read(fd, h, 1))
	{
		int l = 0;
		if (*h != ' ' && *h != '\n')
			i = (i * 10) + (*h - 48);
		else
		{
			o = 0;
			while (l == 0 && read(fp, g, 1))
			{
				while (i == space && *g != '\n' && *g != ' ')
				{
					o = (o * 10) + (*g - 48);
					read(fp, g, 1);
				}
				if (i == space)
				{
					out += o;
					l = 1;
					i = 0;
				}
				if (*g == ' ')
					space++;
			}
		}
	}
	printf("%d", out);
}
