# fibonacci series

read -p "Enter the number of terms: " n

for (( i=0; i<n; i++ ))
do
    # first term is 0
    if [ $i -eq 0 ]
    then
        a=0
        echo "$a "
    
    # second term is 1
    elif [ $i -eq 1 ]
    then
        b=1
        echo "$b "
    # next term is equal to sum of two pervious terms
    else
        c=$((a+b))
        echo "$c "
        a=$b
        b=$c
    fi
done