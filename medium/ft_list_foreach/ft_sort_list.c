#include "ft_list2.h"

void	ft_list2sort(t_list **begin_list, int (*cmp)(int, int))
{
	int		changed;
	t_list	*current_elem;
	int		temp;

	changed = 1;
	while (changed)
	{
		changed = 0;
		current_elem = *begin_list;
		while (current_elem->next)
		{
			if (!cmp(current_elem->data, current_elem->next->data))
			{
				changed = 1;
				temp = current_elem->data;
				current_elem->data = current_elem->next->data;
				current_elem->next->data = temp;
			}
			current_elem = current_elem->next;
		}
	}
}

t_list	*ft_sort_list(t_list *begin_list, int (*cmp)(int, int))
{
	ft_list2sort(&begin_list, cmp);
	return (begin_list);
}
