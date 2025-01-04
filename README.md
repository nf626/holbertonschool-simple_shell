![Holberton logo](https://github.com/user-attachments/assets/15d9ca86-c3f2-478c-aa83-60e419b532af)

# Simple Shell
This repository contains the files required to initialise the UNIX simple shell program.
___

## About this project
This project is made for Holberton School. It is a simple, stripped down version of the linux shell, created with the C programming language, 
___

## Flowchart
Our thought process for developing a UNIX simple shell.
![image](https://github.com/user-attachments/assets/7386f02d-16f7-4074-aca0-2a476dfc9aa6)
___

## How to compile
All files are compiled using gcc (Ubuntu 9.4.0-1ubuntu1~22.04) with flags: -Wall -Werror -Wextra -pedantic -std=gnu89

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
___

## Installation
How to install and use UNIX Simple Shell

```bash
  Clone Repo: git clone https://github.com/nf626/holbertonschool-simple_shell.git
  Compile: gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
  Run interactive mode: ./hsh
  Run non-interactive mode: echo "/bin/ls" | ./hsh
```
___

# Examples
## Interactive Mode
Using /bin/ls or ls command lists the current directory contents of files and directories.
```c
#cisfun$ /bin/ls
AUTHORS         execute.c       interactive.c       parse_input.c  shell_main.c
README.md       fork_process.c  man_1_simple_shell  read_input.c
environ_path.c  hsh             non_interactive.c   shell.h
#cisfun$ exit
```
Using /bin/ls -l or ls -l command lists the current directory contents of files and directories in long format.
```c
#cisfun$ /bin/ls -l
total 68
-rw-r--r-- 1 root root   187 Jan  4 01:24 AUTHORS
-rw-r--r-- 1 root root   543 Jan  4 01:24 README.md
-rwxr-xr-x 1 root root  2491 Jan  4 01:24 environ_path.c
-rwxr-xr-x 1 root root  1308 Jan  4 01:24 execute.c
-rwxr-xr-x 1 root root  1161 Jan  4 01:24 fork_process.c
-rwxr-xr-x 1 root root 17576 Jan  4 01:25 hsh
-rwxr-xr-x 1 root root   421 Jan  4 01:24 interactive.c
-rw-r--r-- 1 root root  2240 Jan  4 01:24 man_1_simple_shell
-rwxr-xr-x 1 root root   301 Jan  4 01:24 non_interactive.c
-rwxr-xr-x 1 root root   904 Jan  4 01:24 parse_input.c
-rwxr-xr-x 1 root root   380 Jan  4 01:24 read_input.c
-rwxr-xr-x 1 root root   833 Jan  4 01:24 shell.h
-rwxr-xr-x 1 root root   242 Jan  4 01:24 shell_main.c
#cisfun$ exit
```
___

## Non-Interactive Mode
```c
echo "/bin/ls" | ./hsh
AUTHORS         execute.c       interactive.c       parse_input.c  shell_main.c
README.md       fork_process.c  man_1_simple_shell  read_input.c
environ_path.c  hsh             non_interactive.c   shell.h
```
```c
echo "ls -l" | ./hsh
total 68
-rw-r--r-- 1 root root   187 Jan  4 01:24 AUTHORS
-rw-r--r-- 1 root root   543 Jan  4 01:24 README.md
-rwxr-xr-x 1 root root  2491 Jan  4 01:24 environ_path.c
-rwxr-xr-x 1 root root  1308 Jan  4 01:24 execute.c
-rwxr-xr-x 1 root root  1161 Jan  4 01:24 fork_process.c
-rwxr-xr-x 1 root root 17576 Jan  4 01:25 hsh
-rwxr-xr-x 1 root root   421 Jan  4 01:24 interactive.c
-rw-r--r-- 1 root root  2240 Jan  4 01:24 man_1_simple_shell
-rwxr-xr-x 1 root root   301 Jan  4 01:24 non_interactive.c
-rwxr-xr-x 1 root root   904 Jan  4 01:24 parse_input.c
-rwxr-xr-x 1 root root   380 Jan  4 01:24 read_input.c
-rwxr-xr-x 1 root root   833 Jan  4 01:24 shell.h
-rwxr-xr-x 1 root root   242 Jan  4 01:24 shell_main.c
```
___

# Authors
-[Nigel Feng] - (https://github.com/nf626)
*[Rico Pascua] - (https://github.com/FullTiltHeatstroke)
+[Won Chak Leung] - (https://github.com/chak8x8)
