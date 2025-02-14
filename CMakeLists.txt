FIND_PACKAGE(Boost 1.53.0 COMPONENTS regex REQUIRED)
INCLUDE_DIRECTORIES(${BOOST_INCLUDED_DIR})

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
    unit_tests/unit_tests.cpp
    src/Parser.cpp
    src/Executor.cpp
)

ADD_EXECUTABLE(rshell
    src/main.cpp
    src/Parser.cpp
    src/Executor.cpp
)

TARGET_LINK_LIBRARIES(
    rshell
    LINK_PUBLIC ${BOOST_LIBRARIES}
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
