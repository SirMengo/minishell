#include "execute.h"

int main(int ac, char **av, char **ev)
{
	t_list *lst = NULL;
	char str[PATH_MAX];
	char str2[] = "";

	create_lst(&lst, ev);
	unset(&lst, "HOME");
	show_envars(lst);
}