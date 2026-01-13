#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_stack
{
    int *arr;
    int top;
    int size;
} t_stack;

void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);
t_stack *init_stack(int size);
void free_stack(t_stack *stack);
int is_sorted(t_stack *stack);
void print_stack(t_stack *stack);
int *parse_numbers(int argc, char **argv, int *size);
void normalize(int *arr, int size);
void radix_sort(t_stack *a, t_stack *b);
void sort_small(t_stack *a);



#endif
