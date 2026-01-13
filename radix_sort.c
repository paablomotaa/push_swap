/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmota-ga <pmota-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 09:58:35 by pmota-ga          #+#    #+#             */
/*   Updated: 2026/01/13 11:18:43 by pmota-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bits(int size)
{
	int	max;
	int	bits;

	max = size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	size;
	int	bits;
	int	i;
	int	count;
	int	num;

	size = a->top + 1;
	bits = max_bits(size);
	i = 0;
	while (i < bits)
	{
		count = size;
		while (count > 0)
		{
			num = a->arr[a->top];
			if (((num >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			count--;
		}
		while (b->top >= 0)
			pa(a, b);
		i++;
	}
}

