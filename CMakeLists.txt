cmake_minimum_required(VERSION 2.6)

project(RayCast)

add_executable(RayCast 
src/main.cpp
src/Engine.cpp 
src/Player.cpp  
src/vec.cpp 
src/RayCast.cpp
src/Physics.cpp
src/Button.cpp

headers/Player.h 
headers/Engine.h 
headers/Button.h
headers/vec.h 
)

set(SFML_DIR "external/SFML-2.6.1/lib/cmake/SFML")

target_link_libraries(RayCast sfml-graphics)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_DIR}/cmake_modules")
find_package(SFML 2.5 REQUIRED graphics network audio window system)
