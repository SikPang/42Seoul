#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd = open("t_empty.txt", O_RDONLY);

	printf("%d\n", fd);
	printf("return : %s\n", get_next_line(fd));
	printf("return : %s\n", get_next_line(fd));
	printf("return : %s\n", get_next_line(fd));
	printf("return : %s\n", get_next_line(fd));
	printf("return : %s\n", get_next_line(fd));
	printf("return : %s\n", get_next_line(fd));
	printf("return : %s\n", get_next_line(fd));

	printf("return : %s\n", get_next_line(fd));
	printf("return : %s\n", get_next_line(fd));
	printf("return : %s\n", get_next_line(fd));
}