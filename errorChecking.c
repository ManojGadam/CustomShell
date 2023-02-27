#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include "isValidInput.h"
#include "errorChecking.h"
int errorChecking(char **cmd,int noOfCommands)
{
  for (int i = 0; i < noOfCommands; i++)
  {
    //making sure the input , output and & redirection are in correct places according to grammar 
    if(strcmp(cmd[i],"<")==0)
    {
      if(cmd[i+1] == NULL)
      {
        printf("%s\n","invalid input");
        return 1;
      }
      if(open(cmd[i+1],O_RDONLY)==-1)
      {
        printf("IUPUI : %s %s\n",cmd[i+1],"No such file or directory");
        return 1;
      }
      i++;	
    }
  else if(strcmp(cmd[i],"&")==0 )
   {
    if(i!=noOfCommands-1)
    {
      printf("%s\n","syntax error near unexpected token '&'");     
      return 1; 
    }
    else if(i==0)
    {
       printf("%s\n","invalid input");
      return 1;
    }
   }  
  else if(strcmp(cmd[i],">")==0 )
  {
    if(cmd[i+1]==NULL || (i!=noOfCommands-2 && i!= noOfCommands-3))
    {
      printf("%s\n","invalid input");
      return 1;
    }
  }
  // | should be between two commands
  else if(strcmp(cmd[i],"|") == 0)
  {
    if( i == noOfCommands-1)
    {
      printf("%s\n","Invalid Input");
      return 1;
    }
    if(i+1==noOfCommands || isValidInput(cmd[i+1])==0 || i==0)
    {
      printf("Command %s not found\n",cmd[i+1]);
      return 1;
    }
  }
  //  else if(isValidInput(cmd[i])!=1)
  //  {
  //   if(cmd[i+1])
  //    printf("%s %s\n",cmd[i],"command not found");
  //    return 1;     
  //  } 
  }
  
  
  return 0;
}
