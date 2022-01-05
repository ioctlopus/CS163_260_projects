planters: planters.cpp plantermgr.o
	g++ --std=c++11 -g -Wall -Wextra -o planters plantermgr.o bst.o node.o planters.cpp
plantermgr.o: plantermgr.cpp plantermgr.h bst.o
	g++ --std=c++11 -g -Wall -Wextra -c -o plantermgr.o plantermgr.cpp
bst.o: bst.cpp bst.h node.o
	g++ --std=c++11 -g -Wall -Wextra -c -o bst.o bst.cpp
node.o: node.cpp node.h
	g++ --std=c++11 -g -Wall -Wextra -c -o node.o node.cpp
clean:
	rm node.o bst.o plantermgr.o planters
