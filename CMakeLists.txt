cmake_minimum_required(VERSION 3.23)
project(libft C)


add_library(libft STATIC "")

add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/include/libft/libft.h
                   COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/src/libft.h 
                   ${CMAKE_CURRENT_BINARY_DIR}/include/libft/libft.h
                   COMMENT "Copying libft.h to build directory"
                   DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/libft.h
)

add_custom_target(libft_header ALL
                  DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/include/libft/libft.h
)

add_dependencies(libft libft_header)

# Export includes as interface
target_include_directories(libft INTERFACE
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
)

# Link math library
target_link_libraries(libft PUBLIC m)

add_subdirectory(src)