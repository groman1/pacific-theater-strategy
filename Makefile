main:
	cc src/main.c -lncurses -o ptgame
mapgen: 
	cc src/mapgenerator.c -lncurses -o mapgen
clean:
	rm mapgen ptgame
