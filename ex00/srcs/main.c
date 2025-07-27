/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:17:05 by egalindo          #+#    #+#             */
/*   Updated: 2025/07/27 20:25:19 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

int	main(int argc, char **argv)
{
	char	*dict_name;

	if (ft_check_args (argc, argv) == 1)
	{
		write (1, "Error\n", 6);
		return (1);
	}
	if(argc == 2)
	{
		dict_name="numbers.dict";
		chunks(argv[1], dict_name);
	}
	if(argc == 3)
	{
		dict_name = argv[1];
		chunks(argv[2], dict_name);
	}
	return (0);
}
