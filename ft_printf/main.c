#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	// ft_printf("%X\n", LONG_MAX);
	// printf("%X\n", LONG_MAX);

	int len1 = 0;
	int len2 = 0;
	
	//char
	char q = 'a';
	char w = 'b';
	//str
	char *test1 = "babo";
	char *test2 = "mae rong";
	len1 += printf	 ("p_c:%c, %c, %s, %s\n", q, w,test1, test2);
	len2 += ft_printf("my :%c, %c, %s, %s\n", q, w, test1, test2);
	printf("\n");

	//memory address
	char p = 'a';
	int pi = 35;
	char *pp = NULL;
	len1 += printf	 ("p_p:%p, %p, %p\n", &p, &pi, pp);
	len2 += ft_printf("my :%p, %p, %p\n", &p, &pi, pp);
	printf("\n");

	// digit
	int min = INT_MIN;
	int max = INT_MAX;
	len1 += printf	 ("p_d:%d, %d, %d\n", min-1, max+1, 0);
	len2 += ft_printf("my :%d, %d, %d\n", min-1, max+1, 0);
	printf("\n");

	// unsigned dec
	len1 += printf	 ("p_u:%u == %u\n", min, -1-max);
	len2 += ft_printf("my :%u == %u\n", min, -1-max);
	printf("\n");

	// unsigned hex
	len1 += printf	 ("p_x:%x, %x, %x\n", 12345, LONG_MAX, -1);
	len2 += ft_printf("my :%x, %x, %x\n", 12345, LONG_MAX, -1);
	printf("\n");

	// unsigned hex upper
	len1 += printf	 ("p_X:%X, %X, %X\n", max, LONG_MIN, -max);
	len2 += ft_printf("my :%X, %X, %X\n", max, LONG_MIN, -max);
	printf("\n");

	// // edgecase
	// len1 += printf	 ("p_error :%d%,% %s%%\n", min-1, test1);
	// len2 += ft_printf("my_error:%d%,% %s%%\n", min-1, test1);
	// len1 += printf	 ("p_error :%d\n", min-1);
	// len2 += ft_printf("my_error:%d\n", min-1);
	// len1 += printf("p_error :%$%\(*%d\n");
	// len2 += printf("my_error:%$%\(*%d\n");
	// printf("\n");

	// return value
	printf ("p_len :%d\n", len1);
	printf ("my_len:%d\n", len2);
}