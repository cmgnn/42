/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 20:53:55 by fjacquem          #+#    #+#             */
/*   Updated: 2015/12/01 20:53:57 by fjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int		sign;
	char	*cur;
	int		result;

	result = 0;
	cur = (char *)str;
	while (*cur && *cur != '-' && *cur != '+' && !ft_isdigit(*(cur + 1)))
		cur++;
	sign = (*cur == '-') ? -1 : 1;
	cur = (*cur == '+' || *cur == '-') ? cur + 1 : cur;
	while (ft_isdigit(*cur))
	{
		result = result * 10 + *cur - 48;
		cur++;
	}
	result *= sign;
	return (result);
}
