#include "arraylist.h"

t_ArrayList	*createArrayList(int max_element_count)
{
	t_ArrayList	*tmp;

	tmp = (t_ArrayList *)ft_calloc(1, sizeof(t_ArrayList));
	tmp->max_element_count = max_element_count;
	tmp->current_element_count = 0;
	tmp->p_element = (t_ArrayListNode *)ft_calloc
		(max_element_count, sizeof(t_ArrayListNode));
	return (tmp);
}

void	deleteArrayList(t_ArrayList *pList)
{
	free(pList->p_element);
	free(pList);
	pList = NULL;
}

int	addALElement(t_ArrayList *pList, int position, t_ArrayListNode element)
{
	t_ArrayListNode	*tmp;

	if (isArrayListFull(pList))
	{
		pList->max_element_count *= 3;
		tmp = (t_ArrayListNode *)calloc(pList->max_element_count,
				sizeof(t_ArrayListNode));
		ft_memcpy(tmp, pList->p_element,
			pList->current_element_count * sizeof(t_ArrayListNode));
		free(pList->p_element);
		pList->p_element = tmp;
	}
	if ((pList->current_element_count && position > pList->current_element_count))
		return (FALSE);
	ft_memmove(pList->p_element + position + 1, pList->p_element + position,
		sizeof(t_ArrayListNode) * (pList->current_element_count - position));
	*(pList->p_element + position) = element;
	(pList->current_element_count)++;
	return (TRUE);
}

int	removeALElement(t_ArrayList *pList, int position)
{
	if (position >= pList->current_element_count
		|| pList->current_element_count == 0)
		return (FALSE);
	ft_memmove(pList->p_element + position, pList->p_element + position + 1,
		sizeof(t_ArrayListNode) * (pList->current_element_count - position));
	(pList->current_element_count)--;
	return (TRUE);
}

t_ArrayListNode	*getALElement(t_ArrayList *pList, int position)
{
	if (position < pList->max_element_count)
		return (pList->p_element + position);
	return (NULL);
}
