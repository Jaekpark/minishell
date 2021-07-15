#include "../../includes/minishell.h"

void	run_pwd()
{
	char *cwd;

	cwd = getcwd(NULL, 0);
	printf("%s\n", cwd);
}
