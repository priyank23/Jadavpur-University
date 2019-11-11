#!/bin/bash

echo $(find . -mindepth 1 -type f| wc -l)
#dirs=$(find . -mindepth 1 -type d -print0 | while IFS= read -r -d '' line; do
#	echo $line
#done)

find . -mindepth 1 -type d -print0 | while IFS= read -r -d '' line; do
	echo $line " -> " $(find "$line" -mindepth 1 -type f|wc -l)
	find "$line" -mindepth 1 -maxdepth 1 -type f -print0 | while read -r -d '' line2; do
		echo -e '\t' $line2 
	done 
	echo ""
done


echo "List of modified files in last 2 days"
find . -type f -mtime -2 -printf "%TR %TD %p\n"
