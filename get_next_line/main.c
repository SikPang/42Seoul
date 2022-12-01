#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("t_hello.txt", O_RDONLY);

	printf("%d\n", fd);
	printf("return : %s\n", get_next_line(fd));
	printf("return : %s\n", get_next_line(fd));
}