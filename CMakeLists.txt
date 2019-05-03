cmake_minimum_required(VERSION 3.13)
project(LakLok)

set(CMAKE_CXX_STANDARD 14)

file(GLOB LOCAL_INCLUDES source_files/*.cpp source_files/*/*.cpp scenes/*)

add_executable(LakLok ${LOCAL_INCLUDES} main.cpp scenes/mainGame1.cpp scenes/mainGame2.cpp scenes/mainGame3.cpp scenes/mainGame4.cpp)

include_directories("C:/Dev/c-cpp-lib/SDL2-2.0.9/i686-w64-mingw32/include/SDL2")
link_directories("C:/Dev/c-cpp-lib/SDL2-2.0.9/i686-w64-mingw32/lib")
target_link_libraries(LakLok "C:/Dev/c-cpp-lib/SDL2-2.0.9/i686-w64-mingw32/lib/libSDL2.dll.a")

include_directories("C:/Dev/c-cpp-lib/SDL2_image-2.0.4/i686-w64-mingw32/include/SDL2")
link_directories("C:/Dev/c-cpp-lib/SDL2_image-2.0.4/i686-w64-mingw32/lib")
target_link_libraries(LakLok "C:/Dev/c-cpp-lib/SDL2_image-2.0.4/i686-w64-mingw32/lib/libSDL2_image.dll.a")

include_directories("C:/Dev/c-cpp-lib/SDL2_ttf-2.0.15/i686-w64-mingw32/include/SDL2")
link_directories("C:/Dev/c-cpp-lib/SDL2_ttf-2.0.15/i686-w64-mingw32/lib")
target_link_libraries(LakLok "C:/Dev/c-cpp-lib/SDL2_ttf-2.0.15/i686-w64-mingw32/lib/libSDL2_ttf.dll.a")