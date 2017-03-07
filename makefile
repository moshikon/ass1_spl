# All Targets
all: project1

# Tool invocations
# Executable "project1" depends on the files print.o and run.o.
project1: bin/main.o bin/cyberdns.o bin/cyberworm.o bin/cyberexpert.o bin/cyberpc.o bin/cyberschedule.o
	@echo 'Building target: cyber'
	@echo 'Invoking: C++ Linker'
	g++ -o bin/cyber bin/main.o bin/cyberdns.o bin/cyberworm.o bin/cyberexpert.o bin/cyberpc.o bin/cyberschedule.o -L/usr/lib
	@echo 'Finished building target: cyber'
	@echo ' '

# Depends on the source and header files
bin/main.o: src/main.cpp
	g++ -g -Wall -c -Linclude -o bin/main.o  src/main.cpp 

# Depends on the source and header files 
bin/cyberexpert.o: src/cyberexpert.cpp
	g++ -g -Wall -c -Linclude -o bin/cyberexpert.o  src/cyberexpert.cpp

# Depends on the source and header files 
bin/cyberworm.o: src/cyberworm.cpp
	g++ -g -Wall -c -Linclude -o bin/cyberworm.o  src/cyberworm.cpp
	
	# Depends on the source and header files 
bin/cyberpc.o: src/cyberpc.cpp
	g++ -g -Wall -c -Linclude -o bin/cyberpc.o  src/cyberpc.cpp
	
	# Depends on the source and header files 
bin/cyberdns.o: src/cyberdns.cpp
	g++ -g -Wall -c -Linclude -o bin/cyberdns.o  src/cyberdns.cpp
	
		# Depends on the source and header files 
bin/cyberschedule.o: src/cyberschedule.cpp
	g++ -g -Wall -c -Linclude -o bin/cyberschedule.o  src/cyberschedule.cpp

#Clean the build directory
clean: 
	rm -f bin/*