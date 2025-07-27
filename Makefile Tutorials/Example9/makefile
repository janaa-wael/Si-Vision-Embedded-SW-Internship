CC = gcc # Flag for implicit rules
CFLAG = -g # Flag for implicit rules - Turns on debug info

# Implicit Rule #1: blah is built via the C linker implicit rule.
# Implicit Rule #2: blah.o is built via the C compilation implicit rule because blah.c exists

blah: blah.o

blah.c:
	echo "int main() {return 0;}" > blah.c

clean:
	rm -f blah*
	


