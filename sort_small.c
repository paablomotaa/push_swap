/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmota-ga <pmota-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:11:49 by pmota-ga          #+#    #+#             */
/*   Updated: 2026/01/13 11:17:47 by pmota-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	if (a->top == 1)
	{
		if (a->arr[a->top] > a->arr[a->top - 1])
			sa(a);
	}
	else if (a->top == 2)
	{
		top = a->arr[a->top];
		mid = a->arr[a->top - 1];
		bot = a->arr[a->top - 2];
		if (top > mid && mid < bot && top < bot)
			sa(a);
		else if (top > mid && mid > bot)
		{
			sa(a);
			rra(a);
		}
		else if (top > mid && mid < bot && top > bot)
			ra(a);
		else if (top < mid && mid > bot && top < bot)
		{
			sa(a);
			ra(a);
		}
		else if (top < mid && mid > bot && top > bot)
			rra(a);
	}
}
