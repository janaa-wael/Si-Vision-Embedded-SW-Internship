objects = foo.o bar.o all.o
all: $(objects)
	$(CC) $^ -o all

foo.o: foo.c
	$(CC) -c foo.c -o foo.o

bar.o: bar.c
	$(CC) -c bar.c -o bar.o

all.o: all.c
	$(CC) -c all.c -o all.o

all.c:
	echo "int main() {return 0;}" > all.c

#Note: all.c doesn't use this rule because MAke prioritizes more specific matches when there is more than one match.

%.c:
	touch $@

clean:
	rm -f *.c *.o all
