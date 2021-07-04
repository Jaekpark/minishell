#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libs/includes/libft.h"
# include <curses.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <term.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>
# include <wchar.h>

# define TRUE 1
# define FALSE 0
# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define QUOTE 81
# define D_QUOTE 68

# define PIPE "|"
# define O_REDIR ">"
# define I_REDIR "<"
# define A_REDIR ">>"
# define HEREDOC "<<"

# define PROMPT "\033[1;32mBraveShell\033[0;31m$\033[0m "
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\03[0;36m"
# define WHITE "\033[0;37m"
# define RESET "\033[0m"

typedef struct		s_lexer
{
	char *lex;
	int s_quote;
	int	e_quote;
	int is_quote;
	int	err;
}	t_lexer;

typedef struct		s_flag
{
	int				begin;
	int				st;
	int				ed;
	int				quote;
	int				d_quote;
}					t_flag;

typedef struct		s_div
{
	int				st;
	int				ed;
	struct s_div	*next;
	struct s_div	*prev;
}					t_div;

typedef struct		s_token
{
	char			*token;
	char			type;
	int				i;
	struct s_token	*next;
	struct s_token	*prev;
} t_token;

typedef struct		s_redir
{
	char type;
	char *target;
	char *arg;
} t_redir;

typedef struct		s_hdoc
{
	char *delimiter;
	char *arg;
} t_hdoc;

typedef struct		s_syntax
{
	char *cmd;
	char **arg;
	t_redir *redir;
	t_hdoc	*hdoc;
} t_syntax;

typedef struct		s_pipe
{
	t_syntax		*syntax;
	struct s_pipe	*next;
	struct s_pipe	*prev;
}					t_pipe;

typedef struct		s_lst
{
	void			*head;
	void			*tail;
}					t_lst;

typedef struct		s_conf
{
	char			**env;
	char			*cmd;
	t_lexer			*lexer;
	t_lst			*token;
	t_lst			*syntax;
	struct termios	term;
}					t_conf;

void				print_error(char *msg);
void				make_div(t_lst *lst, int st, int ed);
void				make_token(t_lst *lst, int st, int ed);
char				*ft_strrdup(char *s, int st, int ed);
int					ft_isspace(int c);
int					ft_isquote(char c);
void				init_flag(t_flag *flag);
void				init_lst(t_lst *lst);
void				init_lexer(t_lexer *lexer);
void				free_lexer(t_lexer *lexer);
int					ft_isspec(char *cmd, int i);
#endif
