#creates .so object for the smartheap library 
add_library(smartheap SHARED
    src/heap.cpp #actual feature
    src/heap_utils.cpp #feature utils
    include/smartheap/smartheap.hpp #library's umbrella header (includes the latter two)
    include/smartheap/heap_utils.hpp #library's util header 
    include/smartheap/heap.hpp #library's feature header
)

#makes header files accessable by subprojects
target_include_directories(smartheap 
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)