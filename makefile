Project5: island.o proj5Base.o
	g++ -o Project5 island.o proj5Base.o

island.o: island.cpp island.h
	g++ -c island.cpp

proj5Base.o: proj5Base.cpp island.h
	g++ -c proj5Base.cpp