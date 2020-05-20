#! /bin/bash

hash='$6$AB.f/K06$IsV3oABaBO4UEBertVwViFgqFcuRvPfBDBVojDJkwg43AlPlgfD.y8nCpjnb01EgwwrVaxpYRzYjgT5G1g4lw.'

salt=$(echo $hash | cut -d$ -f3)
streng=$(echo $hash | cut -d$ -f4)
echo "$salt"
echo "$streng"
for p in {a..z}{a..z}{a..z}
do
	generert=$(echo $p | mkpasswd -m sha-512 -s -S $salt)
	echo "$generert"
	if [ "$generert" = "$hash" ]
	then
		echo "Passordet er \"$p\" for hash"
	fi
done

