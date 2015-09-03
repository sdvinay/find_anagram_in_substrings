main:	main.c
	gcc main.c -o main

run:	main
	./test.bash

run_q:	main
	./test.bash | grep FAIL # the exit code of grep is "backwards", so the make fails if the run succeeds and vice versa
