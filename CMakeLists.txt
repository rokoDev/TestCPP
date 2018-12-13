set(cmake_version 3.13.1)

cmake_minimum_required(VERSION ${cmake_version})

set(LibName "TestCPP")

project(${LibName} 
		VERSION 1.0.0.0
		LANGUAGES CXX)
		
message(STATUS "cur c++ compiler is:${CMAKE_CXX_COMPILER}")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fPIC -Wall")

set(LIB_HEADERS ${CMAKE_SOURCE_DIR}/include/${LibName})

enable_testing() #must be in root(top) CMakeLists.txt to avoid "No tests were found" message on Appveyor ci

add_subdirectory(src)
add_subdirectory(googletest)
add_subdirectory(tests)
