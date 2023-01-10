void	ft_pop(t_list **begin, void *data_ref, int *(comp)())
{
	t_list	*tmp;

	if (begin)
	{
		while (begin && !comp((*begin)->data, data_ref))
		{
			tmp = *begin;
			*begin = (*begin)->next;
			free(tmp);
		}
	}
	if (!*begin)
		begin = NULL;
}

void	ft_remove(t_list **begin, void *data_ref, int *(comp)())
{
	t_list	*tmp =  NULL;
	t_list	*tmp_prec = NULL;
	int	supr = 0;

	ft_pop(begin, data_ref, comp);
	if (begin)
	{
		tmp = *begin;
		tmp_prec = tmp;
		while (tmp)
		{
			if (!comp(tmp->data, data_ref))
			{
				tmp_prec->next = tmp->next
				free(tmp);
				supr = 1;
			}
			if(supr)
				tmp = tmp_prec;
			tmp_prec = tmp;
			tmp = tmp->next;
			supr = 0;
		}
	}
}
