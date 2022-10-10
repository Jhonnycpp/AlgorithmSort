#!/bin/bash
rm -rf build
rm -rf CMakeFiles
rm -f cmake_install.cmake
rm -f CMakeCache.txt
rm -f Makefile
rm -f compile_commands.json

. ./scripts/colors.sh

echo -e "${COLOR_LIGHT_GREEN}-- Clear project.${COLOR_NC}"