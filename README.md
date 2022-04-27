# print.h standalone
spin-off from C-headers
print.h variadic print macros
print(args) print all arguments(space separated)
hexprint(args) prints all arguments in hex(except strings)
dbgprint(args) prints all arguments to stderr
dbghexprint(args) prints all arguments to stderr in hex(if possible)
dprint(delim,args) prints all arguments separated by delim string
hexdprint(delim,args) hex prints all arguments separated by delim string
fprint(FILE*,args) write all arguments(space separated) to file
hexfprint(FILE*,args) hex-write all arguments(space separated) to file
fdprint(delim,file,args)  writes all arguments with custom delim
hexfdprint(delim,file,args) writes all arguments in hex(except strings) with custom delim
