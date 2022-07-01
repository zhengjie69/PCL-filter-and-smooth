cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
 
 project(filter_and_smoothing)
 
 find_package(PCL 1.2 REQUIRED)
 
 include_directories(${PCL_INCLUDE_DIRS})
 link_directories(${PCL_LIBRARY_DIRS})
 add_definitions(${PCL_DEFINITIONS})

add_executable (filter_and_smoothing_ply src/filter_and_smoothing_ply.cpp)
target_link_libraries (filter_and_smoothing_ply ${PCL_LIBRARIES})

add_executable (filter_and_smoothing_pcd src/filter_and_smoothing_pcd.cpp)
target_link_libraries (filter_and_smoothing_pcd ${PCL_LIBRARIES})