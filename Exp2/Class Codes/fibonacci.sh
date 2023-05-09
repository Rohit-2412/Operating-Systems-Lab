# fibonacci

n=6
a=(0 1)

for ((i=2 ;i<n; i++))
do
    a[i]=$((a[i-1]+a[i-2]))
done

echo ${a[@]}