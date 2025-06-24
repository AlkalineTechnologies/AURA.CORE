cmake_minimum_required(VERSION 3.10)

project(aura.core VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS source/*.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS source/*.h)
file(GLOB_RECURSE EXTLIB_SOURCE_FILES CONFIGURE_DEPENDS external/*.cpp)
file(GLOB_RECURSE EXTLIB_HEADER_FILES CONFIGURE_DEPENDS external/*.h)

add_library(aura.core SHARED ${SOURCE_FILES} ${HEADER_FILES} ${EXTLIB_SOURCE_FILES} ${EXTLIB_HEADER_FILES})
set_target_properties(aura.core PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_include_directories( aura.core
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/source/
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/external/
)

file(GLOB GLEW_SOURCES external/GLEW/glew.c)
add_library(glew STATIC ${GLEW_SOURCES})
target_include_directories(glew PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/external/GLEW)
target_compile_definitions(glew PUBLIC GLEW_STATIC)
set_target_properties(glew PROPERTIES LINKER_LANGUAGE C)

if(WIN32)
    set(SDL2_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/SDL2/include")
    set(SDL2_LIBRARY "${CMAKE_SOURCE_DIR}/SDL2/lib/x64/SDL2.lib")
else()
    find_package(SDL2 REQUIRED)
    set(SDL2_INCLUDE_DIR ${SDL2_INCLUDE_DIRS})
    set(SDL2_LIBRARY ${SDL2_LIBRARIES})
endif()

target_compile_options(aura.core PRIVATE -fvisibility=hidden)
target_include_directories( aura.core 
    PRIVATE ${SDL2_INCLUDE_DIRS}
)
target_link_libraries( aura.core 
    ${SDL2_LIBRARIES}
    GL
    glew
)

add_definitions(-DGLEW_STATIC -DGLEW_NO_GLU)

if (WIN32)
    target_compile_definitions(aura.core PRIVATE AURA_PLATFORM_WINDOWS)
elseif(LINUX)
    target_compile_definitions(aura.core PRIVATE AURA_PLATFORM_LINUX)
elseif(APPLE)
    target_compile_definitions(aura.core PRIVATE AURA_PLATFORM_MACOS)
endif()


