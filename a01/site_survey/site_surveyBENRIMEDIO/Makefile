process: datalogger.o process.cpp
	g++ -g -Wall -Wextra -o process datalogger.o linkedlist.o Node.o Survey_data.o process.cpp
datalogger.o: linkedlist.o datalogger.cpp
	g++ -c -g -Wall -Wextra -o datalogger.o datalogger.cpp
linkedlist.o: Node.o linkedlist.cpp
	g++ -c -g -Wall -Wextra -o linkedlist.o linkedlist.cpp
Node.o: survey_data.o Node.cpp
	g++ -c -g -Wall -Wextra -o Node.o Node.cpp
survey_data.o: Survey_data.cpp
	g++ -c -g -Wall -Wextra -o Survey_data.o Survey_data.cpp
clean:
	rm ./Survey_data.o ./Node.o ./linkedlist.o ./datalogger.o ./process
