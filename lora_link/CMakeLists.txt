add_library(lora_link
    kernel/kernel.cpp
    controller/controller.cpp
    data/data.cpp
)
target_include_directories(lora_link PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(lora_link PUBLIC px4_link)
