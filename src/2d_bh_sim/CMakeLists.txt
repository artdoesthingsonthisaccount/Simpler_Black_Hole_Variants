add_executable(2d_bh_sim 
    main.cpp
    bh.cpp    
)


#old code:
# target_include_directories(2d_bh_sim PRIVATE
#     ${GLFW3_INCLUDE_DIRS}
#     ${GLEW_INCLUDE_DIRS}
# )
# target_link_directories(2d_bh_sim PRIVATE
#     ${GLFW3_LIBRARIES}
#     ${GLEW_LIBRARIES}
#     OpenGL::GL
#     Eigen3::Eigen
# )
# target_link_directories(2d_bh_sim PRIVATE
#     ${GLFW3_LIBRARY_DIRS}
#     ${GLEW_LIBRARY_DIRS}

# )
# target_link_options(2d_bh_sim PRIVATE
#     ${GLFW3_LDFLAGS_OTHER}
#     ${GLEW_LDFLAGS_OTHER}
# )

#weird linking fix I had to do because the GLEW package apparently doesn't ship a modern CMake Config file 
target_include_directories(2d_bh_sim PRIVATE ${GLEW_INCLUDE_DIRS})

#links the OpenGL and Eigen libraries
target_link_libraries(2d_bh_sim PRIVATE
    OpenGL::GL
    Eigen3::Eigen
    ${GLEW_LIBRARIES}
    glfw
)