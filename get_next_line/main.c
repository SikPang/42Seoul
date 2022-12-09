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
	int fd = open("t_edge.txt", O_RDONLY);
	printf("fd = %d\n", fd);

	print_line(fd);
	print_line(fd);
	print_line(fd);
	print_line(fd);
	print_line(fd);

	print_line(fd);
	print_line(fd);
	print_line(fd);
	print_line(fd);
	print_line(fd);

	print_line(fd);
}

// int main()
// {
// 	int fd1 = open("t_oneline.txt", O_RDONLY);
// 	int fd2 = open("t_hello.txt", O_RDONLY);
// 	int fd3 = open("t_edge.txt", O_RDONLY);

// 	print_line(fd1);
// 	print_line(fd2);
// 	print_line(fd3);

// 	print_line(fd1);
// 	print_line(fd2);
// 	print_line(fd3);

// 	print_line(fd1);
// 	print_line(fd2);
// 	print_line(fd3);
// }