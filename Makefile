$(CC) = gcc
shell: shell.o parseCommandsIntoTable.o addCommand.o getCommandInformation.o isValidInput.o errorChecking.o
	$(CC) shell.o parseCommandsIntoTable.o addCommand.o getCommandInformation.o isValidInput.o errorChecking.o -o shell

shell.o: shell.c header.h isValidInput.h errorChecking.h getCommandInformation.h
	$(CC) -c shell.c

parseCommandsIntoTable.o: parseCommandsIntoTable.c header.h isValidInput.h
	$(CC) -c parseCommandsIntoTable.c

addCommand.o: addCommand.c header.h
	$(CC) -c addCommand.c

getCommandInformation.o: getCommandInformation.c getCommandInformation.h
	$(CC) -c getCommandInformation.c

isValidInput.o: isValidInput.c isValidInput.h
	$(CC) -c isValidInput.c

errorChecking.o: errorChecking.c errorChecking.h isValidInput.h
	$(CC) -c errorChecking.c

Clean:
	rm *.o shell