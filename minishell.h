/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwilke <dwilke@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:35:24 by dwilke            #+#    #+#             */
/*   Updated: 2024/01/08 19:37:44 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>

typedef struct s_pipecommand
{
	int						pipe_id;
	char					*command;
	char					**args;
	int						in_dir;
	char					*in_dir_name;
	int						out_dir;
	char					*in_op;
	int						type;
	int						malloc_err;
	struct s_pipecommand	*next;
}	t_pipecommand;

typedef struct s_minidat
{
	t_pipecommand	*first;
	char			**paths;
	pid_t			forklosophers[100]; 
	int				iter;
	int				cmdnum;
	int				last_exit;
	char			**envp;
	char			**newvp;
	char			*cwd; 
	char			*owd;
	char			*curhome;
	char			**envpclone;
	int				err;
	int				exit;
	int				envlines;
}				t_minidat;

typedef struct s_strs
{
	char			*s;
	struct s_strs	*next;
}	t_strs;

typedef struct s_ex_data
{
	int						i;
	int						start;
	char					*line;
	char					*new_line;
	struct s_minidat		*data;
	struct s_pipecommand	*pipe;
}	t_ex_data;

int				check_command(char *cmd, t_pipecommand **pipe, t_minidat *dat);
void			jump_spaces(char *cmd, int *i);
t_strs			*split_by(char *s, char c, t_pipecommand **pipe);
void			parse_pipecommand(char *s, t_pipecommand **pipe, 
					t_minidat *dat);
void			get_out(char *s, int *i, t_pipecommand **pipe);
char			*get_name(char *s, int start, int end, t_pipecommand **pipe);
void			set_start_end(char *s, int *i, int *start, int *end);
void			get_in(char *s, int *i, t_pipecommand **pipe);
void			get_arg(char *s, int *i, t_strs **args, t_pipecommand **pipe);
char			*strjoin_se(char *s1, char *s2, int start, int end);
char			*strjoin_env(char *s1, char *s2, int start, int end);
int				ft_strlen(char *s);
void			free_strs(t_strs *strs);
void			free_pipe(t_pipecommand *pipe, t_minidat *minidat);
void			free_strs_conv(t_strs *strs);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_fd(char *s, int fd);
void			check_malloc_err(t_pipecommand **pipe, t_minidat *dat);
char			**convert(t_strs *args, t_pipecommand **pipe);
t_strs			*init_vars(int *i, int *start, t_strs **strs,
					t_pipecommand **pipe);
void			ft_putstr_fd(char *s, int fd);
int				ft_green_env(t_minidat *minidat);
int				ft_strlen(char *s);
char			*ft_strdup(char *s);
void			ft_putchar_fd(char c, int fd);
char			*ft_strchr(char *s, int num);
int				ft_export_err(t_minidat *minidat);
int				ft_isdigit(int c);
int				ft_green_export(t_minidat *minidat, t_pipecommand *pipecmd);
int				ft_init(t_minidat *minidat, char **envp);
int				ft_green_unset(t_minidat *minidat, t_pipecommand *pcmd);
int				ft_strncmp(char *s1, char *s2, int n);
int				ft_unset_error(t_minidat *minidat);
void			start_exec(t_minidat *minidat, t_pipecommand *utor);
void			exec_utor(t_minidat *minidat, int *oldpipe, \
							t_pipecommand *utor);
void			utor_child(t_minidat *minidat, int *oldpipe, \
							t_pipecommand *utor, int *pipes);
int				dup_stdout(t_minidat *minidat, int *pipes, \
							t_pipecommand *utor);
int				dup_stdin(int *oldpipe, t_pipecommand *utor);
void			ft_dup_err(t_minidat *minidat);
void			ft_pipe_err(t_minidat *minidat);
void			ft_fork_err(t_minidat *minidat);
int				ft_strlen(char *s);
int				ft_strcmp(char *s1, char *s2);
int				ft_heredoc_fork_err(t_minidat *minidat);
int				do_heredoc(t_minidat *minidat, int fd, char *eof);
int				ft_unset_noargs(t_minidat *minidat);
char			*ft_substr(char *s, int start, int len);
int				ft_strncmp(char *s1, char *s2, int n);
char			**ft_split(char *s, char c);
int				ft_isalpha(char *s);
int				ft_green_pwd(t_minidat *minidat);
int				ft_green_exit(t_minidat *minidat, t_pipecommand *spcmd);
int				ft_green_cd(t_minidat *minidat, t_pipecommand *incmd);
char			**ft_get_paths(t_minidat *minidat);
char			*ft_get_cwd(t_minidat *minidat);
int				ft_export_err(t_minidat *minidat);
char			*ft_createword(char *str, char c, int curword);
char			**ft_clonenvp(t_minidat *minidat, char **envp);
int				ft_cd_err(t_minidat *minidat, t_pipecommand *cmd);
int				ft_atoi(char *str);
void			free_strs(t_strs *strs);
void			free_strs_conv(t_strs *strs);
void			free_pipe(t_pipecommand *pipe, t_minidat *minidat);
void			exec_builtins(t_minidat *minidat, int *oldpipe, \
								t_pipecommand *utor);
void			check_path(t_pipecommand **pipe, t_minidat *dat);
void			check_malloc_err(t_pipecommand **pipe, t_minidat *minidat);
int				ft_green_echo(int nl, t_minidat *minidat, t_pipecommand *cmd);
int				bi_exec_builtin(t_minidat *minidat, t_pipecommand *cmd);
int				get_builtin_type(t_pipecommand *cmd);
void			ft_alpha_part(t_minidat *minidat);
void			simple_child(t_minidat *minidat, t_pipecommand *cmd);
void			ft_execve_err(t_minidat *minidat);
char			*ft_strjoin(char *s1, char *s2);
void			ft_malloc_err(t_minidat *minidat);
void			ft_putstr(char *s);
int				ft_countwords(char *str, char c);
void			exec_simple(t_minidat *minidat, t_pipecommand *cmd);
void			ft_unplug_pipes(t_minidat *minidat, t_pipecommand **incmd);
int				ft_malloc_err_int(t_minidat *minidat);
void			simple_builtin(t_minidat *minidat, t_pipecommand *cmd);
void			init_pipecommand(t_pipecommand **pipe);
void			free_minidat(t_minidat *minidat);
char			*ft_prep_cwd(t_minidat *minidat, char *str);
char			**ft_clonenvp_err(t_minidat *minidat);
void			ft_set_exit(t_minidat *minidat, int status,
					t_pipecommand *utor);
int				check_command_new(char *line, t_pipecommand **pipe,
					t_minidat *data);
char			*ft_itoa(int n);
void			set_type(t_pipecommand **pipe);
void			set_count(t_minidat **dat, t_pipecommand **pipe);
char			*ft_get_home(t_minidat *minidat);
char			**ft_get_slash(t_minidat *minidat);
char			**ft_prep_cd(t_minidat *minidat, t_pipecommand *incmd);
int				ft_frexport_err(t_minidat *minidat);
int				ft_is_nn(char *str);
void			ft_init_minidat(t_minidat *minidat, char **envp);
char			*ft_get_home(t_minidat *minidat);
t_strs			*init_strs(void);
void			parse_commands(t_pipecommand *pipe, t_strs *splits,
					t_minidat *dat);
void			parse_in_file(char *s, t_pipecommand *pipe);
void			parse_in_heredoc(char *s, t_pipecommand *pipe, t_minidat *dat);
t_strs			*parse_out(t_strs *splits, t_pipecommand *pipe);
t_strs			*parse_in(t_strs *splits, t_pipecommand *pipe, t_minidat *dat);
void			parse_out_new(char *s, t_pipecommand *pipe);
void			parse_out_append(char *s, t_pipecommand *pipe);
int				create_pipes(t_pipecommand **pipe, t_minidat *data,
					t_strs *strs);
char			*expand_envs(char *line, t_minidat *data, t_pipecommand **pipe);
void			init_ex_d(t_ex_data *ex_d, char *line, t_minidat *data,
					t_pipecommand **pipe);
t_pipecommand	*init_p(void);
t_strs			*init_strs(void);
void			jump_to_next(t_ex_data *ex_d, char c);
void			replace_env_new(t_ex_data *ex_d);
t_strs			*split_command(t_pipecommand **pipe, char *s, t_strs *strs);
int				ft_is_onechar(char c);
void			normibuster(int argc, char **argv);
char			*get_value(char *name, t_minidat *dat);
char			**get_paths(t_minidat *dat, t_pipecommand **pipe);
void			free_arr(char **arr);

#endif
