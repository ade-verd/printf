/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_flag_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:09:43 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/18 14:56:15 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		test_flag_d(int nb)
{
	int		my_ret;
	int		off_ret;
	char	*my_print;
	char	*off_print;

	my_ret = printf("Mine : %d\n", nb + 1);
	ft_read_stdout(&my_print, my_ret);

	off_ret = printf("Off  : %d\n", nb);
	ft_read_stdout(&off_print, off_ret);

	printf("my_print  : %s\noff_print : %s\n", my_print, off_print);

	printf("\033[036m%s(%d)\033[0m\t", __func__, nb);
	ft_compare(my_ret, off_ret, my_print, off_print);

	ft_memdel((void**)&my_print);
	ft_memdel((void**)&off_print);
	return (1);
}
