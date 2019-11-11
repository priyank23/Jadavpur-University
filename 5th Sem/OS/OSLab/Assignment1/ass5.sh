#!/bin/sh

red='\e[0;31m'
reset='\e[0;37m'
green='\e[0;32m'
yellow='\e[0;33m'
read -p "Enter filename: " File

if [[ ! -r $File ]]; then
	printf "$red The file does not exist!!$reset\n"
	exit 1
fi

read -p "String to be searched: " str

freq=$(grep -o $str $File  | wc -l)

if (( $freq == 0 )); then
	printf "$red The entered string does not exist!!$reset\n"
	exit 1
fi

printf "\n$green$str occured %d times in the given file$reset\n\n" $freq
printf "$yellow"
printf "Line\t==>  frequency$reset\n"  
grep -on $str $File | uniq -c | cut -d : -f 1 |
while read -r line; do
	token=($line)
	printf "%d\t==>  %d\n" ${token[1]} ${token[0]}
done
