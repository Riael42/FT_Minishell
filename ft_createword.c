/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createword.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:39:09 by riael             #+#    #+#             */
/*   Updated: 2023/12/21 15:09:59 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	ft_skipword(char *str, char c, int i);
static int	ft_skipspace(char *str, char c, int i);

char	*ft_createword(char *str, char c, int curword)
{
	int		i;
	int		size;
	char	*word;

	i = ft_skipspace(str, c, 0);
	size = 0;
	while (curword > 0)
	{
		i = ft_skipword(str, c, i);
		i = ft_skipspace(str, c, i);
		curword -= 1;
	}
	while (str[i + size] != c && str[i + size] != '\0')
		size += 1;
	word = (char *)malloc(sizeof(char) * size + 1);
	if (word == ((void *)0))
		return ((void *)0);
	word[size] = '\0';
	size -= 1;
	while (size >= 0)
	{
		word[size] = str[i + size];
		size -= 1;
	}
	return (word);
}

static int	ft_skipword(char *str, char c, int i)
{
	while (str[i] != c)
		i += 1;
	return (i);
}

static int	ft_skipspace(char *str, char c, int i)
{
	while (str[i] == c)
		i += 1;
	return (i);
}
