#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "header.h"
#include "isValidInput.h"
#include "errorChecking.h"
#include "getCommandInformation.h" 





int main(int argc,char **argv)
{
   while(1)
   {
    int maxCmdLength = 1024;
    char cmd[maxCmdLength];
     char **parsedStr = malloc(maxCmdLength*sizeof(char *));
    //  if(*parsedStr == NULL)
    //  {
    //   perror("malloc");
    //   exit(EXIT_FAILURE);
    //  }
     printf("IUPUI>");
     fflush(stdout);
     fgets(cmd,maxCmdLength,stdin);
     
     int isBackGround,size,noOfPipes;
     char *inputFile = NULL;
     char *outputFile = NULL;
     char *token = strtok(cmd," ");
     //used to get number of strings, pipes , commands array and if & is present in command or not
     getCommandSizeAndPipePosition(token,&size,&isBackGround,&noOfPipes,parsedStr);
     Command **commands = malloc(sizeof(Command)*size);
    //  if(*commands == NULL)
    //  {
    //   perror("malloc");
    //   exit(1);
    //  }
     //ValidatingInput
     if(errorChecking(parsedStr,size)!=0)continue; 
     //creating a command table structure with parsed command array and getting input and outfiles if (<,>) are present    
     int numOfCommands = parseCommandsIntoTable(size,parsedStr,&inputFile,&outputFile,commands);
     if(numOfCommands == -1)break;
     if(numOfCommands == -2)continue;
     
     //duplicating the file descriptors to close them
      int tmpIn = dup(0);
      int tmpOut = dup(1);
      if(tmpIn == -1 || tmpOut == -1)
      {
        perror("error duplicating file descriptor");
        exit(1);
      }
      int filedes = open(inputFile,O_RDONLY);
      if(filedes < 0)filedes = dup(tmpIn);
      int ret,outdes;


     for (int i = 0; i < numOfCommands; i++)
     {
      if(dup2(filedes,0) == -1)
      {
        perror("dup2");
        exit(1);
      }
      close(filedes);
      if(i==numOfCommands-1)
      {
        outdes = open(outputFile,O_CREAT|O_TRUNC|O_WRONLY,0644);
        if(outdes < 0)outdes = dup(tmpOut);
      }
      else
      {
        if(noOfPipes > 0)
        {
          int pipefd[2];
          if(pipe(pipefd)<0)
          {
            perror("pipe");exit(1);
          }
          outdes = pipefd[1];
          filedes = pipefd[0];
        }
      }
      if(dup2(outdes,1)==-1)
      {
        perror("dup2");
        exit(1);
      }
      close(outdes);
      ret = fork();
      if(ret<0)
      {
        perror("fork");
        exit(1);
      }
      else if(ret == 0)
      {
        printf("%s","in");
        if(execvp(commands[i]->name,commands[i]->arguments) < 0)
        {
          perror("execvp");
          exit(1);
        }
      }
      else 
      {
        if(!isBackGround) waitpid(ret,NULL,0);
      }

     }
           

      dup2(tmpIn, 0); // restoring standard input
      dup2(tmpOut, 1); // restoring standard output
      close(tmpIn);
      close(tmpOut);
      //if(!isBackGround) waitpid(ret,NULL,0);


      memset(cmd,0,sizeof(cmd));
      memset(token,0,sizeof(token));
      free(commands);
      free(parsedStr);
      // free(inputFile);
      // free(outputFile);
   }
   return 0;
}





