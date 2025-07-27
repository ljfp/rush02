/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_big_unit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaires-r <jaires-r@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:11:51 by jaires-r          #+#    #+#             */
/*   Updated: 2025/07/27 19:50:06 by nponcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../includes/rush02.h"

char	*big_unit(int num_zeros)
{
	int		i;
	char	*to_find;
	
	to_find = (char *) malloc(sizeof(char) *(1 + num_zeros + 2));
	if (to_find == NULL)
		return (NULL);
	to_find[0] = '1';
	i = 1;
	while (i <= num_zeros)
	{
		to_find[i] = '0';
		i++;
	}
	to_find[num_zeros + 1] = ':';
	to_find[num_zeros + 2] = '\0';
	return (to_find);
}


void	print_big_units(int	len, int idx, char *dict_name)
{
	char	*to_find;
	int		num_zeros;

	num_zeros = (len - (idx + 3));
	if (num_zeros > 0 && num_zeros % 3 == 0)
	{
	to_find = big_unit(num_zeros);
		if (to_find)
		{
			print_num(to_find, dict_name);
			free(to_find);
		}		
	}
}
