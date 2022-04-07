project(SchedulingAlgorithm)

cmake_minimum_required(VERSION 3.1)

aux_source_directory(./project Project_Dir)

aux_source_directory(./project/src Src_Dir)

add_executable(example ${Project_Dir} ${Src_Dir})

include_directories(./project/include)