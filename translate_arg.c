/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponcin <nponcin@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:50:04 by nponcin           #+#    #+#             */
/*   Updated: 2025/07/27 14:59:59 by nponcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_extract(char *str);
int 	chunks(char *str);
void 	print_num(char *str);
void 	decompose(char digit1, char digit2, char digit3);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	chunks(char *str)
{
	int		i;
	int		len;
	int		padding;
	char	padded_str[1024];

	i = 0;
	len = ft_strlen(str);
	padding = (3 - (len % 3)) % 3;
	while (i < padding)
	{
		padded_str[i] = '0';
		i++;
	}
	i = 0;
	while (i < 3 - padding)
	{
		padded_str[padding + i] = str[i];
		i++;
	}
	len = len + padding;
	i = 0;
	while (i < len)
	{
		decompose(str[i], str[i + 1], str[i + 2]);
		if (i + 3 < len)
			write(1, " ", 1);
		i += 3;
	}
	write(1, "\n", 1);
	return (0);
}

void decompose(char d1, char d2, char d3)
{
	char	temp[4];

	if (d1 != '0')
	{
		temp[0] = d1;
		temp[1] = '\0';
		print_num(temp);
		write(1, " ", 1);
		print_num("100");
		if (d2 != '0' || d3 != '0')
			write(1, " and ", 5);
	}
	if (d2 == '1')
	{
		temp[0] = d2;
		temp[1] = d3;
		temp[2] = '\0';
		print_num(temp);
	}
	else
	{
		if (d2 != '0')
		{
			temp[0] = d2;
			temp[1] = '0';
			temp[2] = '\0';
			print_num(temp);
				if (d3 != '0')
					write(1, "-", 1);
		}
		if (d3 != '0' && d2 != '1')
		{
			temp[0] = d3;
			temp[1] = '\0';
			print_num(temp);
		}
	}
}
