# !/bin/bash

RED='\033[0;31m'
NC='\033[0m' # No Color

echo "\n${RED}Unity tests + Address Sanitizer${NC}\n"
./test_sort.out

echo "\n${RED}CPPcheck${NC}\n"
cppcheck --enable=all src/sort.c 


echo "\n${RED}Valgrind${NC}\n"
valgrind --leak-check=full --show-leak-kinds=all ./test_sort.out

echo "\n${RED}Sanitizer${NC}\n"
./test_sort_sanitize.out

echo "\n${RED}Gcov check${NC}\n"
gcov -b sort.gcno
