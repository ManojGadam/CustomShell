#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include "header.h"
#include "isValidInput.h"
/*This function parses the commands one by one and adds command to command table. During parsing it also finds input redirection and output redirection and keeps track of them
@param size is the number of of commands(strings) obtained from the user input
@param parsedStr is the array of commands(strings) obtained from the user input
@param inputFile is used to return file if input redirection(<) is present
@param outputFile is used to return file if output redirection(>) is present
@param commands is used to return Command structure array from user inputs
@return number of commands in the Command structure array, -1 if exit is present,-2 if any errors are present
*/
int parseCommandsIntoTable(int size,char **parsedStr,char **inputFile,char **outputFile,Command **commands)
{
char *command = NULL;
char **args = malloc(sizeof(char *)*10);
// if(*args == NULL)
// {
//     perror("malloc");
//     exit(1);
// }
int j=0,numOfCommands = 0;
for (int i = 0; i < size; i++)
     {
      char *current = parsedStr[i];
      if(isValidInput(current))
      {
        command = current;
        args[0] = command;
        j++;
      }
      else if(strcmp(current,"exit") == 0)
      {
        return -1;
      } 
      else if(strcmp(current,"|")==0)
      {
        addCommand(commands,&numOfCommands,command,args,j,1);
        j=0;
        command = NULL;
      }
      else if( strcmp(current,"<") != 0 && strcmp(current,">")!=0 && strcmp(current,"|")!=0 && strcmp(current,"&")!=0 && command!=NULL)
      {
        args[j] = current;
        j++;
      }
      else if(strcmp(current,"<") == 0)
      {
        //detecting incorrect input as per shell literature. If more than one command is present or no commands are present before < then error is thrown
        if(numOfCommands > 1 || (numOfCommands == 1 && command!=NULL) || (numOfCommands < 1 && command == NULL) )
        {
            printf("%s\n","invalid input");
            return -2;
        }
        *inputFile = parsedStr[i+1];
        i++;
        continue;
      }
      else if(strcmp(current,">") == 0)
      {
        *outputFile = parsedStr[i+1];
        i++;
        continue;
      }
      else if(strcmp(current,"&") == 0)
      {
        continue;
      }
      else
      {
        printf("Command %s not found\n",current);
        return -2;
      }
     }
     //edge case what if there is no builtin command
     if(command != NULL)addCommand(commands,&numOfCommands,command,args,j,0);
      free(args);
   return numOfCommands;   
}

