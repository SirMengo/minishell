/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_contents.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:53:07 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/15 12:53:18 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_free.h"

void	free_env(void *content)
{
	t_envar	*env;
	
	env = content;
	if (env->key)
		free(env->key);
	if (env->value)
		free(env->value);
	free(env);
}
