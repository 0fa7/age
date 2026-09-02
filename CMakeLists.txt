cmake_minimum_required(VERSION 4.3)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

project(age LANGUAGES CXX)

set(AGE_SOURCES
    "src/main.cpp")

add_executable(age ${AGE_SOURCES})
target_include_directories(age PUBLIC "C:/Program Files/SDL3/include")
target_link_directories(age PUBLIC "C:/Program Files/SDL3/lib")
target_link_libraries(age SDL3)

add_custom_command(TARGET age POST_BUILD        
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  
    "${PROJECT_SOURCE_DIR}/lib/SDL3.dll"      
    $<TARGET_FILE_DIR:age>) 