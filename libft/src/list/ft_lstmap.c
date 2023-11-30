/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:14:32 by ycontre           #+#    #+#             */
/*   Updated: 2023/11/30 10:52:19 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*temp;

	new_list = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (temp == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, temp);
		lst = lst->next;
	}
	return (new_list);
}
