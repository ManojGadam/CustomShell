#include <string.h>
#include <stdio.h>
#include "isValidInput.h"
int isValidInput(char *cmd)
{
  char *builtInCmds[]   = {
    "echo",
    "pwd",
    "history",
    "alias",
    "export",
    "set",
    "unset",
    "type",
    "exec",
    "read",
    "source",
    "shift",
    "test",
    "times",
    "true",
    "false",
    "umask",
    "wait",
    "jobs",
    "fg",
    "bg",
    "kill",
    "nice",
    "nohup",
    "time",
    "setenv",
    "unsetenv",
    "getenv",
    "grep",
    "sed",
    "awk",
    "cut",
    "sort",
    "uniq",
    "clear",
    "wc",
    "head",
    "tail",
    "tee",
    "find",
    "locate",
    "which",
    "whereis",
    "man",
    "ls",
    "fmt",
    "pr",
    "tr",
    "more",
    "du",
    "cat",
    "mkdir",
    "whoami",
    "ifconfig",
    "rev"
};
  int size = sizeof(builtInCmds)/sizeof(char*);;
  for (int i = 0; i < size; i++)
  {
    if(strcmp(builtInCmds[i],cmd)==0)return 1;
  }
  return 0;
}

