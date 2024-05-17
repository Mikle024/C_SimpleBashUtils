#!/bin/bash

i = 0
suc=0
fail = 0
PATTERN_1 = Hello
PATTERN_2 = world
TESTS_FILES=tests/test_files/*.txt
PATTERN_FILE=tests/test_files/pattern.txt
COUNTER=0

testing() {
i=$((i+1))
grep $var $PATTERN_1 $TESTS_FILES > 1
./s21_grep $var $PATTERN_1 $TESTS_FILES > 2

diff 1 2

if [ $? -eq  0 ]
then
    echo "Test $i. $var: SUCCESSFUL"
    suc=$((suc+1))
    echo "---------------------------------------------------"
else
    echo "Test $i. $var: FAILED"
    fail=$((fail+1))
    echo "---------------------------------------------------"
fi
}

for var1 in v c l n h o
do
    var="-$var1"
    testing $i
done

for var1 in v c l n h o
do
    for var2 in v c l n h o
    do
        if [ $var1 != $var2 ]
        then

            var="-$var1 -$var2"
            testing $i

        fi
    done
done

for var1 in v c l n h o
do
    for var2 in v c l n h o
    do
        for var3 in v c l n h o
        do
            if [ $var1 != $var2 ] && [ $var2 != $var3 ] && [ $var1 != $var3 ]
            then

                var="-$var1 -$var2 -$var3"
                testing $i

            fi
        done
    done
done


i=$((i+1))

grep -e $PATTERN_1 -e $PATTERN_2 $TESTS_FILES > 1
./s21_grep -e $PATTERN_1 -e $PATTERN_2 $TESTS_FILES > 2

diff 1 2

if [ $? -eq  0 ]
then
    echo "Test $i. Flags -e -e: SUCCESSFUL"
    suc=$((suc+1))
    echo "---------------------------------------------------"
else
    echo "Test $i. Flags -e -e: FAILED"
    fail=$((fail+1))
    echo "---------------------------------------------------"
fi


i=$((i+1))

grep -f $PATTERN_FILE $TESTS_FILES > 1
./s21_grep -f $PATTERN_FILE $TESTS_FILES > 2

diff 1 2

if [ $? -eq  0 ]
then
    echo "Test $i. Flag -f: SUCCESSFUL"
    suc=$((suc+1))
    echo "---------------------------------------------------"
else
    echo "Test $i. Flag -f: FAILED"
    fail=$((fail+1))
    echo "---------------------------------------------------"
fi
rm 1 2
echo "\033[31mFAIL: $fail\033[0m"
echo "\033[32mSUCCESS: $suc\033[0m"
echo "ALL: $i"