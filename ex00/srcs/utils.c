/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:48:43 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/27 21:54:27 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"
#include "../includes/rush02.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	handle_zero_case(char *pad_str, int len, char *dict_name)
{
	if (len == 3 && pad_str[0] == '0' && pad_str[1] == '0' && pad_str[2] == '0')
	{
		print_num("0", dict_name);
		write(1, "\n", 1);
		free(pad_str);
		return (1);
	}
	return (0);
}
