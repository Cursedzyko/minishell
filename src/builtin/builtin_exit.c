/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:39:06 by pandalaf          #+#    #+#             */
/*   Updated: 2022/12/14 16:57:05 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <readline/readline.h>

//Function writes out the "too many arguments" error to standard error.
static int	error_exit(t_minidata *minidata, int err, char *arg)
{
	write(STDERR_FILENO, "minishell: exit: ", 17);
	if (err == 1)
	{
		write(STDERR_FILENO, arg, ft_strlen(arg));
		write(STDERR_FILENO, ": numeric argument required", 27);
	}
	else
	{
		write(STDERR_FILENO, "too many arguments", 18);
		update_return(minidata, 2);
	}
	write(STDERR_FILENO, "\n", 1);
	return (255);
}

//Function frees elements and exits the program with given number.
static void	free_exit(int ret, char **splitline, t_minidata *minidata)
{
	free_split(splitline);
	free_minidata(minidata);
	exit(ret);
}

//Function exits the program cleanly.
void	builtin_exit(t_minidata *minidata)
{
	char	**splitline;
	int		exitno;

	exitno = 0;
	splitline = ft_split(minidata->currline, ' ');
	if (split_size(splitline) == 1 || split_size(splitline) == 2)
	{
		if (split_size(splitline) == 2 && (ft_atol(splitline[1]) == -1 || \
			is_validnum(splitline[1]) == 0))
			exitno = error_exit(minidata, 1, splitline[1]);
		else if (split_size(splitline) == 2)
		{
			if (ft_atol(splitline[1]) > 0)
				exitno = ft_atol(splitline[1]) % 256;
			else
				exitno = (ft_atol(splitline[1]) * -1) % 256;
		}
		else
			exitno = EXIT_SUCCESS;
		free_exit(exitno, splitline, minidata);
	}
	error_exit(minidata, 2, 0);
	free_split(splitline);
	rl_on_new_line();
}
