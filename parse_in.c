/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwilke <dwilke@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:28:27 by dwilke            #+#    #+#             */
/*   Updated: 2024/01/08 20:28:30 by dwilke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

t_strs	*parse_in(t_strs *splits, t_pipecommand *pipe, t_minidat *dat)
{
	if (splits->s[1] && splits->s[1] != '<')
		parse_in_file(&(splits->s[1]), pipe);
	else if (splits->next && splits->s[1] == 0)
	{
		parse_in_file(splits->next->s, pipe);
		return (splits->next);
	}
	else if (splits->s[1] && splits->s[1] == '<' && splits->s[2])
		parse_in_heredoc(&(splits->s[2]), pipe, dat);
	else if (splits->next == NULL)
	{
		pipe->in_dir = -5;
		return (splits->next);
	}
	else
	{
		parse_in_heredoc(splits->next->s, pipe, dat);
		return (splits->next);
	}
	return (splits);
}

void	parse_in_heredoc(char *s, t_pipecommand *pipe, t_minidat *dat)
{
	char	*end;
	char	*file;
	char	*num;
	int		in_fd;

	file = NULL;
	end = ft_strdup(s);
	num = ft_itoa(pipe->pipe_id);
	file = strjoin_se(file, "tmp_", 0, 4);
	file = strjoin_se(file, num, 0, ft_strlen(num));
	in_fd = open(file, O_CREAT | O_RDWR, 0000600);
	dat->last_exit = do_heredoc(dat, in_fd, end);
	free(end);
	close(in_fd);
	pipe->in_dir = open(file, O_CREAT | O_RDWR, 0000600);
	pipe->in_op = ft_strdup(file);
	free(file);
	free(num);
}

void	parse_in_file(char *s, t_pipecommand *pipe)
{
	char	*name;

	name = ft_strdup(s);
	if (pipe->in_dir > 0)
		close(pipe->in_dir);
	pipe->in_dir = open(name, O_RDONLY);
	pipe->in_dir_name = name;
}
