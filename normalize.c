/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmota-ga <pmota-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 09:55:19 by pmota-ga          #+#    #+#             */
/*   Updated: 2026/01/13 11:23:41 by pmota-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	find_index(int num, int *sorted, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

static void	copy_and_sort(int *arr, int *copy, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		copy[i] = arr[i];
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (copy[j] > copy[j + 1])
			{
				tmp = copy[j];
				copy[j] = copy[j + 1];
				copy[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	normalize(int *arr, int size)
{
	int	*sorted;
	int	i;

	sorted = (int *)malloc(sizeof(int) * size);
	if (!sorted)
		return ;
	copy_and_sort(arr, sorted, size);
	i = 0;
	while (i < size)
	{
		arr[i] = find_index(arr[i], sorted, size);
		i++;
	}
	free(sorted);
}