all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	echo "test1"
	bin/gauss dane/A dane/b
	
	echo "test2"
	bin/gauss dane/A-G-1 dane/b-G-1
	
	echo "test3"
	bin/gauss dane/A-G-2 dane/b-G-2
	
	echo "test4"
	bin/gauss dane/A-G-3 dane/b-G-3
