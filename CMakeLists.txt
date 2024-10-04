cmake_minimum_required(VERSION 3.5)

project(06.homework)

add_executable(containers
    dm_vector.hpp
    dm_list_1_way.hpp
    dm_list_2_way.hpp

    containers.cpp
    
    )
set_target_properties(containers PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)