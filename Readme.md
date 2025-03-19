# Minishell

As beautiful as a shell

## Overview
Minishell is a simple shell implementation written in C. The project aims to provide a basic command-line interface, similar to Bash-5.2, with fundamental shell features such as executing commands, handling pipes, redirections, and managing environment variables.

## Features
- Interactive prompt displaying
- Command execution with absolute and relative paths
- Handling of built-in commands:
  - `echo` (with `-n` option)
  - `cd` (with relative or absolute path)
  - `pwd`
  - `export`
  - `unset`
  - `env`
  - `exit`
- Input and output redirections (`<`, `>`, `>>`, `<<`)
- Pipe support (`|`)
- Environment variable expansion (`$VAR` and `$?`)
- Signal handling (`Ctrl+C`, `Ctrl+D`, `Ctrl+\`)
- Command history

## Installation & Usage
### Compilation
```sh
make
```
This will generate the `minishell` executable.

### Running the Shell
```sh
./minishell
```

### Exiting
- Type `exit`
- Press `Ctrl+D`

## Requirements
- C compiler (`gcc`)
- `readline` library (modify path accordingly in the Makefile if needed)

## Project Structure
```
minishell/
├── src/          # Source files
├── inc/          # Header files
├── Makefile      # Build instructions
└── README.md     # Project documentation
```

## Authors
- De Win Guillaume
- Kerstens Reda
