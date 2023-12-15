#!/bin/bash

# example for 1 test (output either Error, KO or OK):
# ARG="97064 538667"; ./push_swap $ARG | ./checker $ARG

echo ""

if [ "$#" -ne 1 ]; then
	echo "Usage: $0 <number_of_integers>"
	exit 1
fi

# Check if the argument is a positive integer
if ! [[ $1 =~ ^[0-9]+$ ]]; then
	echo "Error: Argument must be a positive integer."
	exit 1
fi

generate_random_numbers() {
	local num=$1
	local range=1000000

	# Generate numbers and shuffle them
	jot -r $num 1 $range | awk '!seen[$0]++' | head -n $num | tr '\n' ' '
}

ARG=$(generate_random_numbers "$1" | sed 's/ $//')

# Run push_swap with a timeout of 10 seconds
PUSH_SWAP_OUTPUT=$""
PUSH_SWAP_OUTPUT=$(gtimeout 10s ./push_swap $ARG)

# Check if push_swap was terminated due to timeout
if [ $? -eq 124 ]; then
	echo "Error: push_swap execution time exceeded 2 seconds."
	echo "$ARG" >> timeout_errors.txt
	exit 1
fi

if [ "$PUSH_SWAP_OUTPUT" == "" ]; then
	CHECKER_OUTPUT=$(echo -n "$PUSH_SWAP_OUTPUT" | ./checker $ARG)

else
	CHECKER_OUTPUT=$(echo "$PUSH_SWAP_OUTPUT" | ./checker $ARG)
fi

echo "$PUSH_SWAP_OUTPUT"
echo "$ARG"
echo "$CHECKER_OUTPUT"

# if [[ $CHECKER_OUTPUT == $PUSH_SWAP_OUTPUT ]]; then
#	 echo "OK"
#	 echo "$ARG" >> working.txt
if [[ $CHECKER_OUTPUT == *"KO"* ]]; then
	echo "$ARG" >> KO.txt
elif [[ $CHECKER_OUTPUT == *"Error"* ]]; then
	echo "$ARG" >> errors.txt
else
	echo "$ARG" >> working.txt
fi

