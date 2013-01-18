all: daggen

daggen_OBJECTS = daggen.o daggen_commons.o
# Tool invocations
daggen: $(daggen_OBJECTS) 
	gcc $(CFLAGS) -o daggen $(daggen_OBJECTS) -lm
