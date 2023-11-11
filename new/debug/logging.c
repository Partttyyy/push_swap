#include "../push_swap.h"

#include <stdio.h>

void	log_error(char *type, char *msg)
{
	FILE	*fd;
	char	*temp = ft_strjoin("./debug/logs/", type);
	char	*path = ft_strjoin(temp, ".txt");
	free(temp);
	fd = fopen(path, "a");
	if (!fd)
	{
		printf("could not open error log\n");
		return ;
	}

	fprintf(fd, "%s\n", msg);
	free(path);
	fclose(fd);
}
