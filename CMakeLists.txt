cmake_minimum_required(VERSION 3.10)

# set c compiler
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

# set project name 
project(game_of_life)

# specify the c standard
set(CMAKE_C_STANDARD 11)

# Add source files
set(SOURCES 
    src/main.c 
    src/array.c
)

# link directory
link_directories(${PROJECT_SOURCE_DIR}/raylib-5.0_win64_mingw-w64/lib)

# includes directoryes
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/raylib-5.0_win64_mingw-w64/include
)

# add the executable 
add_executable(${PROJECT_NAME} ${SOURCES})

# link raylib
target_link_libraries(${PROJECT_NAME} raylib winmm gdi32)