# for loop for array
echo "for loop for array"
for i in a b c d e f g h i j k l 
do
    echo $i
done

echo ""

# iterate over array


echo "iterate over array"
arr=(1 2 3 4 5 6 7 8 9 10)

for i in ${arr[@]}
do
    echo $i
done

echo ""

# iterate within a range
echo "iterate within a range"

# syntax: for i in {start..end}
for i in {1..10}
do
    echo $i
done

echo ""

# iterate within a range with step
echo "iterate within a range with step"

# syntax: for i in `seq start step end`
for i in `seq 1 2 10`
do
    echo $i
done
