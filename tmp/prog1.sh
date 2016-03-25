#!/usr/bin/env/ sh

read -p "Input your answer: " answer
if [[ -z $answer ]]
then
    echo "No Input!"
else
    echo "answer is: $answer"
fi
