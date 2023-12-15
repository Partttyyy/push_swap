#!/bin/bash

check_instruction_count () {
	local INSTRUCTION_COUNT=$1
	local RETURN_VAL="OK"

	echo "test"
	if (($2==0)); then
		if (($INSTRUCTION_COUNT>3)); then
			RETURN_VAL="KO"
		fi
	elif (($2==1)); then
		if (($INSTRUCTION_COUNT>12)); then
			RETURN_VAL="KO"
		fi
	elif (($2==2)); then
		if (($INSTRUCTION_COUNT>700)); then
			if (($POINTS_100==5)); then
				POINTS_100=4
			fi
			if (($INSTRUCTION_COUNT>900)); then
				if (($POINTS_100==4)); then
					POINTS_100=3
				fi
				if (($INSTRUCTION_COUNT>1100)); then
					if (($POINTS_100==3)); then
						POINTS_100=2
					fi
					if (($INSTRUCTION_COUNT>1300)); then
						if (($POINTS_100==2)); then
							POINTS_100=1
						fi
						if (($INSTRUCTION_COUNT>1500)); then
							RETURN_VAL="KO"
							POINTS_100=0
						fi
					fi
				fi
			fi
		fi
	elif (($2==3)); then
		if (($INSTRUCTION_COUNT>5500)); then
			if (($POINTS_500==5)); then
				POINTS_500=4
			fi
			if (($INSTRUCTION_COUNT>7000)); then
				if (($POINTS_500==4)); then
					POINTS_500=3
				fi
				if (($INSTRUCTION_COUNT>8500)); then
					if (($POINTS_500==3)); then
						POINTS_500=2
					fi
					if (($INSTRUCTION_COUNT>10000)); then
						if (($POINTS_500==2)); then
							POINTS_500=1
						fi
						if (($INSTRUCTION_COUNT>11500)); then
							RETURN_VAL="KO"
							POINTS_500=0
						fi
					fi
				fi
			fi
		fi
	fi
	echo "$RETURN_VAL"
}

test_input () {

	local INPUT=$1


	PUSH_SWAP_OUTPUT=$(gtimeout 10s ./push_swap $INPUT)
	if [ $? -eq 124 ]; then
		echo "Error: push_swap execution time exceeded 2 seconds (check traces for input)."
		echo "timeout: $INPUT" >> traces.txt
		exit 1
	fi

	if [ "$PUSH_SWAP_OUTPUT" == "" ]; then
		CHECKER_OUTPUT=$(echo -n "$PUSH_SWAP_OUTPUT" | $CHECKER $INPUT)
		#stdin=$(cat)
		#CHECKER_OUTPUT=$(printf '' | $CHECKER $INPUT)
		INSTRUCTION_COUNT=$(echo -n "$PUSH_SWAP_OUTPUT" | wc -l | tr -d ' ')
	else
		CHECKER_OUTPUT=$(echo "$PUSH_SWAP_OUTPUT" | $CHECKER $INPUT)
		INSTRUCTION_COUNT=$(echo "$PUSH_SWAP_OUTPUT" | wc -l | tr -d ' ')
	fi
	INPUTSIZE=$(echo "$INPUT" | wc -w | tr -d ' ')
	if [[ $CHECKER_OUTPUT == *"KO"* ]]; then
		echo "$INPUT" >> traces.txt
		let "KO_COUNT++"
	elif [[ $CHECKER_OUTPUT == *"Error"* ]]; then
		if [ $PUSH_SWAP_OUTPUT == *"Error"* ]; then
			echo "Correct Error message"
		else
			echo "$INPUT" >> traces.txt
			let "KO_COUNT++"
		fi
	elif [[ $CHECKER_OUTPUT == "OK" ]]; then
		IS_SPECIAL=0
		i=0
		SPECIAL_INPUT_SIZES=$"3 5 100 500"
		for NUMBER in $SPECIAL_INPUT_SIZES; do
			if (($NUMBER == $INPUTSIZE)); then
				IS_SPECIAL=$i
			fi
			((i++))
		done
		if ((IS_SPECIAL > 0)); then
			check_instruction_count $INSTRUCTION_COUNT $IS_SPECIAL
			var=$(check_instruction_count $INSTRUCTION_COUNT $IS_SPECIAL)
			if [ "$result" == "KO" ]; then
				echo "$INPUT" >> traces.txt
				let "KO_COUNT++"
			else
				if (("$INSTRUCTION_COUNT" > "$MAX_INSTRUCTIONS")); then
					MAX_INSTRUCTIONS=$INSTRUCTION_COUNT
				fi
		fi
		else
			if (("$INSTRUCTION_COUNT" > "$MAX_INSTRUCTIONS")); then
				MAX_INSTRUCTIONS=$INSTRUCTION_COUNT
			fi
		fi
	fi
	if (($TEST_NB>0)); then
		let "PROGRESS=$TEST_NB * 100 / $TEST_COUNT"
		echo "Progress: $PROGRESS %"
	fi
	echo $CHECKER_OUTPUT
}

generate_random_numbers() {
	local num=$1
	local range=1000000

	if ((num>0)); then
		jot -r $num 1 $range | awk '!seen[$0]++' | head -n $num | tr '\n' ' '
	fi
}

check_valid_argument() {
	if ! [[ $1 =~ ^[0-9]+$ ]]; then
		if [ $1 == "eval" ]; then
			return
		else
			echo "Error: Argument $2('$1') must be a positive integer."
			exit 1
		fi
	fi
}

check_programm_args()
{
	if [ "$#" -ne 1 ] && [ "$#" -ne 2 ] && [ "$#" -ne 3 ]; then
		echo -e "Usage:
		\t\033[1m$0 <number_of_integers> <path/to/tester> <number_of_tests>\033[0m
		\tFirst argument: The \033[1mnumber count to test\033[0m or \033[1m'eval'\033[0m to check all the test cases in the 42 eval sheet
		\tsecond argument: optional, \033[1m'x'\033[0m to ignore or a \033[1mpath to a different checker to use\033[0m
		\tthird argument: optional, the \033[1mcount of tests\033[0m to take (default 1)"
		exit 1
	fi

	check_valid_argument $1 "1"

	if [ $1 == "eval" ]; then
		EVAL=1
	fi
	if [ "$#" -gt 1 ] && [ $2 != "x" ]; then
		CHECKER=$2
	else
		CHECKER=$"./checker_Mac"
	fi

	if [ "$#" -gt 2 ]; then
		check_valid_argument $3 3
		TEST_COUNT=$3
	else
		TEST_COUNT=1
	fi
}

summery()
{
	echo "-------------------------------------------------------"
	echo "Carefull: this tester currently does not test two empty stacks at the moment reliable!"
	echo -e "All testes done:\n"
	if (($EVAL == 1)); then
		echo "points for 100 elements: $POINTS_100/5"
		echo "points for 500 elements: $POINTS_500/5"
	fi
	if [ $QUESTIONABLE_ERRORS -eq 0 ] && [ $KO_COUNT -eq 0 ]; then
		if (($EVAL == 1)); then
			echo "Congratz, Eval passed, no tests failed!"
		else
			echo "All tests passed!"
		fi
	elif [ $QUESTIONABLE_ERRORS -ne 0 ] && [ $KO_COUNT -eq 0 ] ; then
		echo "All sorting tests passed, $QUESTIONABLE_ERRORS potential phrasing errors found (inputs for (potential) issues in the traces)."
	else
		if [ $QUESTIONABLE_ERRORS -eq 0 ]; then
			echo "$KO_COUNT KOs and potentialy $QUESTIONABLE_ERRORS phrasing errors found (inputs for (potential) issues in the traces)."
		else
			echo "$KO_COUNT KOs and no potential $QUESTIONABLE_ERRORS phrasing errors found (inputs for (potential) issues in the traces)."
		fi
	fi
	if (( $EVAL == 0 )); then
		echo "Highest instruction count (when OK): $MAX_INSTRUCTIONS"
	fi
		echo "Used checker: $CHECKER"
}

run_evals() {
	eval_fixed_tests=("42" "2 3" "0 1 2 3" "0 1 2 3 4 5 6 7 8 9")
	test_input "2 1 0"
	test_input "1 5 2 4 3"
	MAX_INSTRUCTIONS=0
	for test in "${eval_fixed_tests[@]}"; do
		test_input "$test"
		if (($MAX_INSTRUCTIONS != 0)); then
			echo "$INPUT" >> traces.txt
			echo "KO"
			((KO_COUNT++))
			MAX_INSTRUCTIONS=0
		fi
	done
	for ((TEST_NB = 0; TEST_NB < $TEST_COUNT; TEST_NB++)) do
		MAX_INSTRUCTIONS=0
		for ((count=0; count<10;count++)) do
			INPUT=$(generate_random_numbers $count)
			INPUT=$(echo "$INPUT" | tr ' ' '\n' | sort -n | tr '\n' ' ')
			test_input "$INPUT"
			if (($MAX_INSTRUCTIONS != 0)); then
				echo "$INPUT" >> traces.txt
				echo "KO, should be 0 instructions"
				((KO_COUNT++))
				MAX_INSTRUCTIONS=0
			fi
		done
		for ((count=0; count<4;count++)) do
			INPUT=$(generate_random_numbers $count)
			test_input "$INPUT"
		done
		INPUT=$(generate_random_numbers 5)
		test_input "$INPUT"
		INPUT=$(generate_random_numbers 100)
		test_input "$INPUT"
		INPUT=$(generate_random_numbers 500)
		test_input "$INPUT"
	done
}

TEST_NB=0
KO_COUNT=0
QUESTIONABLE_ERRORS=0
MAX_INSTRUCTIONS=0
COUNT_FAILS=0
EVAL=0
POINTS_100=5
POINTS_500=5
check_programm_args "$@"


if (($EVAL == 0)); then
	for ((TEST_NB = 0; TEST_NB < $TEST_COUNT; TEST_NB++)) do
		INPUT=$(generate_random_numbers "$1")
		test_input "$INPUT"
		if (($TEST_NB> 0)); then
			let "PROGRESS=$TEST_NB * 100 / $TEST_COUNT"
			echo "Progress: $PROGRESS %"
		fi
	done
else
	run_evals
	echo "eval testing.."
fi

summery
