#!/bin/sh

max=0
touch file
while [[ $max -le $1 ]]
do

	#./client ola queroja 9002 10.250.24.158>>file&
	#./client ola queroja 9002 10.250.27.232>>file&
	./client ola queroja 9002 127.0.0.1>>file&
	max=$((max +1))
	echo "Cliente spawnado"
done

echo "terminei!!!!";
