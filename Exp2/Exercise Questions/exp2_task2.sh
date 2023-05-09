# small calculator

# print menu
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
echo "5. Exit"

# read choice
echo -n "Enter your choice: "
read choice

# read numbers
echo -n "Enter first number: "
read num1

echo -n "Enter second number: "
read num2

# perform operation using switch case

case $choice in
    1) 
        echo "Addition: $(($num1+$num2))"
        ;;
    2) 
        echo "Subtraction: $(($num1-$num2))"
        ;;
    3) 
        echo "Multiplication: $(($num1*$num2))"
        ;;
    4) 
        echo "Division: $(($num1/$num2))"
        ;;
    5) 
        exit;;
    *) echo "Invalid choice";;
esac