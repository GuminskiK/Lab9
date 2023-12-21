all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	@echo "test"
	-@bin/gauss dane/A dane/b
	
	@echo "test G-1"
	-@bin/gauss dane/A-G-1 dane/b-G-1
	
	@echo "test G-2"
	-@bin/gauss dane/A-G-2 dane/b-G-2
	
	@echo "test G-3"
	-@bin/gauss dane/A-G-3 dane/b-G-3

	@echo "test C-1"
	-@bin/gauss dane/A-C-1 dane/b-C-1
	
	@echo "test C-2"
	-@bin/gauss dane/A-C-2 dane/b-C-2

	@echo "test C-3"
	-@bin/gauss dane/A-C-3 dane/b-C-3
