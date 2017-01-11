/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_tab_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 17:12:29 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/28 17:32:23 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size_tab_base(size_t n, int base)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}
