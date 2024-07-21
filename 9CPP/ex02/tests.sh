#!/bin/bash

execute_ford-johnson() {
	word_count=$(echo "$@" | wc -w)
	if [ "$word_count" -le 5 ]; then
		echo "$@"
	else
		echo -n "$@" | awk '{for(i=1;i<=10;i++)printf "%s%s", $i, (i==5?"":" ")}'
		echo " [...]"
	fi
	valgrind -q ./PmergeMe $@ | grep sorted
}

make cre

execute_ford-johnson `shuf -i 1-100000 -n 6 | tr "\n" " "`
execute_ford-johnson `shuf -i 1-100000 -n 8 | tr "\n" " "`
execute_ford-johnson `shuf -i 1-100000 -n 150 | tr "\n" " "`
execute_ford-johnson `shuf -i 1-100000 -n 99 | tr "\n" " "`
