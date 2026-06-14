cmake_minimum_required(VERSION 3.23)
project(libft C)


add_library(libft STATIC "")

add_custom_command(TARGET libft POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/src/libft.h 
                   ${CMAKE_CURRENT_BINARY_DIR}/include/libft/libft.h
                   COMMENT "Copying libft.h to build directory"
                   DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/libft.h
)

# Export includes as interface
target_include_directories(libft INTERFACE
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
                           $<INSTALL_INTERFACE:include>
)

add_subdirectory(src)