all: build run

build:
	# -g is for GDB debug support
	gcc *.c -g -o app.exe

run:
	./app.exe
