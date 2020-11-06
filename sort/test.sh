# !/bin/bash

RED='\033[0;31m'
NC='\033[0m' # No Color

echo "\n${RED}Unity tests + Address Sanitizer${NC}\n"
./test_identifier.out

echo "\n${RED}CPPcheck${NC}\n"
cppcheck --enable=all src/identifier.c 


echo "\n${RED}Valgrind${NC}\n"
valgrind --leak-check=full --show-leak-kinds=all ./test_identifier.out


echo "\n${RED}Gcov check${NC}\n"
gcov -b identifier.gcno
