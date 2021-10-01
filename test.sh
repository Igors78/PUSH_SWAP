#!/bin/bash

MAX=0
ITERATIONS=0
SUM=0

for i in {1..10}
do
		export ARG=`ruby -e "puts (0...500).to_a.shuffle.join(' ')"`
		if ./push_swap $ARG | ./checker_linux $ARG | grep -q KO
		then
			echo "Error from checker"
			echo $ARG
			break
		fi
		NUMBER="$(./push_swap $ARG | wc -l | sed 's/ //g')"
		if [ "$NUMBER" -gt "$MAX" ]
			then
			MAX=$NUMBER;
		fi
		echo $i ":" $NUMBER
		let SUM+=$NUMBER;
		let ITERATIONS+=1
done

echo "AVG: $(($SUM / $ITERATIONS))"
echo "MAX: " $MAX