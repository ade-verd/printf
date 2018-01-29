/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:09:01 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/29 18:36:31 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int_types_diouxx(va_list ap, t_indic **ind, t_buff **buff)
{
	char	*str;

	ft_get_string(ind, ap, &str);
	ft_indicators_manager(ind, buff, &str);
	ft_putsbuffer(buff, str);
	if ((*buff)->suffix)
		ft_putsbuffer(buff, (*buff)->suffix);
}

void	ft_int_type_D(va_list ap, t_indic **ind, t_buff **buff)
{
	if ((*ind)->type == 'D')
	{
		(*ind)->type = 'd';
		if ((*ind)->size)
		{
			(*ind)->size[0] = 'l';
			(*ind)->size[1] = '\0';
		}
		else
		{
			(*ind)->size = ft_strnew(1);
			(*ind)->size[0] = 'l';
		}
	}
	ft_int_types_diouxx(ap, ind, buff);
}

void	ft_int_arg(va_list ap, t_indic **ind, t_buff **buff)
{
	const t_ft	g_ft[] = {
		{"diouxX", ft_int_types_diouxx, NULL, NULL},
		{"D", ft_int_type_D, NULL, NULL},
		{0, 0, 0, 0}
	};
	int			i;

	i = 0;
	while (g_ft[i].letter)
	{
		if ((*ind)->type && ft_strchr(g_ft[i].letter, (*ind)->type))
		{
			g_ft[i].f1(ap, ind, buff);
			break ;
		}
		i++;
	}
}
