# Libft

![Standard](https://img.shields.io/badge/standard-ANSI%20C89-lightgrey.svg)
![License](https://img.shields.io/badge/license-MIT-blue.svg)

## Table of Content

1. [About Libft](#about-libft)
2. [Functions](#functions)
3. [Setup](#setup)
4. [License](#license)

## About Libft <a name="about-libft"></a>

Open source library with about 50 functions.
This is an author's copy of the popular functions of the C library for use in educational projects of [School 21 in Moscow](https://21-school.ru/) ("School 42" franchise).

## Functions <a name="functions"></a>

Libc functions | Additional functions | Personal Functions
:----------- | :-----------: | :-----------:
memset		| ft_memalloc	| ft_atoi_base
bzero		| ft_memdel		| ft_itoa_base
memcpy		| ft_strnew		| ft_convert_base
memccpy		| ft_strdel		| ft_srtcasecmp
memmove		| ft_strclr		| ft_sqrt
memchr		| ft_striter	|
memcmp		| ft_striteri	|
strlen		| ft_strmap		|
strdup		| ft_strmapi	|
strcpy		| ft_strequ		|
strncpy		| ft_strnequ	|
strcat		| ft_strsub		|
strlcat		| ft_strjoin	|
strchr		| ft_strtrim	|
strrchr		| ft_strsplit	|
strstr		| ft_itoa		|
strnstr		| ft_putchar	|
strcmp		| ft_putstr		|
strncmp		| ft_putendl	|
atoi		| ft_putnbr		|
isalpha		| ft_putchar_fd	|
isdigit		| ft_putstr_fd	|
isalnum		| ft_putendl_fd	|
isascii		| ft_putnbr_fd	|
isprint		|
toupper		|
tolower		|

## Setup <a name="setup"></a>

Download the repository, and compile the library using the Makefile.
You can use the following commands:

Command       |  Description
:-------------|:-------------
`make`        | Compile the library.
`make clean`  | Remove objects files.
`make fclean` | Remove objects files and the library.
`make re`     | Re-compile the library.

The binary `libft.a` will be created at the root of the project's directory.

### Local <a name="local"></a>

Copy the `includes/` directory into the root of your project, and
make sure to compile your source code with the following flags:

	gcc libft.a -I./includes <your_file.c> -o <output_name>

## License <a name="license"></a>

This project is licensed under the MIT License - see the [LICENSE](https://github.com/semenpindak/Libft/blob/master/LICENSE)
file for details.
