/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:34:59 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/01 14:50:34 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_error_dispatch	g_error_dispatch[NB_ERRORS] = {
{ERRNUM_ARGS, ERRMSG_ARGS},
{ERRNUM_FILE, ERRMSG_FILE},
{ERRNUM_ID, ERRMSG_ID},
{ERRNUM_RANGE, ERRMSG_RANGE},
{ERRNUM_UNIT, ERRMSG_UNIT},
{ERRNUM_SPECS, ERRMSG_SPECS},
{ERRNUM_SCENE, ERRMSG_SCENE},
{ERRNUM_FORMAT, ERRMSG_FORMAT}
};

static void	handle_buf_overflow(char *buf)
{
	buf += (ERR_BUFSIZE - 5);
	ft_strlcpy(buf, "...\n", ERR_BUFSIZE);
}

int	mrt_error(char *(*f)(int), int errnum, const char *msg)
{
	static char	buf[ERR_BUFSIZE];
	char		*errstr;
	size_t		ret;

	ft_bzero(buf, ERR_BUFSIZE);
	ret = ft_strlcat(buf, "Error\n", ft_strlen("Error\n") + 1);
	if (msg)
		ret += ft_strlcat(buf, (char *)msg,
				ft_strlen(buf) + ft_strlen((char *)msg) + 1);
	errstr = f(errnum);
	if (errstr)
	{
		if (msg)
			ret += ft_strlcat(buf, ": ", ft_strlen(buf) + ft_strlen(": ") + 1);
		ret += ft_strlcat(buf, errstr, ft_strlen(buf) + ft_strlen(errstr) + 1);
	}
	ret += ft_strlcat(buf, "\n", ft_strlen(buf) + ft_strlen("\n") + 1);
	if (ret >= ERR_BUFSIZE)
		handle_buf_overflow(buf);
	write(STDERR_FILENO, buf, ft_strlen(buf));
	return (false);
}

char	*mrt_strerror(int errnum)
{
	size_t	i;

	i = 0;
	while (i < NB_ERRORS)
	{
		if (errnum == g_error_dispatch[i].errnum)
			return (g_error_dispatch[i].errmsg);
		i++;
	}
	return (NULL);
}

static void	int_to_str(int n, char s[12])
{
	size_t	i;
	long	nb;

	ft_bzero(s, 12);
	nb = n;
	if (n < 0)
		nb = -nb;
	i = ft_get_num_len(nb, 10);
	if (n < 0)
		i++;
	s[i] = '\0';
	if (n < 0)
		s[0] = '-';
	while (nb >= 0)
	{
		i--;
		s[i] = (nb % 10) + '0';
		nb /= 10;
		if (nb == 0)
			break ;
	}
}

int	mrt_parse_error(int errnum, int line_nb, const char *msg)
{
	static char	buf[ERR_BUFSIZE];
	char		*errstr;
	char		tmp[12];
	size_t		ret;

	ft_bzero(buf, ERR_BUFSIZE);
	ret = ft_strlcat(buf, "Error\nline ", ft_strlen("Error\nline ") + 1);
	int_to_str(line_nb, tmp);
	ret += ft_strlcat(buf, tmp, ft_strlen(buf) + ft_strlen(tmp) + 1);
	ret += ft_strlcat(buf, ": ", ft_strlen(buf) + ft_strlen(": ") + 1);
	if (msg)
	{
		ret += ft_strlcat(buf, (char *)msg,
				ft_strlen(buf) + ft_strlen((char *)msg) + 1);
		ret += ft_strlcat(buf, ": ", ft_strlen(buf) + ft_strlen(": ") + 1);
	}
	errstr = mrt_strerror(errnum);
	if (errstr)
		ret += ft_strlcat(buf, errstr, ft_strlen(buf) + ft_strlen(errstr) + 1);
	ret += ft_strlcat(buf, "\n", ft_strlen(buf) + ft_strlen("\n") + 1);
	if (ret >= ERR_BUFSIZE)
		handle_buf_overflow(buf);
	write(STDERR_FILENO, buf, ft_strlen(buf));
	return (false);
}
