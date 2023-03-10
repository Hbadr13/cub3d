/* ************************************************************************** */
/*								                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:11:04 by mbenaoui          #+#    #+#             */
/*   Updated: 2022/10/26 13:11:10 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	if_player(char c)
{
	if (c != 'S' && c != 'N' && c != 'W' && c != 'E' && c != 'D')
		return (0);
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	len_tab(char **tab, int index)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	if (index == 0)
	{
		if (i != 3)
			msg_error(3);
	}
	return (i);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
