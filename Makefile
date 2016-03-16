# ========================================================================================
# Set include directories.
INCLUDEDIR = /usr/local/include

# ========================================================================================
# Compile flags
CPPFLAGS = 
CC=gcc

# ========================================================================================
# TARGET/Source definitions
SRCDIR = .
TARGET = a.out
OBJS = $(TARGET).o
SRC = $(wildcard $(SRCDIR)/*.c)

# ========================================================================================
# Make all option.
LDLIBS = 
LIBS = -l pthread -lm

all: $(TARGET)
$(TARGET): $(SRC:.c=.o)
		$(CC) $(CPPFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS) $(LIBS)

# ========================================================================================
# Clean all option

clean:
	rm -f *.bak
	rm -f $(SRCDIR)*.o $(SRCDIR)*~ $(SRCDIR)fcs $(SRCDIR).depend
	rm -f *.o *~ $(TARGET) .depend $(TARGET)
