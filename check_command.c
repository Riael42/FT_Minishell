/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwilke <dwilke@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:44:20 by dwilke            #+#    #+#             */
/*   Updated: 2023/12/21 15:13:28 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	jump_spaces(char *cmd, int *i)
{
	while (cmd[*i] && cmd[*i] == ' ')
		(*i)++;
}

char	*replace_env(char *s, t_pipecommand **pipe)
{
	int		i;
	int		start;
	char	*ret;

	i = 0;
	start = 0;
	ret = NULL;
	while (s[i])
	{
		if (s[i] == '\'')
		{
			i++;
			while (s[i] && s[i] != '\'')
				i++;
			if (s[i])
				i++;
		}
		else if (s[i] == '$')
		{
			ret = strjoin_se(ret, s, start, i);
			if (ret == NULL)
				(*pipe)->malloc_err = 1;
			i++;
			start = i;
			while (s[i] && s[i] != ' ' && s[i] != '"' && s[i] != '\'' && 
				s[i] != '<' && s[i] != '>')
				(i)++;
			ret = strjoin_env(ret, s, start, i);
			if (ret == NULL)
				(*pipe)->malloc_err = 1;
			start = i;
		}
		else
			i++;
	}
	if (i != start)
	{
		ret = strjoin_se(ret, s, start, i);
		if (ret == NULL)
			(*pipe)->malloc_err = 1;
	}
	return (ret);
}

void	set_count(t_minidat **dat, t_pipecommand **pipe)
{
	t_pipecommand	*tmp;
	int				i;

	tmp = *pipe;
	i = 0;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp-> next;
	}
	(*dat)->cmdnum = i;
}

void	init_pipecommand(t_pipecommand **pipe)
{
	(*pipe)->next = NULL;
	(*pipe)->in_op = NULL;
	(*pipe)->command = NULL;
	(*pipe)->args = NULL;
	(*pipe)->malloc_err = 0;
	(*pipe)->type = 0;
}

int	check_command(char *cmd, t_pipecommand **pipe, t_minidat *dat)
{
	char			*s;
	t_strs			*strs;
	t_pipecommand	*tmp;
	int				i;
	t_strs			*head;

	//s = replace_env(cmd, pipe, dat);
	if (s == NULL)
		return (0);
	strs = split_by(s, '|', pipe);
	head = strs;
	tmp = *pipe;
	init_pipecommand(&tmp);
	i = 0;
	while (strs != NULL)
	{
		tmp->pipe_id = i++;
		tmp->out_dir = -42;
		tmp->in_dir = -42;
		if (ft_strcmp(strs->s, "") != 0)
			parse_pipecommand(strs->s, &tmp, dat);
		if (tmp->in_op != NULL)
		{
			tmp->in_dir = open("tmp", O_CREAT | O_RDWR, 0000600);
			do_heredoc(dat, tmp->in_dir, tmp->in_op);
			close(tmp->in_dir);
			tmp->in_dir = open("tmp", O_CREAT | O_RDWR, 0000600);
		}
		strs = strs->next;
		if (strs != NULL)
		{
			tmp->next = malloc(sizeof(t_pipecommand));
			if (tmp->next == NULL)
				tmp->malloc_err = 1;
			tmp = tmp->next;
			init_pipecommand(&tmp);
		}
	}
	free_strs(head);
	free(s);
	check_malloc_err(pipe, dat);
	set_count(&dat, pipe);
	dat->first = *pipe;
	return (1);
}

// int	main(int argc, char **argv, char **envp)
// {
// 	t_pipecommand	*pipe;
// 	t_pipecommand	*tmp;

// 	pipe = malloc(sizeof(t_pipecommand));
// 	if (check_command("git bla || echo ex", &pipe) == 0)
// 	{
// 		free(pipe);
// 		return (1);
// 	}
// 	int i;
// 	tmp = pipe;
// 	while (pipe != NULL)
// 	{
// 		printf("pipeid: %d\n", pipe->pipe_id);
// 		printf("command: %s\n", pipe->command);
// 		i = 0;
// 		while (pipe->args && pipe->args[i] != NULL)
// 			printf("arg: %s\n", pipe->args[i++]);
// 		printf("indir: %d\n", pipe->in_dir);
// 		printf("outdir: %d\n", pipe->out_dir);
// 		printf("inop: %s\n", pipe->in_op);
// 		printf("type: %d\n", pipe->type);
// 		pipe = pipe->next;
// 	}
// 	free_pipe(tmp);
// }
