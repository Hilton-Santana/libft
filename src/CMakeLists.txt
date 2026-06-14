set(sub_dirs libchar
             libfd
             libmem
             libnb
             libstr
             t_lst
             vec_algebra
    )

foreach(sub_dir ${sub_dirs})
    add_subdirectory(${sub_dir})
endforeach()

