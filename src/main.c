/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 10:05:32 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/16 10:05:33 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int main(int argc, char **argv)
{
    int i;
    t_node *stack_a;
    t_node *stack_b;
    int len_arg;

    len_arg = argc - 1;
    i = len_arg;
    if (argc == 0)
      return (0);
    if (!(stack_a = (t_node*)malloc(sizeof(t_node))))
      return (-1);
    stack_a = NULL;
    if (!(stack_b = (t_node*)malloc(sizeof(t_node))))
      return (-1);
    stack_b = NULL;
    while (i)
    {
      if (!(ft_push_front(&stack_a, ft_atoi(argv[i]))))
        return (-1);
      i--;
    }
//    ft_push_back(&lst_tab, 42);
//    ft_delete_first(&lst_tab);
  //  ft_rotate(&lst_tab);
  //  ft_lst_display(lst_tab);
  //  ft_reverse_rotate(&lst_tab);
    ft_push_ab(&stack_a, &stack_b);
    ft_push_ab(&stack_a, &stack_b);
    ft_push_ab(&stack_a, &stack_b);
    ft_swap_one_two(&stack_a);
  //  ft_rotate(&stack_a);
  //  ft_rotate(&stack_a);
    ft_push_ab(&stack_b, &stack_a);
//    ft_reverse_rotate(&stack_a);
    ft_putendl("===[A]===");
    ft_lst_display(stack_a);
    ft_putendl("===[B]===");
    ft_lst_display(stack_b);
    return (0);
}
/*
for i = 2:n,
    for (k = i; k > 1 and a[k] < a[k-1]; k--)
        swap a[k,k-1]
    → invariant: a[1..i] is sorted
end
*/
/*
t_node *ft_sort_list(t_node *lst)
{
    t_node *head;
    t_node *current;
    t_node *stack_b;

    // zero or one element in list
    if(lst == NULL || lst->next == NULL)
        return (lst);
    head = NULL; // head is the first element of resulting sorted list
    while(lst != NULL)
    {
        current = lst;
        lst = lst->next;
        if(head == NULL || current->data < head->data) // insert into the head of the sorted list // or as the first element into an empty sorted list
        {
            current->next = head;
            head = current;
        }
        else
        { // insert current element into proper position in non-empty sorted list
            stack_b = head;
            while(stack_b != NULL)
            {
                if(stack_b->next == NULL || current->data < stack_b->next->data) // last element of the sorted list // middle of the list
                {
                    current->next = stack_b->next; // insert into middle of the sorted list or as the last element
                    stack_b->next = current;
                    break; // done
                }
                stack_b = stack_b->next;
            }
        }
    }
    return (head);
}
*/
