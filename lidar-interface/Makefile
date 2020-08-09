app: main.o interface.o cmd.o
	g++ $^ -o $@

main.o: main.cpp
	g++ -c $< -o $@

interface.o: interface.cpp interface.hpp
	g++ -c $< -o $@

cmd.o: cmd.cpp cmd.hpp
	g++ -c $< -o $@

clean:
	rm *.o app