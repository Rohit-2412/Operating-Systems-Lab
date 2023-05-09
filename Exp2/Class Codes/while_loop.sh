i=1
while((i<10))
do
echo $i
((i+=3))
done

i=1
while [ $i -le 5 ]
do
echo "Level $i"
((i++))
done