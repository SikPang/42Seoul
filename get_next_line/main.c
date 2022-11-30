#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("hello.txt", O_RDONLY);

	printf("%d\n", fd);
	printf("return : %p\n", get_next_line(fd));
	printf("return : %p\n", get_next_line(fd));
}