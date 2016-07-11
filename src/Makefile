obj = Storage.o Meeting.o User.o Date.o AgendaService.o AgendaUI.o
main : $(obj)
	g++ -o main -std=c++0x Agenda.cpp $(obj)
AgendaUI.o : AgendaUI.cpp AgendaUI.h
	g++ -c -std=c++0x AgendaUI.cpp
AgendaService.o : AgendaService.cpp AgendaService.h
	g++ -c -std=c++0x AgendaService.cpp
Storage.o : Storage.h Storage.cpp
	g++ -c -std=c++0x Storage.cpp
Meeting.o : Meeting.h Meeting.cpp
	g++ -c Meeting.cpp
User.o : User.h User.cpp
	g++ -c User.cpp
Date.o : Date.h Date.cpp
	g++ -c Date.cpp
clean :
	rm $(obj) main
