# get_next_line

**Español**

**get_next_line** es un proyecto que consiste en implementar una función en C llamada `get_next_line`, que permite leer una línea de un archivo cada vez que se llama. Esta función es útil para procesar archivos de texto línea por línea, gestionando internamente un buffer eficiente y permitiendo múltiples descriptores de archivo abiertos simultáneamente.

---

## 📚 Descripción

El objetivo es crear una función que devuelva cada vez la siguiente línea de un archivo, manteniendo el estado entre llamadas sucesivas. Esta función debe funcionar correctamente con cualquier tipo de archivo, soportando archivos grandes, múltiples descriptores y cualquier tamaño de línea.

### Función principal

```c
char *get_next_line(int fd);
```

- **fd**: Descriptor de archivo desde el que leer.
- **Devuelve**: La siguiente línea (incluyendo el salto de línea, si lo hay) o `NULL` si se llegó al final del archivo o hay error.

---

## 🛠️ Compilación

Asegúrate de tener un compilador de C instalado.

```bash
git clone https://github.com/Juansito19/get_next_line.git
cd get_next_line
make
```

Esto generará los archivos objeto y la librería `libftgnl.a` si está implementada.

---

## 🚀 Uso

Incluye el archivo de cabecera en tu proyecto:

```c
#include "get_next_line.h"
```

Compila tu programa junto con los archivos objeto o la librería generada:

```bash
gcc main.c get_next_line.c get_next_line_utils.c -o mi_programa
# o si tienes la librería
gcc main.c libftgnl.a -o mi_programa
```

Ejemplo de uso en C:

```c
int fd = open("archivo.txt", O_RDONLY);
char *line;
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

---

## 📝 Notas sobre la implementación

- El buffer size puede configurarse (por defecto suele ser 42 o 1024).
- El código es portable y sigue buenas prácticas de manejo de memoria.
- Soporta múltiples descriptores de archivo abiertos en paralelo.

---

## 📂 Estructura del proyecto

- `get_next_line.c` y `get_next_line_utils.c`: Código fuente de la función principal y utilidades.
- `get_next_line.h`: Archivo de cabecera.
- `Makefile`: Automatiza la compilación.

---

## 🧑‍💻 Autor

- Juan ([@Juansito19](https://github.com/Juansito19))

---

# get_next_line

**English**

**get_next_line** is a project that consists of implementing a C function called `get_next_line`, which allows you to read one line at a time from a file descriptor. This function is useful for processing text files line by line, managing an efficient internal buffer, and supporting multiple open file descriptors simultaneously.

---

## 📚 Description

The goal is to create a function that, upon each call, returns the next line from a file, maintaining state between calls. The function should work correctly with any type of file, support large files, multiple descriptors, and any line size.

### Main function

```c
char *get_next_line(int fd);
```

- **fd**: File descriptor to read from.
- **Returns**: The next line (including the newline character, if present) or `NULL` if end-of-file is reached or on error.

---

## 🛠️ Compilation

Make sure you have a C compiler installed.

```bash
git clone https://github.com/Juansito19/get_next_line.git
cd get_next_line
make
```

This will generate the object files and the `libftgnl.a` library if implemented.

---

## 🚀 Usage

Include the header file in your project:

```c
#include "get_next_line.h"
```

Compile your program along with the object files or the generated library:

```bash
gcc main.c get_next_line.c get_next_line_utils.c -o my_program
# or if you have the library
gcc main.c libftgnl.a -o my_program
```

Example usage in C:

```c
int fd = open("file.txt", O_RDONLY);
char *line;
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

---

## 📝 Implementation notes

- The buffer size can be configured (commonly 42 or 1024).
- The code is portable and follows good memory management practices.
- Supports multiple file descriptors opened in parallel.

---

## 📂 Project structure

- `get_next_line.c` and `get_next_line_utils.c`: Main function and utilities source code.
- `get_next_line.h`: Header file.
- `Makefile`: Build automation.

---

## 🧑‍💻 Author

- Juan ([@Juansito19](https://github.com/Juansito19))
