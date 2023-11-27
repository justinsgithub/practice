#!/usr/bin/bash

# IFS=$'\n'
#
# for line in $(grep '//' main.c); do
# 	newline=$(echo $line | sed 's/  \/\/ //')
# 	outputfile=test/$(echo $newline | sed 's/(.*);//').txt
# 	sed "s,$line,  $newline," main.c >test.c && cc test.c && ./a.out >$outputfile
# done

# no need for IFS= with while loop
grep '//' main.c | while read -r line; do
	echo $line
	newline=$(echo $line | sed 's/\/\/ //')
	echo $newline
	outputfile=test/$(echo $newline | sed 's/(.*);//').txt
	echo $outputfile
	sed "s,$line,  $newline," main.c >test.c && gcc test.c
	./a.out <input.txt >$outputfile
done

rm test.c a.out
