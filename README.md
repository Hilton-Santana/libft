# Libft

First project of Level 0 42 grade school. It involves reproducing important functions of the standard library of C. 
We added a CMakeLists.txt at the source to allow cross-platform compilation.

# Compiling

```
cmake -B build
cmake --build build
```

# Consuming
```
if (TARGET libft)
    return()
endif()


include(FetchContent)

FetchContent_Declare(
    libft
    GIT_REPOSITORY https://github.com/Hilton-Santana/libft.git
    GIT_TAG        v1.0.0
)

FetchContent_MakeAvailable(libft)
```
