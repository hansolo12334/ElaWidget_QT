﻿cmake_minimum_required(VERSION 3.5)

project(ElaWidget_QT VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-std=c++17)
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network Multimedia)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network Multimedia Sql)

# FILE(GLOB ORIGIN *.cpp *.h)
# FILE(GLOB MODELVIEW ModelView/*.h ModelView/*.cpp)
# FILE(GLOB EAXMPLEPAGE ExamplePage/*.h ExamplePage/*.cpp)
FILE(GLOB SOURCE_FILE src/*.cpp)
FILE(GLOB HEADER_FILE include/*.h)
FILE(GLOB PAGES_FILE include/pages/*.h src/pages/*.cpp)
FILE(GLOB TOOLS include/tools/*.h src/tools/*.cpp)
# source_group(ModelView FILES ${MODELVIEW})
# source_group(ExamplePage FILES ${EAXMPLEPAGE})

# source_group(PAGES_SOURCE FILES ${PAGES_FILE})
SET(PAGES_SOURCE include/pages/)
SET(TOOLS_SOURCE include/tools/)

message(STATUS "SOURCE_FILE : ${SOURCE_FILE}")


set(PROJECT_SOURCES
    # ${ORIGIN}
    # ${MODELVIEW}
    # ${EAXMPLEPAGE}
    ${SOURCE_FILE}
    ${HEADER_FILE}
    ${PAGES_FILE}
    ${TOOLS}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ElaWidget_QT
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

    #遍历所有资源文件
    file(GLOB_RECURSE RES_PATHS *.png *.jpg *.svg *.ico *.ttf *.webp *.js)
    foreach(filepath ${RES_PATHS})
            string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/" "" filename ${filepath})
            list(APPEND resource_files ${filename})
    endforeach(filepath)

    qt_add_resources(${PROJECT_NAME} "ElaWidget_QT"
        RESOURCES PREFIX "/"
        FILES
        ${resource_files}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ElaWidget_QT APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ElaWidget_QT SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        qt5_add_big_resources(PROJECT_SOURCES
            ../src/include/ElaWidgetTools.qrc
            ElaWidget_QT.qrc
        )
        add_executable(ElaWidget_QT
            ${PROJECT_SOURCES}
        )
    endif()
endif()

list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/third_party/install/lib/cmake/)
find_package(ELAWIDGETTOOLS REQUIRED)
if(ELAWIDGETTOOLS_FOUND)
    message(STATUS "ELAWIDGETTOOLS_INCLUDE_DIR = ${ELAWIDGETTOOLS_INCLUDE_DIRS}")
    message(STATUS "ELAWIDGETTOOLS_LIBRARIES = ${ELAWIDGETTOOLS_LIBRARIES}")
    message(STATUS "ELAWIDGETTOOLS_LIB_DIR = ${ELAWIDGETTOOLS_LIBRARY_DIRS}")
endif ()
set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_BINARY_DIR})
include_directories(include)

target_include_directories(ElaWidget_QT PUBLIC
    ${ELAWIDGETTOOLS_INCLUDE_DIRS}
    # ExamplePage
    # ModelView
    ${PAGES_SOURCE}
    ${TOOLS_SOURCE}
)
target_link_libraries(ElaWidget_QT PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Multimedia
    Qt${QT_VERSION_MAJOR}::Sql
    ElaWidgetTools
)
target_link_directories(ElaWidget_QT PUBLIC
    ${ELAWIDGETTOOLS_LIBRARY_DIRS}
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ElaWidget_QT)
endif()
set_target_properties(ElaWidget_QT PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE FALSE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ElaWidget_QT)
endif()


set(SOURCE_DLL "${CMAKE_SOURCE_DIR}/third_party/install/bin/ElaWidgetToolsd.dll")
set(TARGET_DLL "${CMAKE_BINARY_DIR}/$<CONFIG>/ElaWidgetToolsd.dll")

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${SOURCE_DLL}"
    "${TARGET_DLL}"
    COMMENT "Copying ElaWidgetToolsd.dll to output directory"
)
