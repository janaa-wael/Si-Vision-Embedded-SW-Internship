hey: one two
	# Outputs "hey", since this is the targget name
	echo $@

	#Output all prerequisites newer than the target
	echo $?

	#Output all prerequisites
	echo $^

	#Output the first prerequisite
	echo $<

	touch hey

one:
	touch one

two:
	touch two

clean:
	rm -f hey one two
