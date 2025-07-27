/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponcin <nponcin@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:59:48 by nponcin           #+#    #+#             */
/*   Updated: 2025/07/27 17:42:09 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/rush02.h"

char	*ft_strndup(char *src, int n)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (dup == NULL)
		return (NULL);
	while (i < n)
	{
		dup[i] = src[i];
		i++;
	}
	dup[n] = '\0';
	return (dup);
}

char	*ft_extract(char *str)
{
	int		start;
	int		end;
	int		string_len;
	char	*result;

	if (str == NULL)
		return (NULL);
	start = 0;
	while ((str[start] >= '0' && str[start] <= '9')
		|| str[start] == ' ' || str[start] == ':')
	{
		start++;
	}
	end = start;
	while (str[end] >= 'a' && str[end] <= 'z')
	{
		end++;
	}
	string_len = (end - start);
	result = ft_strndup(&str[start], string_len);
	return (result);
}
