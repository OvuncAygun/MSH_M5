cmake_minimum_required(VERSION 3.10)
project(MSH_M5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    MSH_M1
    GIT_REPOSITORY https://github.com/OvuncAygun/MSH_M1.git
    GIT_TAG main
)

FetchContent_MakeAvailable(MSH_M1)

add_library(MSH_M5)

target_link_libraries(MSH_M5 MSH_M1)

target_include_directories(MSH_M5 PRIVATE
    include
    include/Test
    src
)

target_sources(MSH_M5
    PRIVATE
        src/MSH_M5.cpp
    
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/MSH_M5.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/ILogger.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/IObserver.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/NotificationType.h
)

include(CTest)
enable_testing()

