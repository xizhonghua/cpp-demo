## C++ Unit Test using Boost Unit Test Framework

#### Overview
In this demo, you will learn how to compile lib and test using cmake.

#### Folder Structure
```
├── include
│   └── mylib
│       ├── calc.h
│       └── fact.h
├── src
│   ├── clac.cpp
│   └── fact.cpp
└── test
    ├── test_calc.cpp
    └── test_fact.cpp
```

#### CMake file
```cmake
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
add_executable( ${testname} ${TEST_SOURCES})
## link our test executable with mylib and boost 
target_link_libraries (${testname}
                      mylib
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
```

#### Class for test
[./include/mylib/calc.h](include/mylib/calc.h)
```cpp
#ifndef __MY_LIB_CALC_H__
#define __MY_LIB_CALC_H__
class Calc
{
public:
    int add(int a, int b);
    int sub(int a, int b);
    int mul(int a, int b);
};
#endif //__MY_LIB_CALC_H__
```
[./include/mylib/fact.h](include/mylib/fact.h)
```cpp
#ifndef __MY_LIB_FACT_H__
#define __MY_LIB_FACT_H__
class Fact
{
public:
    int fact(int n);
};
#endif //__MY_LIB_FACT_H__
```
#### Test file
Notice, if you want to link multiple test file into one executable,
the macro `BOOST_TEST_DYN_LINK` should only be defined once.

[./test/test_calc.cpp](test/test_calc.cpp)
```cpp
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE calc
#include <boost/test/unit_test.hpp>
#include <mylib/calc.h>

BOOST_AUTO_TEST_CASE(Calc_add)
{
    Calc c;
    BOOST_CHECK(c.add(1,2) == 3);
    BOOST_CHECK(c.add(2,1) == 3);
}

BOOST_AUTO_TEST_CASE(Calc_sub)
{
    Calc c;
    BOOST_CHECK(c.sub(1,2) == -1);
    BOOST_CHECK(c.sub(2,1) == 1);
}

BOOST_AUTO_TEST_CASE(Calc_mul)
{
    Calc c;
    BOOST_CHECK(c.mul(1,2) == 2);
    BOOST_CHECK(c.mul(2,1) == 2);
    BOOST_CHECK(c.mul(2,0) == 0);
    BOOST_CHECK(c.mul(0,-1) == 0);
    BOOST_CHECK(c.mul(3,5) == 15);
}
```
[./test/test_fact.cpp](test/test_fact.cpp)
```cpp
#define BOOST_TEST_MODULE fact
#include <boost/test/unit_test.hpp>
#include <mylib/fact.h>

BOOST_AUTO_TEST_CASE(fact)
{
    Fact f;
    BOOST_CHECK(f.fact(0) == 1);
    BOOST_CHECK(f.fact(1) == 1);
    BOOST_CHECK(f.fact(2) == 2);
    BOOST_CHECK(f.fact(3) == 6);
    BOOST_CHECK(f.fact(4) == 24);
    BOOST_CHECK(f.fact(5) == 120);
}
```

#### Build
```shell
cmake .
make
```

#### Test results
```shell
Running 4 test cases...
boost_unit_test_demo/test/test_calc.cpp:17: error in "Calc_sub": check c.sub(1,2) == -1 failed
boost_unit_test_demo/test/test_calc.cpp:18: error in "Calc_sub": check c.sub(2,1) == 1 failed

*** 2 failures detected in test suite "calc"
```
