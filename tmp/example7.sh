#!usr/bin/env bash
select item in continue finish
do
if [ $item = finish ]
then
    break
fi
done
