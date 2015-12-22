/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:32:55 by fjacquem          #+#    #+#             */
/*   Updated: 2014/11/26 15:56:49 by fjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char *str, char c)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	split = malloc(sizeof(char*) * ft_count_words(str, c));
	while (*str)
	{
		split[i] = malloc(sizeof(char) * ft_count_char(str, c));
		str = ft_strskip_char(str, c);
		j = 0;
		while (*str && *str != c)
			split[i][j++] = *(str++);
		split[i][j] = '\0';
		i++;
		str++;
	}
	return (split);
}
