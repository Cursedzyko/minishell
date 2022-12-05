/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:53:13 by pandalaf          #+#    #+#             */
/*   Updated: 2022/12/05 21:28:46 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <readline/history.h>
#include <readline/readline.h>

//Function handles permanent settings of the terminal.
void	terminal_setup(void)
{
	struct termios	termparams;
	struct termios	newtermparams;
	int				ret;

	setup_signal();
	ret = tcgetattr(0, &termparams);
	newtermparams = termparams;
	newtermparams.c_lflag &= ~ECHOCTL;
	ret = tcsetattr(0, 0, &newtermparams);
	(void) ret;
}

//Function exits the program cleanly.
static void	cleanexit(t_minidata *minidata)
{
	free_minidata(minidata);
	exit(EXIT_SUCCESS);
}

//Function performs the terminal attributes setting and readline initialisation.
static void	main_loop(t_minidata *minidata)
{
	terminal_setup();
	minidata->currline = (char *) 1;
	while (minidata->currline != 0)
	{
		minidata->currline = readline(PROMPT);
		if (minidata->currline == 0)
			cleanexit(minidata);
		add_history (minidata->currline);
		if (minidata->currline[0] == '\0')
			continue ;
		parser(minidata);
		loop_reset(minidata);
	}
}

//Program is an interactive shell.
int	main(int argc, char **argv, char **env)
{
	t_minidata	*minidata;

	if (argv && argc == 1)
	{
		minidata = init_minidata(env);
		main_loop(minidata);
	}
	else
		ft_putstr_fd("No arguments are required", STDERR_FILENO);
	return (0);
}
