/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiestre <mdiestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:39:30 by mdiestre          #+#    #+#             */
/*   Updated: 2025/05/29 10:49:10 by mdiestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>


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
char *capture_output_to_file(int (*func)(void), int *ret)
{
	const char *filename = "tmp_output.txt";
	int saved_stdout = dup(1);
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return NULL;

	dup2(fd, 1);
	close(fd);

	*ret = func();

	fflush(stdout);
	dup2(saved_stdout, 1);
	close(saved_stdout);

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return NULL;

	// Obtener tamaño del archivo
	off_t size = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);

	char *buffer = malloc(size + 1);
	if (!buffer)
		return NULL;

	ssize_t n = read(fd, buffer, size);
	close(fd);
	unlink(filename);

	if (n < 0)
		return NULL;

	buffer[n] = '\0';
	return buffer;
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
	s1 = capture_output_to_file(test_printf_char_basic, &r1);
	s2 = capture_output_to_file(test_ft_printf_char_basic, &r2);
	ft_ok(strcmp(s1, s2) == 0, "Caso normal 'A'");
	ft_ok(r1 == r2, "Valor devuelto ('A')");
	free(s1); free(s2);

	// Carácter nulo
	s1 = capture_output_to_file(test_printf_char_null, &r1);
	s2 = capture_output_to_file(test_ft_printf_char_null, &r2);
	ft_ok(strcmp(s1, s2) == 0, "Carácter nulo (\\0)");
	ft_ok(r1 == r2, "Valor devuelto (\\0)");
	free(s1); free(s2);

	// Carácter negativo
	s1 = capture_output_to_file(test_printf_char_neg, &r1);
	s2 = capture_output_to_file(test_ft_printf_char_neg, &r2);
	ft_ok(strcmp(s1, s2) == 0, "Carácter negativo (-1)");
	ft_ok(r1 == r2, "Valor devuelto (-1)");
	free(s1); free(s2);

	// Carácter > 127
	s1 = capture_output_to_file(test_printf_char_big, &r1);
	s2 = capture_output_to_file(test_ft_printf_char_big, &r2);
	ft_ok(strcmp(s1, s2) == 0, "Carácter > 127 (128)");
	ft_ok(r1 == r2, "Valor devuelto (128)");
	free(s1); free(s2);

	// Varios caracteres seguidos
	s1 = capture_output_to_file(test_printf_char_multi, &r1);
	s2 = capture_output_to_file(test_ft_printf_char_multi, &r2);
	ft_ok(strcmp(s1, s2) == 0, "Varios %c seguidos");
	ft_ok(r1 == r2, "Valor devuelto (varios)");
	free(s1); free(s2);

	printf("\n");
}

// ======================== TEST: %str ============================= //

int test_printf_str_basic(void)  { return printf("str: [%s]\n", "Hola"); }
int test_ft_printf_str_basic(void) { return ft_printf("str: [%s]\n", "Hola"); }

int test_printf_str_null(void)  { return printf("str: [%s]\n", (char *)NULL); }
int test_ft_printf_str_null(void) { return ft_printf("str: [%s]\n", (char *)NULL); }

int test_printf_str_empty(void)  { return printf("str: [%s]\n", ""); }
int test_ft_printf_str_empty(void) { return ft_printf("str: [%s]\n", ""); }

int test_printf_str_multi(void)  { return printf("str: [%s|%s|%s]\n", "uno", "dos", "tres"); }
int test_ft_printf_str_multi(void) { return ft_printf("str: [%s|%s|%s]\n", "uno", "dos", "tres"); }

void test_str(void)
{
	printf("\033[38;5;214m[TEST %%s - print_str]\033[0m\n");

	int r1, r2;
	char *s1, *s2;

	// Caso básico
	s1 = capture_output_to_file(test_printf_str_basic, &r1);
	s2 = capture_output_to_file(test_ft_printf_str_basic, &r2);
	ft_ok(strcmp(s1, s2) == 0, "Cadena normal \"Hola\"");
	ft_ok(r1 == r2, "Valor devuelto (Hola)");
	free(s1); free(s2);

	// NULL
	s1 = capture_output_to_file(test_printf_str_null, &r1);
	s2 = capture_output_to_file(test_ft_printf_str_null, &r2);
	ft_ok(strcmp(s1, s2) == 0, "Cadena NULL");
	ft_ok(r1 == r2, "Valor devuelto (NULL)");
	free(s1); free(s2);

	// Vacía
	s1 = capture_output_to_file(test_printf_str_empty, &r1);
	s2 = capture_output_to_file(test_ft_printf_str_empty, &r2);
	ft_ok(strcmp(s1, s2) == 0, "Cadena vacía");
	ft_ok(r1 == r2, "Valor devuelto (\"\")");
	free(s1); free(s2);

	// Múltiples strings
	s1 = capture_output_to_file(test_printf_str_multi, &r1);
	s2 = capture_output_to_file(test_ft_printf_str_multi, &r2);
	ft_ok(strcmp(s1, s2) == 0, "Varios %s seguidos");
	ft_ok(r1 == r2, "Valor devuelto (multi)");
	free(s1); free(s2);

	printf("\n");
}


// ======================== TEST: %i %d ============================= //

int test_printf_int_zero(void)     { return printf("int: [%d]\n", 0); }
int test_ft_printf_int_zero(void)  { return ft_printf("int: [%d]\n", 0); }

int test_printf_int_pos(void)      { return printf("int: [%d]\n", 42); }
int test_ft_printf_int_pos(void)   { return ft_printf("int: [%d]\n", 42); }

int test_printf_int_neg(void)      { return printf("int: [%d]\n", -42); }
int test_ft_printf_int_neg(void)   { return ft_printf("int: [%d]\n", -42); }

int test_printf_int_max(void)      { return printf("int: [%d]\n", INT_MAX); }
int test_ft_printf_int_max(void)   { return ft_printf("int: [%d]\n", INT_MAX); }

int test_printf_int_min(void)      { return printf("int: [%d]\n", INT_MIN); }
int test_ft_printf_int_min(void)   { return ft_printf("int: [%d]\n", INT_MIN); }

int test_printf_int_multiple(void) { return printf("ints: [%d %i %d]\n", 1, -2, 123456); }
int test_ft_printf_int_multiple(void) { return ft_printf("ints: [%d %i %d]\n", 1, -2, 123456); }

void test_int(void)
{
	printf("\033[38;5;214m[TEST %%d / %%i - print_int]\033[0m\n");

	int r1, r2;
	char *s1, *s2;

	// 0
	s1 = capture_output_to_file(test_printf_int_zero, &r1);
	s2 = capture_output_to_file(test_ft_printf_int_zero, &r2);
	ft_ok(strcmp(s1, s2) == 0, "Entero 0");
	ft_ok(r1 == r2, "Valor devuelto (0)");
	free(s1); free(s2);

	// Positivo
	s1 = capture_output_to_file(test_printf_int_pos, &r1);
	s2 = capture_output_to_file(test_ft_printf_int_pos, &r2);
	ft_ok(strcmp(s1, s2) == 0, "Entero positivo 42");
	ft_ok(r1 == r2, "Valor devuelto (42)");
	free(s1); free(s2);

	// Negativo
	s1 = capture_output_to_file(test_printf_int_neg, &r1);
	s2 = capture_output_to_file(test_ft_printf_int_neg, &r2);
	ft_ok(strcmp(s1, s2) == 0, "Entero negativo -42");
	ft_ok(r1 == r2, "Valor devuelto (-42)");
	free(s1); free(s2);

	// INT_MAX
	s1 = capture_output_to_file(test_printf_int_max, &r1);
	s2 = capture_output_to_file(test_ft_printf_int_max, &r2);
	ft_ok(strcmp(s1, s2) == 0, "INT_MAX");
	ft_ok(r1 == r2, "Valor devuelto (INT_MAX)");
	free(s1); free(s2);

	// INT_MIN
	s1 = capture_output_to_file(test_printf_int_min, &r1);
	s2 = capture_output_to_file(test_ft_printf_int_min, &r2);
	ft_ok(strcmp(s1, s2) == 0, "INT_MIN");
	ft_ok(r1 == r2, "Valor devuelto (INT_MIN)");
	free(s1); free(s2);

	// Múltiples ints
	s1 = capture_output_to_file(test_printf_int_multiple, &r1);
	s2 = capture_output_to_file(test_ft_printf_int_multiple, &r2);
	ft_ok(strcmp(s1, s2) == 0, "Varios %d y %i");
	ft_ok(r1 == r2, "Valor devuelto (múltiples)");
	free(s1); free(s2);

	printf("\n");
}

// ======================== TEST: UNSIGNED ============================= //
int test_printf_u_zero(void)      { return printf("u: [%u]\n", 0); }
int test_ft_printf_u_zero(void)   { return ft_printf("u: [%u]\n", 0); }

int test_printf_u_42(void)        { return printf("u: [%u]\n", 42); }
int test_ft_printf_u_42(void)     { return ft_printf("u: [%u]\n", 42); }

int test_printf_u_max(void)       { return printf("u: [%u]\n", UINT_MAX); }
int test_ft_printf_u_max(void)    { return ft_printf("u: [%u]\n", UINT_MAX); }

int test_printf_u_multi(void)     { return printf("u: [%u %u %u]\n", 1, 9999, UINT_MAX); }
int test_ft_printf_u_multi(void)  { return ft_printf("u: [%u %u %u]\n", 1, 9999, UINT_MAX); }

void test_unsigned(void)
{
	printf("\033[38;5;214m[TEST %%u - ft_print_unsigned]\033[0m\n");

	int r1, r2;
	char *s1, *s2;

	// 0
	s1 = capture_output_to_file(test_printf_u_zero, &r1);
	s2 = capture_output_to_file(test_ft_printf_u_zero, &r2);
	ft_ok(strcmp(s1, s2) == 0, "Unsigned 0");
	ft_ok(r1 == r2, "Valor devuelto (0)");
	free(s1); free(s2);

	// 42
	s1 = capture_output_to_file(test_printf_u_42, &r1);
	s2 = capture_output_to_file(test_ft_printf_u_42, &r2);
	ft_ok(strcmp(s1, s2) == 0, "Unsigned 42");
	ft_ok(r1 == r2, "Valor devuelto (42)");
	free(s1); free(s2);

	// UINT_MAX
	s1 = capture_output_to_file(test_printf_u_max, &r1);
	s2 = capture_output_to_file(test_ft_printf_u_max, &r2);
	ft_ok(strcmp(s1, s2) == 0, "Unsigned UINT_MAX");
	ft_ok(r1 == r2, "Valor devuelto (UINT_MAX)");
	free(s1); free(s2);

	// Varios %u seguidos
	s1 = capture_output_to_file(test_printf_u_multi, &r1);
	s2 = capture_output_to_file(test_ft_printf_u_multi, &r2);
	ft_ok(strcmp(s1, s2) == 0, "Varios %u seguidos");
	ft_ok(r1 == r2, "Valor devuelto (multi)");
	free(s1); free(s2);

	printf("\n");
}

// ======================== TEST: HEX ============================= //

int test_printf_hex_lower(void)  { return printf("hex: [%x]\n", 255); }
int test_ft_printf_hex_lower(void) { return ft_printf("hex: [%x]\n", 255); }

int test_printf_hex_upper(void)  { return printf("hex: [%X]\n", 255); }
int test_ft_printf_hex_upper(void) { return ft_printf("hex: [%X]\n", 255); }

int test_printf_hex_zero(void)  { return printf("hex: [%x]\n", 0); }
int test_ft_printf_hex_zero(void) { return ft_printf("hex: [%x]\n", 0); }

int test_printf_hex_multi(void)  { return printf("hex: [%x %X %x]\n", 10, 28, UINT_MAX); }
int test_ft_printf_hex_multi(void) { return ft_printf("hex: [%x %X %x]\n", 10, 28, UINT_MAX); }

void test_hex(void)
{
	printf("\033[38;5;214m[TEST %%x / %%X - ft_print_hex]\033[0m\n");

	int r1, r2;
	char *s1, *s2;

	// %x lowercase
	s1 = capture_output_to_file(test_printf_hex_lower, &r1);
	s2 = capture_output_to_file(test_ft_printf_hex_lower, &r2);
	ft_ok(strcmp(s1, s2) == 0, "255 → %x (lowercase)");
	ft_ok(r1 == r2, "Valor devuelto (%x)");
	free(s1); free(s2);

	// %X uppercase
	s1 = capture_output_to_file(test_printf_hex_upper, &r1);
	s2 = capture_output_to_file(test_ft_printf_hex_upper, &r2);
	ft_ok(strcmp(s1, s2) == 0, "255 → %X (uppercase)");
	ft_ok(r1 == r2, "Valor devuelto (%X)");
	free(s1); free(s2);

	// %x con 0
	s1 = capture_output_to_file(test_printf_hex_zero, &r1);
	s2 = capture_output_to_file(test_ft_printf_hex_zero, &r2);
	ft_ok(strcmp(s1, s2) == 0, "0 → %x");
	ft_ok(r1 == r2, "Valor devuelto (0)");
	free(s1); free(s2);

	// varios %x y %X
	s1 = capture_output_to_file(test_printf_hex_multi, &r1);
	s2 = capture_output_to_file(test_ft_printf_hex_multi, &r2);
	ft_ok(strcmp(s1, s2) == 0, "Varios %x y %X");
	ft_ok(r1 == r2, "Valor devuelto (multi)");
	free(s1); free(s2);

	printf("\n");
}
// ======================== TEST: %p ============================= //

int test_ft_printf_ptr_null(void) { return ft_printf("ptr: [%p]\n", NULL); }

int test_ft_printf_ptr_real(void)
{
	int x = 42;
	return ft_printf("ptr: [%p]\n", &x);
}

int test_ft_printf_ptr_multi(void)
{
	int a = 1, b = 2;
	return ft_printf("ptrs: [%p %p]\n", &a, &b);
}

void test_ptr(void)
{
	printf("\033[38;5;214m[TEST %%p - ft_print_ptr]\033[0m\n");

	int r;
	char *s;

	// NULL
	s = capture_output_to_file(test_ft_printf_ptr_null, &r);
	ft_ok(strcmp(s, "ptr: [0x0]\n") == 0, "Puntero NULL → 0x0");
	ft_ok(r == 11, "Valor devuelto (NULL)");
	free(s);

	// Dirección de variable local (relajado, solo que empieza por "ptr: [0x")
	s = capture_output_to_file(test_ft_printf_ptr_real, &r);
	ft_ok(strncmp(s, "ptr: [0x", 8) == 0, "Dirección de variable local (empieza por 0x)");
	ft_ok(r > 10, "Valor devuelto (puntero no NULL)");
	free(s);

	// Múltiples punteros (relajado también)
	s = capture_output_to_file(test_ft_printf_ptr_multi, &r);
	ft_ok(strncmp(s, "ptrs: [0x", 9) == 0, "Varios punteros %p seguidos (empieza por 0x)");
	ft_ok(r > 20, "Valor devuelto (multi punteros)");
	free(s);

	printf("\n");
}

// ======================== TEST: %% ============================= //

int test_ft_printf_percent_simple(void) { return ft_printf("percent: [%%]\n"); }

int test_ft_printf_percent_multi(void) { return ft_printf("percent: [%%%%]\n"); }

void test_percent(void)
{
	printf("\033[38;5;214m[TEST %% - ft_printf]\033[0m\n");

	int r;
	char *s;

	// Caso simple
	s = capture_output_to_file(test_ft_printf_percent_simple, &r);
	ft_ok(strcmp(s, "percent: [%]\n") == 0, "Caso simple %%");
	ft_ok(r == 13, "Valor devuelto (simple)");
	free(s);

	// Caso doble (debe imprimir dos %)
	s = capture_output_to_file(test_ft_printf_percent_multi, &r);
	ft_ok(strcmp(s, "percent: [%%]\n") == 0, "Caso doble (%%%%)");
	ft_ok(r == 14, "Valor devuelto (doble)");
	free(s);

	printf("\n");
}

// ======================== MAIN ============================= //

int main(void)
{
	test_char();
	test_str();
	test_int();
	test_unsigned();
	test_hex();
	test_ptr();
	test_percent();

	if (g_result)
		printf("\n\033[0;32m✅ TODOS LOS TESTS PASADOS\033[0m\n\n");
	else
		printf("\n\033[0;31m❌ ALGÚN TEST HA FALLADO\033[0m\n\n");

	return (0);
}

