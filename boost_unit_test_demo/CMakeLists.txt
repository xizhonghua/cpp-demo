cmake_minimum_required(VERSION 2.8)

list(APPEND CMAKE_CXX_FLAGS "-std=c++11")

find_package (Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(/opt/local/include)
include_directories(./include)

## mylib
file (GLOB LIB_SOURCES src/*.cpp )
file (GLOB LIB_HEADERS include/mylib/*.h )
add_library (mylib ${LIB_SOURCES} ${LIB_HEADERS})
## tests

file (GLOB TEST_SOURCES test/*.cpp )

SET(testname test_all)
add_executable( ${testname} ${TEST_SOURCES} )

target_link_libraries (${testname}
                      mylib  
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
