#!/bin/bash

# C'est kdo ! <3 Lucien
# Each of the files within this directory should be one-line long
TCSH_TESTS="./tests/functional_tests/tcsh"
BASH_TESTS="./tests/functional_tests/bash"

BIN="./42sh"
TCSH_BIN="/usr/bin/tcsh"
BASH_BIN="/usr/bin/bash"

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[1;34m'
WHITE='\033[1;37m'

total_tests=0
passed_tests=0

if [ ! -x "$BIN" ]  || [ ! -x "$BASH_BIN" ] || [ ! -x "$TCSH_BIN" ]; then
    echo "Please build $BIN using make, and make accesible $TCSH_BIN and $BASH_BIN."
    exit 1
fi

send_file_to_bin() {
    CH_BIN="$1"
    INPUT="$2"
    DEST="$3"
    while IFS= read -r line; do
        echo "$line"
    done <<< "$INPUT" | "$CH_BIN" >> $DEST 2>&1
}

compare_output() {
    input="$1"
    test_name="$2"
    O_BIN="$3"
    ((total_tests++))
    echo "Test n° $total_tests"
    send_file_to_bin "$BIN" "$input" ".my_output"
    my_res=$?
    my_output=$(strings .my_output)
    send_file_to_bin "$O_BIN" "$input" ".real_output"
    real_res=$?
    real_output=$(strings .real_output)
    rm .my_output .real_output
    if [[ "$my_output" == "$real_output" && ( $my_res -eq $real_res || ( $my_res -eq 84 && $real_res -eq 1 ) ) ]]; then
        ((passed_tests++))
        echo -e "$GREEN >> Passed: $test_name $WHITE"
        echo -e " - ExitCodes: ( $BIN : $my_res | $O_BIN : $real_res ) - "
        echo -e "----------------------------------------------\n"
    else
        echo -e $RED ">> Failed: $test_name $WHITE"
        echo "Given input: $input"
        echo -e "$my_output\nOutput: $my_res" > .my
        echo -e "$real_output\nOutput: $real_res" > .real
        echo -e "\n-> $BIN's Output:"
        echo -e "$YELLOW$my_output$WHITE <-"
        echo ""
        echo "-> $O_BIN's Output:"
        echo -e "$BLUE$real_output$WHITE <-"
        diff .my .real
        echo -e " - ExitCodes: ($YELLOW $BIN : $my_res$WHITE |$BLUE $O_BIN : $real_res$WHITE ) - "
        echo -e "----------------------------------------------\n"
        rm .my .real
    fi
}

echo -e "\n----------------------------------------------\n"
for filename in $(find -type f -path "$TCSH_TESTS*"); do
    if [ -f $filename ]; then
        compare_output "$(strings $filename)" "${filename#$TCSH_TESTS}" "$TCSH_BIN"
    fi
done
for filename in $(find -type f -path "$BASH_TESTS*"); do
    if [ -f $filename ]; then
        compare_output "$(strings $filename)" "${filename#$BASH_TESTS}" "$BASH_BIN"
    fi
done
 
echo "###        Results         ###"
if [ $total_tests == $passed_tests ]; then
    echo -e "          $GREEN $passed_tests$WHITE / $total_tests\n"
else
    echo -e "          $RED $passed_tests$WHITE / $total_tests\n"
fi
echo -e "###      $GREEN BizBiz <3$WHITE        ###"
