/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:27:25 by pandalaf          #+#    #+#             */
/*   Updated: 2022/12/05 22:31:37 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include <stdlib.h>

//Function finds the command element within a simple command line.
char	*findcommand(const char *line)
{
	char	**split;
	char	*cmd;
	int		i;

	split = ft_split(line, ' ');
	i = 0;
	while (split[i] != 0)
		i++;
	while (i > 0)
	{
		free(split[i]);
		i--;
	}
	cmd = split[0];
	free(split);
	return (cmd);
}

//Function acts when the input command line is a valid one.
static void	execution(t_minidata *minidata)
{
	if (is_builtincmd(minidata) > 0)
		builtin_execution(minidata);
	//path (check permissions)
	//direct (check permissions)
}

//Function performs the parsing of a command line.
void	parser(t_minidata *minidata)
{
	if (is_valid_quotes(minidata->currline) == 0)
		ft_printf("syntax error: unable to locate closing quotation\n");
	if (read_token(minidata) == 0)
		ft_printf("\n");
	start_parser(minidata);
	if (is_validcmdline(minidata) == 1)
		execution(minidata);
	else
		error_cmd_nf(minidata->currline);
}
