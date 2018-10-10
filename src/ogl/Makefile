LIBPATH += -L"/System/Library/Frameworks/OpenGL.framework/Libraries"

FRAMEWORK = -framework GLUT
FRAMEWORK += -framework OpenGL 

PROGRAMS  `= rect 
PROGRAMS += reshape1 reshape2 reshape3
PROGRAMS += single double
PROGRAMS += primitives concave

.SUFFIXES: .c .cpp .h

.c.o:
	gcc $(INCLUDES) -c $<

.cpp.o:
	g++ $(INCLUDES) -c $<

all: $(PROGRAMS)

clean:
	rm -f $(PROGRAMS)
	rm -f *.o
	rm -f *~

rect: rect.o
	gcc rect.o -o $@ $(FRAMEWORK) $(LIBS)

reshape1: reshape1.o
	gcc reshape1.o -o $@ $(FRAMEWORK) $(LIBS)

reshape2: reshape2.o
	gcc reshape2.o -o $@ $(FRAMEWORK) $(LIBS)

reshape3: reshape3.o
	gcc reshape3.o -o $@ $(FRAMEWORK) $(LIBS)

single: single.o
	gcc single.o -o $@ $(FRAMEWORK) $(LIBS)

double: double.o
	gcc double.o -o $@ $(FRAMEWORK) $(LIBS)

primitives: primitives.o
	gcc primitives.o -o $@ $(FRAMEWORK) $(LIBS)

concave: concave.o
	gcc concave.o -o $@ $(FRAMEWORK) $(LIBS)


