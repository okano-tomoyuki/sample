cmake_minimum_required(VERSION 3.5)

project(sample VERSION 0.1 LANGUAGES CXX)

set(CXX $ENV{LOCAL_COMPILER})
set(CMAKE_CXX_COMPILER $ENV{LOCAL_COMPILER_PATH})

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Gui Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Gui Sql)

set(CMAKE_AUTOUIC_SEARCH_PATHS view/)
set(AUTOMOC_PATH_PREFIX ON)

file(GLOB_RECURSE Header include/*.hpp)
file(GLOB_RECURSE Source src/*.cpp)

set(PROJECT_SOURCES
    ${Header}
    ${Source}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(sample
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
endif()

target_include_directories(sample PRIVATE "${PROJECT_SOURCE_DIR}/include")

target_link_libraries(sample 
    PRIVATE 
        Qt${QT_VERSION_MAJOR}::Widgets 
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Sql

)

set_target_properties(sample PROPERTIES
    WIN32_EXECUTABLE TRUE
)

install(TARGETS sample
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(sample)
endif()
