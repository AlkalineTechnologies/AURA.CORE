cmake_minimum_required(VERSION 3.10)

project(AURA.CORE VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS source/*.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS source/include/*.h)

add_library(AURA.CORE SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories( AURA.CORE
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/source/include
)

if(WIN32)

    set(SDL2_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/SDL2/include")
    set(SDL2_LIBRARY "${CMAKE_SOURCE_DIR}/SDL2/lib/x64/SDL2.lib")
else()
    find_package(SDL2 REQUIRED)
    set(SDL2_INCLUDE_DIR ${SDL2_INCLUDE_DIRS})
    set(SDL2_LIBRARY ${SDL2_LIBRARIES})
endif()

target_include_directories( AURA.CORE PRIVATE ${SDL2_INCLUDE_DIRS} )
target_link_libraries( AURA.CORE PRIVATE ${SDL2_LIBRARIES} )

if (WIN32)
    target_compile_definitions(AURA.CORE PRIVATE AURA_PLATFORM_WINDOWS)
elseif(LINUX)
    target_compile_definitions(AURA.CORE PRIVATE AURA_PLATFORM_LINUX)
elseif(APPLE)
    target_compile_definitions(AURA.CORE PRIVATE AURA_PLATFORM_MACOS)
endif()


