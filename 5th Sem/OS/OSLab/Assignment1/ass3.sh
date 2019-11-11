#!/bin/sh

echo "Enter file name with path w.r.t current directory"
read File
num=$(stat --format=%b $File)
echo "Number of disk blocks allocated to $File = $num"
