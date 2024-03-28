/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:02:46 by lbouguet          #+#    #+#             */
/*   Updated: 2023/04/14 15:52:13 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# ifndef TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif
# ifndef FOUND
#  define FOUND 1
# endif
# ifndef FREE
#  define FREE 0
# endif
# ifndef ULL
#  define ULL unsigned long long
# endif
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_Var_width
{
	int			i;
	int			j;
	char		*width_char;
}				t_Vw;

typedef struct s_Var
{
	int			i;
	int			pos_mod;
	const char	*format;
}				t_Var;

typedef union Arg
{
	int						i;
	long long int			lli;
	unsigned int			ui;
	unsigned long long int	ulli;
	void					*p;
	char					*str;
	char					c;
}							t_MyUnion;

typedef struct s_Lol
{
	int						zero;
	int						space;
	int						padding;
}							t_Lol;
typedef struct s_Los
{
	int						bfp;
	int						afp;
	int						padding;
	int						nb;
	int						nb_signed;
}							t_Los;

typedef struct s_Lof
{
	int						zero;
	int						plus;
	int						hashtag_min;
	int						hashtag_maj;
	int						precis;
	int						space;
	int						hyphen;
}							t_Lof;
typedef struct s_Lists
{
	t_Los	los;
	t_Lof	lof;
	t_Lol	lol;
}			t_lists;

int		ft_printf(const char *format, ...);
int		ft_atoi(const char *str);
int		ft_atoi_printf(int nb, const char *flag);
int		ft_char_cmp(char src, char cmp);
char	ft_conv_id(char *str);
int		ft_count_args(const char *format);
char	ft_checkid_conv_spec(char *str);
char	ft_checkid_flags(char *str);
int		ft_checkid_width(char *brut);
int		ft_count_digits(long long int arg);
int		ft_count_only_digits(long long int arg);
void	ft_clean(char **tab);
int		ft_look_through_ui(const char *brut_data, unsigned int arg, char conv);
int		ft_flag_detect(t_Lof *lof);
void	ft_format_spec(const char *brut_data, int conv);
void	ft_flag(const char *brut, t_Lof *lof, char conv);
char	*ft_go_to_conv(const char *brut_data);
int		ft_look_through_int(const char *brut_data, int arg);
//char	*ft_itoa(long long int n);
//char	*ft_litoa(long long int n);
int		ft_nbchar(long long int n);
void	ft_process_int(t_Lof *flag, t_Los *width, int arg);
void	ft_printf_format_spec(int conv, int pad, char *raw);
int		ft_putchar(char a);
int		ft_putformat(const char *str, int global_count);
int		ft_char_conv_id(char a);
void	ft_putstr_free(char *str);
char	*ft_dec_to_hex_lli(long long int dec, char conv);
//char	*ft_memset(char *ptr, char c, size_t n);
void	ft_putlenchar(char to_print, int len);
char	ft_sign(int nb);
size_t	ft_strlen(const char *s);
size_t	ft_strlen_tab(const char **tab);
size_t	ft_strlen_break(const char *s, char *stop);
int		ft_strlen_p_brut(const char *str);
int		ft_strlen_arg(int n);
//char	*ft_strdup(char *source);
char	*ft_strdup_bytes_free(char *source, int n);
void	ft_width(const char *brut, t_Los *width, t_Lof *flag);
int		ft_spec_pos(const char *format);
char	*ft_itoa_unsigned(int n);
char	*ft_itoa_ui(unsigned int n);
void	ft_sort_char(t_Lof *flag, t_Los *width, char *arg, t_Lol *len);
void	ft_sort_ui(t_Lof *flag, t_Los *width, t_Lol *len);
void	ft_sort_int(t_Lof *flag, t_Los *width, t_Lol *len, int arg);
void	ft_sort_ui_hexa(t_Lof *flag, t_Los *width, char *arg, t_Lol *len);
void	ft_sort_str(t_Lof *flag, t_Los *width, char *arg, t_Lol *len);
void	ft_sort_ptr(t_Lof *flag, t_Los *width, char *arg, t_Lol *len);
void	ft_print_ptr(t_Lof *flag, t_Los *width, t_Lol *len, char *arg);
void	ft_print_str(t_Lof *flag, t_Los *width, t_Lol *len, char *arg);
void	ft_print_char(t_Lof *flag, t_Los *width, t_Lol *len, char *arg);
void	ft_print_ui(t_Lof *flag, t_Los *width, t_Lol *len, unsigned int arg);
void	ft_print_int(t_Lof *flag, t_Los *width, t_Lol *len, int arg);
void	ft_print_ui_hexa(t_Lof *flag, t_Los *width, t_Lol *len, char *arg);
int		ft_look_ptr(const char *brut_data, long long int arg, char conv);
int		ft_look_ptr_ulli(const char *brut_data, ULL arg, char conv);
int		ft_look_str(const char *brut_data, char *arg, char conv);
int		ft_look_char(const char *brut_data, char *arg, char conv);
int		ft_look_ui_hexa(const char *brut_data, char *arg, char conv);
int		ft_look_int(const char *brut_data, int a);
int		ft_look_ui(const char *brut_data, unsigned int arg, char conv);
char	*ft_dec_to_hex_ulli(unsigned long long int dec, char conv);
char	*ft_dec_to_hex(unsigned int dec, char conv);
char	ft_itoa_hexa_maj(unsigned int n);
char	ft_itoa_hexa_min(unsigned int n);
void	ft_putstr(char *str);
char	*ft_itoa_ui(unsigned int n);
int		ft_nbchar_unsigned(long long int n);
void	ft_str_reverse(char *str);
#endif