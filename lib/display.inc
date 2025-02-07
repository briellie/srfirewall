#!/bin/bash
# By Brielle Bruns <bruns@2mbit.com>
# URL: http://www.sosdg.org/freestuff/firewall
# License: GPLv3
#
#    Copyright (C) 2009 - 2014  Brielle Bruns
#    Copyright (C) 2009 - 2014  The Summit Open Source Development Group
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.


# ANSI color sequences
BLUE="\e[34m"
GREEN="\e[32m"
RED="\e[31m"
YELLOW="\e[33m"
PURPLE="\e[35m"
AQUA="\e[36m"
WHITE="\e[97m"
GREY="\e[37m"
DEFAULT_COLOR="\e[39m"

# display_c $COLOR $TEXT BOOL(YN)
# $COLOR being bash colors
# $TEXT being what to output (make sure to put " " around text)
# BOOL being (Y or N) to do newline at end or not
function display_c {
	unset COLOR_CODE TEXT NEWLINE
	DEFAULT_COLOR="\E[39m"
	COLOR_CODE=`pick_color $1`
	TEXT="$2"
	if [ "$3" == "N" ]; then
		NEWLINE="-n"
	fi
	echo -e ${NEWLINE} "${COLOR_CODE}${TEXT}${DEFAULT_COLOR}"
}

# Monochrome version of above
function display_m {
	unset TEXT NEWLINE
	TEXT="$2"
	if [ "$3" == "N" ]; then
		NEWLINE="-n"
	fi
	echo -e $NEWLINE "$TEXT"
}

# pick_color $COLOR
# returns appropriate color codes for use in display_c and such
function pick_color {
	case $1 in
		BLUE) COLOR="\E[34m" ;;
		GREEN) COLOR="\E[32m" ;;
		RED) COLOR="\E[31m" ;;
		YELLOW) COLOR="\E[33m" ;;
		PURPLE) COLOR="\E[35m" ;;
		AQUA) COLOR="\E[36m" ;;
		WHITE) COLOR="\E[1m" ;;
		GREY) COLOR="\E[37m" ;;
		*) COLOR="\E[37m" ;;
	esac
	echo "${COLOR}"
}

# reset_color
function reset_color {
	unset NEWLINE
	DEFAULT_COLOR="\E[39m"
	if [ "$1" == "N" ]; then
		NEWLINE="-n"
	fi
	echo ${NEWLINE} -e "${DEFAULT_COLOR}"
}

# show_help
# Show command line options help
function show_help {
	 ${display} DEFAULT_COLOR "SRFirewall ${FW_VERSION}"
	 ${display} DEFAULT_COLOR "\n${0} -[fghv]\n"
 	 ${display} DEFAULT_COLOR "\t-f\tFlushes all rules back to default ACCEPT"
 	 ${display} DEFAULT_COLOR "\t-g\tGenerate cached rule files (not implemented yet)"
	 ${display} DEFAULT_COLOR "\t-h\tShows this help"
	 ${display} DEFAULT_COLOR "\t-v\tShow version"
 }
 
 function show_version {
	${display} DEFAULT_COLOR "SRFirewall ${FW_VERSION}"
	${display} DEFAULT_COLOR "Written by: Brielle Bruns <bruns@2mbit.com>"
	${display} DEFAULT_COLOR "http://www.sosdg.org/freestuff/firewall"
	${display} DEFAULT_COLOR "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="
	${display} DEFAULT_COLOR "Released under the GNU GPL Version 3"
	${display} DEFAULT_COLOR "https://www.gnu.org/licenses/gpl-3.0.txt"
}