cmake_minimum_required(VERSION 3.7)
project(myapp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)


add_subdirectory(lib/uni-algo-1.2.0)
add_subdirectory(lib/fmt-10.2.0)

set(
    SOURCES_FILES
    src/main.cpp
    src/Lexer.cpp
    src/persian_toolkit.cpp
    src/file_toolkit.cpp
    src/Token.cpp
    src/Parser.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE uni-algo fmt)
target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    lib/uni-algo-1.2.0/include
    lib/fmt-10.2.0/include
    include
)
