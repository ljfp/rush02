/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponcin <nponcin@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:50:04 by nponcin           #+#    #+#             */
/*   Updated: 2025/07/27 19:42:30 by nponcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h" 

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	chunks(char *str, char	*dict_name)
{
	int		i;
	int		len;
	int		padding;
	int		idx;
	char	padded_str[1024];

	i = 0;
	len = ft_strlen(str);
	padding = (3 - (len % 3)) % 3;
	while (i < padding)
	{
		padded_str[i] = '0';
		i++;
	}
	idx = 0;
	while (idx < len)
	{
		padded_str[padding + idx] = str[idx];
		idx++;
	}
	len = len + padding;
	padded_str[len] = '\0';
	idx = 0;
	while (idx < len)
	{
		decompose(padded_str[idx], padded_str[idx + 1], padded_str[idx + 2], dict_name);
		if ((idx + 3) < len)
		{
			write(1, " ", 1);
			print_big_units(len, idx, dict_name);
		}
		idx += 3;
	}
	write(1, "\n", 1);
	return (0);
}

void decompose(char d1, char d2, char d3, char *dict_name)
{
	char	temp[4];

	if (d1 != '0')
	{
		temp[0] = d1;
		temp[1] = '\0';
		print_num(temp, dict_name);
		write(1, " ", 1);
		print_num("100", dict_name);
		if (d2 != '0' || d3 != '0')
			write(1, " and ", 5);
	}
	if (d2 == '1')
	{
		temp[0] = d2;
		temp[1] = d3;
		temp[2] = '\0';
		print_num(temp, dict_name);
	}
	else
	{
		if (d2 != '0')
		{
			temp[0] = d2;
			temp[1] = '0';
			temp[2] = '\0';
			print_num(temp, dict_name);
				if (d3 != '0')
					write(1, "-", 1);
		}
		if (d3 != '0')
		{
			temp[0] = d3;
			temp[1] = '\0';
			print_num(temp, dict_name);
		}
	}
	
}
