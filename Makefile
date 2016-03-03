all:server

server:main.o p2pserver.o ioreuse.o message.o
	g++ -lc -o server main.o p2pserver.o ioreuse.o message.o
