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
CFLAGES := -O4 $(STACK) $(WARNS) -std=c99

# libs
LIBS := -lm

# %.o files
NAMES := $(SRCDIR)/*.c
OBJECTS := $(patsubset %, $(LIBDIR)/%.o,$(NAMES))

defalut : all

all: $(OBJECTS)
	$(CC) $(NAMES) $+ $(CFLAGES) $(LIBS)\

$(LIBDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $^ -o $@ $(CFLAGES) $(LIBDIR)

clean:
	@rm -rvf a.out $(LIBDIR)/*;