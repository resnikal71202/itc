#Define compiler

CC := gcc

#Paths
SRCDIR := src
LIBDIR := lib

# Protection for stack-smashing attack
STACK := -fstack-protector-all -Wstack-protector

# Specifies to GCC the required warnings
WARNS := -Wall -Wextra 

# flags for comeling
CFLAGES := -O4 $(STACK) $(WARNS)

# libs
LIBS := #-lm

# %.o files
NAMES := $(notdir $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(patsubset %, $(LIBDIR)/%.o,$(NAMES))

defalut : all

all: $(OBJECTS)
	$(CC) $+ $(CFLAGES) $(LIBS)

clean:
	@rm a.out $(LIBDIR)/*;