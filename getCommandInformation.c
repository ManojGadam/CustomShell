#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include "getCommandInformation.h"
void getCommandSizeAndPipePosition(char cmd[1024],int *size, int *isBackGround,int *noOfPipes,char **parsedStr)
{
    int i=0,p = 0;
  while(cmd!=NULL)
  {
    if(strcmp(cmd,"&\n")==0)
    {
      *isBackGround = 1;
    }
    if(strcmp(cmd,"|")==0) p++;
    parsedStr[i] = malloc(strlen(cmd)+1);
    strcpy(parsedStr[i],cmd);
    cmd = strtok(NULL," ");
    i++;
  }
  char *lst = parsedStr[i];
  parsedStr[i-1][strcspn(parsedStr[i-1],"\n")]='\0';
  *size = i;
  *noOfPipes = p;
}