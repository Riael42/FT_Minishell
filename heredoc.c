/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:37:55 by riael             #+#    #+#             */
/*   Updated: 2024/01/09 20:58:43 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"
#include <sys/ioctl.h>

int		ft_heredoc_fork_err(t_minidat *minidat);
void	ft_heredoc_write(char *str, char *eof, int fd);
void	ft_heredoc_parent(pid_t forkid, int status, t_minidat *minidat);

void	sig_handlers(int signum)
{
	signum++;
	exit(130);
}

int	do_heredoc(t_minidat *minidat, int fd, char *eof)
{
	char	*str;
	pid_t	forkid;
	int		status;

	str = NULL;
	status = 0;
	forkid = fork();
	if (forkid < 0)
		return (ft_heredoc_fork_err(minidat));
	if (forkid == 0)
	{
		signal(SIGINT, sig_handlers);
		while (ft_strncmp(str, eof, ft_strlen(eof)) != 0)
		{
			if (str != (void *)0)
				free(str);
			str = readline("heredoc:");
			ft_heredoc_write(str, eof, fd);
		}
		free(str);
		exit (0);
	}
	else
		ft_heredoc_parent(forkid, status, minidat);
	return (minidat->last_exit);
}

void	ft_heredoc_parent(pid_t forkid, int status, t_minidat *minidat)
{
	waitpid(forkid, &status, 0);
	WIFEXITED(status);
	minidat->last_exit = WEXITSTATUS(status);
	write(1, "\n", 1);
	rl_redisplay();
}

void	ft_heredoc_write(char *str, char *eof, int fd)
{
	if (ft_strncmp(str, eof, ft_strlen(eof)) != 0)
	{
		write(fd, str, strlen(str));
		write(fd, "\n", 1);
	}
}

int	ft_heredoc_fork_err(t_minidat *minidat)
{
	write(2, "Error while forking\n", 20);
	minidat->last_exit = -42;
	minidat->err = 1;
	return (-42);
}
