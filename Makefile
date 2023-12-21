all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b
	echo "test C-1"
	bin/gauss dane/A-C-1 dane/b-C-1
	echo "test C-2"
	bin/gauss dane/A-C-2 dane/b-C-2
	echo "test C-3"
	bin/gauss dane/A-C-3 dane/b-C-3
