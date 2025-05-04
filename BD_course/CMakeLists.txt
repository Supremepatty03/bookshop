cmake_minimum_required(VERSION 3.16)

project(BD_course VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Sql Core Widgets)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt6 REQUIRED COMPONENTS WebEngineWidgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(BD_course
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        registration_window.h registration_window.cpp
        registration_window.ui
        db_connector.h db_connector.cpp
        db_inserter.h db_inserter.cpp
        db_queries.h db_queries.cpp
        registration_service.h registration_service.cpp
        book.h book.cpp
        bookcardwidget.h bookcardwidget.cpp bookcardwidget.ui
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET BD_course APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(BD_course SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(BD_course
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(BD_course PRIVATE
    Qt6::Core
    Qt6::Sql
    Qt6::Gui
    #Qt6::Test
    Qt6::Widgets
    Qt6::WebEngineWidgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.BD_course)
endif()
set_target_properties(BD_course PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/sdek_widget.html
               ${CMAKE_CURRENT_BINARY_DIR}/sdek_widget.html COPYONLY)

include(GNUInstallDirs)
install(TARGETS BD_course
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(BD_course)
endif()
