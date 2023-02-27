# Lab1 - Super Simple Shell

This lab is a simple command-line interface developed in C for executing various commands and pipelines. The shell is capable of parsing input commands and executing them in a separate process. It also supports redirection, background processes,

## How to build
To build this shell run "make" in linux shell or bash


## How to launch and quit

To launch this shell use "./shell" after building the shell
To quit run "exit" in the running shell


## Examples

Here are some example commands and their outputs from the shell

1. ls

aa.txt			 header.h		   shell.c
addCommand.c		 helloworld.txt		   Shell_cpy.txt
addCommand.o		 isValidInput.c		   shell.o
codeitr1.txt		 isValidInput.o		   snap

2. ls -l

total 208
-rw-rw-r-- 1 1001 1001     2 Feb 22 15:18 aa.txt
-rw-rw-r-- 1 1001 1001  1164 Feb 24 13:25 addCommand.c
-rw-rw-r-- 1 1001 1001  1544 Feb 24 13:26 addCommand.o
-rw-rw-r-- 1 1001 1001  7172 Feb 20 16:51 codeitr1.txt
-rw-rw-r-- 1 1001 1001  7483 Feb 20 19:16 coder_version2.txt
-rw-rw-r-- 1 1001 1001  6802 Feb 19 05:42 code.txt
drwxr-xr-x 2 1001 1001  4096 Jan 28 22:50 Desktop

3. head temp.txt

Finding the top financial advisor in the United States means choosing between thousands of options. Whether you're looking for help with retirement, wealth management or tax planning, the U.S. is home to thousands of advisors that can meet your specific needs. Based on the methodology outlined below, SmartAsset identified these financial advisor firms as among the top 5 financial advisor firms in the U.S.
Rank 	FINANCIAL ADVISOR 	ASSETS MANAGED
1 	Fisher Investments 	$208,905,102,124
2 	Captrust 	$655,054,291,754
3 	Mercer Global Advisors, Inc. 	$34,011,524,251
4 	Madison Investment Advisors, LLC 	$19,427,234,565
5 	Summit Rock Advisors, LP 	$21,733,298,515

Methodology

4. cat < t1.txt

abcdef

5. ls -l > t2.txt

total 204
-rw-rw-r-- 1 gmanoj gmanoj     2 Feb 22 15:18 aa.txt
-rw-rw-r-- 1 gmanoj gmanoj  1164 Feb 24 13:25 addCommand.c
-rw-rw-r-- 1 gmanoj gmanoj  1544 Feb 24 13:26 addCommand.o
-rw-rw-r-- 1 gmanoj gmanoj  7172 Feb 20 16:51 codeitr1.txt
-rw-rw-r-- 1 gmanoj gmanoj  7483 Feb 20 19:16 coder_version2.txt
-rw-rw-r-- 1 gmanoj gmanoj  6802 Feb 19 05:42 code.txt
drwxr-xr-x 2 gmanoj gmanoj  4096 Jan 28 22:50 Desktop

 6.cat < t1.txt > t2.txt
 
 abcdef (in t2.txt)
 
 7. cat < temp.txt | head
 
  Finding the top financial advisor in the United States means choosing between thousands of options. Whether you're looking for help with retirement, wealth management or tax planning, the U.S. is home to thousands of advisors that can meet your specific needs. Based on the methodology outlined below, SmartAsset identified these financial advisor firms as among the top 5 financial advisor firms in the U.S.
Rank 	FINANCIAL ADVISOR 	ASSETS MANAGED
1 	Fisher Investments 	$208,905,102,124
2 	Captrust 	$655,054,291,754
3 	Mercer Global Advisors, Inc. 	$34,011,524,251
4 	Madison Investment Advisors, LLC 	$19,427,234,565
5 	Summit Rock Advisors, LP 	$21,733,298,515

Methodology

8. ifconfig | grep UP

enp0s3: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536

9. cat < temp.txt | head | sort



1 	Fisher Investments 	$208,905,102,124
2 	Captrust 	$655,054,291,754
3 	Mercer Global Advisors, Inc. 	$34,011,524,251
4 	Madison Investment Advisors, LLC 	$19,427,234,565
5 	Summit Rock Advisors, LP 	$21,733,298,515
 Finding the top financial advisor in the United States means choosing between thousands of options. Whether you're looking for help with retirement, wealth management or tax planning, the U.S. is home to thousands of advisors that can meet your specific needs. Based on the methodology outlined below, SmartAsset identified these financial advisor firms as among the top 5 financial advisor firms in the U.S.
Methodology
Rank 	FINANCIAL ADVISOR 	ASSETS MANAGED

10. cat < temp.txt | head | sort | head -n 4



1 	Fisher Investments 	$208,905,102,124
2 	Captrust 	$655,054,291,754

11.cat < temp.txt | more | more | grep 2 | sort | head | wc > t3.txt

     10     263    1771
     
12.cat < temp.txt | more | more | grep 2 | sort | head | wc  &     
     
     IUPUI>     10     263    1771

13. ls | head -n 3 &

IUPUI>aa.txt
addCommand.c
addCommand.o

14. cat temp.txt | more | more | more | more | more | sort | grep 2 | sort | head

1 	Fisher Investments 	$208,905,102,124
2 	Captrust 	$655,054,291,754
3 	Mercer Global Advisors, Inc. 	$34,011,524,251
4 	Madison Investment Advisors, LLC 	$19,427,234,565
5 	Summit Rock Advisors, LP 	$21,733,298,515
A 2020 Northwestern Mutual study found that 71% of U.S. adults admit their financial planning needs improvement. However, only 29% of Americans work with a financial advisor.3
Consider this example: A recent Vanguard study found that, on average, a hypothetical $500K investment would grow to over $3.4 million under the care of an advisor over 25 years, whereas the expected value from self-management would be $1.69 million, or 50% less. In other words, an advisor-managed portfolio would average 8% annualized growth over a 25-year period, compared to 5% from a self-managed portfolio.2
election-2024-trump-89232.jpg
Even the comparatively few president books that are due out this year suggest readers’ curiosity isn’t consumed by larger-than-life statesmen. Instead, they’re focused on what Bruce Nichols, the publisher of Little, Brown and Company, described to me as “non-canonical” chief executives. For instance, a rare biography of James Garfield is due this summer. Garfield spent a scant six months in office in 1881 before dying of a gunshot wound by an assassin, but the rest of his life was fascinating — or at least readers had better hope it was. Likewise, Richard Norton Smith’s long-planned biography of Gerald Ford, a 2½-year White House resident, is expected in April.
If that view is gaining a foothold among not-especially-radical folks who’d otherwise be glad to pay $24.95 for an ornament featuring Lyndon Johnson’s 1967 Blue Room Christmas Tree, it’s probably even more pronounced among the general public.


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



