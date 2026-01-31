# Minimum required CMake version
cmake_minimum_required(VERSION 3.12)

# Project information: name, language, and version
project(MouseHeartbeat VERSION 1.0
  LANGUAGES CXX
)

# Specify the C++ standard (e.g., C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    # Set a custom default path if the user hasn't specified one
    set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/install" CACHE PATH "default install path" FORCE)
endif()

add_subdirectory(src)