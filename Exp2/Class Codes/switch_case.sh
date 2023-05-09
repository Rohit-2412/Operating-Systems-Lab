#!/bin/bash

# This script will demonstrate the use of case statements

echo -n "Whether you are a student? "
read answer

case $answer in
    "Y" | "y" | "YES" | "Yes" | "yes")
    echo "You are a student"
    ;;
    
    "N" | "n" | "NO" | "No" | "no")
    echo "You are not a student"
    ;;

    *)
    echo "Invalid input"
esac

echo ""
echo ""

echo -n "Enter your age: "
read age

case $age in
    [0-9])
    echo "You are a kid"
    ;;

    [1-5][0-9])
    echo "You are a teenager"
    ;;

    [6-9][0-9])
    echo "You are an adult"
    ;;

    *)
    echo "You are a senior citizen"
esac

# check if user can vote or not

echo ""
echo ""

echo -n"Enter your age: "

read age

case $age in
    [0-18])
    echo "You are not eligible to vote"
    ;;

    [1-9][0-9])
    echo "You can vote"
    ;;

    *)
    echo"Invalid Input"
esac