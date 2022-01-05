builders: builder.o builders.cpp
	g++ --std=c++11 -g -Wall -Wextra -o builders structuretype.o event.o Node.o linkedlist.o stack.o builder.o builders.cpp
builder.o: stack.o linkedlist.o builder.cpp
	g++ --std=c++11 -g -c -Wall -Wextra -o builder.o builder.cpp
stack.o: Node.o stack.cpp
	g++ --std=c++11 -g -c -Wall -Wextra -o stack.o stack.cpp
linkedlist.o: Node.o linkedlist.cpp
	g++ --std=c++11 -g -c -Wall -Wextra -o linkedlist.o linkedlist.cpp
Node.o: event.o Node.cpp
	g++ --std=c++11 -g -c -Wall -Wextra -o Node.o Node.cpp
event.o: structuretype.o event.cpp
	g++ --std=c++11 -g -c -Wall -Wextra -o event.o event.cpp
structuretype.o: structuretype.cpp
	g++ --std=c++11 -g -c -Wall -Wextra -o structuretype.o structuretype.cpp
clean:
	rm ./event.o ./Node.o ./linkedlist.o ./stack.o ./structuretype.o ./builder.o ./builders
