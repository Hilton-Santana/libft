set(sources ft_long_to_hex.c
             ft_printf.c
             ft_putchar_fd.c
             ft_putendl_fd.c
             ft_putnbr_base.c
             ft_putnbr_fd.c
             ft_putstr_fd.c
             get_next_line.c)

target_sources(libft PRIVATE ${sources})