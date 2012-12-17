#/usr/bin/sh

ELEMENT_COUNT=1000000

make -C ../.. all

for i in 131072 262144 524288 2000000
do
    echo "===== $ELEMENT_COUNT elements in $i bins ====="
    echo -n "c-collection hash map:"
    time ./hash_insert_test $i $ELEMENT_COUNT
    echo -n "std::unordered_map:"
    time ./std_hash_insert_test $i $ELEMENT_COUNT
done
