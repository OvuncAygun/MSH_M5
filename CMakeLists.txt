cmake_minimum_required(VERSION 3.10)
project(MSH_M5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(MSH_M5)

if(TARGET MSH_M1)
    target_link_libraries(MSH_M5 PUBLIC MSH_M1)
else()
    add_library(EXTERNAL INTERFACE)
    target_include_directories(EXTERNAL
        INTERFACE
            ${CMAKE_CURRENT_SOURCE_DIR}/external
    )
    target_link_libraries(MSH_M5 PUBLIC EXTERNAL)
endif()

target_include_directories(MSH_M5
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    
    PRIVATE
        src
)

target_sources(MSH_M5
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/MSH_M5.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/ILogger.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/IObserver.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/NotificationType.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/LogManager.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/NotificationListener.h
    
    PRIVATE
        src/MSH_M5.cpp
        src/LogManager.cpp
        src/NotificationListener.cpp
)

include(CTest)
enable_testing()

# FOR TESTING



add_executable(MSH_Test src/Main.cpp)
target_link_libraries(MSH_Test PRIVATE MSH_M5)

