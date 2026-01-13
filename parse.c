/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmota-ga <pmota-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 09:55:37 by pmota-ga          #+#    #+#             */
/*   Updated: 2026/01/13 11:19:49 by pmota-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <ctype.h>
#include <stdlib.h>

static int	is_number(char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*parse_numbers(int argc, char **argv, int *size)
{
	int	*arr;
	int	i;
	long	num;

	arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (!arr)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
		{
			free(arr);
			return (NULL);
		}
		num = atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free(arr);
			return (NULL);
		}
		arr[i - 1] = (int)num;
		i++;
	}
	if (has_duplicates(arr, argc - 1))
	{
		free(arr);
		return (NULL);
	}
	*size = argc - 1;
	return (arr);
}
