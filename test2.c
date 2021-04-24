#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	char *line = NULL;
	int fd = open("aaa.txt", O_RDONLY);
	int res = 0;

	for (int i = 0; i < 10; i++)
	{
		res = get_next_line(fd, &line);
		printf("res : %d line : %s\n", res, line);
		free(line);
	}
	close(fd);
	return (0);
}