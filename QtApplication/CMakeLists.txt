cmake_minimum_required(VERSION 3.16)

project(QtApplication VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt5 with QtQuick
find_package(Qt5 REQUIRED COMPONENTS Quick)

# Add executable for the Qt application
add_executable(appQtApplication
    src/main.cpp
    src/NetworkManager.cpp
)

# # Add QML resources (ensure resources.qrc is set up correctly)
# qt5_add_resources(appQtApplication
#     resources.qrc
# )

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

target_include_directories(appQtApplication PRIVATE include)

# Link Qt5 libraries (for Qt Quick module)
target_link_libraries(appQtApplication
    PRIVATE Qt5::Quick
)

# Optional: Install section (if needed)
include(GNUInstallDirs)
install(TARGETS appQtApplication
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
