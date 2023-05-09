# program to print the multiplicataion table
echo -n "Enter number for multiplication table: "
read num

for i in {1..10}
do
    val=$((num*i))
    echo "$num * $i = $val"
done