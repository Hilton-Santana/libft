set(sources ft_bzero.c
             ft_calloc.c
             ft_memchr.c
             ft_memcmp.c
             ft_memcpy.c
             ft_memmove.c
             ft_memset.c)

target_sources(libft PRIVATE ${sources})