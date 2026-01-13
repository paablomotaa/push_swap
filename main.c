/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmota-ga <pmota-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:00:27 by pmota-ga          #+#    #+#             */
/*   Updated: 2026/01/13 11:24:49 by pmota-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		size;
	int		*numbers;
	t_stack	*a;
	t_stack	*b;
	int		i;

	if (argc < 2)
		return (0);
	numbers = parse_numbers(argc, argv, &size);
	if (!numbers)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	normalize(numbers, size);
	a = init_stack(size);
	b = init_stack(size);
	if (!a || !b)
	{
		free(numbers);
		free_stack(a);
		free_stack(b);
		return (1);
	}
	i = 0;
	while (i < size)
	{
		a->arr[i] = numbers[i];
		i++;
	}
	a->top = size - 1;
	free(numbers);
	if (size <= 3)
		sort_small(a);
	else
		radix_sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}

