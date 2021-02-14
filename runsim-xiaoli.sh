#!/bin/bash
if [[ -f /.dockerenv ]]; then 
    EXEC_FILE="/code/sim-xiaoli/bin/riscv-console-sim"
    if [[ ! -f $EXEC_FILE ]]; then
        CUR_DIR="$(pwd)"
        MAKE_CMD="cd /code/sim-xiaoli && make clean && make && cd $CUR_DIR"
        echo $MAKE_CMD
        ( cd /code/sim-xiaoli && make clean && make && cd $CUR_DIR )
        if [ $? -ne 0 ]; then
            exit
        fi
    fi
    SIM_RUN_CMD="runuser -u docker $EXEC_FILE -- $@"
    echo $SIM_RUN_CMD
    $SIM_RUN_CMD
else
    EXEC_FILE="./sim-xiaoli/bin/riscv-console-sim"
    if [[ ! -f $EXEC_FILE ]]; then
        CUR_DIR="$(pwd)"
        MAKE_CMD="cd ./sim-xiaoli && make clean && make && cd $CUR_DIR"
        echo $MAKE_CMD
        (cd ./sim-xiaoli && make clean && make && cd $CUR_DIR)
        if [ $? -ne 0 ]; then
            exit
        fi
    fi
    echo "$EXEC_FILE" "$@"
    $EXEC_FILE "$@"
fi
