#! /bin/bash

echo "Ditt brukernavn er ${USER}"
echo "Prosessen du kjører er $$"
echo "Operativsystemet er `uname`"
echo "Din hjemmekatalog: ${HOME}"
filer=ls /home/andreas/ | wc -l
#kataloger= ls -ld */ | wc -l 
echo "Antall filer i hjemmekatalog: $filer"
#echo "Antall kataloger: $kataloger"
