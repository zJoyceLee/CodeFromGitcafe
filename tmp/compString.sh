#!/usr/bin/env bash

read -p "Please enter first string: " string1
read -p "Please enter setcond string: " string2

if [ string1 = string2 ]
then
    echo "string1 equal to string2"
else
    echo "string1 not equal to string2"
fi

if [ string1 ]
then
    echo "string1 is not empty"
else
    echo "string1 is empth"
fi

if [ -n string2 ]
then
    echo "string2 has a length greater than zero"
else
    echo "string2 has a length equal to zero"
fi
