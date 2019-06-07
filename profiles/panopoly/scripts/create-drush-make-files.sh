#!/bin/bash

OUTPUT=$1
if [ z"$OUTPUT" = z ]; then
	echo "Must pass name of file to create as argument"
	exit 1
fi

echo ";" > $OUTPUT
echo "; GENERATED FILE - DO NOT EDIT!" >> $OUTPUT
echo ";" >> $OUTPUT
echo >> $OUTPUT

for module in $(ls modules/panopoly | grep -e '^panopoly_'); do
	makefile=modules/panopoly/$module/$module.make
	if [ -e $makefile ]; then
		cat $makefile >> $OUTPUT
		echo >> $OUTPUT
	fi
done

