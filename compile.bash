#!/bin/bash

# cygwin doesn't come with make wtf

SRC_DIR="src"
EXEC_PATH="bin"
EXEC_NAME="sudoku.exe"
TEST_DIR="test"
OUTPUT_PATH="$TEST_DIR/output"

make()
{
    echo "g++ ${SRC_DIR}/*.cpp -o ${EXEC_PATH}/${EXEC_NAME}"
    g++ ${SRC_DIR}/*.cpp -o ${EXEC_PATH}/${EXEC_NAME}
}

run()
{
    cd "${EXEC_PATH}"
    ./sudoku.exe
}

clean()
{
    rm "${EXEC_PATH}/${EXEC_NAME}"
    rm "*.stackdump"
}

make_tests(){
    src_files=find $SRC_DIR/*.cpp ! -name 'main.cpp'
    echo $src_files
    for f in $TEST_DIR/test_*.cpp 
    do
        testname=$(basename $f .cpp)
        echo "g++ $f ${SRC_DIR}/*.cpp -o $EXEC_PATH/$testname.exe"
        g++ $f ${SRC_DIR}/*.cpp -o "$EXEC_PATH/$testname.exe"
    done
}

run_tests(){
    for f in $EXEC_DIR/test_*.exe
    do
        testname=$(basename $f .exe)
        $EXEC_PATH/$testname.exe > "$OUTPUT_PATH/output_$testname.txt"
    done
}

# Must run in base directory
cd $(dirname $0)
# Argument to compile/run/create
num=$2

if [[ ! -d ./$EXEC_PATH ]]; then
    mkdir $EXEC_PATH
fi
if [[ ! -d ./$OUTPUT_PATH ]]; then
    mkdir $OUTPUT_PATH
fi

case $1 in
    "make" )
        make
    ;;
    "run" )
        run
    ;;
    "clean" )
        clean
    ;;
    "tests" )
        make_tests
        run_tests
    ;;
esac
