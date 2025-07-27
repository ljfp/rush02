/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponcin <nponcin@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 15:48:37 by nponcin           #+#    #+#             */
/*   Updated: 2025/07/27 17:42:52 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>


/* args.c */
int		ft_check_args(int argc, char **argv);
int		ft_return_len(int argc, char **argv);
char	*ft_convert_args(int argc, char **argv);

/* extract_word.c */

char	*ft_strndup(char *src, int n);
char	*ft_extract(char *str);

/* print_num.c */

char	*ft_strstr(char *str, char *to_find);
void	print_num(char *str);

/* translate_arg.c */

int		ft_strlen(char *str);
int		chunks(char *str);
void	decompose(char d1, char d2, char d3);

/* print_big_unit.c */

int		nbr_chunks(char *str);
char	*big_unit(int nbr_chnks);
void	print_big_units(char *str, int nbr_chnks);

#endif
