#!/bin/bash
read -p "Enter first number: " num1
read -p "Enter second number: " num2

addition=$(($num1 + $num2))
subtraction=$(($num1 - $num2))
multiplication=$(($num1 * $num2))
division=$(($num1 / $num2))

echo ""
echo "Addition of $num1 and $num2: $addition"
echo "Subtraction of $num1 and $num2: $subtraction"
echo "Multiplication of $num1 and $num2: $multiplication"
echo "Division of $num1 and $num2: $division"