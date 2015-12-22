/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 20:53:35 by fjacquem          #+#    #+#             */
/*   Updated: 2015/12/01 20:53:37 by fjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(char *str, char c)
{
	int i;

	i = 0;
	while (*str)
	{
		str = ft_strskip_char(str, c);
		if (*str && *str != c)
			i++;
		str = ft_strskip_word(str, c);
		str++;
	}
	return (i);
}
