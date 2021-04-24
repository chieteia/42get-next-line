#include <stdio.h>
#include <stdlib.h>

int	wrap_malloc(void *p, size_t len)
{
	*(void **)p = malloc(len);
	return (!!*(void **)p);
}

int	wrap_malloc(void *p, size_t len)
{
	printf("before malloc : %p\n", p);
	p = malloc(len);
	printf("after malloc : %p\n", p);
	return (!!p);
}

int	main(void)
{
	char	*str;
	printf("original : %p\n", str);
	printf("original : %p\n", &str);
	int		res;

	res = 0;
	res = wrap_malloc(str, sizeof(char) * 10 + 1);
	if (res)
		printf("malloc suceeded\n");
	else
		printf("malloc failed\n");
	for (int i = 0; i < 10; i++)
	{
		str[i] = 'a' + i;
		str[i + 1] = '\0';
	};
	while (*str)
	{
		printf("%c\n", *str);
		printf("%p\n", str);
		str++;
	};
	//free(str);
	return (0);
}
