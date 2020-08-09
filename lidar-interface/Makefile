app: main.o interface.o cmd.o
	g++ $^ -o $@ -lpthread -std=c++17

main.o: main.cpp
	g++ -c $< -o $@ -std=c++17

interface.o: interface.cpp interface.hpp
	g++ -c $< -o $@ -std=c++17

cmd.o: cmd.cpp cmd.hpp
	g++ -c $< -o $@ -std=c++17

clean:
	rm *.o app