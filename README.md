*This project has been created as part of the 42 curriculum by msimoes, xalves* 

## Description
The MiniHorse project is a Unix shell implementation, recreating the core functionality of Bash. This project covers process management, piping, signal handling, enviroment variable expansion, redirections and heredocs.

## Features
- Interactive prompt with the command history (via readline)
- Enviroment variable expansion (`$VAR`, `$?`)
- Quote handling (single and double quotes)
- Pipes (`|`) between commands
- Redirections: `>`, `>>`, `<`, `<<` (heredoc)
- Built-in commands

## Built-in Commands
| Command | Description |
|---------|-------------|
| `echo [-n]` | Print arguments to stdout |
| `cd [path]` | Change current directory |
| `pwd` | Print current working directory |
| `export [key=value]` | Set or display environment variables |
| `unset [key]` | Remove an environment variable |
| `env` | Display all environment variables |
| `exit [code]` | Exit the shell with an optional exit code |

## Instructions

### Compilation
To compile the project simply run:
```bash
make
```
To recompile everything run:
```bash
make re
```

Both of these will create a `minishell` executable.

### Usage
```bash
./minishell
```
This will start the interactive shell prompt.

### Examples
Running basic commands:
```bash
minishell: echo "Hello, World!"
minishell: ls -la | grep src
minishell: cat file.txt > output.txt
minishell: export MY_VAR=hello && echo $MY_VAR
```

Using heredoc:
```bash
minishell: cat << EOF
> Hello
> World
> EOF
```

### Cleanup
Remove object files:
```bash
make clean
```
Remove object files and executable:
```bash
make fclean
```

## Resources
- [Bash Reference Manual](https://www.gnu.org/software/bash/manual/bash.html)
- [GNU Readline Library](https://tiswww.case.edu/php/chet/readline/rltop.html)
- [Unix fork/exec/pipe - man pages](https://www.man7.org/linux/man-pages/man2/fork.2.html)
- [Unix Signals - man pages](https://www.man7.org/linux/man-pages/man7/signal.7.html)

### AI usage
No AI was used to write the code of this project. AI was only used to find problems with the code and suggest fixes.
It was also used to make a draft for the README.