cmake_minimum_required(VERSION 3.10)
project(MSH_M5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(MSH_M5)

target_include_directories(MSH_M5
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/external
    
    PRIVATE
        src
        external
)

target_sources(MSH_M5
    PRIVATE
        src/MSH_M5.cpp
        src/LogManager.cpp
        src/NotificationListener.cpp
    
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/MSH_M5.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/ILogger.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/IObserver.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/NotificationType.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/LogManager.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/NotificationListener.h
)

include(CTest)
enable_testing()

# FOR TESTING

#[[

add_executable(MSH_Test src/Main.cpp)
target_link_libraries(MSH_Test PRIVATE MSH_M5)

]]