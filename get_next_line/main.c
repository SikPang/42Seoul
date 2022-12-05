#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void print_line(int fd)
{
	char *str = get_next_line(fd);
	printf("return : %s\n-------- \n", str);
	free(str);
}

int main()
{
	int fd = open("t_hello.txt", O_RDONLY);
	printf("fd = %d\n", fd);

	print_line(5);
	// print_line(fd);
	// print_line(fd);
	// print_line(fd);
	// print_line(fd);

	// print_line(fd);
	// print_line(fd);
	// print_line(fd);
	// print_line(fd);
	// print_line(fd);
}