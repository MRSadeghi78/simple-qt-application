cmake_minimum_required(VERSION 3.16)

project(QtApplication VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt5 with QtQuick
find_package(Qt5 REQUIRED COMPONENTS Quick)
find_package(Qt5 COMPONENTS Core Quick REQUIRED)

# Add executable for the Qt application
add_executable(appQtApplication
    main.cpp
    NetworkManager.cpp
    TimerManager.cpp
    ApplicationManager.cpp
    USBManager.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appQtApplication PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appQtApplication
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)


# Link Qt5 libraries (for Qt Quick module)
target_link_libraries(appQtApplication
    Qt5::Quick
    Qt5::Core
)

# Optional: Install section (if needed)
include(GNUInstallDirs)
install(TARGETS appQtApplication
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
