/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 19:44:34 by vkorniie          #+#    #+#             */
/*   Updated: 2018/08/03 10:56:17 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <wchar.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <locale.h>
# include "libft/libft.h"
# define FS ft_strlen(s)

typedef struct		s_prin
{
	size_t			res;
	int				res2;
	unsigned int	mask0;
	unsigned int	mask1;
	unsigned int	mask2;
	unsigned int	mask3;
	unsigned int	v;
	int				counter;
	int				fl_minus;
	int				fl_plus;
	int				fl_space;
	int				fl_hash;
	int				fl_zero;
	int				width;
	int				precs;
	short int		h_size;
	short int		hh_size;
	short int		l_size;
	short int		ll_size;
	short int		j_size;
	short int		z_size;
	int				p_pr;
	int				p_wd;
	int				temp_z;
	int				t_i;
	int				pr_o;
	int				itr;
	int				sitr;
	int				check;
	va_list			*ptr;
}					t_prin;

int					ft_printf(const char *format, ...);
int					size_binary(unsigned int number);
void				d_i_qual(va_list arg_ptr, t_prin *p, char *str, int i);
void				oxu_qual(va_list arg_ptr, t_prin *p, char *str, int i);
void				p_qual(va_list arg_ptr, t_prin *p);
void				c_big_qual(char *str, int i, va_list arg_ptr, t_prin *p);
void				c_big_begin(wchar_t value, t_prin *p);
void				write_unic(unsigned char octet, wchar_t value, t_prin *p);
void				write_unica(unsigned char octet, t_prin *p);
void				write_unicc(unsigned char octet, t_prin *p);
void				write_unicb(unsigned char octet, t_prin *p);
void				dissection(char *str, int i, va_list arg_ptr, t_prin *p);
void				s_big_qual(char *str, int i, va_list arg_ptr, t_prin *p);
void				find_signs(char *s, int *i, t_prin *r);
void				struct_iniz(t_prin *r);
void				write_flags(char *p, t_prin *r);
void				find_width(char *s, int *i, t_prin *r);
void				find_precision(char *s, int *i, t_prin *r);
void				find_modif(char *s, int *i, t_prin *r);
void				l_h_mod(char *s, int *i, t_prin *r);
void				flag_writter(t_prin *p, char *s, intmax_t n);
void				find_real_p(char *s, t_prin *p);
void				find_real_w(char *s, t_prin *p, intmax_t n);
void				print_begin(char *s, t_prin *p);
void				print_cont(char *s, t_prin *p);
void				print_a(char *s, t_prin *p, intmax_t n);
void				print_b(char *s, t_prin *p);
void				print_no_wd(char *s, t_prin *p, intmax_t n);
void				printwd_no_minus(char *s, t_prin *p, intmax_t n);
void				printwd_w_minus(char *s, t_prin *p);
void				print_wdt(char *s, t_prin *p);
void				print_d_i(char *s, t_prin *p);
void				print_pr_m(char *s, t_prin *p);
void				print_no_flminus(char *s, t_prin *p);
void				print_w_flmin(char *s, t_prin *p);
void				print_pr_nm(char *s, t_prin *p);
void				print_posit_wd(char *s, t_prin *p, intmax_t n);
void				print_negat_w(char *s, t_prin *p);
void				find_base(uintmax_t n, t_prin *p, char *str, int i);
void				write_oux(t_prin *p, char *s, uintmax_t n, char *str);
void				find_wd_oux(char *s, t_prin *p);
void				print_uox_a(t_prin *p, char *str, uintmax_t n, char *s);
void				print_uox(t_prin *p, char *str, uintmax_t n, char *s);
void				print_uox_b(t_prin *p, char *str, uintmax_t n, char *s);
void				print_uox_c(t_prin *p, char *str, uintmax_t n, char *s);
void				print_uox_d(t_prin *p, char *s, uintmax_t n, char *str);
void				print_uox_e(t_prin *p, char *s, uintmax_t n, char *str);
void				print_uox_g(t_prin *p, char *s, char *str, uintmax_t n);
void				print_uox_fin(t_prin *p, char *s, uintmax_t n, char *str);
void				print_uox_ddt(t_prin *p, char *s, uintmax_t n, char *str);
void				write_oux_final(t_prin *p, uintmax_t n, char *str, char *s);
void				write_oux_ff(uintmax_t n, char *s, t_prin *p);
void				put_char_c(t_prin *p, char c);
void				write_string(t_prin *p, char *s, char *str, uintmax_t i);
void				find_w_fors(t_prin *p, char *s);
void				write_s_a(t_prin *p, char *s);
void				write_s_b(t_prin *p, char *s);
void				write_s_c(t_prin *p, char *s);
void				sbig_size(wchar_t *val, t_prin *p);
void				write_point(char *s, t_prin *p, intmax_t n);
void				write_big_s(wchar_t *ss, t_prin *p);
void				wd_for_bigs(t_prin *p, wchar_t *ss);
void				check_next(wchar_t c, t_prin *ps);
void				print_s_biig(t_prin *p, wchar_t *ss);
void				print_s_biga(wchar_t *ss, t_prin *p);
void				print_bigs_c(t_prin *p, wchar_t *ss, int res);
void				print_sbig_aa(t_prin *p, wchar_t *ss, int res);
void				print_sbig_ab(t_prin *p, wchar_t *ss, int res);
void				print_s_bigb(t_prin *p, wchar_t *ss, int res);
void				put_char_cc(t_prin *p, char c);
void				print_uox_fin(t_prin *p, char *s, uintmax_t n, char *str);
void				print_uox_f(t_prin *p, char *s, uintmax_t n, char *str);
void				write_zero_s(t_prin *p, wchar_t *ss);
void				write_point_c(char *s, t_prin *p);
void				find_perec(char *s, int *i, t_prin *p);

#endif
