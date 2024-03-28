/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:03:15 by lbouguet          #+#    #+#             */
/*   Updated: 2023/04/14 15:06:50 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	g_c = 0;

void	handle_numeric(char spec, t_Var *var, t_MyUnion *arg, va_list *next)
{
	if (spec == 'u' || spec == 'x' || spec == 'X')
		arg->ui = va_arg(*next, unsigned int);
	else
		arg->i = va_arg(*next, int);
	if (spec == 'u')
		g_c += ft_look_ui(var->format + var->pos_mod, arg->ui, 'u');
	else if (spec == 'x')
		g_c += ft_look_ui(var->format + var->pos_mod, arg->ui, 'x');
	else if (spec == 'X')
		g_c += ft_look_ui(var->format + var->pos_mod, arg->ui, 'X');
	else
		g_c += ft_look_int(var->format + var->pos_mod, arg->i);
}

void	handle_args(char spec, t_Var *var, t_MyUnion *arg, va_list *next)
{
	if (spec == 'd' || spec == 'i' || spec == 'u' || spec == 'x' || spec == 'X')
		handle_numeric(spec, var, arg, next);
	else if (spec == 'c')
	{
		arg->c = (char)va_arg(*next, int);
		g_c += ft_look_char(var->format + var->pos_mod, &arg->c, 'c');
	}
	else if (spec == 's')
	{
		arg->str = va_arg(*next, char *);
		g_c += ft_look_str(var->format + var->pos_mod, arg->str, 's');
	}
	else if (spec == 'p')
	{
		arg->lli = (long long int)va_arg(*next, void *);
		if (arg->ulli > 9223372036854775807)
			g_c += ft_look_ptr_ulli(var->format + var->pos_mod, arg->ulli, 'p');
		else
			g_c += ft_look_ptr(var->format + var->pos_mod, arg->lli, 'p');
	}
	else
		return ;
}

void	ft_init_var_glob(t_Var *p, const char *s)
{
	p->i = 0;
	p->pos_mod = 0;
	p->format = s;
	g_c = 0;
	return ;
}

void	ft_print_mod(t_Var *p)
{
	p->i += 1;
	ft_putchar(p->format[p->i]);
	g_c++;
}

int	ft_printf(const char *format, ...)
{
	va_list		next;
	t_Var		var;
	t_MyUnion	arg;

	ft_init_var_glob(&var, format);
	if (ft_count_args(var.format) == 0)
		return (g_c = ft_putformat(var.format, g_c));
	va_start(next, format);
	while (var.format[var.i] != '\0')
	{
		while (var.format[var.i] != '\0' && var.format[var.i] != '%')
			g_c += ft_putchar(var.format[var.i++]);
		var.pos_mod = var.i;
		if (var.format[var.pos_mod + 1] == '%')
			ft_print_mod(&var);
		else
			var.i = ft_spec_pos(var.format + var.pos_mod) + var.pos_mod;
		handle_args(var.format[var.i], &var, &arg, &next);
		if (var.format[var.i] != '\0')
			var.i++;
	}
	return (va_end(next), g_c);
}
