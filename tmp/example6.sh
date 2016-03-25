#!usr/bin/env bash
loopcount=0
result=0
midleResult=0
while [ $loopcount -lt 10 ]
do
loopcount=`expr $loopcount + 1`
midleResult=`expr $loopcount \* 2`
result=`expr $result + $midleResult`
done
echo “result is $result”
