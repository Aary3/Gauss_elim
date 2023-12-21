all:
	gcc --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b
	bin/gauss dane/C dane/D
	bin/gauss dane/E dane/F
