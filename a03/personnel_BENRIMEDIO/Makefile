personnel: personnel.cpp personmgr.o
	g++ --std=c++11 -Wall -Wextra -g -o personnel personmgr.o hashtable.o person.o personnel.cpp
personmgr.o: personmgr.cpp personmgr.h hashtable.o
	g++ --std=c++11 -Wall -Wextra -g -c -o personmgr.o personmgr.cpp
hashtable.o: hashtable.cpp hashtable.h person.o
	g++ --std=c++11 -Wall -Wextra -g -c -o hashtable.o hashtable.cpp
person.o: person.cpp person.h
	g++ --std=c++11 -Wall -Wextra -g -c -o person.o person.cpp
clean:
	rm ./personmgr.o ./person.o ./hashtable.o ./personnel
