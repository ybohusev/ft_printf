/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:46:34 by ybohusev          #+#    #+#             */
/*   Updated: 2018/01/22 14:46:36 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <stdio.h>

typedef	struct	s_specifiers
{
	t_flags		flag;
	int			width;
	int			precision;
	char		*modifier;
	char		*type;
}				t_spec;

typedef	struct	s_flags
{
	int			minus;
	int			plus;
	int			space;
	int			hash;
	int			zero;
}				t_flags;


void			ft_printf(const char *format, ...);
char			*get_flag(char **sp);
int				get_width(char **sp);
int				get_precision(char **sp);
char			*get_modifier(char **sp);
char			*get_type(char **sp);
int				work_with_dec(t_spec sp, va_list ap);

#endif
