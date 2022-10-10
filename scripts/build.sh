#!/bin/bash
. ./scripts/colors.sh
echo -e "${COLOR_LIGHT_GREEN}-- Build project.${COLOR_NC}"

PROCESS_PARAM=$(nproc)

echo -e "Build with ${COLOR_YELLOW}${PROCESS_PARAM}${COLOR_NC} process."

cmake .
make -j${PROCESS_PARAM}