/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implemt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <fjacquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/05 09:53:57 by fjacquem          #+#    #+#             */
/*   Updated: 2015/12/01 20:41:35 by fjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMPLEMT_H
# define IMPLEMT_H
# include "libft.h"

long	ft_pow(int value, unsigned int n);
char	*ft_itoa_base(int value, char *base_digits);
void	ft_putnbr_base_fd(int nb, char *base, int fd);
void	ft_putnbr_base(int nb, char *base);
void	ft_putdouble(double d);
void	ft_puthex(unsigned int number);
void	ft_print(const char *str, ...);
char	*ft_strrev(char *str);
void	ft_putnstr(char *str, unsigned int offset);

#endif
