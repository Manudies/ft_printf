# ft_printf

Este proyecto forma parte del programa de 42 y consiste en una reimplementación de la función `printf` de la biblioteca estándar de C.

## 🎯 Objetivo

Implementar una versión propia de `printf`, capaz de gestionar conversiones básicas y argumentos variables, respetando el comportamiento de la versión original.

## ✅ Parte obligatoria

La función `ft_printf` acepta los siguientes formatos:

- `%c` → carácter
- `%s` → string
- `%p` → puntero
- `%d` / `%i` → entero con signo
- `%u` → entero sin signo
- `%x` / `%X` → hexadecimal (minúscula/mayúscula)
- `%%` → símbolo del porcentaje

## ⭐ Parte bonus

Se ha implementado soporte para flags adicionales (`+`, ` `, `0`, `.`, `-`, `width`) aplicados a `%d`.

## 🛠️ Compilación

```bash
make            # Compila la parte obligatoria
make bonus      # Compila también los bonus
make clean      # Elimina los objetos
make fclean     # Limpia objetos y archivos finales
