/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiestre <mdiestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:45:56 by mdiestre          #+#    #+#             */
/*   Updated: 2025/05/20 11:17:28 by mdiestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int	g_result = 1;

void	ft_ok(int condition, const char *test_name)
{
	if (condition)
		printf("\033[0;32m[OK]\033[0m %s\n", test_name);
	else
	{
		printf("\033[0;31m[KO]\033[0m %s\n", test_name);
		g_result = 0;
	}
}

void	test_case(const char *desc, const char *format, char expected_conv, t_flags expected_flags)
{
	t_flags flags;
	const char *conversion = parse_flags(format, &flags);

	printf("\033[38;5;214m[TEST] %s\033[0m\n", desc);
	ft_ok(*conversion == expected_conv, "Conversion detectada correctamente");

	ft_ok(flags.minus == expected_flags.minus, "Flag '-'");
	ft_ok(flags.zero == expected_flags.zero, "Flag '0'");
	ft_ok(flags.width == expected_flags.width, "Width");
	ft_ok(flags.dot == expected_flags.dot, "Flag '.'");
	ft_ok(flags.precision == expected_flags.precision, "Precision");
	ft_ok(flags.hash == expected_flags.hash, "Flag '#'");
	ft_ok(flags.plus == expected_flags.plus, "Flag '+'");
	ft_ok(flags.space == expected_flags.space, "Flag ' '");
	printf("\n");
}
void	test_print_int_case(const char *desc, int n, t_flags flags, const char *expected)
{
	char	buffer[100];
	int		saved_stdout = dup(1);
	int		fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	printf("\033[38;5;214m[TEST] %s\033[0m\n", desc);

	dup2(fd, 1); // redirige stdout a archivo temporal
	ft_print_int_bonus(n, &flags);
	close(fd);
	dup2(saved_stdout, 1); // restauramos stdout

	fd = open("test_output.txt", O_RDONLY);
	int bytes = read(fd, buffer, 99);
	buffer[bytes] = '\0';
	close(fd);

	ft_ok(strncmp(buffer, expected, strlen(expected)) == 0, "Resultado correcto");
	printf("Output:    [%s]\n", buffer);
	printf("Esperado:  [%s]\n\n", expected);
}

void	test_parse_flags(void)
{
	printf("===============================================\n");
	printf(" TEST BONUS - PARSE FLAGS\n");
	printf("===============================================\n\n");

	test_case("Caso completo '-0# +8.5d'", "-0# +8.5d", 'd',
		(t_flags){1, 1, 8, 5, 1, 1, 1, 1});
	
	test_case("Solo ancho y precision '10.3d'", "10.3d", 'd',
		(t_flags){0, 0, 10, 3, 1, 0, 0, 0});
	
	test_case("Solo flags combinados '-0+ #d'", "-0+ #d", 'd',
		(t_flags){1, 1, 0, 0, 0, 1, 1, 1});
	
	test_case("Solo precision '.4s'", ".4s", 's',
		(t_flags){0, 0, 0, 4, 1, 0, 0, 0});
	
	test_case("Caso sin flags ni precision 'd'", "d", 'd',
		(t_flags){0, 0, 0, 0, 0, 0, 0, 0});
}

void	test_print_int(void)
{
	printf("===============================================\n");
	printf(" TEST BONUS - PRINT INT\n");
	printf("===============================================\n\n");

	test_print_int_case("1. Width con cero padding (\"%08d\", 42)",
		42, (t_flags){0, 1, 8, 0, 0, 0, 0, 0}, "00000042");

	test_print_int_case("2. Width y precision (\"%8.4d\", 42)",
		42, (t_flags){0, 0, 8, 4, 1, 0, 0, 0}, "    0042");

	test_print_int_case("3. Alineado a la izquierda (\"%-8d\", 42)",
		42, (t_flags){1, 0, 8, 0, 0, 0, 0, 0}, "42      ");

	test_print_int_case("4. Solo precision (\"%.4d\", 42)",
		42, (t_flags){0, 0, 0, 4, 1, 0, 0, 0}, "0042");

	test_print_int_case("5. Flag + (\"%+d\", 42)",
		42, (t_flags){0, 0, 0, 0, 0, 0, 1, 0}, "+42");

	test_print_int_case("6. Flag espacio (\"% d\", 42)",
		42, (t_flags){0, 0, 0, 0, 0, 0, 0, 1}, " 42");

	test_print_int_case("7. Flag + con ancho (\"%+6d\", 42)",
		42, (t_flags){0, 0, 6, 0, 0, 0, 1, 0}, "   +42");

	test_print_int_case("8. Número negativo con precision (\"%8.4d\", -42)",
		-42, (t_flags){0, 0, 8, 4, 1, 0, 0, 0}, "   -0042");

	test_print_int_case("9. Zero + precision (debe ignorar 0)",
		42, (t_flags){0, 1, 8, 4, 1, 0, 0, 0}, "    0042");

	test_print_int_case("10. Solo zero padding (\"%08d\")",
		42, (t_flags){0, 1, 8, 0, 0, 0, 0, 0}, "00000042");

	test_print_int_case("11. Valor 0 y precision 0 (no debe imprimir nada)",
		0, (t_flags){0, 0, 5, 0, 1, 0, 0, 0}, "     ");
		
}

int	main(void)
{
	test_parse_flags();
	test_print_int();

	if (g_result)
		printf("\n\033[0;32m✅ TODOS LOS TESTS DE PARSE_FLAGS PASADOS\033[0m\n\n");
	else
		printf("\n\033[0;31m❌ ALGÚN TEST DE PARSE_FLAGS HA FALLADO\033[0m\n\n");

	return (0);
}
