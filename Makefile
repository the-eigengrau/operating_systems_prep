doctor:
	@uname -a
	@gcc --version | head -n 1
	@gdb --version | head -n 1
	@valgrind --version
	@strace -V 2>&1 | head -n 1
