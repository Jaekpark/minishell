#include "../../includes/minishell.h"

int		ft_isspec(char *cmd, int i)
{
	int	last;

	last = 0;
	if (cmd[i + 1] == '\0')
		last = 1;
	if (cmd[i] == '|')
		return (1);
	else if (last != 1 && (ft_strncmp(&cmd[i], "<<", 2)) == 0)
		return (2);
	else if (last != 1 && (ft_strncmp(&cmd[i], ">>", 2)) == 0)
		return (3);
	else if (cmd[i] == '<')
		return (4);
	else if (cmd[i] == '>')
		return (5);
	return (0);
}

char	*ft_strrdup(char *s, int st, int ed)
{
	int		i;
	char	*ret;
	int		dst_len;
	int		src_len;

	i = 0;
	dst_len = ed - st + 1;
	src_len = ft_strlen(s);
	if (!s || dst_len > src_len)
		return (NULL);
	ret = malloc(sizeof(char) * dst_len + 1);
	while (st <= ed)
	{
		ret[i] = s[st];
		i++;
		st++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin_sp(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;

	i = -1;
	j = -1;
	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1) || !(s2))
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(newstr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 2))))
		return (NULL);
	while (s1[++i])
		newstr[i] = s1[i];
	newstr[i++] = ' ';
	while (s2[++j])
		newstr[i++] = s2[j];
	newstr[i] = '\0';
	free(s1);
	return (newstr);
}

int		ft_isspace(int c)
{
	if ((char)c == ' ')
		return (1);
	else if ((char)c == '\t')
		return (2);
	else if ((char)c == '\v')
		return (3);
	else if ((char)c == '\n')
		return (4);
	else if ((char)c == '\f')
		return (5);
	else if ((char)c == '\r')
		return (6);
	return (0);
}

int		ft_isquote(char c)
{
	/*(" = 34)*/
	/*(' = 39)*/
	/*(D68 = ")*/
	/*(Q81 = ')*/
	if (c == 34)
		return (68);
	else if (c == 39)
		return (81);
	return (0);
}

char	**ft_split_env(char *env)
{
	char	**ret;
	int		i;

	i = -1;
	if (!env)
		return (NULL);
	ret = malloc(sizeof(char *) * 3);
	while (env[++i])
	{
		if (env[i] == '=' && env[i + 1] != '\0')
		{
			ret[0] = ft_strrdup(env, 0, i - 1);
			ret[1] = ft_strrdup(env, i + 1, ft_strlen(env) - 1);
			ret[2] = NULL;
			break ;
		}
		else if (env[i] == '=' && env[i + 1] == '\0')
		{
			ret[0] = ft_strrdup(env, 0, i - 1);
			ret[1] = NULL;
			ret[2] = NULL;
			break ;
		}
	}
	return (ret);
}
