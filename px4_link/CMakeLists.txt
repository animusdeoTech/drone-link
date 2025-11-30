add_library(px4_link
    kernel/kernel.cpp
    controller/controller.cpp
    data/data.cpp
)
target_include_directories(px4_link PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

