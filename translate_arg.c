/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponcin <nponcin@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:50:04 by nponcin           #+#    #+#             */
/*   Updated: 2025/07/26 23:54:31 by nponcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	ft_extract(char *str);
int chunks(char *str);
void print_num(char *str);
void decompose(char digit1, char digit2, char digit3);

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
	int	i;
	int	len;
	int	chunks;

	i = 0;
	len = ft_strlen(str);
	if (len % 3 == 0)
		chunks = len / 3;
	else
		chunks = ((len / 3) + 1);
	while (str[i] != '\0' && i < len)
	{
		decompose(str[i], str[i + 1], str[i + 2]);
		i = i + 3;
	}
	return (1);
}

void decompose(char digit1, char digit2, char digit3)
{
	char	tens[3];

	if (digit2 == '1')
	{
		print_num(&digit1);
		write(1, "hundred", 7);
		tens[0] = digit2;
		tens[1] = digit3;
		tens[2] = '\0';
		print_num(tens);
	}
	if (digit2 != '0' && digit2 != '1')
	{
		print_num(&digit1);
		write(1, "hundred", 7);
		tens[0] = digit2;
		tens[1] = '0';
		tens[2] = '\0';
		print_num(tens);
		print_num(&digit3);
	}
	else
	{
		print_num(&digit1);
		write(1, "hundred", 7);
		print_num(&digit3);
	}
}
