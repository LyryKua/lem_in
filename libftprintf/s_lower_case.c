/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_lower_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:49:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/28 16:26:23 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	s_print(t_specification spec, char *str)
{
	if (spec.precision == -1)
		return ;
	if (spec.precision && spec.precision < (int)ft_strlen(str))
	{
		while (spec.precision--)
		{
			ft_putchar(*str++);
			g_return++;
		}
	}
	else
	{
		ft_putstr(str);
		g_return += (int)ft_strlen(str);
	}
}

static void	left_align(t_specification spec, char *str)
{
	int	width;
	int	len;

	s_print(spec, str);
	len = (int)ft_strlen(str);
	width = spec.width - (spec.precision && spec.precision < len ?
														spec.precision : len);
	while (width-- > 0)
	{
		ft_putchar((char)(spec.flags.zero == true ? '0' : ' '));
		g_return++;
	}
}

static void	right_align(t_specification spec, char *str)
{
	int	width;
	int	len;

	len = (int)ft_strlen(str);
	width = spec.width - (spec.precision > 0 && spec.precision < len ?
														spec.precision : len);
	if (spec.precision == -1)
		width += len;
	while (width-- > 0)
	{
		ft_putchar((char)(spec.flags.zero == true ? '0' : ' '));
		g_return++;
	}
	s_print(spec, str);
}

void		s_lower_case(void *data, t_specification *spec)
{
	char	*str;
	bool	flag;

	if (spec->modifier != NULL && !ft_strcmp(spec->modifier, "l"))
		s_upper_case(data, spec);
	else
	{
		str = (char *)data;
		flag = false;
		if (str == NULL)
		{
			str = ft_strdup("(null)");
			flag = true;
		}
		if (spec->flags.minus == true)
			left_align(*spec, str);
		else
			right_align(*spec, str);
		if (flag)
			ft_strdel(&str);
	}
}
