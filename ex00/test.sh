#!/bin/bash

EXEC=./ex00
INPUT=input.txt

echo "===== RUNNING BitcoinExchange TESTS ====="
echo "Using input file: $INPUT"
echo ""

# Check if executable exists
if [ ! -f "$EXEC" ]; then
    echo "Error: executable '$EXEC' not found"
    exit 1
fi

# Check if input file exists
if [ ! -f "$INPUT" ]; then
    echo "Error: input file '$INPUT' not found"
    exit 1
fi

echo "===== FULL FILE TEST ====="
$EXEC $INPUT

echo ""
echo "===== EDGE CASE MANUAL TESTS ====="

echo "2009-01-02 | 1" | $EXEC
echo "2000-01-01 | 3" | $EXEC
echo "2001-02-29 | 4" | $EXEC
echo "2004-02-29 | 2" | $EXEC
echo "1900-02-29 | 5" | $EXEC
echo "2012-13-01 | 6" | $EXEC
echo "2012-01-01 | 1001" | $EXEC
echo "2012-01-01 | 3a" | $EXEC
echo "2012-01-01 | -1" | $EXEC

echo ""
echo "===== TEST DONE ====="
