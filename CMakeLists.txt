# - Main CMake buildscript for mpags-cipher


# - Set CMake requirements and declare project
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

# - Set verbosity when generating makefile
set(CMAKE_VERBOSE_MAKEFILE ON)

# - Set vendor extensions to C++11 off

set(CMAKE_CXX_EXTENSIONS OFF)

# - Declare the build of mpags-cipher main program
add_executable(mpags-cipher
  mpags-cipher.cpp
  MPAGSCipher/transformChar.cpp
  MPAGSCipher/transformChar.hpp
  MPAGSCipher/processCommandLine.cpp
  MPAGSCipher/processCommandLine.hpp
  MPAGSCipher/outputStr.cpp
  MPAGSCipher/outputStr.hpp
  MPAGSCipher/runCaesarCipher.cpp
  MPAGSCipher/runCaesarCipher.hpp
)

# Copy 'test' file
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/long.txt
      DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_include_directories(mpags-cipher
  PRIVATE MPAGSCipher
  )

# - Set compiler flags

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

target_compile_features(mpags-cipher
  PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization cxx_binary_literals
  )