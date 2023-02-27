/*Parses the initial user input to array of strings and also returns information like number of commands, number of pipes and whether the given command should be executed in background
@param cmd is the pointer to first command
@param size is used to return number of commands
@param isBackground is used to return whether the given command is background or not
@param noOfPipes is used to return number of pipes in the command
@param parsedStr is used to return the array of commands
*/
void getCommandSizeAndPipePosition(char cmd[1024],int *size, int *isBackGround,int *noOfPipes,char **parsedStr);
