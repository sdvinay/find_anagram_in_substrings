#!/bin/bash

for l in `cat test_inputs.csv`
do 
	args=`echo $l | awk -F, '{print $1, $2, $3}'`
	./main $args
done
