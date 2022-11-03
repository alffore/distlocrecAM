CC= g++ -std=c++17 -c 

CLINKER = g++ -o 

FLAGS = -l proj -l m 

DIR_SRC=./src/
DIR_OBJ=./obj/
DIR_BIN=./bin/

all: clean main lectores coordenadas salidas algoritmo
	$(CLINKER) $(DIR_BIN)distlocrecam.exe $(DIR_OBJ)*.o $(FLAGS)

main:
	$(CC) $(DIR_SRC)principal/*.cpp
	@mv *.o $(DIR_OBJ)	

lectores:
	$(CC) $(DIR_SRC)lectores/*.cpp
	@mv *.o $(DIR_OBJ)

coordenadas:
	$(CC) $(DIR_SRC)coordenadas/*.cpp 
	@mv *.o $(DIR_OBJ)

algoritmo:
	$(CC) $(DIR_SRC)algoritmo/*.cpp 
	@mv *.o $(DIR_OBJ)
	
salidas:
	$(CC) $(DIR_SRC)salidas/*.cpp 
	@mv *.o $(DIR_OBJ)

clean:
	@rm -rfv $(DIR_OBJ)*.o
	@rm -rfv $(DIR_BIN)*.exe