*BASIC FUNCTIONALITIES

GITHUB STRUCTURE:
**DO NOT WORK ON THE MASTER BRANCH**
- clone master
- perform: git pull
- create a local branch and switch there:
	git checkout -b [name_of_your_new_branch]
- work on the function or files you want there.
- when ready to push the branch on github:
	git push origin [name_of_your_new_branch]
- delete local branch:
	git branch -d [name_of_your_new_branch]

COMMIT MESSAGE STRUCTURE:
"UPDATED/ADDED/DELETED [file_name] (for big changes) | UPDATED/ADDED/DELETED [function_name] in [file_name] (small changes in functions) | ADDITIONAL EXPLANATION IF NECESSARY"
ie.
"UPDATED cd_function.c | ADDED pwd_function() in cd_function.c | help"
or if no new file was added:
"ADDED pwd_function() in cd_function.c | lol"

LEGEND:
[ ] not done yet
[*] potential start
[/] working on it, but not done
[X] done

BASIC INTERFACE
[ ] Show prompt when waiting for a new command

EXECV (EXECUTE PROGRAMS)
[ ] search and launch the right executable (based on the PATH variable or by using relative or absolute path) like in bash

BUILT-INS
[ ] echo with '-n'
	[ ] -n implementation, echos without newline at the end.
[ ] cd with relative and absolute path
[ ] pwd without any options
[ ] export without any options
[ ] unset without any options
[ ] env without any options and any arguments
[ ] exit without any options

COMMAND SEPARATOR (;)
[ ] ; separate commands like in bash.
		ie. command1; command2
		this will execute command2 regardless of if command1 succeeded.

ECHO ' and "
[ ] ' should work like in bash except for multiline commands
	ie. echo "$PATH"
	output: /usr/USERNAME/pathlocation
[ ] " should work like in bash except for multiline commands
	ie. echo '$PATH'
	output: $PATH

REDIRECTIONS
[ ] < (REDIRECT INPUT) should work like in bash except for the file descriptor aggregation
	ie. cat < file.txt
	output: whatever's in file.txt gets cat'd.
[*] > (REDIRECT OUTPUT) should work like in bash except for the file descriptor aggregation
	ie. echo "hello > file.txt
	output: the word "hello" is placed in file.txt
[ ] >> (APPEND OUTPUT TO END OF FILE) should work like in bash except for the file descriptor aggregation
	ie. echo "world!" >> file.txt
	output: "world!" gets added to the end of file.txt

PIPE COMMANDS
[ ] | (PIPES) should work like in bash
	ie. command1 | command2
	output: command1 is executed and its output it sent to command2.
ENVIRONMENT VARIABLES
[ ] environment variables ($ followed by characters) should work like in bash.
	[ ] make new env variables
	[ ] call env variables

DOLLAR QUESTION MARK ($?)
[ ] $? (EXIT STATUS OF LAST EXECUTED COMMAND) should work like in bash
	output: returns 0 if last executed command is true
			returns 1 if last executed command is false

THE CONTROLS. (CRTL-*)
[ ] CTRL-C terminates program, sends a SIGINT signal (kill -INT 888 or forcekill: kill -9 888 with 888 as your process ID)
[ ] CTRL-D ending a file (EßOF), closes the connection/closes the bash shell.
[ ] CTRL-\ quit command, causes program to terminate and dump core

REFERENCES:
https://flaviocopes.com/linux-command-echo/ 