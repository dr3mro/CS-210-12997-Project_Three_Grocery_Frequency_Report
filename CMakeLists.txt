cmake_minimum_required(VERSION 3.16)

project(grocery LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Matches the Makefile: generate compile_commands.json for clangd and clang-tidy.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# Flags copied from the Makefile.
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

add_compile_options(-Wall -Wextra -pedantic)

file(GLOB_RECURSE GROCERY_SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(grocery main.cpp ${GROCERY_SOURCES})

target_include_directories(grocery PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}
)

# Expose the compilation database at build/ so clangd finds it without a per-preset path.
if(NOT WIN32)
    file(REMOVE ${CMAKE_SOURCE_DIR}/build/compile_commands.json)
    file(CREATE_LINK ${CMAKE_BINARY_DIR}/compile_commands.json
         ${CMAKE_SOURCE_DIR}/build/compile_commands.json SYMBOLIC)
endif()

# ---- docs and diagrams ----
find_program(DOXYGEN_EXECUTABLE doxygen)
if(DOXYGEN_EXECUTABLE)
    add_custom_target(docs
        COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Generating documentation with Doxygen"
    )
endif()

find_program(DOT_EXECUTABLE dot)
if(DOT_EXECUTABLE)
    set(DIAGRAM_NAMES grocery_flowchart grocery_class_diagram)
    set(DIAGRAM_PNGS "")
    foreach(name IN LISTS DIAGRAM_NAMES)
        set(dot_file ${CMAKE_SOURCE_DIR}/diagrams/${name}.dot)
        set(png_file ${CMAKE_SOURCE_DIR}/diagrams/${name}.png)
        add_custom_command(
            OUTPUT ${png_file}
            COMMAND ${DOT_EXECUTABLE} -Tpng ${dot_file} -o ${png_file}
            DEPENDS ${dot_file}
            COMMENT "Rendering ${name}.png"
        )
        list(APPEND DIAGRAM_PNGS ${png_file})
    endforeach()
    add_custom_target(diagrams DEPENDS ${DIAGRAM_PNGS})
endif()
