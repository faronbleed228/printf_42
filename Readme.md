*This project has been created as part of the 42 curriculum by ypopovyc.*

# ft_printf

## Description

ft_printf is a re-implementation of the standard C `printf` function. The goal is to understand how variadic functions work, how format strings are parsed, and how different data types are converted to their string representations.

The function handles the following conversions: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.

Bonus features include support for the following flags under all conversions: `-`, `0`, `.` (precision), minimum field width.

### Algorithm and Data Structure

The core of ft_printf is a loop that iterates over the format string character by character. When a `%` is encountered, a parser function (`ft_lstformat`) reads the following characters and fills a `t_format` structure containing:

- `conv` — the conversion specifier (`d`, `s`, `x`, etc.)
- `width` — the minimum field width
- `precision` — the precision value
- `has_precision` — whether a `.` was explicitly provided
- `minus` — left-align flag
- `zero` — zero-padding flag

This structure is then passed to a dispatcher (`ft_putvar`) which calls the appropriate output function for each type. Each output function is responsible for computing padding, precision zeros, and sign placement before writing to stdout via `write`.

The choice of a struct over passing individual parameters keeps function signatures clean and makes it easy to combine flags without adding complexity at each call site.

## Instructions

### Compilation

```bash
make        # builds libftprintf.a
make clean  # removes object files
make fclean # removes object files and library
make re     # fclean + make
```

### Usage

Include the header and link against the library:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! You are %d years old.\n", "world", 42);
    return (0);
}
```

Compile with:

```bash
cc  main.c libftprintf.a
```

### Testing

Clone the tester inside the project directory and run if you want the most amount of testing cases:

```bash
git clone https://github.com/Tripouille/printfTester
cd printfTester
make m   # mandatory tests
make b   # bonus tests
make a   # all tests
```

## Resources

- [cppreference — va_arg](https://en.cppreference.com/c/variadic/va_arg) — primary reference for understanding variadic argument handling in C
- [printf format string — Wikipedia](https://en.wikipedia.org/wiki/Printf_format_string) — overview of format specifiers and flag behavior
- [man 3 printf](https://man7.org/linux/man-pages/man3/printf.3.html) — official Linux manual page

### AI Usage

Claude (Anthropic) was used throughout the project strictly as a learning tool — never to write project code. Specifically it was used for:
- Explaining concepts such as variadic functions, integer promotion, and undefined behavior
- Clarifying edge cases (e.g. `INT_MIN`, `NULL` pointers, `%.0d` with zero)
- Generating test cases to compare ft_printf output against the original printf
- Debugging by explaining compiler errors and suggesting where to look

## Public regression checks

```sh
make re
make test
```

The test target compiles the checked-in harness with ASan/UBSan, then compares
both exact stdout bytes and the return value with system printf in separate
processes. The numeric matrix covers d/i/u/x/X, zero, signed limits including
INT_MIN, unsigned maximum, width, precision, left alignment and zero padding.
It includes the zero-with-zero-precision/width regressions for d/u/x/X.
It is not an exhaustive test of every supported specifier.

The Linux run on 2026-10-21 used `ASAN_OPTIONS=detect_leaks=0` because
LeakSanitizer could not inspect process threads. Use `make test SANITIZERS=`
if your compiler does not support the sanitizer flags.

Maintenance fixes and public tests were prepared with OpenAI Codex.
