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
    ./sudoku.exe "$@"
}

clean()
{
    rm "${EXEC_PATH}/${EXEC_NAME}"
    rm "*.stackdump"
}

make_tests(){
    # Get src files and remove main.cpp
    cd $SRC_DIR
    src_files=$(ls -I main.cpp)

    for f in $(ls ${TEST_DIR}/test_*.cpp);
    do
        testname=$(basename $f .cpp)
        g++ ../$f $src_files -o "../$EXEC_PATH/$testname.exe"
    done
    cd ..
}

run_tests(){
    for f in $(ls ${EXEC_PATH}/test_*.exe);
    do
        testname=$(basename $f .exe)
        $EXEC_PATH/$testname.exe > "$OUTPUT_PATH/output_${testname}.txt"
    done
}

# Must run in base directory
cd $(dirname $0)

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
        run "${@:2}"
    ;;
    "clean" )
        clean
    ;;
    "tests" )
        make_tests
        run_tests
    ;;
esac
