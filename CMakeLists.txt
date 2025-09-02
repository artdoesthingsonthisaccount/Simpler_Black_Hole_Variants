CMAKE_MINIMUM_REQUIRED(VERSION 3.16)

project(simpler_bh CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_REQUIRE_STANDARD ON)



find_package(PkgConfig REQUIRED) #cmake module for finding packages

#NOTE: I don't actually know how the pkg functions work
pkg_check_modules(GLFW3 REQUIRED glfw3) #requires finding glfw3 for window management
pkg_check_modules(GLEW  REQUIRED glew) #require finding glew for window managment (also???)
find_package(OpenGL REQUIRED) #require that we find the actual openGL package for rendering

find_package(Eigen3 3.3 REQUIRED NO_MODULE) # requires that we find the eigen package for math




#for my library subdirectory
add_subdirectory(lib/libsmartheap)

#for the subprojects
add_subdirectory(src/2d_bh_sim)
add_subdirectory(src/3d_bh_sim)
add_subdirectory(src/3d_bh_sim_smartheap)
add_subdirectory(src/3d_bh_sim_binary)