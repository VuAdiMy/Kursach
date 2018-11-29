cmake_minimum_required(VERSION 3.12)
project(kursach)
set(CMAKE_CXX_STANDARD 17)

find_package(OPENGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})
include_directories("C:\\Program Files (x86)\\mingw-w64\\i686-8.1.0-win32-dwarf-rt_v6-rev0\\mingw32\\include\\GL")
set(LIBS "freeglut" "libSOIL.a" -lOpenGL32 -lglu32 -static-libstdc++ -static-libgcc)

add_executable(${PROJECT_NAME} Sources/main.cpp)
target_link_libraries(${PROJECT_NAME} ${LIBS})

