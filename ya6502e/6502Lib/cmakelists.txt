cmake_minimum_required(VERSION 3.7)

project(YA6502ELib)

add_compile_options(-W -Wall -Werror) #All warnings, all warning are errors

set (YA6502E_Sources
        "src/public/ya6502e.h"
        "src/private/ya6502e.cpp"
        "src/private/main_6502.cpp")

source_group("src" FILES ${YA6502E_Sources})

add_library(YA6502ELib ${YA6502E_Sources})

target_include_directories(YA6502ELib PUBLIC "${PROJECT_SOURCE_DIR}/src/public")
target_include_directories(YA6502ELib PRIVATE "${PROJECT_SOURCE_DIR}/src/private")
