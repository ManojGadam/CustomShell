

typedef struct 
{
  char *name;
  char *arguments[10]; //optional parameters
  int isPipeToNext;
}Command;
void addCommand(Command **totalCommands,int *numOfCommands,char *command,char **args,int numberOfArgs,int pipeToNext);
int parseCommandsIntoTable(int size,char **parsedStr,char **inputFile,char **outputFile,Command **commands);
