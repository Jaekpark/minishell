#include "../includes/pipe.h"

void	print_error(char *str)
{
	perror(str);
	exit(1);
}
