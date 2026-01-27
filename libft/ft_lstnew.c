/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:00:01 by seukim            #+#    #+#             */
/*   Updated: 2026/01/28 01:13:03 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new_mem;

	new_mem = NULL;
	if (!(new_mem = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new_mem->content = content;
	new_mem->next = NULL;
	return (new_mem);
}
