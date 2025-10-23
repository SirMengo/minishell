#include "execute.h"

int main(int ac, char **av, char **ev)
{
	static t_list *lst;

	create_lst(&lst, ev);
	exports	(lst);
	return (0);
}
