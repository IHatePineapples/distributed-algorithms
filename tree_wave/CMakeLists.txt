add_library(wave_node
    node.cpp
    node.hpp
)

target_link_libraries(wave_node
    node
)

add_executable(tree_wave_algorithm
    main.cpp
)

target_link_libraries(tree_wave_algorithm
    node
    wave_node
)   
