flags = -std=c++11 -c -I./include

install:
	@echo Building C/C++ Syntax Extensions...
	@gcc -I./include -c .\lib\cstext.c
	@g++ $(flags) -o cstextcpp.o .\lib\cstext.cpp
	@g++ -Wno-write-strings $(flags) sample.cpp
	@g++ -o demo.exe *.o
	@rm *.o
	@echo Done. You can run the demo by using "./demo.exe".

clean:
	@rm -f *.o
	@rm -f *.exe