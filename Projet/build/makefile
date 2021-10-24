SRC = ../src/
INCL = ../include/
TEST = ../testing/

build : test_Contact test_Logs test_InteractionTodos
				./test_* && g++ -o build.o $(SRC)*.cpp

test_Contact : $(TEST)Contact.cpp	
	g++ -o test_Contact.o $(TEST)Contact.cpp $(SRC)*[!Main].cpp 

test_Logs : $(TEST)Logs.cpp	
	g++ -o test_Logs.o $(TEST)Logs.cpp $(SRC)*[!Main].cpp 

test_InteractionTodos : $(TEST)InteractionTodos.cpp	
	g++ -o test_iTodos.o $(TEST)InteractionTodos.cpp $(SRC)*[!Main].cpp 

clear : 
	rm *.o