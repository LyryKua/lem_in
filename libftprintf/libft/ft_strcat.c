/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 19:25:27 by khrechen          #+#    #+#             */
/*   Updated: 2016/12/19 19:58:52 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	j;
	size_t	len;

	len = ft_strlen(s1);
	j = 0;
	while (s2[j])
	{
		s1[len + j] = s2[j];
		j++;
	}
	s1[len + j] = '\0';
	return (s1);
}
