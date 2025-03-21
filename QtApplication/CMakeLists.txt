# Minimum CMake version requirement
cmake_minimum_required(VERSION 3.16)

# Project information
project(QtApplication VERSION 0.1 LANGUAGES CXX)

# Automatically handle the Qt moc preprocessor, ui files, and resource files
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find necessary Qt5 components
find_package(Qt5 REQUIRED COMPONENTS Core Quick)

# Locate and configure the libusb package
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBUSB REQUIRED libusb-1.0)

# Define the executable and list all associated source files
add_executable(appQtApplication
    main.cpp
    NetworkManager.cpp
    TimerManager.cpp
    ApplicationManager.cpp
    USBManager.cpp
)

# Set properties for MacOSX Bundle and Windows executable
set_target_properties(appQtApplication PROPERTIES
    MACOSX_BUNDLE TRUE
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    WIN32_EXECUTABLE TRUE
)

# Include directories for libusb
target_include_directories(appQtApplication PRIVATE ${LIBUSB_INCLUDE_DIRS})

# Link the application with Qt5 and libusb libraries
target_link_libraries(appQtApplication
    Qt5::Quick
    Qt5::Core
    ${LIBUSB_LIBRARIES}
)

# Add definitions from pkg-config for libusb
target_compile_definitions(appQtApplication PRIVATE ${LIBUSB_CFLAGS_OTHER})

# Specify installation rules
include(GNUInstallDirs)
install(TARGETS appQtApplication
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
