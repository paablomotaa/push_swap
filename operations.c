/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmota-ga <pmota-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 09:54:17 by pmota-ga          #+#    #+#             */
/*   Updated: 2026/01/13 11:21:26 by pmota-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sa(t_stack *a)
{
	int	tmp;

	if (!a || a->top < 1)
		return ;
	tmp = a->arr[a->top];
	a->arr[a->top] = a->arr[a->top - 1];
	a->arr[a->top - 1] = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	tmp;

	if (!b || b->top < 1)
		return ;
	tmp = b->arr[b->top];
	b->arr[b->top] = b->arr[b->top - 1];
	b->arr[b->top - 1] = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	if (!b || b->top < 0)
		return ;
	if (a->top + 1 >= a->size)
		return ;
	a->top++;
	a->arr[a->top] = b->arr[b->top];
	b->top--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a || a->top < 0)
		return ;
	if (b->top + 1 >= b->size)
		return ;
	b->top++;
	b->arr[b->top] = a->arr[a->top];
	a->top--;
	write(1, "pb\n", 3);
}

void	ra(t_stack *a)
{
	int	i;
	int	top_val;

	if (!a || a->top < 1)
		return ;
	top_val = a->arr[a->top];
	i = a->top;
	while (i > 0)
	{
		a->arr[i] = a->arr[i - 1];
		i--;
	}
	a->arr[0] = top_val;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	int	i;
	int	top_val;

	if (!b || b->top < 1)
		return ;
	top_val = b->arr[b->top];
	i = b->top;
	while (i > 0)
	{
		b->arr[i] = b->arr[i - 1];
		i--;
	}
	b->arr[0] = top_val;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack *a)
{
	int	i;
	int	bottom_val;

	if (!a || a->top < 1)
		return ;
	bottom_val = a->arr[0];
	i = 0;
	while (i < a->top)
	{
		a->arr[i] = a->arr[i + 1];
		i++;
	}
	a->arr[a->top] = bottom_val;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	int	i;
	int	bottom_val;

	if (!b || b->top < 1)
		return ;
	bottom_val = b->arr[0];
	i = 0;
	while (i < b->top)
	{
		b->arr[i] = b->arr[i + 1];
		i++;
	}
	b->arr[b->top] = bottom_val;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
