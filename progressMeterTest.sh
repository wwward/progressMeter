#!/bin/bash
# Just run it to exercise the meter from 0-99 and 99-0 repeating.
# only argument is the serial port path (/dev/cu.usbserial-xxxxx)

VALUE=0
DIRECTIONUP=1
while true; do
	`./progressMeter.sh $1 $VALUE`
	if [ $DIRECTIONUP -eq 0 ]; then
	let VALUE-=1
	elif [ $DIRECTIONUP -eq 1 ]; then
	let VALUE+=1
	fi
	if [ $VALUE -eq 0 ]; then
	let DIRECTIONUP=1
	elif [ $VALUE -gt 99 ]; then
	let DIRECTIONUP=0
	fi
done
