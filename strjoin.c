/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwilke <dwilke@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:21:22 by dwilke            #+#    #+#             */
/*   Updated: 2023/12/19 17:21:55 by dwilke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	*strjoin_env(char *s1, char *s2, int start, int end)
{
	char	*ret;
	int		i;
	int		j;
	char	*name;
	char	*replace;

	name = malloc(sizeof(char) * (end - start + 1));
	if (name == NULL)
		return (NULL);
	j = start;
	i = 0;
	while (j < end)
		name[i++] = s2[j++];
	name[i] = 0;
	replace = getenv(name);
	free(name);
	if (replace != NULL)
	{
		ret = strjoin_se(s1, replace, 0, ft_strlen(replace));
		return (ret);
	}
	return (s1);
}

char	*strjoin_se(char *s1, char *s2, int start, int end)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	ret = malloc(sizeof(char) * (ft_strlen(s1) + (end - start + 1)));
	if (ret == NULL)
		return (NULL);
	while (s1 != NULL && s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	j = start;
	while (j < end)
		ret[i++] = s2[j++];
	ret[i] = 0;
	if (s1 != NULL)
		free(s1);
	return (ret);
}

// void main()
// {
// 	char	*s;
//  	char	str[] = "abcde$USER'bla'blub";

//  	s = NULL;
//  	s = strjoin_se(s, str, 0, 5);
//  	s = strjoin_env(s, str, 6, 10);
//  	printf("s: %s\n", s);
// // 	s = strjoin_se(s, str, 9, 18);
// // 	printf("s: %s\n", s);
// // 	free(s);
// }
