add_executable(tutorial
    main.cpp
)

target_include_directories(tutorial PRIVATE ${GLEW_INCLUDE_DIRS})

target_link_libraries(tutorial PRIVATE
    OpenGL::GL
    Eigen3::Eigen
    ${GLEW_LIBRARIES}
    glfw
)


