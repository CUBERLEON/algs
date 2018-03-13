#! /bin/bash
ARGS=-std=c++14
TESTS_PATH=tests/
SRC_PATH=src
CATCH_PATH=libs/catch

TESTS_SRC=(
    main.cpp

    SortTests.cpp
    InvertionsTests.cpp

    CentroidTests.cpp
    CentroidDecompositionTests.cpp
)
TESTS_SRC=${TESTS_SRC[@]/#/$TESTS_PATH}

g++ $ARGS $ARGS_EXT -I$CATCH_PATH -I$SRC_PATH $TESTS_SRC && (./a.out; rm -f a.out)
test_exit_code=$?
exit "$test_exit_code"
