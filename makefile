proj.exe : metro_ticket.o adding_station.o location.o  
	gcc -o proj.exe metro_ticket.o adding_station.o location.o
metro_ticket.o: metro_ticket.c
	gcc -c metro_ticket.c
adding_station.o: adding_station.c
	gcc -c adding_station.c
location.o: location.c
	gcc -c location.c
clean: 
	rm *.exe *.o
