![Holberton logo](https://github.com/user-attachments/assets/15d9ca86-c3f2-478c-aa83-60e419b532af)

# UNIX Simple Shell
This repository contains the files required to implement and initialise the UNIX simple shell. 
___
## What is a shell?
A shell is a command-line interpreter, designed to take commands from the keyboard and forwards these commands to the operating system for processing.
___
## About this project
This project is made for Holberton School Australia. It is a simple, stripped down version of the UNIX shell, created with the C programming language.
___
## Flowchart
Our thought process of how an UNIX shell works.
![Flowchart](https://github.com/user-attachments/assets/1a813692-51c4-42dc-99a1-7068e45757c0)

___
## How to Compile
All files are compiled using gcc (Ubuntu 9.4.0-1ubuntu1~22.04) using flags: -Wall -Werror -Wextra -pedantic -std=gnu89

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```
___
## Installation
How to install and use the Simple Shell

```bash
Clone Repo: git clone https://github.com/nf626/holbertonschool-simple_shell.git
Change the working directory: cd holbertonschool-simple_shell
Compile: gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
Run interactive mode: ./hsh
Run non-interactive mode: echo "/bin/ls" | ./hsh
```
___
# Usage Examples
## Interactive Mode
Using the /bin/ls or ls command shall list the files in the working directory.
```c
#cisfun$ /bin/ls
AUTHORS    _getenv.c  hsh           man_1_simple_shell  shell.c
README.md  helpers.c  main_utils.c  path.c              shell.h
```

Using the /bin/ls -l or ls -l command shall list the files in the working directory in long format.
```c
#cisfun$ /bin/ls -l
total 56
-rw-r--r-- 1 root root    84 Jan  6 10:47 AUTHORS
-rw-r--r-- 1 root root   541 Jan  6 10:47 README.md
-rw-r--r-- 1 root root   887 Jan  6 10:47 _getenv.c
-rw-r--r-- 1 root root   962 Jan  6 10:47 helpers.c
-rwxr-xr-x 1 root root 17584 Jan  6 11:01 hsh
-rw-r--r-- 1 root root  2301 Jan  6 10:47 main_utils.c
-rw-r--r-- 1 root root  2460 Jan  6 10:47 man_1_simple_shell
-rw-r--r-- 1 root root  2315 Jan  6 10:47 path.c
-rw-r--r-- 1 root root   807 Jan  6 10:47 shell.c
-rw-r--r-- 1 root root   860 Jan  6 10:47 shell.h
```

___
## Non-Interactive Mode
Using echo "/bin/ls" | ./hsh shall list the files in the working directory.
```c
echo "/bin/ls" | ./hsh
AUTHORS    _getenv.c  hsh           man_1_simple_shell  shell.c
README.md  helpers.c  main_utils.c  path.c              shell.h
```

Using echo "ls -l" | ./hsh shall list the files in the working directory in long format.
```c
total 56
-rw-r--r-- 1 root root    84 Jan  6 10:47 AUTHORS
-rw-r--r-- 1 root root   541 Jan  6 10:47 README.md
-rw-r--r-- 1 root root   887 Jan  6 10:47 _getenv.c
-rw-r--r-- 1 root root   962 Jan  6 10:47 helpers.c
-rwxr-xr-x 1 root root 17584 Jan  6 11:01 hsh
-rw-r--r-- 1 root root  2301 Jan  6 10:47 main_utils.c
-rw-r--r-- 1 root root  2460 Jan  6 10:47 man_1_simple_shell
-rw-r--r-- 1 root root  2315 Jan  6 10:47 path.c
-rw-r--r-- 1 root root   807 Jan  6 10:47 shell.c
-rw-r--r-- 1 root root   860 Jan  6 10:47 shell.h
```
___
# Authors
- [Nigel Feng](https://github.com/nf626)
- [Rico Pascua](https://github.com/FullTiltHeatstroke)
- [Won Chak Leung](https://github.com/chak8x8)
