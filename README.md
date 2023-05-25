# Simple Shell

A basic shell that prints a prompt, waits for the user to enter a command, and prints what they entered on the next line.

This shell was developed as a team project for the ALX Africa Software Engineering Program, as part of the low-level programming curriculum.

## Features

- Prints a prompt to indicate that it is ready to accept commands.
- Waits for the user to enter a command.
- Executes the entered command.
- Prints the entered command on the next line.
- Handles basic built-in commands like `cd` and `exit`.

## Getting Started

To get started with the Shell, follow these steps:

1. Clone this repository to your local machine.
2. Compile the shell using the provided Makefile by running the command `make` in the repository's directory.
3. Run the shell by executing the generated `simple_shell` executable.
4. You will see a prompt indicating that the shell is ready for commands. Enter your desired commands and press Enter to execute them.

## Usage

The Simple Shell supports the following built-in commands:

- `cd [directory]`: Change the current working directory to the specified directory. If no directory is provided, it changes to the home directory.
- `exit`: Exit the shell.

Apart from the built-in commands, the Simple Shell can execute other commands available in your system. It searches for commands in the directories listed in the `PATH` environment variable.

## Examples

Here are some examples of using the Simple Shell:
```
$ ./simple_shell
```
```
$ :) ls
```
```
$ ls
README.md shell.c shell.h
```
```
$ :) pwd
```
```
$ pwd
/home/user/simple_shell
```
```
$ :) cd ..
```
```
$ cd ..
```
```
$ :) pwd
```
```
$ pwd
/home/user
```
```
$ :) exit
$
```
```

## Authors

This Simple Shell was developed as a team project by the following ALX Africa Software Engineering Program students:

- Bouaricha Karim
- Bouaricha Ayman

## Acknowledgments

We would like to thank our mentors and instructors at ALX Africa for their guidance and support throughout the development of this project.
