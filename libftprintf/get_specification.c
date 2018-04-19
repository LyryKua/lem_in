/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specification.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:11:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/05 13:11:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static t_flag		get_flags(const char *format, size_t *step)
{
	t_flag	flags;

	flags.hash = false;
	flags.zero = false;
	flags.minus = false;
	flags.plus = false;
	flags.space = false;
	*step = 1;
	while (format[*step] == '#' || format[*step] == '0' || format[*step] == '-'
								|| format[*step] == '+' || format[*step] == ' ')
	{
		if (format[*step] == '#')
			flags.hash = true;
		else if (format[*step] == '0')
			flags.zero = true;
		else if (format[*step] == '-')
			flags.minus = true;
		else if (format[*step] == '+')
			flags.plus = true;
		else if (format[*step] == ' ')
			flags.space = true;
		(*step)++;
	}
	return (flags);
}

static int			get_width(const char *format, va_list *ap, void **data,
																	size_t *tmp)
{
	int	width;

	*tmp = 0;
	if (format[*tmp] == '*')
	{
		width = (int)*data;
		*data = va_arg(*ap, void *);
		(*tmp)++;
	}
	else if (format[*tmp] == '.')
		width = 0;
	else
	{
		width = ft_atoi(format);
		while (ft_isdigit(format[*tmp]))
			(*tmp)++;
	}
	return (width);
}

static int			get_precision(const char *format, t_flag *flags,
																	size_t *tmp)
{
	int	precision;

	*tmp = 0;
	precision = 0;
	if (format[*tmp] == '.')
	{
		(*tmp)++;
		if (format[*tmp] != '0' && ft_isdigit(format[*tmp]))
			precision = ft_atoi(format + 1);
		else
			precision = -1;
		while (ft_isdigit(format[*tmp]))
			(*tmp)++;
		if (precision != 0)
			flags->zero = false;
	}
	return (precision);
}

static char			*get_modifier(const char *format, size_t *tmp)
{
	char	*modifier;

	*tmp = 0;
	while (format[*tmp] == 'l' || format[*tmp] == 'h' || format[*tmp] == 'z'
														|| format[*tmp] == 'j')
		(*tmp)++;
	if (ft_strnstr(format, "z", *tmp))
		modifier = ft_strdup("z");
	else if (ft_strnstr(format, "j", *tmp))
		modifier = ft_strdup("j");
	else if (ft_strnstr(format, "ll", *tmp))
		modifier = ft_strdup("ll");
	else if (ft_strnstr(format, "l", *tmp))
		modifier = ft_strdup("l");
	else if (ft_strnstr(format, "h", *tmp) && !ft_strnstr(format, "hh", *tmp))
		modifier = ft_strdup("h");
	else if (ft_strnstr(format, "hh", *tmp))
		modifier = ft_strdup("hh");
	else
		modifier = NULL;
	return (modifier);
}

t_specification		get_specification(const char *format, va_list *ap,
													void **data, size_t *step)
{
	t_specification	spec;
	size_t			tmp;

	spec.flags = get_flags(format, step);
	format += *step;
	spec.width = get_width(format, ap, data, &tmp);
	format += tmp;
	*step += tmp;
	spec.precision = get_precision(format, &spec.flags, &tmp);
	format += tmp;
	*step += tmp;
	spec.modifier = get_modifier(format, &tmp);
	format += tmp;
	*step += tmp;
	spec.type = *format;
	if (spec.type == 's' || spec.type == 'S' || spec.type == 'p'
		|| spec.type == 'i' || spec.type == 'd' || spec.type == 'D'
		|| spec.type == 'o' || spec.type == 'O' || spec.type == 'u'
		|| spec.type == 'U' || spec.type == 'x' || spec.type == 'X'
		|| spec.type == 'c' || spec.type == 'C' || spec.type == 'b'
		|| spec.type == 'B' || spec.type == '%')
		(*step)++;
	spec.flags.zero = (spec.flags.zero && spec.flags.minus) ?
														false : spec.flags.zero;
	return (spec);
}
