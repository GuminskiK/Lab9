all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b
	bin/gauss dane/A-C-1 dane/b-C-1
	bin/gauss dane/A-C-2 dane/b-C-2
	bin/gauss dane/A-C-3 dane/b-C-3
