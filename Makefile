all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	@echo "test G-1"
	@bin/gauss dane/A dane/b
	
	@echo "test G-2"
	@bin/gauss dane/A-G-1 dane/b-G-1
	
	@echo "test G-3"
	@bin/gauss dane/A-G-2 dane/b-G-2
	
	@echo "test G-4"
	@bin/gauss dane/A-G-3 dane/b-G-3
