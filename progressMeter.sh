#!/bin/bash

# Takes simple input: first argument is the serial port of the arduinoi
# ex. (/dev/cu.usbserial-#####)
# second argument is an integer 0-99 representing progress percentage.
VALUE=`echo "obase=16 ; $2" | bc`
printf '%b' "\x$VALUE" > $1

