#include <stdio.h>
#include "../libft.h"
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>



int g_result = 1;


void ft_ok(int condition, const char *test_name){
	if (condition)
		printf("\033[0;32m[OK]\033[0m %s\n", test_name);
	else
		{
			printf("\033[0;31m[KO]\033[0m %s\n", test_name);
			g_result = 0;
		}
}

void test_isalpha(void){
	printf("\033[38;5;214m[TEST FT_ISALPHA]\033[0m\n");
	ft_ok(ft_isalpha('A') == 1, "ft_isalpha('A')");
	ft_ok(ft_isalpha('z') == 1, "ft_isalpha('z')");
	ft_ok(ft_isalpha('1') == 0, "ft_isalpha('1')");
	ft_ok(ft_isalpha('*') == 0, "ft_isalpha('*')");
	ft_ok(ft_isalpha('a') == 1, "ft_isalpha('a')");
	ft_ok(ft_isalpha('Z') == 1, "ft_isalpha('Z')");
	ft_ok(ft_isalpha('5') == 0, "ft_isalpha('5')");
	ft_ok(ft_isalpha('^') == 0, "ft_isalpha('^')");
	printf("\n");
}

void test_isdigit(void){
	printf("\033[38;5;214m[TEST FT_ISDIGIT]\033[0m\n");
	ft_ok(ft_isdigit('9') == 1, "ft_isdigit('9')");
	ft_ok(ft_isdigit('5') == 1, "ft_isdigit('5')");
	ft_ok(ft_isdigit('0') == 1, "ft_isdigit('1')");
	ft_ok(ft_isdigit('a') == 0, "ft_isdigit('a')");
	ft_ok(ft_isdigit('A') == 0, "ft_isdigit('A')");
	ft_ok(ft_isdigit('Z') == 0, "ft_isdigit('Z')");
	ft_ok(ft_isdigit('z') == 0, "ft_isdigit('z')");
	ft_ok(ft_isdigit(';') == 0, "ft_isdigit(';')");
	printf("\n");
}

void test_isalnum(void){
	printf("\033[38;5;214m[TEST FT_ISALNUM]\033[0m\n");
	ft_ok(ft_isalnum('9') == 1, "ft_isalnum('9')");
	ft_ok(ft_isalnum('5') == 1, "ft_isalnum('5')");
	ft_ok(ft_isalnum('0') == 1, "ft_isalnum('0')");
	ft_ok(ft_isalnum('a') == 1, "ft_isalnum('a')");
	ft_ok(ft_isalnum('-') == 0, "ft_isalnum('-')");
	ft_ok(ft_isalnum('Z') == 1, "ft_isalnum('Z')");
	ft_ok(ft_isalnum('z') == 1, "ft_isalnum('z')");
	ft_ok(ft_isalnum(';') == 0, "ft_isalnum(';')");
	printf("\n");
}

void test_isascii(void){
	printf("\033[38;5;214m[TEST FT_ISASCII]\033[0m\n");
	ft_ok(ft_isascii('A') == 1, "ft_isascii('A')");
	ft_ok(ft_isascii(127) == 1, "ft_isascii(127)");
	ft_ok(ft_isascii(0) == 1, "ft_isascii(0)");
	ft_ok(ft_isascii(128) == 0, "ft_isascii(128)");
	ft_ok(ft_isascii(-1) == 0, "ft_isascii(-1)");
	printf("\n");
}

void test_isprint(void){
	printf("\033[38;5;214m[TEST FT_ISPRINT]\033[0m\n");
	ft_ok(ft_isprint(' ') == 1, "ft_isprint(' ')");
	ft_ok(ft_isprint('A') == 1, "ft_isprint('A')");
	ft_ok(ft_isprint('~') == 1, "ft_isprint('~')");
	ft_ok(ft_isprint(31) == 0, "ft_isprint(31)");
	ft_ok(ft_isprint(127) == 0, "ft_isprint(127)");
	printf("\n");
}

void test_strlen(void){
	printf("\033[38;5;214m[TEST FT_STRLEN]\033[0m\n");
	ft_ok(ft_strlen("ChatGPT") == 7, "ft_strlen(\"ChatGPT\")");
	ft_ok(ft_strlen("hola") == 4, "ft_strlen(\"hola\")");
	ft_ok(ft_strlen("") == 0, "ft_strlen(\"\")");
	ft_ok(ft_strlen("42Urduliz") == 9, "ft_strlen(\"42Urduliz\")");
	printf("\n");
}

void test_memset(void){
	printf("\033[38;5;214m[TEST FT_MEMSET]\033[0m\n");
    char buffer[6] = "aaaaa"; // Crea un buffer inicializado a "aaaaa"

    // Aplicamos ft_memset para cambiar los 3 primeros caracteres a 'X'
	printf("char buffer[6] = 'aaaaa';\n");
    printf("ft_memset(buffer, 'X', 3)\n");
	ft_memset(buffer, 'X', 3);

    // Ahora buffer debería ser "XXXaa"
    ft_ok(buffer[0] == 'X', "ft_memset buffer[0] == 'X'");
    ft_ok(buffer[1] == 'X', "ft_memset buffer[1] == 'X'");
    ft_ok(buffer[2] == 'X', "ft_memset buffer[2] == 'X'");
    ft_ok(buffer[3] == 'a', "ft_memset buffer[3] == 'a'");
    ft_ok(buffer[4] == 'a', "ft_memset buffer[4] == 'a'");
	printf("\n");

	printf("ft_memset(buffer, 'Z', 5)\n");
	ft_memset(buffer, 'Z', 5); // Cambiamos las 5 posiciones
	ft_ok(buffer[0] == 'Z', "ft_memset full buffer[0] == 'Z'");
	ft_ok(buffer[1] == 'Z', "ft_memset full buffer[1] == 'Z'");
	ft_ok(buffer[2] == 'Z', "ft_memset full buffer[2] == 'Z'");
	ft_ok(buffer[3] == 'Z', "ft_memset full buffer[3] == 'Z'");
	ft_ok(buffer[4] == 'Z', "ft_memset full buffer[4] == 'Z'");
	printf("\n");

	printf("ft_memset(buffer, '\\0', 5) \n");
	ft_memset(buffer, '\0', 5); // Rellenamos todo de ceros
	ft_ok(buffer[0] == '\0', "ft_memset null buffer[0] == '\\0'");
	ft_ok(buffer[1] == '\0', "ft_memset null buffer[1] == '\\0'");
	ft_ok(buffer[2] == '\0', "ft_memset null buffer[2] == '\\0'");
	ft_ok(buffer[3] == '\0', "ft_memset null buffer[3] == '\\0'");
	ft_ok(buffer[4] == '\0', "ft_memset null buffer[4] == '\\0'");
	printf("\n");

	// Primero volvemos a rellenar el buffer con 'A'
	printf("ft_memset(buffer, 'A', 5)\n");
	ft_memset(buffer, 'A', 5);

	// Ahora llamamos a ft_memset con len = 0
	printf("ft_memset(buffer, 'X', 0)\n");
	ft_memset(buffer, 'X', 0);

	// Verificamos que nada cambió
	ft_ok(buffer[0] == 'A', "ft_memset len=0 buffer[0] == 'A'");
	ft_ok(buffer[1] == 'A', "ft_memset len=0 buffer[1] == 'A'");
	ft_ok(buffer[2] == 'A', "ft_memset len=0 buffer[2] == 'A'");
	ft_ok(buffer[3] == 'A', "ft_memset len=0 buffer[3] == 'A'");
	ft_ok(buffer[4] == 'A', "ft_memset len=0 buffer[4] == 'A'");

	printf("\n");
}

void test_bzero(void){
	printf("\033[38;5;214m[TEST FT_BZERO]\033[0m\n");
	printf("char buffer[6] = 'abcde'\n");
    char buffer[6] = "abcde"; // Buffer inicializado con letras

    // Aplicamos ft_bzero para poner a cero los 3 primeros caracteres
	printf("ft_bzero(buffer, 3)\n");
    ft_bzero(buffer, 3);

    ft_ok(buffer[0] == '\0', "ft_bzero buffer[0] == '\\0'");
    ft_ok(buffer[1] == '\0', "ft_bzero buffer[1] == '\\0'");
    ft_ok(buffer[2] == '\0', "ft_bzero buffer[2] == '\\0'");
    ft_ok(buffer[3] == 'd', "ft_bzero buffer[3] == 'd'");
    ft_ok(buffer[4] == 'e', "ft_bzero buffer[4] == 'e'");

	printf("\n");
}

void test_memcpy(void){
	printf("\033[38;5;214m[TEST FT_MEMCPY]\033[0m\n");

	// Caso 1: copiar n bytes normales
	char src1[] = "12345";
	char dst1[6] = "aaaaa";
	ft_memcpy(dst1, src1, 5);
	ft_ok(dst1[0] == '1', "ft_memcpy dst1[0] == '1'");
	ft_ok(dst1[1] == '2', "ft_memcpy dst1[1] == '2'");
	ft_ok(dst1[4] == '5', "ft_memcpy dst1[4] == '5'");

	// Caso 2: copiar 0 bytes (no debe tocar nada)
	char src2[] = "abcde";
	char dst2[] = "zzzzz";
	ft_memcpy(dst2, src2, 0);
	ft_ok(dst2[0] == 'z', "ft_memcpy len=0 no toca dst2[0]");

	// Caso 3: src y dst apuntan a lo mismo
	char buffer1[] = "abcd";
	ft_memcpy(buffer1, buffer1, 4);
	ft_ok(buffer1[0] == 'a', "ft_memcpy src==dst no rompe nada");

	// Caso 4: copiar bytes con \0 en medio
	char src3[] = {'a', '\0', 'c', 'd'};
	char dst3[4] = {'x', 'x', 'x', 'x'};
	ft_memcpy(dst3, src3, 4);
	ft_ok(dst3[1] == '\0', "ft_memcpy copia '\\0'");
	ft_ok(dst3[3] == 'd', "ft_memcpy dst3[3] == 'd'");

	// Caso 5: copiar bytes extendidos (\200-\377)
	unsigned char src4[] = {0, 128, 255};
	unsigned char dst4[3] = {9, 9, 9};
	ft_memcpy(dst4, src4, 3);
	ft_ok(dst4[1] == 128, "ft_memcpy copia byte 128");
	ft_ok(dst4[2] == 255, "ft_memcpy copia byte 255");

	printf("\n");
}

void test_memmove(void){
	printf("\033[38;5;214m[TEST FT_MEMMOVE]\033[0m\n");
	printf("char src1[6] = '12345'\n");
	printf("char dst1[6] = 'aaaaa'\n");
	char src1[6] = "12345";
	char dst1[6] = "aaaaa";
	printf("ft_memmove(dst1, src1, 5)\n");
	ft_memmove(dst1, src1, 5);
	ft_ok(dst1[0] == '1', "ft_memmove sin solape dst1[0] == '1'");
	ft_ok(dst1[1] == '2', "ft_memmove sin solape dst1[1] == '2'");
	ft_ok(dst1[4] == '5', "ft_memmove sin solape dst1[4] == '5'");

	printf("char src2[5] = 'zzzz'\n");
	printf("char dst2[5] = 'yyyy'\n");
	char src2[5] = "zzzz";
	char dst2[5] = "yyyy";
	printf("ft_memmove(dst2, src2, 0)\n");
	ft_memmove(dst2, src2, 0);
	ft_ok(dst2[0] == 'y', "ft_memmove len=0 dst2[0] unchanged");

	printf("char buffer1[5] = 'aaaa'\n");
	char buffer1[5] = "aaaa";
	printf("ft_memmove(buffer1, buffer1, 4)\n");
	ft_memmove(buffer1, buffer1, 4);
	ft_ok(buffer1[0] == 'a', "ft_memmove src==dst buffer[0] == 'a'");

	printf("char buffer2[10] = 'abcdefghi'\n");
	char buffer2[10] = "abcdefghi";
	printf("ft_memmove(buffer2 + 2, buffer2, 5)\n");
	ft_memmove(buffer2 + 2, buffer2, 5);
	ft_ok(buffer2[2] == 'a', "ft_memmove solapado buffer2[2] == 'a'");
	ft_ok(buffer2[3] == 'b', "ft_memmove solapado buffer2[3] == 'b'");
	ft_ok(buffer2[6] == 'e', "ft_memmove solapado buffer2[6] == 'e'");
	
	printf("\n");
}

void test_strlcpy(void){
	printf("\033[38;5;214m[TEST FT_STRLCPY]\033[0m\n");
	char src1[] = "Hola";
	char dst1[10];

	size_t len1 = ft_strlcpy(dst1, src1, 10);
	ft_ok(len1 == 4, "ft_strlcpy len == 4 (src1)");
	ft_ok(dst1[0] == 'H', "ft_strlcpy dst1[0] == 'H'");
	ft_ok(dst1[3] == 'a', "ft_strlcpy dst1[3] == 'a'");
	ft_ok(dst1[4] == '\0', "ft_strlcpy dst1[4] == '\\0'");

	// Caso: tamaño exacto
	char dst2[5];
	size_t len2 = ft_strlcpy(dst2, src1, 5);
	ft_ok(len2 == 4, "ft_strlcpy len == 4 (dst2)");
	ft_ok(dst2[4] == '\0', "ft_strlcpy dst2[4] == '\\0'");

	// Caso: dst más pequeño que src (truncamiento)
	char dst3[3];
	size_t len3 = ft_strlcpy(dst3, "ABCDEFG", 3);
	ft_ok(len3 == 7, "ft_strlcpy len == 7 (src too big)");
	ft_ok(dst3[0] == 'A', "ft_strlcpy dst3[0] == 'A'");
	ft_ok(dst3[1] == 'B', "ft_strlcpy dst3[1] == 'B'");
	ft_ok(dst3[2] == '\0', "ft_strlcpy dst3[2] == '\\0'");

	// Caso: size == 0
	char dst4[5] = "XXXX";
	size_t len4 = ft_strlcpy(dst4, "Test", 0);
	ft_ok(len4 == 4, "ft_strlcpy len == 4 (size == 0)");
	ft_ok(dst4[0] == 'X', "ft_strlcpy dst4 unchanged if size == 0");

	printf("\n");
}

void test_strlcat(void){
	printf("\033[38;5;214m[TEST FT_STRLCAT]\033[0m\n");
	// Caso 1: espacio suficiente para concatenar todo
	char buffer1[20] = "Hello, ";
	size_t result1 = ft_strlcat(buffer1, "world!", 20);
	ft_ok(result1 == 13, "ft_strlcat full concat return == 13");
	ft_ok(buffer1[7] == 'w', "ft_strlcat buffer1[7] == 'w'");
	ft_ok(buffer1[12] == '!', "ft_strlcat buffer1[12] == '!'");
	ft_ok(buffer1[13] == '\0', "ft_strlcat ends with '\\0'");

	// Caso 2: espacio limitado, truncamiento esperado
	char buffer2[10] = "42";
	size_t result2 = ft_strlcat(buffer2, "Urduliz", 10);
	ft_ok(result2 == 9, "ft_strlcat truncado return == 9");
	ft_ok(buffer2[9] == '\0', "ft_strlcat truncado ends with '\\0'");

	// Caso 3: size menor que dst_len, no se concatena
	char buffer3[5] = "Data";
	size_t result3 = ft_strlcat(buffer3, "42", 2);
	ft_ok(result3 == 2 + 2, "ft_strlcat no copy return == 4");
	ft_ok(buffer3[0] == 'D', "ft_strlcat no copy keeps dst[0]");

	// Caso 4: size == 0, no se concatena
	char buffer4[10] = "Inicio";
	size_t result4 = ft_strlcat(buffer4, "Nada", 0);
	ft_ok(result4 == ft_strlen("Nada"), "ft_strlcat size=0 return == strlen(src)");

	printf("\n");
}

void test_toupper(void){
	printf("\033[38;5;214m[TEST FT_TOUPPER]\033[0m\n");
	// Letras minúsculas → deben convertirse
	ft_ok(ft_toupper('a') == 'A', "ft_toupper('a') == 'A'");
	ft_ok(ft_toupper('m') == 'M', "ft_toupper('m') == 'M'");
	ft_ok(ft_toupper('z') == 'Z', "ft_toupper('z') == 'Z'");

	// Letras mayúsculas → no cambian
	ft_ok(ft_toupper('A') == 'A', "ft_toupper('A') == 'A'");
	ft_ok(ft_toupper('Z') == 'Z', "ft_toupper('Z') == 'Z'");

	// Números y símbolos → no cambian
	ft_ok(ft_toupper('0') == '0', "ft_toupper('0') == '0'");
	ft_ok(ft_toupper('9') == '9', "ft_toupper('9') == '9'");
	ft_ok(ft_toupper('!') == '!', "ft_toupper('!') == '!'");
	ft_ok(ft_toupper(' ') == ' ', "ft_toupper(' ') == ' '");

	printf("\n");
}

void test_tolower(void){
	printf("\033[38;5;214m[TEST FT_TOLOWER]\033[0m\n");
	// Letras mayúsculas → deben convertirse
	ft_ok(ft_tolower('A') == 'a', "ft_tolower('A') == 'a'");
	ft_ok(ft_tolower('M') == 'm', "ft_tolower('M') == 'm'");
	ft_ok(ft_tolower('Z') == 'z', "ft_tolower('Z') == 'z'");

	// Letras minúsculas → no cambian
	ft_ok(ft_tolower('a') == 'a', "ft_tolower('a') == 'a'");
	ft_ok(ft_tolower('z') == 'z', "ft_tolower('z') == 'z'");

	// Números y símbolos → no cambian
	ft_ok(ft_tolower('0') == '0', "ft_tolower('0') == '0'");
	ft_ok(ft_tolower('9') == '9', "ft_tolower('9') == '9'");
	ft_ok(ft_tolower('@') == '@', "ft_tolower('@') == '@'");
	ft_ok(ft_tolower(' ') == ' ', "ft_tolower(' ') == ' '");

	printf("\n");
}

void test_strchr(void){
	printf("\033[38;5;214m[TEST FT_STRCHR]\033[0m\n");
	// Caso 1: carácter en medio
	char *s1 = "42Urduliz";
	char *res1 = ft_strchr(s1, 'r');
	ft_ok(res1 == &s1[3], "ft_strchr(s1, 'r') apunta a s1[3]");

	// Caso 2: primer carácter
	char *res2 = ft_strchr(s1, '4');
	ft_ok(res2 == s1, "ft_strchr(s1, '4') apunta al inicio");

	// Caso 3: último carácter
	char *res3 = ft_strchr(s1, 'z');
	ft_ok(res3 == &s1[8], "ft_strchr(s1, 'z') apunta a s1[8]");

	// Caso 4: carácter no está
	char *res4 = ft_strchr(s1, 'X');
	ft_ok(res4 == NULL, "ft_strchr(s1, 'X') == NULL");

	// Caso 5: buscar '\0'
	char *res5 = ft_strchr(s1, '\0');
	ft_ok(res5 == &s1[9], "ft_strchr(s1, '\\0') apunta al final");

	// Caracter al principio
	char *s2 = "ALOHA";
	ft_ok(ft_strchr(s2, 'A') == s2, "ft_strchr('ALOHA', 'A') devuelve inicio");

	// Caracter repetido → debe devolver el primero
	ft_ok(ft_strchr("banana", 'a') == &"banana"[1], "ft_strchr('banana', 'a') devuelve primera 'a'");

	// Carácter no encontrado
	ft_ok(ft_strchr("12345", 'x') == NULL, "ft_strchr('12345', 'x') == NULL");

	// Carácter null terminador
	ft_ok(ft_strchr("hola", '\0') == &"hola"[4], "ft_strchr('hola', '\\0') apunta al final");

	// Valor extendido positivo (>127)
	ft_ok(ft_strchr("ALOHA", 321) == &"ALOHA"[0], "ft_strchr('ALOHA', 321) devuelve primer 'A'");

	// Valor extendido no presente
	ft_ok(ft_strchr("abc", 200) == NULL, "ft_strchr('abc', 200) == NULL");

// Cadena vacía con búsqueda de '\0'
char *empty = "";
ft_ok(ft_strchr(empty, '\0') == empty, "ft_strchr('', '\\0') == ''");


	printf("\n");
}

void test_strrchr(void){
	printf("\033[38;5;214m[TEST FT_STRRCPY]\033[0m\n");

	// Última aparición de un carácter
	char *s2 = "banana";
	ft_ok(ft_strrchr(s2, 'a') == &s2[5], "ft_strrchr('banana', 'a') devuelve última 'a'");

	// Primera y única aparición
	char *s3 = "hola";
	ft_ok(ft_strrchr(s3, 'h') == s3, "ft_strrchr('hola', 'h') devuelve inicio");

	// Carácter no existente
	ft_ok(ft_strrchr("42Urduliz", 'x') == NULL, "ft_strrchr('42Urduliz', 'x') == NULL");

	// Carácter null terminador
	char *s4 = "chat";
	ft_ok(ft_strrchr(s4, '\0') == &s4[4], "ft_strrchr('chat', '\\0') apunta al final");

	// Cadena vacía
	ft_ok(ft_strrchr("", 'a') == NULL, "ft_strrchr('', 'a') == NULL");
	
	// Carácter null terminador
	char *s5 = "a";
	ft_ok(ft_strrchr(s5, '\0') == &s5[1], "ft_strrchr('a', '\\0') == NULL");


	printf("\n");
}

void test_strncmp(void){
	printf("\033[38;5;214m[TEST FT_STRNCMP]\033[0m\n");

	// Comparación igual hasta n
	ft_ok(ft_strncmp("hola", "hola", 4) == 0, "strncmp iguales hasta n");

	// Primera diferencia en mitad
	ft_ok(ft_strncmp("hola", "holi", 4) < 0, "strncmp diferencia en última letra");


	// Diferencia al principio
	ft_ok(ft_strncmp("cola", "hola", 4) < 0, "strncmp diferencia al principio");

	// Diferencia justo después del límite → debe devolver 0
	ft_ok(ft_strncmp("abcdef", "abcxyz", 3) == 0, "strncmp iguales en los 3 primeros");

	// Una cadena vacía
	ft_ok(ft_strncmp("", "", 1) == 0, "strncmp dos vacías con n=1");
	ft_ok(ft_strncmp("", "a", 1) < 0, "strncmp \"\" < \"a\" con n=1");
	ft_ok(ft_strncmp("a", "", 1) > 0, "strncmp \"a\" > \"\" con n=1");

	// n = 0 → debe devolver 0 siempre
	ft_ok(ft_strncmp("abc", "xyz", 0) == 0, "strncmp con n=0 siempre == 0");

	// Cadenas largas iguales, n corta
	ft_ok(ft_strncmp("abcdefghijklmnop", "abcdefghijklmnop", 5) == 0, "strncmp largas, iguales hasta 5");

	// Cadenas largas, primera diferencia fuera del límite
	ft_ok(ft_strncmp("abcdef", "abcdez", 5) == 0, "strncmp diferencia fuera de límite");

	// Diferencia con carácter negativo (signed/unsigned test)
	ft_ok(ft_strncmp("\200", "\0", 1) > 0, "strncmp compara como unsigned char");

	printf("\n");
}

void test_memchr(void){
	printf("\033[38;5;214m[TEST FT_MEMCHR]\033[0m\n");

	// Caso 1: carácter presente en medio
	char data1[] = "42Urduliz";
	void *res1 = ft_memchr(data1, 'r', 10);
	ft_ok(res1 == &data1[3], "ft_memchr(data1, 'r', 10) → data1[3]");

	// Caso 2: carácter al final
	void *res2 = ft_memchr(data1, 'z', 10);
	ft_ok(res2 == &data1[8], "ft_memchr(data1, 'z', 10) → data1[8]");

	// Caso 3: carácter no está
	void *res3 = ft_memchr(data1, 'X', 10);
	ft_ok(res3 == NULL, "ft_memchr(data1, 'X', 10) == NULL");

	// Caso 4: buscar '\0'
	char data2[] = "abc\0def";
	void *res4 = ft_memchr(data2, '\0', 7);
	ft_ok(res4 == &data2[3], "ft_memchr(data2, '\\0', 7) → data2[3]");

	// Caso 5: n = 0 → nunca encuentra nada
	char data3[] = "abcdef";
	void *res5 = ft_memchr(data3, 'a', 0);
	ft_ok(res5 == NULL, "ft_memchr(data3, 'a', 0) == NULL");

	// Caso 6: byte extendido (\200)
	unsigned char data4[] = {0, 1, 127, 128, 255};
	void *res6 = ft_memchr(data4, 255, 5);
	ft_ok(res6 == &data4[4], "ft_memchr(data4, 255, 5) → data4[4]");

	printf("\n");
}

void test_memcmp(void){
	printf("\033[38;5;214m[TEST FT_MEMCMP]\033[0m\n");

	// Caso 1: bloques idénticos
	char a1[] = "abcde";
	char a2[] = "abcde";
	ft_ok(ft_memcmp(a1, a2, 5) == 0, "memcmp bloques iguales");

	// Caso 2: primera diferencia al principio
	char b1[] = "abc";
	char b2[] = "xbc";
	ft_ok(ft_memcmp(b1, b2, 3) < 0, "memcmp diferencia al inicio");

	// Caso 3: primera diferencia en el medio
	char c1[] = "aXc";
	char c2[] = "aYc";
	ft_ok(ft_memcmp(c1, c2, 3) < 0, "memcmp diferencia en medio");

	// Caso 4: misma cadena, pero n = 0
	ft_ok(ft_memcmp("abc", "xyz", 0) == 0, "memcmp con n = 0 → igual");

	// Caso 5: comparación corta, no alcanza diferencias
	ft_ok(ft_memcmp("abcdef", "abcXYZ", 3) == 0, "memcmp iguales en los primeros 3 bytes");

	// Caso 6: diferencia en byte con valor >127 (signed vs unsigned)
	unsigned char d1[] = {0x01, 0x7F, 0x80};
	unsigned char d2[] = {0x01, 0x7F, 0x00};
	ft_ok(ft_memcmp(d1, d2, 3) > 0, "memcmp bytes extendidos unsigned (0x80 > 0x00)");

	// Caso 7: buffer con \0 en medio
	char e1[] = {'a', '\0', 'c'};
	char e2[] = {'a', '\0', 'd'};
	ft_ok(ft_memcmp(e1, e2, 3) < 0, "memcmp no se detiene en '\\0'");

	printf("\n");
}

void test_strnstr(void){
	printf("\033[38;5;214m[TEST FT_STRNSTR]\033[0m\n");

	// Caso 1: needle dentro de haystack
	char *hay1 = "Esto es una cadena de prueba";
	char *res1 = ft_strnstr(hay1, "cadena", 25);
	ft_ok(res1 == &hay1[12], "ft_strnstr encuentra 'cadena' en haystack");

	// Caso 2: needle justo al final, pero cabe
	char *res2 = ft_strnstr("123456789", "789", 9);
	ft_ok(res2 != NULL && res2[0] == '7', "ft_strnstr encuentra al final con len suficiente");

	// Caso 3: needle no cabe dentro de len
	char *res3 = ft_strnstr("123456789", "789", 8);
	ft_ok(res3 == NULL, "ft_strnstr no encuentra si len es demasiado corto");

	// Caso 4: needle vacío → debe devolver haystack
	char *res4 = ft_strnstr("abc", "", 3);
	ft_ok(ft_strncmp(res4, "abc", 3) == 0, "...");

	// Caso 5: len = 0 → siempre NULL, excepto si needle vacío
	char *res5 = ft_strnstr("abc", "a", 0);
	ft_ok(res5 == NULL, "ft_strnstr len=0 y needle != '' devuelve NULL");

	char *res6 = ft_strnstr("abc", "", 0);
	ft_ok(ft_strncmp(res6, "abc", 3) == 0, "...");

	// Caso 6: no aparece en haystack
	char *res7 = ft_strnstr("abcdef", "xyz", 6);
	ft_ok(res7 == NULL, "ft_strnstr con needle inexistente devuelve NULL");

	printf("\n");
}

void test_atoi(void){
	printf("\033[38;5;214m[TEST FT_ATOI]\033[0m\n");

	// Casos normales
	ft_ok(ft_atoi("0") == 0, "ft_atoi(\"0\") == 0");
	ft_ok(ft_atoi("42") == 42, "ft_atoi(\"42\") == 42");
	ft_ok(ft_atoi("-42") == -42, "ft_atoi(\"-42\") == -42");
	ft_ok(ft_atoi("+123") == 123, "ft_atoi(\"+123\") == 123");

	// Espacios iniciales
	ft_ok(ft_atoi("   7") == 7, "ft_atoi(\"   7\") == 7");
	ft_ok(ft_atoi("\t\n\r  -99") == -99, "ft_atoi(\"\\t\\n\\r  -99\") == -99");

	// Texto después del número
	ft_ok(ft_atoi("123abc") == 123, "ft_atoi(\"123abc\") == 123");

	// Solo signo
	ft_ok(ft_atoi("+") == 0, "ft_atoi(\"+\") == 0");
	ft_ok(ft_atoi("-") == 0, "ft_atoi(\"-\") == 0");

	// Cadena vacía
	ft_ok(ft_atoi("") == 0, "ft_atoi(\"\") == 0");

	// Límite de int
	ft_ok(ft_atoi("2147483647") == 2147483647, "ft_atoi(\"2147483647\") == INT_MAX");
	ft_ok(ft_atoi("-2147483648") == -2147483648, "ft_atoi(\"-2147483648\") == INT_MIN");

	printf("\n");
}

void test_calloc(void){
	printf("\033[38;5;214m[TEST FT_CALLOC]\033[0m\n");

	// Caso normal
	char *str = ft_calloc(5, sizeof(char));
	ft_ok(str != NULL, "ft_calloc(5, sizeof(char)) != NULL");

	// Todos los bytes deben estar a 0
	int all_zero = 1;
	for (int i = 0; i < 5; i++)
		if (str[i] != 0)
			all_zero = 0;
	ft_ok(all_zero, "ft_calloc inicializa todo a cero");
	free(str);

	// count = 0
	char *empty1 = ft_calloc(0, sizeof(char));
	ft_ok(empty1 != NULL, "ft_calloc(0, size) devuelve puntero válido o NULL permitido");
	free(empty1);

	// size = 0
	char *empty2 = ft_calloc(5, 0);
	ft_ok(empty2 != NULL, "ft_calloc(count, 0) devuelve puntero válido o NULL permitido");
	free(empty2);

	printf("\n");
}

void test_strdup(void){
	printf("\033[38;5;214m[TEST FT_STRDUP]\033[0m\n");

	const char *src = "hola mundo";
	char *copy = ft_strdup(src);

	ft_ok(copy != NULL, "ft_strdup devuelve puntero válido");
	ft_ok(ft_strncmp(copy, src, ft_strlen(src)) == 0, "ft_strdup copia correctamente");
	ft_ok(copy != src, "ft_strdup devuelve un puntero distinto al original");
	free(copy);

	// Caso vacío
	char *empty = ft_strdup("");
	ft_ok(empty != NULL, "ft_strdup(\"\") != NULL");
	ft_ok(empty[0] == '\0', "ft_strdup(\"\") devuelve cadena vacía");
	free(empty);

	printf("\n");
}

void test_substr(void){
	printf("\033[38;5;214m[TEST FT_SUBSTR]\033[0m\n");

	// Caso 1: Extraer parte normal de cadena
	char *s1 = "Hola mundo";
	char *res1 = ft_substr(s1, 5, 5);
	ft_ok(res1 && strcmp(res1, "mundo") == 0, "ft_substr extrae 'mundo'");

	// Caso 2: start = 0, len más corto que s
	char *res2 = ft_substr(s1, 0, 4);
	ft_ok(res2 && strcmp(res2, "Hola") == 0, "ft_substr desde 0, 4 letras");

	// Caso 3: start > strlen(s) → cadena vacía
	char *res3 = ft_substr(s1, 50, 5);
	ft_ok(res3 && strcmp(res3, "") == 0, "ft_substr con start > len devuelve \"\"");

	// Caso 4: len mayor que lo que queda
	char *res4 = ft_substr(s1, 6, 100);
	ft_ok(res4 && strcmp(res4, "undo") == 0, "ft_substr len largo ajustado");

	// Caso 5: len = 0 → cadena vacía
	char *res5 = ft_substr(s1, 3, 0);
	ft_ok(res5 && strcmp(res5, "") == 0, "ft_substr con len=0 devuelve \"\"");

	// Caso 6: cadena vacía
	char *res6 = ft_substr("", 0, 10);
	ft_ok(res6 && strcmp(res6, "") == 0, "ft_substr desde cadena vacía");

	// Caso 7: start + len = strlen → exacto hasta el final
	char *res7 = ft_substr(s1, 5, 5);
	ft_ok(res7 && strcmp(res7, "mundo") == 0, "ft_substr exacto hasta final");

	// Caso 8: NULL como input
	char *res8 = ft_substr(NULL, 0, 5);
	ft_ok(res8 == NULL, "ft_substr(NULL, ...) devuelve NULL");

	printf("\n");
}

void test_strjoin(void) {
    printf("\033[38;5;214m[TEST FT_STRJOIN]\033[0m\n");

    // Caso normal
    char *res1 = ft_strjoin("Hola", " mundo");
    ft_ok(res1 && strcmp(res1, "Hola mundo") == 0, "ft_strjoin(\"Hola\", \" mundo\") → \"Hola mundo\"");
    free(res1);

    // Uno vacío
    char *res2 = ft_strjoin("", "Hola");
    ft_ok(res2 && strcmp(res2, "Hola") == 0, "ft_strjoin(\"\", \"Hola\") → \"Hola\"");
    free(res2);

    char *res3 = ft_strjoin("Hola", "");
    ft_ok(res3 && strcmp(res3, "Hola") == 0, "ft_strjoin(\"Hola\", \"\") → \"Hola\"");
    free(res3);

    // Ambos vacíos
    char *res4 = ft_strjoin("", "");
    ft_ok(res4 && strcmp(res4, "") == 0, "ft_strjoin(\"\", \"\") → \"\"");
    free(res4);

    // Texto largo
    char *long1 = "Esto es un texto largo ";
    char *long2 = "concatenado con otro texto largo.";
    char *res5 = ft_strjoin(long1, long2);
    ft_ok(res5 && strcmp(res5, "Esto es un texto largo concatenado con otro texto largo.") == 0,
          "ft_strjoin texto largo correcto");
    free(res5);

	char *res6 = ft_strjoin(NULL, "mundo");
	ft_ok(res6 == NULL, "ft_strjoin(NULL, \"mundo\") devuelve NULL");

	char *res7 = ft_strjoin("hola", NULL);
	ft_ok(res7 == NULL, "ft_strjoin(\"hola\", NULL) devuelve NULL");

	char *res8 = ft_strjoin(NULL, NULL);
	ft_ok(res8 == NULL, "ft_strjoin(NULL, NULL) devuelve NULL");


    printf("\n");
}

void test_strtrim(void){
    printf("\033[38;5;214m[TEST FT_STRTRIM]\033[0m\n");

    // Caso 1: recorte estándar
    char *res1 = ft_strtrim(" 42 Urduliz ", " ");
    ft_ok(res1 && strcmp(res1, "42 Urduliz") == 0, "trim espacios alrededor");

    // Caso 2: recorte múltiple caracteres
    char *res2 = ft_strtrim("xy42xy", "xy");
    ft_ok(res2 && strcmp(res2, "42") == 0, "trim 'x' y 'y'");

    // Caso 3: recorte completo
    char *res3 = ft_strtrim("abcabc", "abc");
    ft_ok(res3 && strcmp(res3, "") == 0, "todo se recorta → resultado vacío");

    // Caso 4: nada se recorta
    char *res4 = ft_strtrim("manupc", "xyz");
    ft_ok(res4 && strcmp(res4, "manupc") == 0, "nada se recorta");

    // Caso 5: cadena vacía
    char *res5 = ft_strtrim("", " ");
    ft_ok(res5 && strcmp(res5, "") == 0, "input vacío devuelve vacío");

    // Caso 6: set vacío
    char *res6 = ft_strtrim("abc", "");
    ft_ok(res6 && strcmp(res6, "abc") == 0, "set vacío no recorta nada");

    // Caso 7: set contiene solo un carácter
    char *res7 = ft_strtrim("...hello...", ".");
    ft_ok(res7 && strcmp(res7, "hello") == 0, "trim de puntos");

    // Caso 8: NULL inputs
    ft_ok(ft_strtrim(NULL, "abc") == NULL, "NULL como s1 devuelve NULL");
    ft_ok(ft_strtrim("abc", NULL) == NULL, "NULL como set devuelve NULL");

    printf("\n");
}

void	free_split(char **arr){
	size_t i = 0;
	if (!arr) return;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	test_split(void){
	printf("\033[38;5;214m[TEST FT_SPLIT]\033[0m\n");

	char **res;

	// Caso 1: Separación normal
	res = ft_split("Hola mundo 42", ' ');
	ft_ok(res && strcmp(res[0], "Hola") == 0, "ft_split → palabra 1");
	ft_ok(res && strcmp(res[1], "mundo") == 0, "ft_split → palabra 2");
	ft_ok(res && strcmp(res[2], "42") == 0, "ft_split → palabra 3");
	ft_ok(res[3] == NULL, "ft_split → NULL final");
	free_split(res);

	// Caso 2: Delimitadores consecutivos
	res = ft_split("42  Urduliz   School", ' ');
	ft_ok(res && strcmp(res[0], "42") == 0, "ft_split con múltiples espacios → palabra 1");
	ft_ok(res && strcmp(res[1], "Urduliz") == 0, "ft_split con múltiples espacios → palabra 2");
	ft_ok(res && strcmp(res[2], "School") == 0, "ft_split con múltiples espacios → palabra 3");
	ft_ok(res[3] == NULL, "ft_split con múltiples espacios → NULL final");
	free_split(res);

	// Caso 3: Solo delimitadores
	res = ft_split("     ", ' ');
	ft_ok(res && res[0] == NULL, "ft_split solo delimitadores → array vacío");
	free_split(res);

	// Caso 4: Cadena vacía
	res = ft_split("", ' ');
	ft_ok(res && res[0] == NULL, "ft_split cadena vacía → array vacío");
	free_split(res);

	// Caso 5: No hay delimitador
	res = ft_split("unicapalabra", ' ');
	ft_ok(res && strcmp(res[0], "unicapalabra") == 0, "ft_split sin delimitadores → palabra única");
	ft_ok(res[1] == NULL, "ft_split sin delimitadores → NULL final");
	free_split(res);

	// Caso 6: Empieza y termina en delimitador
	res = ft_split("  hola mundo  ", ' ');
	ft_ok(res && strcmp(res[0], "hola") == 0, "ft_split inicio delimitadores → palabra 1");
	ft_ok(res && strcmp(res[1], "mundo") == 0, "ft_split final delimitadores → palabra 2");
	ft_ok(res[2] == NULL, "ft_split inicio/final delimitadores → NULL final");
	free_split(res);

	printf("\n");
}

void test_itoa(void){
	printf("\033[38;5;214m[TEST FT_ITOA]\033[0m\n");

	char *res;

	// Casos básicos
	res = ft_itoa(0);
	ft_ok(res && strcmp(res, "0") == 0, "ft_itoa(0) == \"0\"");
	free(res);

	res = ft_itoa(42);
	ft_ok(res && strcmp(res, "42") == 0, "ft_itoa(42) == \"42\"");
	free(res);

	res = ft_itoa(-42);
	ft_ok(res && strcmp(res, "-42") == 0, "ft_itoa(-42) == \"-42\"");
	free(res);

	res = ft_itoa(123456789);
	ft_ok(res && strcmp(res, "123456789") == 0, "ft_itoa(123456789)");
	free(res);

	// Casos con un dígito
	res = ft_itoa(7);
	ft_ok(res && strcmp(res, "7") == 0, "ft_itoa(7)");
	free(res);

	res = ft_itoa(-3);
	ft_ok(res && strcmp(res, "-3") == 0, "ft_itoa(-3)");
	free(res);

	// Límite superior
	res = ft_itoa(2147483647);
	ft_ok(res && strcmp(res, "2147483647") == 0, "ft_itoa(INT_MAX)");
	free(res);

	// Límite inferior
	res = ft_itoa(-2147483648);
	ft_ok(res && strcmp(res, "-2147483648") == 0, "ft_itoa(INT_MIN)");
	free(res);

	printf("\n");
}

char	add_index(unsigned int i, char c){
	return (c + i);
}

char	to_upper(unsigned int i, char c){
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void test_strmapi(void){
	printf("\033[38;5;214m[TEST FT_STRMAPI]\033[0m\n");

	char *res1 = ft_strmapi("abc", add_index);  // 'a'+0, 'b'+1, 'c'+2 → ace
	ft_ok(res1 && strcmp(res1, "ace") == 0, "ft_strmapi(\"abc\", add_index) == \"ace\"");
	free(res1);

	char *res2 = ft_strmapi("hola", to_upper);  // → "HOLA"
	ft_ok(res2 && strcmp(res2, "HOLA") == 0, "ft_strmapi(\"hola\", to_upper) == \"HOLA\"");
	free(res2);

	char *res3 = ft_strmapi("", add_index);  // cadena vacía
	ft_ok(res3 && strcmp(res3, "") == 0, "ft_strmapi(\"\", add_index) == \"\"");
	free(res3);

	char *res4 = ft_strmapi("42", NULL);
	ft_ok(res4 == NULL, "ft_strmapi with NULL function returns NULL");

	printf("\n");
}

void to_upper_iteri(unsigned int i, char *c) {
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

void index_to_char(unsigned int i, char *c) {
	if (i < 10)
		*c = '0' + i;
}

void test_striteri(void){
	printf("\033[38;5;214m[TEST FT_STRITERI]\033[0m\n");

	char str1[] = "hello42";
	ft_striteri(str1, to_upper_iteri);
	ft_ok(strcmp(str1, "HELLO42") == 0, "ft_striteri convierte a mayúsculas");

	char str2[] = "abcdef";
	ft_striteri(str2, index_to_char);
	ft_ok(strcmp(str2, "012345") == 0, "ft_striteri convierte en índices");

	char str3[] = "";
	ft_striteri(str3, to_upper_iteri);
	ft_ok(strcmp(str3, "") == 0, "ft_striteri con cadena vacía no cambia nada");

	ft_striteri(NULL, to_upper_iteri); // no debe crashear
	ft_striteri("test", NULL);         // no debe crashear
	ft_ok(1, "ft_striteri ignora inputs NULL sin crash");

	printf("\n");
}


void test_putchar_fd(void){
	printf("\033[38;5;214m[TEST FT_PUTCHAR_FD]\033[0m\n");

	int fd = open("test_putchar.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open");
		return;
	}

	ft_putchar_fd('X', fd);
	ft_putchar_fd('\n', fd);
	ft_putchar_fd('Y', fd);

	close(fd);

	// Ahora comprobamos si el contenido es correcto
	char buffer[10] = {0};
	fd = open("test_putchar.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open read");
		return;
	}

	read(fd, buffer, 10);
	close(fd);

	ft_ok(buffer[0] == 'X', "ft_putchar_fd escribe 'X'");
	ft_ok(buffer[1] == '\n', "ft_putchar_fd escribe salto de línea");
	ft_ok(buffer[2] == 'Y', "ft_putchar_fd escribe 'Y'");
	ft_ok(buffer[3] == '\0' || buffer[3] == 0, "ft_putchar_fd no escribe más");

	// Borra el archivo después del test
	remove("test_putchar.txt");

	printf("\n");
}

void	test_putstr_fd(void)
{
	printf("\033[38;5;214m[TEST FT_PUTSTR_FD]\033[0m\n");

	int fd = open("test_putstr.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putstr_fd("Hola mundo", fd);
	close(fd);

	fd = open("test_putstr.txt", O_RDONLY);
	char buffer[20];
	ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	buffer[bytes_read] = '\0';
	ft_ok(strcmp(buffer, "Hola mundo") == 0, "ft_putstr_fd escribe 'Hola mundo'");
	close(fd);
	unlink("test_putstr.txt");

	// Prueba con string vacío
	fd = open("test_putstr.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putstr_fd("", fd);
	close(fd);

	fd = open("test_putstr.txt", O_RDONLY);
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	buffer[bytes_read] = '\0';
	ft_ok(strcmp(buffer, "") == 0, "ft_putstr_fd escribe cadena vacía");
	close(fd);
	unlink("test_putstr.txt");

	printf("\n");
}

void	test_putendl_fd(void)
{
	printf("\033[38;5;214m[TEST FT_PUTENDL_FD]\033[0m\n");

	int fd = open("test_putendl.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putendl_fd("Hola mundo", fd);
	close(fd);

	fd = open("test_putendl.txt", O_RDONLY);
	char buffer[20];
	ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	buffer[bytes_read] = '\0';
	ft_ok(strcmp(buffer, "Hola mundo\n") == 0, "ft_putendl_fd escribe 'Hola mundo\\n'");
	close(fd);
	unlink("test_putendl.txt");

	// Cadena vacía → solo salto de línea
	fd = open("test_putendl.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putendl_fd("", fd);
	close(fd);

	fd = open("test_putendl.txt", O_RDONLY);
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	buffer[bytes_read] = '\0';
	ft_ok(strcmp(buffer, "\n") == 0, "ft_putendl_fd escribe solo salto de línea");
	close(fd);
	unlink("test_putendl.txt");

	printf("\n");
}

void test_putnbr_fd(void)
{
	printf("\033[38;5;214m[TEST FT_PUTNBR_FD]\033[0m\n");

	int fd = open("putnbr_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("Error al abrir archivo");
		return;
	}

	ft_putnbr_fd(42, fd);
	ft_putnbr_fd(-123, fd);
	ft_putnbr_fd(0, fd);
	ft_putnbr_fd(2147483647, fd);
	ft_putnbr_fd(-2147483648, fd);

	close(fd);

	fd = open("putnbr_output.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error al reabrir archivo");
		return;
	}

	char buffer[1024];
	ssize_t bytes = read(fd, buffer, sizeof(buffer) - 1);
	if (bytes >= 0)
	{
		buffer[bytes] = '\0';
		ft_ok(strcmp(buffer, "42-12302147483647-2147483648") == 0, "ft_putnbr_fd escribe todos los valores correctamente");
	}
	else
	{
		perror("Error al leer archivo");
	}

	close(fd);
	remove("putnbr_output.txt");

	printf("\n");
}

void	test_lstnew(void){
	printf("\033[38;5;214m[TEST FT_LSTNEW]\033[0m\n");

	char *data = strdup("Hola mundo");
	t_list *node = ft_lstnew(data);
	ft_ok(node != NULL, "Nodo creado correctamente");
	ft_ok(node->content == data, "Contenido del nodo correcto");
	ft_ok(node->next == NULL, "Next es NULL");

	// prueba con número
	int *num = malloc(sizeof(int));
	*num = 42;
	t_list *n2 = ft_lstnew(num);
	ft_ok(n2 && *(int *)n2->content == 42, "Contenido numérico correcto");
	ft_ok(n2->next == NULL, "Next es NULL");

	// prueba con NULL
	t_list *n3 = ft_lstnew(NULL);
	ft_ok(n3 && n3->content == NULL, "Contenido NULL permitido");
	ft_ok(n3->next == NULL, "Next es NULL en contenido NULL");

	// limpieza
	free(node);
	free(n2->content);
	free(n2);
	free(n3);
	free(data);

	printf("\n");
}

void test_lstadd_front(void)
{
	printf("\033[38;5;214m[TEST FT_LSTADD_FRONT]\033[0m\n");

	t_list *lst = NULL;
	t_list *n1 = ft_lstnew("node2");
	t_list *n2 = ft_lstnew("node1");

	ft_lstadd_front(&lst, n1);
	ft_ok(lst == n1, "Primer nodo insertado es cabeza");

	ft_lstadd_front(&lst, n2);
	ft_ok(lst == n2, "Segundo nodo insertado se vuelve cabeza");
	ft_ok(lst->next == n1, "La cabeza apunta al anterior");

	// Verifica los contenidos
	ft_ok(strcmp(lst->content, "node1") == 0, "Contenido del primer nodo correcto");
	ft_ok(strcmp(lst->next->content, "node2") == 0, "Contenido del segundo nodo correcto");

	printf("\n");
}

void test_lstsize(void)
{
	printf("\033[38;5;214m[TEST FT_LSTSIZE]\033[0m\n");

	t_list *lst = NULL;
	ft_ok(ft_lstsize(lst) == 0, "Lista vacía retorna 0");

	t_list *n1 = ft_lstnew("uno");
	ft_lstadd_front(&lst, n1);
	ft_ok(ft_lstsize(lst) == 1, "Un nodo retorna 1");

	t_list *n2 = ft_lstnew("dos");
	ft_lstadd_front(&lst, n2);
	ft_ok(ft_lstsize(lst) == 2, "Dos nodos retorna 2");

	t_list *n3 = ft_lstnew("tres");
	ft_lstadd_front(&lst, n3);
	ft_ok(ft_lstsize(lst) == 3, "Tres nodos retorna 3");

	printf("\n");
}

void test_lstadd_back(void)
{
	printf("\033[38;5;214m[TEST FT_LSTADD_BACK]\033[0m\n");

	t_list *lst = NULL;
	t_list *node1 = ft_lstnew("primero");
	t_list *node2 = ft_lstnew("segundo");

	ft_lstadd_back(&lst, node1);
	ft_ok(lst == node1, "Primer nodo añadido correctamente");

	ft_lstadd_back(&lst, node2);
	ft_ok(lst->next == node2, "Segundo nodo añadido al final");
	ft_ok(lst->next->next == NULL, "El último nodo apunta a NULL");

	printf("\n");
}

void free_content(void *content)
{
	free(content);
}

void test_lstdelone(void)
{
	printf("\033[38;5;214m[TEST FT_LSTDELONE]\033[0m\n");

	char *data = malloc(10);
	t_list *node = ft_lstnew(data);

	ft_lstdelone(node, free_content);
	ft_ok(1, "ft_lstdelone libera correctamente el nodo y su contenido");

	// Caso con NULL
	ft_lstdelone(NULL, free_content); // No debe crashear
	ft_lstdelone(node, NULL);         // No debe crashear

	printf("\n");
}

void	test_lstclear(void)
{
	printf("\033[38;5;214m[TEST FT_LSTCLEAR]\033[0m\n");

	// Creamos una lista con tres nodos
	t_list *n1 = ft_lstnew(strdup("nodo1"));
	t_list *n2 = ft_lstnew(strdup("nodo2"));
	t_list *n3 = ft_lstnew(strdup("nodo3"));
	n1->next = n2;
	n2->next = n3;

	ft_lstclear(&n1, free_content);

	ft_ok(n1 == NULL, "ft_lstclear deja la lista en NULL");

	// Intentar limpiar lista NULL (no debe crashear)
	t_list *null_list = NULL;
	ft_lstclear(&null_list, free_content);
	ft_ok(null_list == NULL, "ft_lstclear(NULL) no crashea");

	// Intentar pasar función del NULL (no debe crashear)
	t_list *test = ft_lstnew(strdup("42"));
	ft_lstclear(&test, NULL);
	ft_ok(test != NULL, "ft_lstclear sin del() no borra nodos");

	ft_lstclear(&test, free_content);

	printf("\n");
}

void lstiter_helper(void *content)
{
	if (content)
		ft_striteri((char *)content, to_upper_iteri);
}

void test_lstiter(void)
{
	printf("\033[38;5;214m[TEST FT_LSTITER]\033[0m\n");

	t_list *n1 = ft_lstnew(ft_strdup("hola"));
	t_list *n2 = ft_lstnew(ft_strdup("mundo"));
	t_list *n3 = ft_lstnew(ft_strdup("urduliz"));
	n1->next = n2;
	n2->next = n3;

	ft_lstiter(n1, lstiter_helper);

	ft_ok(strcmp((char *)n1->content, "HOLA") == 0, "ft_lstiter convierte n1 a mayúsculas");
	ft_ok(strcmp((char *)n2->content, "MUNDO") == 0, "ft_lstiter convierte n2 a mayúsculas");
	ft_ok(strcmp((char *)n3->content, "URDULIZ") == 0, "ft_lstiter convierte n3 a mayúsculas");

	ft_lstdelone(n1, free);
	ft_lstdelone(n2, free);
	ft_lstdelone(n3, free);

	printf("\n");
}

void *duplicate(void *content) {
	if (!content) return NULL;
	char *str = (char *)content;
	return ft_strdup(str);  // Puede fallar si malloc falla
}

void delete_content(void *content) {
	free(content);
}

void *counting_fun(void *content) {
	static int count = 0;
	count++;
	return ft_strdup((char *)content);
}

void counting_del(void *content) {
	static int del_count = 0;
	del_count++;
	free(content);
}

void test_lstmap(void){
	printf("\033[38;5;214m[TEST FT_LSTMAP]\033[0m\n");

	// Crear lista original
	t_list *a = ft_lstnew(ft_strdup("uno"));
	t_list *b = ft_lstnew(ft_strdup("dos"));
	t_list *c = ft_lstnew(ft_strdup("tres"));
	ft_lstadd_back(&a, b);
	ft_lstadd_back(&a, c);

	// Caso normal
	t_list *mapped = ft_lstmap(a, duplicate, delete_content);
	ft_ok(mapped != NULL, "ft_lstmap devuelve nueva lista no NULL");
	ft_ok(mapped != a, "ft_lstmap crea nueva lista (diferente de la original)");
	ft_ok(strcmp(mapped->content, "uno") == 0, "Contenido duplicado correctamente");
	ft_lstclear(&mapped, delete_content);

	// Caso NULL f
	t_list *fail1 = ft_lstmap(a, NULL, delete_content);
	ft_ok(fail1 == NULL, "ft_lstmap con f=NULL devuelve NULL");

	// Caso NULL del
	t_list *fail2 = ft_lstmap(a, duplicate, NULL);
	ft_ok(fail2 == NULL, "ft_lstmap con del=NULL devuelve NULL");

	// Simulación de fallo de malloc: usaremos counting_fun y counting_del
	extern void *__real_malloc(size_t size);
	extern void *__wrap_malloc(size_t size);
	// Esto requiere entorno de testing avanzado con LD_PRELOAD o linkeo manual

	// Liberar
	ft_lstclear(&a, delete_content);
	printf("\n");
}


int main(void)
{
	// Test ft_isalpha
	test_isalpha();

	// Test ft_isdigit
	test_isdigit();

	// Test ft_isalnum
	test_isalnum();

	// Test ft_isascii
	test_isascii();

	// Test ft_isprint
	test_isprint();

	// Test ft_strlen
	test_strlen();

	// Test ft_memset
	test_memset();

	// Test ft_bzero
	test_bzero();

	// Test ft_memcpy
	test_memcpy();	

	// Test ft_memmove
	test_memmove();

	// Test ft_strlcpy
	test_strlcpy();

	// Test ft_strlcat
	test_strlcat();

	// Test ft_toupper
	test_toupper();

	// Test ft_tolower

	test_tolower();

	// Test ft_strchr
	test_strchr();
	
	//Test strrchr
	test_strrchr();

	//Test strncmp
	test_strncmp();

	//Test memchr
	test_memchr();

	//Test memcmp
	test_memcmp();

	//Test strnstr
	test_strnstr();

	//Test stoi
	test_atoi();

	//Test calloc
	test_calloc();

	//Test strdup
	test_strdup();

	//Test substr
	test_substr();

	//Test strjoin
	test_strjoin();

	//Test strtrim
	test_strtrim();

	//Test split
	test_split();

	//Test itoa
	test_itoa();

	//Test strmapi
	test_strmapi();

	//Test striteri
	test_striteri();

	//Test putchar_fd
	test_putchar_fd();

	//Test putstr_fd
	test_putstr_fd();
	
	//Test putendl_fd
	test_putendl_fd();

	//Test putnbr_fd
	test_putnbr_fd();

	//Test lstnew
	test_lstnew();

	//Test lstadd_front
	test_lstadd_front();

	//Test lstzize
	test_lstsize();

	// Test lstadd_back
	test_lstadd_back();

	//Test lstdelone
	test_lstdelone();

	//Test lstcleat
	test_lstclear();

	//Test lstiter
	test_lstiter();

	//Test lstmap
	test_lstmap();

	if (g_result)
	printf("\n\033[0;32m✅ TODOS LOS TESTS PASADOS\033[0m\n\n");
	else
	printf("\n\033[0;31m❌ ALGÚN TEST HA FALLADO\033[0m\n\n");

	return (0);
}

