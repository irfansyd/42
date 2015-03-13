/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:30:22 by sboudouk          #+#    #+#             */
/*   Updated: 2014/11/06 19:49:01 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	if (c == ' ' ||\
		c == '\t' ||\
		c == '\n' ||\
		c == '\v' ||\
		c == '\f' ||\
		c == '\r')
		return (1);
	else
		return (0);
}