/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_ar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 08:49:01 by sboudouk          #+#    #+#             */
/*   Updated: 2015/01/05 08:49:01 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_infos	*ft_sort_a(t_infos *llist, t_infos *node)
{
	t_infos *tmp;
	t_infos *tmp2;

	tmp2 = NULL;
	tmp = llist;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, node->name) > 0)
		{
			node->nxt = tmp;
			if (tmp2)
				tmp2->nxt = node;
			else
				return (node);
			return (llist);
		}
		tmp2 = tmp;
		tmp = tmp->nxt;
	}
	tmp2->nxt = node;
	node->nxt = NULL;
	return (llist);
}

t_infos	*ft_sort_ar(t_infos *llist, t_infos *node)
{
	t_infos *tmp;
	t_infos *tmp2;

	tmp2 = NULL;
	tmp = llist;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, node->name) < 0)
		{
			node->nxt = tmp;
			if (tmp2)
				tmp2->nxt = node;
			else
				return (node);
			return (llist);
		}
		tmp2 = tmp;
		tmp = tmp->nxt;
	}
	tmp2->nxt = node;
	node->nxt = NULL;
	return (llist);
}
