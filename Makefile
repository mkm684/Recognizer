CC = g++

# compiler flags:
CFLAGS  = -g -Wall -lpthread


# the build target executable:
TARGET = main

all: 
		$(CC) *.cpp -o $(TARGET) $(CFLAGS)

clean:
		$(RM) $(TARGET)