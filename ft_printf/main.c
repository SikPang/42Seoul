#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	int len1 = 0;
	int len2 = 0;
	
	// char
	char q = 'a';
	char w = 'b';
	// str
	char *test1 = "babo";
	char *test2 = "mae rong";
	len1 += printf	 ("p_c:%c, %c, %s, %s\n", q, w, test1, test2);
	len2 += ft_printf("my :%c, %c, %s, %s\n", q, w, test1, test2);
	printf("\n");

	// address
	char p = 'a';
	int pi = 35;
	char *pp = NULL;
	printf	 ("p_p:%p, %p, %p, %p, %p, %p\n", &p, &pi, pp, INT_MAX, INT_MIN, 0);
	ft_printf("my :%p, %p, %p, %p, %p, %p\n", &p, &pi, pp, INT_MAX, INT_MIN, 0);
	printf("\n");

	// decimal
	int min = INT_MIN;
	int max = INT_MAX;
	len1 += printf	 ("p_d:%d, %d, %d\n", min-1, max+1, 0);
	len2 += ft_printf("my :%d, %d, %d\n", min-1, max+1, 0);
	printf("\n");

	// integer
	len1 += printf	 ("p_d:%i, %i, %i\n", min-1, max+1, 0);
	len2 += ft_printf("my :%i, %i, %i\n", min-1, max+1, 0);
	printf("\n");

	// unsigned int
	len1 += printf	 ("p_u:%u == %u\n", min, -1-max);
	len2 += ft_printf("my :%u == %u\n", min, -1-max);
	printf("\n");

	// hex lower
	len1 += printf	 ("p_x:%x, %x, %x\n", 12345, LONG_MAX, -1);
	len2 += ft_printf("my :%x, %x, %x\n", 12345, LONG_MAX, -1);
	printf("\n");

	// hex upper
	len1 += printf	 ("p_X:%X, %X, %X\n", max, LONG_MIN, -max);
	len2 += ft_printf("my :%X, %X, %X\n", max, LONG_MIN, -max);
	printf("\n");

	// percent
	len1 += printf	 ("p_%% : %%\n");
	len2 += ft_printf("my_%%: %%\n");
	printf("\n");

	// others
	len1 += printf	 ("p_other : %z\n");
	len2 += ft_printf("my_other: %z\n");
	len1 += printf	 ("p_other : %h\n");
	len2 += ft_printf("my_other: %h\n");
	len1 += printf	 ("p_other : %0\n");
	len2 += ft_printf("my_other: %0\n");
	printf("\n");

	// return value
	printf ("p_len :%d\n", len1);
	printf ("my_len:%d\n", len2);
}