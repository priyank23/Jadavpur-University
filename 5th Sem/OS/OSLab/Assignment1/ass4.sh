#!/bin/sh

#files=( "$@" )
#printf "\e[0;32mFile \t num_printf \t num_scanf \t num_int\n"
#for i in 0 1 2 3; do
#	printf "\e[0;33m${files[$i]} \t "
#	countP=$(grep -o "printf" ${files[$i]} | wc -l)
#	countS=$(grep -o "scanf" ${files[$i]} | wc -l)
#	countI=$(grep -o "int " ${files[$i]} | wc -l)
#	printf "$countP \t\t $countS \t\t $countI \n"
#done
countP=0
countI=0
countS=0
if [[ ! -r "$1" ]]; then
	printf "File does not exist or read permission denied!!\n"
	exit 1
fi

while IFS=" " read -r line; do
	for word in "$line"; do
		if [[ $word =~ "printf" ]]; then
			countP=$(echo "$countP+1" | bc)
		fi 
		if [[ $word =~ "scanf" ]]; then
			countS=$(echo "$countS+1" | bc)
		fi 
		if [[ $word =~ "int" ]]; then
			countI=$(echo "$countI+1" | bc)
		fi 
	done
done < "$1"

echo -e "\e[0;32mnumber of printf: \e[0;33m$countP"
echo -e "\e[0;32mnumber of scanf: \e[0;33m$countS"
echo -e "\e[0;32mnumber of int: \e[0;33m$countI"
