add_executable(3d_bh_sim 
    main.cpp
    bh.cpp
)


#weird linking fix I had to do because the GLEW package apparently doesn't ship a modern CMake Config file 
target_include_directories(2d_bh_sim PRIVATE ${GLEW_INCLUDE_DIRS})

#links the OpenGL and Eigen libraries
target_link_libraries(3d_bh_sim PRIVATE
    OpenGL::GL
    Eigen3::Eigen
    ${GLEW_LIBRARIES}
    glfw
)