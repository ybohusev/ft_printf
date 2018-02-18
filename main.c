/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 13:07:26 by ybohusev          #+#    #+#             */
/*   Updated: 2018/02/18 13:19:58 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <limits.h>

int	main(void)
{
	int		a;
	int		b;

	setlocale(LC_ALL, "en_US.UTF-8");
	printf("-----------------------------\n");
	a = ft_printf("%c", 'q');
	printf("\n-----------------------------\n");
	b = printf("%c", 'q');
	printf("\n-----------------------------\n");
	printf("my - %d, standart - %d", a, b);
	printf("\n-----------------------------\n");
	return (0);
}
