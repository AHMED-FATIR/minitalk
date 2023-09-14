# minitalk
This is my implementation of the minitalk project from 42 school.

Description : 
Minitalk is a small client-server program that allows two processes to communicate with each other using signals. 
The server process waits for a signal from the client process, decodes the message, and prints it to the console. 
The client process sends a message to the server process by sending a series of signals, 
where each signal represents a bit in the message.

Usage : 
To use the minitalk program, follow these steps:

Start the server process by running the ./server command.
In a separate terminal window, run the ./client [server-pid] [message] command to send a message to the server process.
The server process will decode the message and print it to the console.
Note: The message argument in step 2 must be a string of ASCII characters, 
and the length of the message must not exceed the maximum signal length allowed by the system.
