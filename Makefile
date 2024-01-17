NAME=minishell

CC=cc

CFLAGS=-Werror -Wall -Wextra -g

SRCS=	bi_exec_builtins.c\
		check_malloc_err.c\
		check_path.c\
		dup.c\
		exec_builtins.c\
		exec_simple.c\
		free_pipe.c\
		free_strs.c\
		ft_atoi.c\
		ft_cd_err.c\
		ft_clean.c\
		ft_clonenvp.c\
		ft_createword.c\
		ft_export_err.c\
		ft_get_cwd.c\
		ft_get_paths.c\
		ft_green_cd.c\
		ft_green_echo.c\
		ft_green_env.c\
		ft_green_exit.c\
		ft_green_export.c\
		ft_green_pwd.c\
		ft_green_unset.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_pipe_err.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strchr.c\
		ft_strcmp.c\
		ft_strdup.c\
		ft_strlen.c\
		ft_strncmp.c\
		ft_substr.c\
		ft_unset_err.c\
		get_builtin_type.c\
		heredoc.c\
		main.c\
		parse_get_arg.c\
		parse_get_in.c\
		parse_get_out.c\
		parse_pipecommand.c\
		parse_utils.c\
		pipe.c\
		split_by.c\
		split_by_utils.c\
		strjoin.c\
		ft_strjoin.c\
		ft_countwords.c\
		ft_execve_err.c\
		ft_unplug_pipes.c\
		simple_builtin.c\
		free_minidat.c\
		ft_prep_cwd.c\
		ft_clonenvp_err.c\
		ft_set_exit.c\
		check_command_new.c\
		ft_itoa.c\
		ft_get_slash.c\
		ft_prep_cd.c\
		ft_frexport_err.c\
		ft_is_nn.c\
		ft_get_home.c\
		ft_init_minidat.c\
		parse_in.c\
		parse_new.c\
		parse_out.c\
		create_pipes.c\
		expand_envs.c\
		init_ex_d.c\
		init_p.c\
		init_strs.c\
		jump_to_next.c\
		replace_env_new.c\
		split_command.c\
		utils.c\
		check_path_utils.c\

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -o $(NAME) -lreadline

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
