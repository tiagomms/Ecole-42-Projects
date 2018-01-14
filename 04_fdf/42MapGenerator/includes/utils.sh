#!/bin/bash

if [ "$MAPGENERATOR_SH" == "1" ]
then

	COLUMNS=`tput cols`
	if [ "$COLUMNS" == "" ]
	then
		$COLUMNS=80;
	fi;

	if [ "$OPT_NO_COLOR" == "0" ]
	then
		C_CLEAR="\033[0m"
		C_YELLOW="\033[33;1m"
		C_RED="\033[31m"
		C_GREEN="\033[32m"
		C_CYAN="\033[36;1m"
		C_WHITE="\033[37;1m"
		C_BLUE="\033[34;1m"
		C_GREY="\033[1;30m"
		C_BLACK="\033[30;1m"
		C_INVERT="\033[44;1m"$C_WHITE
	fi

	function display_error
	{
		echo $C_RED"  !!! $1 !!!"$C_CLEAR
	}

	function display_hr
	{
		local MARGIN
		(( MARGIN= $COLUMNS ))
		if [ "$1" == "" ]
		then
			printf $C_GREY""
		else
			printf "$1"
		fi
		printf "%"$MARGIN"s" "" | sed s/' '/"${c:=_}"/g | cut -c1-$MARGIN
		printf "$C_CLEAR"
	}

	function display_hr2
    {
        local MARGIN
        (( MARGIN= $COLUMNS ))
        printf $C_GREY""
	    printf "%"$MARGIN"s" "" | sed s/' '/"${c:=¯ }"/g | cut -c1-$MARGIN
	    printf $C_CLEAR""
	    if [ "$1" != "" ]
	    then
		    echo "$1";
		fi
	}

	function display_righttitle
	{
		local LEN MARGIN
		if [ "$1" != "" ]
		then
			LEN=${#1}
			(( MARGIN= $COLUMNS - $LEN))
			printf "%"$MARGIN"s" " "
			printf "$1\n"
		else
			printf "\n"
		fi
	}

	function display_center
	{
	    local LEN MARGIN
	    if [ "$1" != "" ]
		then
		    LEN=${#1}
		    (( MARGIN= ($COLUMNS - $LEN) / 2 ))
		    printf "%"$MARGIN"s" " "
			printf "$1"
			printf "%"$MARGIN"s" " "
			printf "\n"
		else
			printf "\n"
		fi
	}

	function display_header
	{
		local MARGIN
		echo "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
		echo "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n "
		clear
		printf $C_GREY""
		display_center " "
		display_center "  _  _  ____  __  __              ____             "
		display_center " | || ||___ \|  \/  | __ _ _ __  / ___| ___ _ __   "
		display_center " | || |_ __) | |\/| |/ _\` | '_ \| |  _ / _ \ '_ \ "
		display_center " |__   _/ __/| |  | | (_| | |_) | |_| |  __/ | | | "
		display_center "    |_||_____|_|  |_|\__,_| .__/ \____|\___|_| |_| "
		display_center " jgigault @ student.42.fr |_|       06 51 15 98 82 "
		display_center " "
		display_center " "
		printf $C_CLEAR""
	}

	function display_footer
	{
		echo $C_WHITE""
		printf "%"$COLUMNS"s" "" | sed s/' '/"${c:=#}"/g | cut -c1-$COLUMNS
		echo $C_CLEAR""
	}

	function ft_atoi
	{
		local SELN
		if [ "$1" != "1" -a "$1" != "2" -a "$1" != "3" -a "$1" != "4" -a "$1" != "5" -a "$1" != "6" -a "$1" != "7" -a "$1" != "8" -a "$1" != "9" ]
		then
			SELN=`LC_CTYPE=C printf '%d' "'$1"`
			if (( $SELN >= 65 )) && (( $SELN <= 90 ))
			then
				(( SELN=$SELN - 65 + 10 ))
				printf "$SELN"
			else
				if (( $SELN >= 97 )) && (( $SELN <= 122 ))
				then
					(( SELN=$SELN - 97 + 10 ))
					printf "$SELN"
				else
					printf "0"
				fi
			fi
		else
			printf "$1"
		fi
	}

	function display_menu
	{
		local -a MENU FUNCS
		local PARAMS0 TOTAL SEL LEN SELN
		PARAMS0="\"$1\" "
		SEL=""
		shift 1
		while (( $# > 0 ))
        do
			PARAMS0=$PARAMS0" $1 \"$2\""
			(( TOTAL += 1 ))
			FUNCS[$TOTAL]="$1"
			MENU[$TOTAL]="$2"
			if (( $TOTAL < 10 ))
			then
				SELN=$TOTAL
			else
				(( SELN=65 + $TOTAL - 10 ))
				SELN=`echo "$SELN" | awk '{printf("%c", $0)}'`
			fi
			(( LEN=$COLUMNS - ${#2} - 9 ))
			printf $C_INVERT"  "$SELN")    $2 "
			printf "%"$LEN"s" " "
			printf $C_CLEAR"\n"
			shift 2
        done
		printf "\n  "$C_WHITE"Type a number between 1 and "$SELN": "
		tput cnorm
		read -s -n 1 SEL
		tput civis
		SEL=`ft_atoi "$SEL"`
		while [ -z "${MENU[$SEL]}" -o "$(echo "${FUNCS[$SEL]}" | grep open)" != "" ]
		do
			printf "\a"
			if [ "$(echo "${FUNCS[$SEL]}" | grep open)" != "" ]
			then
				eval ${FUNCS[$SEL]}
			fi
			SEL=""
			tput cnorm
			read -s -n 1 SEL
			tput civis
			SEL=`ft_atoi "$SEL"`
		done
		printf "\n"
		if [ "${FUNCS[$SEL]}" != "" ]
		then
			eval ${FUNCS[$SEL]}
		fi
	}

	function get_config
	{
		local MYFILE MYPATH RET0
		MYFILE=`printf "$RETURNPATH/.my$1" | sed 's/ /\\ /g'`
		if [ ! -f "$MYFILE" ]
		then
			touch "$MYFILE"
		fi
		MYPATH=`cat "$MYFILE"`
		if [ ! -d "$MYPATH" ]
		then
			printf "" > "$MYFILE"
			MYPATH=""
		fi
		printf "$MYPATH"
	}

	function save_config
	{
		local MYFILE RET0
		MYFILE=".my$1"
		RET0=`printf "$RETURNPATH/$MYFILE" | sed 's/ /\\ /g'`
		RET0=`echo "printf \"$2\" > \"$RET0\""`
		eval $RET0
	}

	function exit_generator
	{
		printf "\n"
		display_hr
		printf "\n\n\n\n"
		tput cnorm
#		clear
		exit
	}

	function display_spinner
	{
		local pid=$1
		local total_delay=0
		local total_delay2=240
		local delay=0.2
		local spinstr='|/-\'
		printf $C_BLUE""
		while [ "$(ps a | awk '{print $1}' | grep $pid)" ];
		do
			if (( $total_delay2 < 1 ))
			then
				kill $pid
				wait $! 2>/dev/null
				(( total_delay2 = $total_delay / 5 ))
				printf $C_RED"  Time out ($total_delay2 sec)"$C_CLEAR > $RETURNPATH/.myret
			fi
			if [ "$OPT_NO_TIMEOUT" == "0" ]
			then
				(( total_delay += 1 ))
			fi
			local temp=${spinstr#?}
			printf "  [%c] " "$spinstr"
			local spinstr=$temp${spinstr%"$temp"}
			if (( $total_delay >= 5 ))
			then
				(( total_delay2 = ( 209 - $total_delay ) / 5 ))
				printf "[time out: %02d]" "$total_delay2"
			fi
			sleep $delay
			printf "\b\b\b\b\b\b"
			if (( $total_delay >= 5 ))
			then
				printf "\b\b\b\b\b\b\b\b\b\b\b\b\b\b"
			fi
		done
		printf "                     \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"
		printf $C_CLEAR""
	}

	function check_fileexists
	{
		local i TOTAL RET0 VALPARAM
		if [ "$1" != "" ]
		then
			i=0
			VALPARAM=`eval echo \$1[\$i]`
			while [ "${!VALPARAM}" != "" ]
			do
				if [ ! -f "$MYPATH/${!VALPARAM}" ]
				then
					(( TOTAL += 1 ))
					RET0=$RET0"Not Found: ${!VALPARAM}\n"
				fi
				(( i += 1 ))
				VALPARAM=`eval echo \$1[\$i]`
			done
			printf "$RET0" > "$RETURNPATH"/.my$1
			if [ "$RET0" == "" ]
			then
				printf $C_GREEN"  All files were found"$C_CLEAR
			else
				if (( $TOTAL == 1 ))
				then
					printf $C_RED"  1 file is missing"$C_CLEAR
				else
					printf $C_RED"  $TOTAL files are missing"$C_CLEAR
				fi
			fi
		else
			printf $C_RED"  An error occured (Files list missing)"$C_CLEAR
		fi
	}

	function create_tmp_dir
	{
		if [ ! -d "$RETURNPATH"/tmp ]
		then
			mkdir "$RETURNPATH"/tmp
		fi
		if [ ! -d "$RETURNPATH"/tmp ]
		then
			display_error "An error occured while creating temporary folder"
			exit_generator
		fi
	}

fi