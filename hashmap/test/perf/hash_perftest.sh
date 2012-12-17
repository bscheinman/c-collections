#/usr/bin/sh

ELEMENT_COUNT=2000000

for i in 32768 65536 131072 262144 524288 2000000
do
    echo "$ELEMENT_COUNT elements in $i bins"
    time ./hash_perftest $i $ELEMENT_COUNT
    time ./std_hash_test $i $ELEMENT_COUNT
done
