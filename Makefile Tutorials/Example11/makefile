objects = foo.o bar.o all.o
all: $(objects)
	$(CC) $^ -o all

# Syntax - targets ...: target pattern : prerequisite patterns ...
# In the case of the first target, foo.o, the target-pattern matches foo.o and sets the "stem" to the foo
# It then replaces the '% in prereq-patterns with that stem

$(objects): %.o: %.c
	$(CC) -c $^ -o $@

all.c:
	echo "int main() {return 0;}" > all.c

# Note: all.c doesn't use this rule because Make prioritizes more specific matches when there's more than one match
%.c:
	touch $@

clean:
	rm -f *.c *.o all
