set(sources ft_isalnum.c
             ft_isalpha.c
             ft_isascii.c
             ft_isdigit.c
             ft_isprint.c
             ft_tolower.c
             ft_toupper.c)

target_sources(libft PRIVATE ${sources})