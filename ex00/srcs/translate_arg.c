/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponcin <nponcin@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:50:04 by nponcin           #+#    #+#             */
/*   Updated: 2025/07/27 22:11:52 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h" 
#include "../includes/utils.h"

int	skip_zeros(char *pad_str)
{
	if (pad_str[0] == '0' && pad_str[1] == '0' && pad_str[2] == '0')
		return (1);
	return (0);
}

char	*zero_pad(int pad, char *str, int len)
{
	int		i;
	char	*pad_str;

	pad_str = (char *) malloc((sizeof(char) * (len + pad + 1)));
	i = 0;
	while (i < pad)
	{
		pad_str[i] = '0';
		i++;
	}
	i = 0;
	while (i < len)
	{
		pad_str[pad + i] = str[i];
		i++;
	}
	len += pad;
	pad_str[len] = '\0';
	return (pad_str);
}

void	space_big_u(int len, int idx, char *dict_name)
{
	write (1, " ", 1);
	print_big_units(len, idx, dict_name);
	write (1, " ", 1);
}

int	chunks(char *str, char	*dict_name)
{
	int		len;
	int		padding;
	int		idx;
	char	*pad_str;

	len = ft_strlen(str);
	padding = (3 - (len % 3)) % 3;
	pad_str = zero_pad(padding, str, len);
	len += padding;
	if (handle_zero_case(pad_str, len, dict_name))
		return (0);
	idx = 0;
	while (idx < len)
	{
		decompose(pad_str[idx], pad_str[idx + 1], pad_str[idx + 2], dict_name);
		if (skip_zeros(&pad_str[idx]) == 1)
		{
			idx += 3;
			continue ;
		}
		if ((idx + 3) < len)
			space_big_u(len, idx, dict_name);
		idx += 3;
	}
	write(1, "\n", 1);
	free(pad_str);
	return (0);
}

void	decompose(char d1, char d2, char d3, char *dict_name)
{
	if (d1 != '0')
		state1(d1, d2, d3, dict_name);
	if (d2 == '1')
		state2(d2, d3, dict_name);
	else
	{
		if (d2 != '0')
			state3(d2, d3, dict_name);
		if (d3 != '0')
			state4(d3, dict_name);
	}
}
