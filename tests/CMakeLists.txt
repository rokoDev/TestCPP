cmake_minimum_required(VERSION ${cmake_version})

project(${LibName}_test)



add_subdirectory(lib/googletest)

include_directories(${DIVISION_HEADERS_DIR})
include_directories(lib/googletest/googletest/include)

set(SOURCE_FILES main.cpp src/divider_tests.cpp)

add_executable(divider_tests ${SOURCE_FILES})
target_link_libraries(divider_tests division gtest)
install(TARGETS divider_tests DESTINATION bin)




message(STATUS "BOOST_ROOT >> ${BOOST_ROOT}")
  
include_directories(${LIB_HEADERS} ${Boost_INCLUDE_DIRS})

add_executable(test_executable
							main.cpp
							SomeClass_test.cpp
							)

target_link_libraries(test_executable
					${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
					${LibName}
)

add_test(NAME test1 COMMAND test_executable)
