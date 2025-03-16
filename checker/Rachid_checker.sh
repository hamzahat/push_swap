#!/bin/bash

# Check if the number of random numbers is provided as an argument
if [ $# -ne 1 ]; then
    echo "Usage: $0 <number_of_random_numbers>"
    exit 1
fi

# Assign the argument to a variable
NUM_RANDOM=$1
A=700
B=5500
MAXINSTR=0
I=0

if [ $NUM_RANDOM -le 100 ]; then
    MAXINSTR=$A
elif [ $NUM_RANDOM -ge 101 ]; then
    MAXINSTR=$B
fi

# ANSI color codes
GREEN='\033[0;32m'
BLUE='\033[0;34m'
RED='\033[0;31m'
NC='\033[0m' # No Color

echo -e "${RED}"
echo "
______              _                                   
| ___ \            | |                                  
| |_/ / _   _  ___ | |__    ___ __      __  __ _  _ __  
|  __/ | | | |/ __|| '_ \  / __|\ \ /\ / / / _  ||  _ \ 
| |    | |_| |\__ \| | | | \__ \ \ V  V / | (_| || |_) |
\_|     \__,_||___/|_| |_| |___/  \_/\_/   \__ _||  __/ 
                                                 | |    
                                                 |_|    
"

echo -e "${BLUE}"

echo -e "${GREEN}------------------------------------------------------\n"
echo -e "${GREEN}\t\t Created by ${BLUE}rboutaik\n"
echo -e "${GREEN}------------------------------------------------------\n"


while :
do
    ARG=$(python -c "import random; print(' '.join(str(random.randint(-2147483648, 2147483647)) for _ in range($NUM_RANDOM)))")
    # ARG=$(jot -r $NUM_RANDOM -2147483648 2147483647 | tr '\n' ' ')
    result=$(./push_swap $ARG | ./checker_Mac $ARG)
    instr=$(./push_swap $ARG | wc -l)
    if [ $instr -gt $MAXINSTR ]; then
        echo "Result: $result [${instr}/$MAXINSTR]"
    else
        echo "Result: $result [${instr}/$MAXINSTR]"
    fi
    
    if [ "$result" == "KO" ] || [ $instr -gt $MAXINSTR ]; then
        echo -e "${RED}KO encountered.${NC} ARG: $ARG"
        break
    else
        echo -e "${GREEN}OK${NC}"
    fi
    if (( i % 30 == 0 )); then
        clear
        echo -e "${RED}"
        echo "
        ______              _                                   
        | ___ \            | |                                  
        | |_/ / _   _  ___ | |__    ___ __      __  __ _  _ __  
        |  __/ | | | |/ __|| '_ \  / __|\ \ /\ / / / _  ||  _ \ 
        | |    | |_| |\__ \| | | | \__ \ \ V  V / | (_| || |_) |
        \_|     \__,_||___/|_| |_| |___/  \_/\_/   \__ _||  __/ 
                                                        | |    
                                                        |_|    
        "

        echo -e "${BLUE}"

        echo -e "\t${GREEN}------------------------------------------------------\n"
        echo -e "\t${GREEN}\t\t Created by ${BLUE}rboutaik\n"
        echo -e "\t${GREEN}------------------------------------------------------\n"
    fi
    ((i++))
done
