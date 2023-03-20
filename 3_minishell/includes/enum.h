/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwsong <kwsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:36:40 by kwsong            #+#    #+#             */
/*   Updated: 2023/03/07 16:43:31 by kwsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

typedef enum e_token_type
{
	DLESS,
	DGREAT,
	LESS,
	GREAT,
	PIPE,
	WORD,
	CMD,
	FILE_NAME,
	FAIL = 100
}	t_token_type;

typedef enum e_null
{
	NULL_POINTER,
	NULL_CHAR,
	NOT_NULL
}	t_null;

typedef enum e_in_quote
{
	NONE,
	SINGLE,
	DOUBLE
}	t_in_quote;

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef enum e_fd
{
	READ,
	WRITE,
}	t_fd;

typedef enum e_evr_state
{
	EVR_NORMAL,
	EVR_ENV,
	EVR_SQUOTE,
	EVR_DQUOTE,
	EVR_END,
	EVR_FAIL,
	SIZE_OF_STATE
}			t_evr_state;

typedef enum e_evr_input_type
{
	ALNUM,
	DOLLAR,
	SQUOTE,
	DQUOTE,
	SPECIAL,
	NULL_CH,
	SIZE_OF_INPUT
}			t_input_type;

typedef enum e_signal
{
	SUCCESS = 0,
	ARG_ERROR = 1,
	CMD_FAIL = 127,
	EXIT_ON_SIGNAL = 130,
	NUM_REQUIRED = 255,
	SYNTAX_ERROR = 258
}			t_signal;

#endif
