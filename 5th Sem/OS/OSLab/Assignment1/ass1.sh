#!/bin/sh

while true; do

	read -p "Enter first number: " num1
	read -p "Enter second number: " num2
	
	sum=$(echo "$num1+$num2" | bc)
	check=$(echo "$num2==0" | bc)	
	if((check==1)); then
		div="Division by zero(0) : ERROR!"	
	else	
		div=$(echo "$num1/$num2" | bc)
	fi	
	sub=$(echo "$num1-$num2" | bc)
	mult=$(echo "$num1*$num2" | bc)

	echo "$num1 + $num2 = $sum"
	echo "$num1 - $num2 = $sub"
	echo "$num1 / $num2 = $div"
	echo "$num1 * $num2 = $mult"

	read -p "continue:[y/n] " ch
	if [[ ! $ch =~ ^[[Yy]|[Yy][Ee][SsPp]] ]]; then
		exit 0
	fi

done
