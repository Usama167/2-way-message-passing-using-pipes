# 2-way-message-passing-using-pipes
communication between 4 processes using named pipes

#Getting Started
# Introduction:
This project is to perform two way message passing between 4 processes
using named pipes.
In this Project we are performing two way communication between 4
processors. At the start of project a message will prompt on terminal asking
user to enter the processors to communicate. As soon as user enters the
two terminals will open one will ask select process to write from and one
will ask select process to read from, and communication between
processes will start.

# Installaton Procedure:

Open up Terminal By pressing Ctrl + Alt + T
Type sudo apt-get install git to install git on your Linux machine.
After the installation is complete, type git clone https://github.com/Usama167/2-way-message-passing-using-pipes.git
Navigate to the target directory through terminal where you have downloaded your git.
Compile the code by typing gcc -o main main.c
Execute the compiled program by typing ./main

# Methodology:

Process communication can be done with many ways such as using
unnamed pipes, named pipes, message queue, and shared memory and
etc. We selected named pipe as our methodology to implement two way
process communication. Named pipes are further enhancement, they are
also Known as FIFO (First In First out).In FIFO two processes share a same
file for communication. Process A writes on the file and Process B read from
the same file or vice versa. System call of mkfifo is used to make FIFO.
