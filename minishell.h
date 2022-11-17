/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:31:24 by pandalaf          #+#    #+#             */
/*   Updated: 2022/11/17 16:07:12 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

//Typedef is for a struct containing critical data.
typedef struct s_minidata
{
	char	**env;
	char	**builtincmds;
}			t_minidata;

// INITIALISATION
//Function initialises the minidata.
void	init_minidata(t_minidata *minidata);

// ERROR HANDLING
//Function handles an "command not found" error.
void	error_cmd_nf(char *line, t_minidata *minidata);
//Function handles an error in signal action setup.
void	error_sig(void);

// MEMORY HANDLING (FREEING)
//Function frees a 2D char array made from ft_split.
void	free_split(char **charr);
//Function frees a minidata struct.
void	free_minidata(t_minidata *minidata);

// EXECUTION

// COMMAND LINE PARSING
//Function finds the command within a simple command line.
char	*findcommand(const char *line);

// VALIDATION
//Function checks that an input line contains valid instructions
int		validline(const char *line, t_minidata *minidata);
//Function determines whether a command is found within the path.
int		is_pathcmd(char *cmd, char **env);


// SIGNALS
//Function sets up the sigaction signal handlers
void	setup_signal(void);

#endif
