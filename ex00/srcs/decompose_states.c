/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompose_states.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:57:21 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/27 22:13:31 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h" 
#include "../includes/utils.h"

void	state1(char d1, char d2, char d3, char *dict_name)
{
	char	temp[2];

	temp[0] = d1;
	temp[1] = '\0';
	print_num(temp, dict_name);
	write(1, " ", 1);
	print_num("100", dict_name);
	if (d2 != '0' || d3 != '0')
		write(1, " and ", 5);
}

void	state2(char d2, char d3, char *dict_name)
{
	char	temp[3];

	temp[0] = d2;
	temp[1] = d3;
	temp[2] = '\0';
	print_num(temp, dict_name);
}

void	state3(char d2, char d3, char *dict_name)
{
	char	temp[3];

	temp[0] = d2;
	temp[1] = '0';
	temp[2] = '\0';
	print_num(temp, dict_name);
	if (d3 != '0')
		write(1, "-", 1);
}

void	state4(char d3, char *dict_name)
{
	char	temp[2];

	temp[0] = d3;
	temp[1] = '\0';
	print_num(temp, dict_name);
}
