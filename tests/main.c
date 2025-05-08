/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manupc <manupc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:32:12 by manupc            #+#    #+#             */
/*   Updated: 2025/05/07 20:08:02 by manupc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int g_result = 1;

void ft_ok(int condition, const char *test_name)
{
	if (condition)
		printf("\033[0;32m[OK]\033[0m %s\n", test_name);
	else
	{
		printf("\033[0;31m[KO]\033[0m %s\n", test_name);
		g_result = 0;
	}
}

// Redirige stdout a archivo, ejecuta printf-like y captura salida en string
char *capture_output(int (*func)(void), int *ret)
{
	int		pipe_fd[2];
	char	buffer[4096];
	int		n;
	char	*out;

	fflush(stdout);
	pipe(pipe_fd);
	int saved_stdout = dup(1);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);

	*ret = func();

	fflush(stdout);
	dup2(saved_stdout, 1);
	close(saved_stdout);

	n = read(pipe_fd[0], buffer, sizeof(buffer) - 1);
	buffer[n] = '\0';
	close(pipe_fd[0]);

	out = strdup(buffer);
	return (out);
}

// ======================== TEST: %c ============================= //

int test_printf_char_basic(void)  { return printf("char: [%c]\n", 'A'); }
int test_ft_printf_char_basic(void) { return ft_printf("char: [%c]\n", 'A'); }

int test_printf_char_null(void)  { return printf("char: [%c]\n", '\0'); }
int test_ft_printf_char_null(void) { return ft_printf("char: [%c]\n", '\0'); }

int test_printf_char_neg(void)  { return printf("char: [%c]\n", -1); }
int test_ft_printf_char_neg(void) { return ft_printf("char: [%c]\n", -1); }

int test_printf_char_big(void)  { return printf("char: [%c]\n", 128); }
int test_ft_printf_char_big(void) { return ft_printf("char: [%c]\n", 128); }

int test_printf_char_multi(void)  { return printf("char: [%c%c%c]\n", 'a', 'b', 'c'); }
int test_ft_printf_char_multi(void) { return ft_printf("char: [%c%c%c]\n", 'a', 'b', 'c'); }

void test_char(void)
{
	printf("\033[38;5;214m[TEST %%c - print_char]\033[0m\n");

	int r1, r2;
	char *s1, *s2;

	// Caso básico
	s1 = capture_output(test_printf_char_basic, &r1);
	s2 = capture_output(test_ft_printf_char_basic, &r2);
	ft_ok(strcmp(s1, s2) == 0, "Caso normal 'A'");
	ft_ok(r1 == r2, "Valor devuelto (caso normal)");
	free(s1); free(s2);

	// Carácter nulo
	s1 = capture_output(test_printf_char_null, &r1);
	s2 = capture_output(test_ft_printf_char_null, &r2);
	ft_ok(strcmp(s1, s2) == 0, "Carácter nulo (\\0)");
	ft_ok(r1 == r2, "Valor devuelto (\\0)");
	free(s1); free(s2);

	// Carácter negativo
	s1 = capture_output(test_printf_char_neg, &r1);
	s2 = capture_output(test_ft_printf_char_neg, &r2);
	ft_ok(strcmp(s1, s2) == 0, "Carácter negativo (-1)");
	ft_ok(r1 == r2, "Valor devuelto (-1)");
	free(s1); free(s2);

	// Carácter > 127
	s1 = capture_output(test_printf_char_big, &r1);
	s2 = capture_output(test_ft_printf_char_big, &r2);
	ft_ok(strcmp(s1, s2) == 0, "Carácter > 127");
	ft_ok(r1 == r2, "Valor devuelto (>127)");
	free(s1); free(s2);

	// Varios caracteres seguidos
	s1 = capture_output(test_printf_char_multi, &r1);
	s2 = capture_output(test_ft_printf_char_multi, &r2);
	ft_ok(strcmp(s1, s2) == 0, "Varios %c seguidos");
	ft_ok(r1 == r2, "Valor devuelto (varios)");
	free(s1); free(s2);

	printf("\n");
}


// ======================== MAIN ============================= //

int main(void)
{
	test_char();

	if (g_result)
		printf("\n\033[0;32m✅ TODOS LOS TESTS PASADOS\033[0m\n\n");
	else
		printf("\n\033[0;31m❌ ALGÚN TEST HA FALLADO\033[0m\n\n");

	return (0);
}

