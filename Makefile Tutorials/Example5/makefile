files:= file1 file2

some_file: $(files)
	echo "Look at these variables: " $(files)
	touch some_file

file1:
	touch file1

file2:
	touch file2

clean:
	rm -f file1 file2 some_file
