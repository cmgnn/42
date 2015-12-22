/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeforeach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 20:53:55 by fjacquem          #+#    #+#             */
/*   Updated: 2015/12/01 20:53:57 by fjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreeforeach(t_btree *root, unsigned int flag, void (*fct)())
{
	if (root)
	{
		if (prefix & flag && root->content)
			(*fct)(root->content);
		ft_btreeforeach(root->left, flag, _do);
		if (affix & flag && root->content)
			(*fct)(root->content);
		ft_btreeforeach(root->right, flag, _do);
		if (suffix & flag && root->content)
			(*fct)(root->content);
	}
}
