LIBS=-I. -I/usr/include/SOIL -lglut -lGLU -lSOIL -lGLEW -lGL -lm -Wall `sdl-config --cflags --libs` -lSDL_mixer -w
FILES=$(shell find ./ -name "*.c")
OBJECTS=$(shell find ./ -name "*.o")
EXEC=Stack
all: objects $(EXEC)
.PHONY: uninstall install clean mrproper reinstall help
help:
	echo "reinstall,install,uninstall,clean,mrproper"
reinstall: uninstall install
uninstall:
	rm -r 
install: all
	cp $(EXEC) $(bindir)
$(EXEC): $(OBJECTS)
	g++ $^ -o $@ $(CFLAGS) $(LIBS)
objects: $(FILES)
	g++ $^ -c $(CFLAGS) $(LIBS)
clean:
	rm -f ./*.o
mrproper: uninstall
	rm -f $(E
