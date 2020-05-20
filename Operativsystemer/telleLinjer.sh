#!/bin/bash

declare -i teller=0;

if [[ $line=~/^[[:SPACE:]]*$/ ]] then
	teller++;
fi
