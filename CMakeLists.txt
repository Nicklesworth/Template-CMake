cmake_minimum_required(VERSION 3.20)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# project info
project(template_project VERSION 0.0.0)
add_executable(${PROJECT_NAME})

# auto-generated configuration file
configure_file(config.h.in config.h)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_BINARY_DIR})

# source files
target_sources(${PROJECT_NAME}
    PRIVATE
        ./src/main.c
        )

# includes
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ./src
        )
