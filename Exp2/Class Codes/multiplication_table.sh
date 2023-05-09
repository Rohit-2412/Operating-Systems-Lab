# write a multiplication table of number entered by user

echo -n "Enter a number: " 

read num

i=1
val=0
while [ $i -lt 11 ]
do 
    val=$(($num * $i))
    echo "$num * $i = $val"
    i=`expr $i + 1`
done