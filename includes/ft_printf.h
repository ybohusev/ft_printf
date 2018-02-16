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

# define M_HH 1
# define M_H 2
# define M_L 3
# define M_LL 4
# define M_J 5
# define M_Z 6

typedef	struct	s_flags
{
	int			minus;
	int			plus;
	int			space;
	int			hash;
	int			zero;
}				t_flags;

typedef	struct	s_specifiers
{
	t_flags		flag;
	int			width;
	int			precision;
	int			modifier;
	char		*type;
}				t_spec;

int				ft_printf(const char *format, ...);
t_flags			get_flag(char **sp);
int				get_width(char **sp);
int				get_precision(char **sp);
int				get_modifier(char **sp);
char			*get_type(char **sp);
int				work_with_dec(t_spec sp, va_list ap);
int				call_int(t_spec sp, intmax_t a);
char			*precis(char *arg, t_spec sp);
char			*width(t_spec sp, char *arg);
char			*sign_int(char *arg, char *tmp, t_spec sp, int a);
int				work_with_uns(t_spec sp, va_list ap);
int				call_uint(t_spec sp, uintmax_t a);
char			*hash_uint(char *arg, t_spec sp, int bwidth);
int				work_with_char(t_spec sp, va_list ap);
int				call_char(t_spec sp, unsigned int a);
int				char_width(t_spec sp, int bytes);
int				print_symbol(char *ch, t_spec sp);
int				work_with_str(t_spec sp, va_list ap);
int				handle_btwper(t_spec sp);

#endif
