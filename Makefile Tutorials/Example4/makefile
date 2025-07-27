all: some_file other_file
	echo "Both targets will run in order"
	
some_file: other_file 
	echo "This will always run, and runs second"
	touch some_file

other_file:
	echo "This will always run, and runs first"
