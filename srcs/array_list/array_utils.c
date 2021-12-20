#include "arraylist.h"

void	clearArrayList(t_ArrayList *pList)
{
	free(pList->p_element);
	pList->p_element = NULL;
	pList->current_element_count = 0;
}

int	getArrayListLength(t_ArrayList *pList)
{
	return (pList->current_element_count);
}

int	isArrayListFull(t_ArrayList *pList)
{
	return (pList->max_element_count == pList->current_element_count);
}
