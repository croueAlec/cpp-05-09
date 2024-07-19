#!/bin/bash

execute_rpn() {
	echo ""
	echo "$1"
	./RPN "$1"
}

make cre

execute_rpn "8 9 * 9 - 9 - 9 - 4 - 1 +"
execute_rpn "7 7 * 7 -"
execute_rpn "1 2 * 2 / 2 * 2 4 - +"
execute_rpn "(1 + 1)"
execute_rpn "8 9 - 3 - -"
