# Lab1 - Super Simple Shell

This lab is a simple command-line interface developed in C for executing various commands and pipelines. The shell is capable of parsing input commands and executing them in a separate process. It also supports redirection, background processes,

## How to build
To build this shell run "make" in linux shell or bash


## How to launch and quit

To launch this shell use "./shell" after building the shell
To quit run "exit" in the running shell


## Examples

Here are some example commands supported by the shell

1. ls


2. ls -l


3. head temp.txt


Methodology

4. cat < t1.txt


5. ls -l > t2.txt

total 204

 6.cat < t1.txt > t2.txt
 
 7. cat < temp.txt | head

8. ifconfig | grep UP

9. cat < temp.txt | head | sort


10. cat < temp.txt | head | sort | head -n 4

11.cat < temp.txt | more | more | grep 2 | sort | head | wc > t3.txt
     
12.cat < temp.txt | more | more | grep 2 | sort | head | wc  &     
     

13. ls | head -n 3 &


14. cat temp.txt | more | more | more | more | more | sort | grep 2 | sort | head


###negative cases

15. &

invalid input

16. |

invalid input

17. abc

Command abc not found

18. ls > t4.txt | more

invalid input

19. ls | cat < t4.txt

invalid input

20. ls | abc

Command abc not found



