cmake_minimum_required(VERSION 3.10.2)

project(datAFLow
  LANGUAGES CXX C
  DESCRIPTION "def-use chain fuzzer"
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

#
# LLVM
#

find_package(LLVM 12 REQUIRED)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION} in ${LLVM_CMAKE_DIR}")

list(APPEND CMAKE_MODULE_PATH ${LLVM_CMAKE_DIR})
include(AddLLVM)

if(NOT LLVM_ENABLE_RTTI)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")
endif(NOT LLVM_ENABLE_RTTI)

include_directories(SYSTEM ${LLVM_INCLUDE_DIRS})
include_directories(BEFORE include)
link_directories(${LLVM_LIBRARY_DIRS})
add_definitions(${LLVM_DEFINITIONS})

#
# datAFLow
#

include_directories(
  include
  ext/svf/include
  ext/aflplusplus/include
)

add_subdirectory(ext)
add_subdirectory(lib)
add_subdirectory(tools)
