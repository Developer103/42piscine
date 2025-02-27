#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

# Default values
PROGRAM_NAME="bsq"
TEST_DIR="test_maps"
VERBOSE=0
VALGRIND_CHECK=0

# Test counter
TOTAL_TESTS=0
PASSED_TESTS=0

# Help message
print_help() {
    echo -e "${BLUE}BSQ Tester${NC}"
    echo "Usage: $0 [options]"
    echo
    echo "Options:"
    echo "  -p, --program NAME    Set the program name (default: bsq)"
    echo "  -d, --dir DIR        Set the test directory (default: test_maps)"
    echo "  -v, --verbose        Enable verbose output"
    echo "  -m, --memory        Enable memory leak check with valgrind"
    echo "  -h, --help           Display this help message"
    echo
    echo "Example:"
    echo "  $0 -p my_bsq -d my_tests -v -m"
}

# Parse command line arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        -p|--program)
            PROGRAM_NAME="$2"
            shift 2
            ;;
        -d|--dir)
            TEST_DIR="$2"
            shift 2
            ;;
        -v|--verbose)
            VERBOSE=1
            shift
            ;;
        -m|--memory)
            VALGRIND_CHECK=1
            # Check if valgrind is installed
            if ! command -v valgrind &> /dev/null; then
                echo -e "${RED}Error: valgrind is not installed${NC}"
                exit 1
            fi
            shift
            ;;
        -h|--help)
            print_help
            exit 0
            ;;
        *)
            echo "Unknown option: $1"
            print_help
            exit 1
            ;;
    esac
done

# Create test directory if it doesn't exist
mkdir -p "$TEST_DIR"

# Function to log verbose messages
log_verbose() {
    if [ $VERBOSE -eq 1 ]; then
        echo -e "${BLUE}[DEBUG] $1${NC}"
    fi
}

# Function to run a test with optional memory check
run_test() {
    local test_name=$1
    local input=$2
    local expected=$3
    
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    
    echo -e "${YELLOW}Running test: ${test_name}${NC}"
    log_verbose "Input:\n$input"
    
    printf "$input" > "$TEST_DIR/temp_test.txt"
    
    # Run the program with or without valgrind
    if [ $VALGRIND_CHECK -eq 1 ]; then
        valgrind_output=$(valgrind --leak-check=full --error-exitcode=1 ./$PROGRAM_NAME "$TEST_DIR/temp_test.txt" 2>&1)
        valgrind_status=$?
        actual=$(./$PROGRAM_NAME "$TEST_DIR/temp_test.txt" 2>&1)
    else
        actual=$(./$PROGRAM_NAME "$TEST_DIR/temp_test.txt" 2>&1)
        valgrind_status=0
    fi
    
    log_verbose "Expected output:\n$expected"
    log_verbose "Actual output:\n$actual"
    
    # Compare output and check memory leaks
    if [ "$actual" == "$expected" ] && [ $valgrind_status -eq 0 ]; then
        echo -e "${GREEN}✓ Test passed${NC}"
        if [ $VALGRIND_CHECK -eq 1 ]; then
            echo -e "${GREEN}✓ No memory leaks detected${NC}"
        fi
        PASSED_TESTS=$((PASSED_TESTS + 1))
    else
        echo -e "${RED}✗ Test failed${NC}"
        if [ "$actual" != "$expected" ]; then
            echo "Expected:"
            echo "$expected"
            echo "Got:"
            echo "$actual"
        fi
        if [ $VALGRIND_CHECK -eq 1 ] && [ $valgrind_status -ne 0 ]; then
            echo -e "${RED}Memory leaks detected:${NC}"
            echo "$valgrind_output"
        fi
    fi
    echo "----------------------------------------"
}

# Function to run stdin test
run_stdin_test() {
    local test_name=$1
    local input=$2
    local expected=$3
    
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    
    echo -e "${YELLOW}Running stdin test: ${test_name}${NC}"
    log_verbose "Input:\n$input"
    
    # Run the program with stdin
    if [ $VALGRIND_CHECK -eq 1 ]; then
        actual=$(echo -ne "$input" | valgrind --leak-check=full --error-exitcode=1 ./$PROGRAM_NAME 2>&1)
        valgrind_status=$?
    else
        actual=$(echo -ne "$input" | ./$PROGRAM_NAME 2>&1)
        valgrind_status=0
    fi
    
    log_verbose "Expected output:\n$expected"
    log_verbose "Actual output:\n$actual"
    
    if [ "$actual" == "$expected" ] && [ $valgrind_status -eq 0 ]; then
        echo -e "${GREEN}✓ Stdin test passed${NC}"
        PASSED_TESTS=$((PASSED_TESTS + 1))
    else
        echo -e "${RED}✗ Stdin test failed${NC}"
        echo "Expected:"
        echo "$expected"
        echo "Got:"
        echo "$actual"
    fi
    echo "----------------------------------------"
}

# Check if program exists and is executable
if [ ! -x "./$PROGRAM_NAME" ]; then
    echo -e "${RED}Error: Program './$PROGRAM_NAME' not found or not executable${NC}"
    exit 1
fi

# Clean and rebuild if Makefile exists
if [ -f "Makefile" ]; then
    echo -e "${YELLOW}Cleaning and rebuilding...${NC}"
    make re
fi

echo -e "${YELLOW}Starting tests for $PROGRAM_NAME${NC}"
echo "Test directory: $TEST_DIR"
echo "----------------------------------------"

# Basic functionality tests
run_test "Basic 3x3" "3.ox\n...\n...\n...\n" $'xxx\nxxx\nxxx'
run_test "With obstacle" "3.ox\n.o.\n...\n...\n" $'.o.\nxx.\nxx.'
run_test "Minimal" "1.ox\n.\n" "x"

# Numeric character tests
run_test "Numbers as map chars 1" "3123\n111\n111\n111\n" $'333\n333\n333'
run_test "Numbers as map chars 2" "3789\n777\n777\n777\n" $'999\n999\n999'
run_test "Mixed numbers and dots" "3.12\n...\n.1.\n...\n" $'222\n212\n222'
run_test "Zero included" "3.0x\n...\n.0.\n...\n" $'.0.\nxx.\nxx.'
run_test "All different numbers" "3123\n456\n789\n123\n" $'333\n333\n333'

# Error handling tests
run_test "Invalid first line" "3.o\n...\n...\n...\n" "map error"
run_test "Different line lengths" "3.ox\n...\n..\n...\n" "map error"
run_test "Invalid character" "3.ox\n...\n.a.\n...\n" "map error"
run_test "Empty file" "" "map error"
run_test "Missing first line" "...\n...\n...\n" "map error"
run_test "Invalid size" "0.ox\n...\n...\n...\n" "map error"
run_test "Negative size" "-1.ox\n...\n...\n...\n" "map error"

# Edge cases
run_test "All obstacles" "3.ox\nooo\nooo\nooo\n" $'ooo\nooo\nooo'
run_test "Single obstacle" "3.ox\n...\n.o.\n...\n" $'x..\n.o.\n...'
run_test "Border case" "4.ox\n....\n.o..\n....\n....\n" $'..xx\n.oxx\n....\n....'

# Standard input tests
echo -e "${YELLOW}Running standard input tests...${NC}"
run_stdin_test "Basic stdin" "3.ox\n...\n...\n...\n" $'xxx\nxxx\nxxx'
run_stdin_test "Stdin with obstacle" "3.ox\n.o.\n...\n...\n" $'.o.\nxx.\nxx.'
run_stdin_test "Invalid stdin" "3.o\n...\n...\n...\n" "map error"

# Multiple files test
echo -e "${YELLOW}Testing multiple files...${NC}"
TOTAL_TESTS=$((TOTAL_TESTS + 1))
printf "3.ox\n...\n...\n...\n" > "$TEST_DIR/temp_test1.txt"
printf "2.ox\n..\n..\n" > "$TEST_DIR/temp_test2.txt"
if [ $VALGRIND_CHECK -eq 1 ]; then
    result=$(valgrind --leak-check=full --error-exitcode=1 ./$PROGRAM_NAME "$TEST_DIR/temp_test1.txt" "$TEST_DIR/temp_test2.txt" 2>&1)
    valgrind_status=$?
else
    result=$(./$PROGRAM_NAME "$TEST_DIR/temp_test1.txt" "$TEST_DIR/temp_test2.txt")
    valgrind_status=0
fi
expected=$'xxx\nxxx\nxxx\n\nxx\nxx'
if [ "$result" == "$expected" ] && [ $valgrind_status -eq 0 ]; then
    echo -e "${GREEN}✓ Multiple files test passed${NC}"
    PASSED_TESTS=$((PASSED_TESTS + 1))
else
    echo -e "${RED}✗ Multiple files test failed${NC}"
    echo "Expected:"
    echo "$expected"
    echo "Got:"
    echo "$result"
fi

# Performance tests
echo -e "${YELLOW}Running performance tests...${NC}"

# Medium map (50x50)
TOTAL_TESTS=$((TOTAL_TESTS + 1))
perl -e 'print "50.ox\n"; for (1..50) { print "." x 50 . "\n"}' > "$TEST_DIR/medium_map.txt"
start_time=$(date +%s.%N)
./$PROGRAM_NAME "$TEST_DIR/medium_map.txt" > /dev/null
end_time=$(date +%s.%N)
execution_time=$(echo "$end_time - $start_time" | bc)
if (( $(echo "$execution_time < 2" | bc -l) )); then
    echo -e "${GREEN}✓ Medium map test passed (Time: ${execution_time}s)${NC}"
    PASSED_TESTS=$((PASSED_TESTS + 1))
else
    echo -e "${RED}✗ Medium map test failed (Time: ${execution_time}s)${NC}"
fi

# Large map (100x100)
TOTAL_TESTS=$((TOTAL_TESTS + 1))
perl -e 'print "100.ox\n"; for (1..100) { print "." x 100 . "\n"}' > "$TEST_DIR/large_map.txt"
start_time=$(date +%s.%N)
./$PROGRAM_NAME "$TEST_DIR/large_map.txt" > /dev/null
end_time=$(date +%s.%N)
execution_time=$(echo "$end_time - $start_time" | bc)
if (( $(echo "$execution_time < 5" | bc -l) )); then
    echo -e "${GREEN}✓ Large map test passed (Time: ${execution_time}s)${NC}"
    PASSED_TESTS=$((PASSED_TESTS + 1))
else
    echo -e "${RED}✗ Large map test failed (Time: ${execution_time}s)${NC}"
fi

# Huge map (200x200)
TOTAL_TESTS=$((TOTAL_TESTS + 1))
perl -e 'print "200.ox\n"; for (1..200) { print "." x 200 . "\n"}' > "$TEST_DIR/huge_map.txt"
start_time=$(date +%s.%N)
./$PROGRAM_NAME "$TEST_DIR/huge_map.txt" > /dev/null
end_time=$(date +%s.%N)
execution_time=$(echo "$end_time - $start_time" | bc)
if (( $(echo "$execution_time < 10" | bc -l) )); then
    echo -e "${GREEN}✓ Huge map test passed (Time: ${execution_time}s)${NC}"
    PASSED_TESTS=$((PASSED_TESTS + 1))
else
    echo -e "${RED}✗ Huge map test failed (Time: ${execution_time}s)${NC}"
fi

# Special case tests
echo -e "${YELLOW}Running special case tests...${NC}"

# Empty lines tests
run_test "Empty lines before map" "\n\n3.ox\n...\n...\n...\n" "map error"
run_test "Empty lines in map" "3.ox\n...\n\n...\n...\n" "map error"
run_test "Empty lines after map" "3.ox\n...\n...\n...\n\n\n" "map error"

# Invisible character tests
run_test "Tab characters" "3\t\n\n\t..\n...\n...\n" "map error"
run_test "Special characters" "3\x00\x01\x02\n...\n...\n...\n" "map error"

# Same character tests
run_test "Same characters" "3xxx\n...\n...\n...\n" "map error"
run_test "Duplicate characters" "3ooo\n...\n...\n...\n" "map error"

# No newline at end test
echo "3.ox\n...\n...\n..." > "$TEST_DIR/no_newline.txt"
truncate -s -1 "$TEST_DIR/no_newline.txt"
run_test "No newline at end" "$(cat $TEST_DIR/no_newline.txt)" "map error"
rm -f "$TEST_DIR/no_newline.txt"

# Cleanup
rm -f "$TEST_DIR/temp_test.txt" "$TEST_DIR/temp_test1.txt" "$TEST_DIR/temp_test2.txt" \
      "$TEST_DIR/medium_map.txt" "$TEST_DIR/large_map.txt" "$TEST_DIR/huge_map.txt"

# Final results
echo -e "\n${YELLOW}Test Results:${NC}"
echo -e "Passed: ${GREEN}${PASSED_TESTS}/${TOTAL_TESTS}${NC} tests"
if [ $PASSED_TESTS -eq $TOTAL_TESTS ]; then
    echo -e "${GREEN}All tests passed!${NC}"
else
    echo -e "${RED}Some tests failed${NC}"
fi

# Exit with appropriate status
[ $PASSED_TESTS -eq $TOTAL_TESTS ] 