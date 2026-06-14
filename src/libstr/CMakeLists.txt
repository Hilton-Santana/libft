set(sources ft_split.c
             ft_strdup.c
             ft_strjoin.c
             ft_strlcpy.c
             ft_strmapi.c
             ft_strnstr.c
             ft_strtrim.c
             ft_strchr.c
             ft_striteri.c
             ft_strlcat.c
             ft_strlen.c
             ft_strncmp.c
             ft_strrchr.c
             ft_substr.c)

target_sources(libft PRIVATE ${sources})