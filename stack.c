/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:56:22 by htalhaou          #+#    #+#             */
/*   Updated: 2023/02/18 19:45:54 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  push(t_list **top, int content)
{
  t_list *node;
  
  node = ft_lstnew(content);
  node->next = *top;
  *top = node;
}

int pop(t_list **top) 
{
  t_list *tmp;
  int result;

  if (*top == NULL)
    return (-1);
  tmp = *top;
  result = tmp->content;
  *top = tmp->next;
  free(tmp);
  return (result);
}

int peek(t_list **head)
{
    if (*head == NULL)
      return -1;
    return (*head)->content;
}

void fill_array_from_stack(t_list *stack_a, int *array, int size)
{
  int i;
  int content;
  t_list  **tmp;

  i = 0;
  tmp = &stack_a;
  while (i < size)
  {
    array[i] = (*tmp)->content;
    (*tmp) = (*tmp)->next;
    i++;
  }
}

void    print_stacks(t_list *s1, t_list *s2)
{
    t_list    *temp1;
    t_list    *temp2;
    int        height1;
    int        height2;
    int        i;

    temp1 = s1;
    temp2 = s2;
    height1 = ft_lstsize(s1);
    height2 = ft_lstsize(s2);
    i = (height1 > height2) ? height1 : height2;
    while (i >= 1)
    {
        if (i <= height1)
        {
            ft_printf("|\t%d\t|", temp1->content);
            temp1 = temp1->next;
        }
        else
            ft_printf("|\t \t|");
        if (i <= height2)
        {
            ft_printf("|\t%d\t|", temp2->content);
            temp2 = temp2->next;
        }
        else
        ft_printf("|\t \t|");
        ft_printf("      ");
        ft_printf("\n");
        i--;
    }
    ft_printf("\033[0;36m""|\tA\t||\tB\t|\n""\033[0;37m");
}