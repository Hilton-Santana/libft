set(sources ft_long_to_hex.c
             ft_printf.c
             ft_putchar_fd.c
             ft_putendl_fd.c
             ft_putnbr_base.c
             ft_putnbr_fd.c
             ft_putstr_fd.c
             get_next_line.c)

target_sources(libft PRIVATE ${sources})

set(exports
    get_next_line.h
)

set(export_outputs)

get_filename_component(CURRENT_MODULE_NAME
                       ${CMAKE_CURRENT_SOURCE_DIR}
                       NAME)

foreach(export ${exports})
    set(src_header ${CMAKE_CURRENT_SOURCE_DIR}/${export})
    set(dst_header ${CMAKE_BINARY_DIR}/include/libft/${CURRENT_MODULE_NAME}/${export})

    add_custom_command(
        OUTPUT ${dst_header}
        COMMAND ${CMAKE_COMMAND} -E make_directory
                ${CMAKE_BINARY_DIR}/include/libft/${CURRENT_MODULE_NAME}
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${src_header}
                ${dst_header}
        DEPENDS ${src_header}
        COMMENT "Copying ${export}"
    )

    list(APPEND export_outputs ${dst_header})
endforeach()

add_custom_target(libfd_exports ALL
    DEPENDS ${export_outputs}
)

add_dependencies(libft libfd_exports)