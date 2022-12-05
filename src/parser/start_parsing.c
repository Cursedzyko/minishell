/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:40:14 by zyunusov          #+#    #+#             */
/*   Updated: 2022/12/05 21:02:05 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	start_parser(t_minidata *minidata)
{
	count_pipes(minidata->lexer_list, minidata);
	if (minidata->lexer_list->token == PIPE)
		return (ft_printf("ERROR PIPE"), 0); 
		//parser_error());
	return (1);
}
