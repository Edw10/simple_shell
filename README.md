### **SIMPLE SHELL**

This is the repository of the project Simple_Shell at [GitHub](1).

The Shell
is a user interface for access to an operating systems services. In general, operating system shells use either a command-line interface (CLI) or graphical user interface (GUI), depending on a computers role and particular operation. It is named a shell because it is the outermost layer around the operating system kernel.
Commands
is a directive to a computer program to perform a specific task.
What is the Process to Execute a Command?
Prompt:
The firts step is print to the user a specific character that indicates the user can type the commands.
Get the User Command:
Next the shell receive the users input with the command requested and they arguments, the system divide that string every whitespace to work wiht it and differentiate between the command and the argument.
Look For the File:
When the system identify the command name, the shell search for the file in the currend directory and every directory listed in the environment variable PATH to determinate if its posible to execute.
Execute the Command:
In order to execute the program the shell need to create another proccess to continue with the shell after that, to do this te shell uses the system calls fork, execve and wait in this way:

*Create by [Edward Osorno](2), [Samuel Rojas Coley](3)*

[1]: https://github.com/
[2]: https://instagram.com/edw10.10
[3]: https://github.com/Saroco83/