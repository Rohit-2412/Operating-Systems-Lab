#!/bin/bash
read -p "Enter first number: " num1
read -p "Enter second number: " num2

# checking if numbers are equal or not
if [ $num1 -eq $num2 ]

then
echo "Number $num1 and Number $num2 are equal"

else
echo "Number $num1 and Number $num2 are not equal"
fi

echo ""
# checking if number1 is less than number2

if [ $num1 -gt $num2 ]

then
echo "Number1 $num1 is greater than $num2"

else
echo "Number $num1 is less than or equal to $num2"
fi

echo ""

# checking if number1 is not equal to number2

if [ $num1 -ne $num2 ]

then
echo "Number1 $num1 is not equal to $num2"

else
echo "Number1 $num1 is equal to $num2"
fi