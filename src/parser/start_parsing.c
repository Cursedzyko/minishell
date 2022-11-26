/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:40:14 by zyunusov          #+#    #+#             */
/*   Updated: 2022/11/26 16:14:47 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	start_parser(t_minidata *minidata)
{
	count_pipes(minidata->lexer_l, minidata);
	if (minidata->lexer_l->token == PIPE)
		return (parser_token_error(minidata, minidata->lexer_l,
				minidata->lexer_l->token));
	return (1);
}
