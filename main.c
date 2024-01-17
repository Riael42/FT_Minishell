/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwilke <dwilke@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:34:09 by dwilke            #+#    #+#             */
/*   Updated: 2024/01/11 15:24:32 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"
#include <sys/ioctl.h>
#include <termios.h>

void	ft_temp_clean(char *str, t_minidat *minidat, \
						t_pipecommand **pipe, struct termios *original_termios);
void	main_core(char *str, t_pipecommand **pipe, t_minidat *minidat);

void	sig_handler(int signum)
{
	if (signum == SIGINT)
	{
		printf("^C\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	sig_handler2(int signum)
{
	signum++;
	printf("\n");
}

int	main(int argc, char **argv, char **envp)
{
	t_pipecommand	*pipe;
	t_minidat		minidat;
	char			*str;
	struct termios	original_termios;

	normibuster(argc, argv);
	ft_init_minidat(&minidat, envp);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	rl_catch_signals = 0;
	tcgetattr(STDIN_FILENO, &original_termios);
	while (minidat.exit == 0)
	{
		pipe = NULL;
		str = readline("minishell>");
		if (str == NULL)
			free_pipe(pipe, &minidat);
		if (str == NULL)
			break ;
		main_core(str, &pipe, &minidat);
		ft_temp_clean(str, &minidat, &pipe, &original_termios);
	}
	free_minidat(&minidat);
	rl_clear_history();
	return (minidat.last_exit);
}

void	ft_temp_clean(char *str, t_minidat *minidat, \
						t_pipecommand **pipe, struct termios *original_termios)
{
	signal(SIGINT, sig_handler);
	free(str);
	free_pipe(*pipe, minidat);
	tcsetattr(STDIN_FILENO, TCSANOW, original_termios);
}

void	main_core(char *str, t_pipecommand **pipe, t_minidat *minidat)
{
	add_history(str);
	signal(SIGINT, sig_handler2);
	if (check_command_new(str, pipe, minidat))
	{
		ft_unplug_pipes(minidat, pipe);
		if (minidat->err == 0 && minidat->cmdnum > 1 && minidat->cmdnum < 100)
			start_exec(minidat, *pipe);
		if (minidat->cmdnum == 1)
		{
			if ((*pipe)->type == 0)
				exec_simple(minidat, *pipe);
			if ((*pipe)->type != 0 && (*pipe)->type != -3)
				simple_builtin(minidat, *pipe);
		}
	}
}
