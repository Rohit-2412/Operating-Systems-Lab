# print prime numbers between 2 and given n
read -p "Enter a number: " n

for ((i=2; i<=n; i++))
do
    for ((j=2; j<=i; j++))
    do
        if [ $((i%j)) -eq 0 ]
        then
            break
        fi
    done
    if [ $i -eq $j ]
    then
        echo $i
    fi
done
