#!/bin/bash
"Shai Dahan-209462712"
if [[ $# -ne 1 ]]  ; then
	echo -e "\nUsage: Need to enter at less 1 Argument!\n"
	exit
fi

if [[ $(echo $1 | tr "." "\n" | tail -n1) != "txt" ]] ; then
	echo -e "\n Not txt file\n"
	exit
fi

file_name="$1"

onlyFirstLetter=$(cat $file_name | tr " " "\n" | cut -c 1 | awk '{print tolower($0)}' | sort | uniq -c | head -n 25 | tail -n 24)
index=1



for x in {a..z}
do
	if [[ $(echo -e "$onlyFirstLetter" | grep $x | sed 's/  *//'  | wc -l)  -eq 1 ]] ; then
		p=$(echo -e "$onlyFirstLetter" | grep $x | sed 's/  *//' | cut -f1 -d" ")
	else
		p=0
	fi
	echo -e "$x\t$p"
done


