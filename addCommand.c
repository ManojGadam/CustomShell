#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include "header.h"
/*Taking the inputs creates a Command structure and adds this structure into an array
@param numOfCommands keeps track of number of actual built in commands leaving all symbols and fileNames
@param command is the name of the builtin command
@param args is an array of optional parameters of a command
@param numberOfArgs is the length of args array
@param pipeToNext keeps track of whether a builtin command is followed by a pipe or not
*/
void addCommand(Command **totalCommands,int *numOfCommands,char *command,char **args,int numberOfArgs,int pipeToNext)
{
  int i=0;
  Command *newCommand = malloc(sizeof(Command));
  // if(newCommand == NULL)
  // {
  //     perror("malloc");
  //     exit(1);
  // }
  newCommand->name = command;
  //newCommand->arguments = malloc(numberOfArgs*sizeof(char *));
  for (i = 0; i < numberOfArgs; i++)
  {
    newCommand->arguments[i] = args[i];
  }
  newCommand->arguments[numberOfArgs] = NULL;
  newCommand->isPipeToNext = pipeToNext;
  totalCommands[*numOfCommands] = newCommand;
  (*numOfCommands)++;
  //free(newCommand);
}
