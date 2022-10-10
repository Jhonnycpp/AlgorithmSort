#!/bin/bash
. ./scripts/colors.sh
echo -e "${COLOR_LIGHT_GREEN}-- Running project.${COLOR_NC}"
$1
echo -e "${COLOR_LIGHT_GREEN}-- End running.${COLOR_NC}"