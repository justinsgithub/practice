#!/usr/bin/bash

# for cfunc in $(grep '//' main.c); do
# 	echo $cfunc
# done

grep '//' main.c | while read -r line; do
	# echo "$line"
	newline=$(echo $line | sed 's/\/\/ //')
	outputfile=$(echo $newline | sed 's/(.*);//').txt
	echo $outputfile
	# echo $newline
	# sed "s,$line,$newline," main.c
	# your code goes here
done

# sed 's/\/\/ \(unknown_escape_char();\)/\1/' main.c; done

# testfile='Zedd, Maren Morris, Grey - The Middle (Official Music Video) [M3mJkSqZbX4].mp3'
# testfile='Zedd, Maren Morris, Grey - The Middle (Official Music Video).mp3'
# mv "$testfile" "$(echo $testfile | sed 's/ \[.*\]//g')"
# mv "$testfile" "$(echo $testfile | sed 's/ (Official Music Video)//g')"

# for file in *; do mv "$file" "$(echo $file | sed 's/ (OFFICIAL VIDEO)//g')"; done
# for file in *; do mv "$file" "$(echo $file | sed 's/ (Official Video)//g')"; done
# for file in *; do mv "$file" "$(echo $file | sed 's/ (Official Music Video)//g')"; done
# for file in *; do mv "$file" "$(echo $file | sed 's/ \[.*\]//g')"; done
# for file in *; do mv "$file" "$(echo $file | sed 's/&/and/g')"; done
# for file in *; do mv "$file" "$(echo $file | sed 's/,//g')"; done
# for file in *; do mv "$file" "$(echo $file | sed "s/'//g')"; done
# for file in *; do mv "$file" "$(echo $file | sed 's/(feat/( feat/g')"; done
# for file in *; do mv "$file" "$(echo $file | sed 's/feat\./feat/g')"; done
# for file in *; do mv "$file" "$(echo $file | sed 's/(//g')"; done
# for file in *; do mv "$file" "$(echo $file | sed 's/)//g')"; done
# for file in *; do mv "$file" "$(echo $file | sed 's/ /-/g')"; done
# for file in *; do mv "$file" "$(echo $file | sed 's/---/-/g')"; done
