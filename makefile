proj.exe : metro_ticket.o adding_station.o location.o view_map.o ticket_fare.o
	gcc -o proj.exe metro_ticket.o adding_station.o location.o view_map.o ticket_fare.o
metro_ticket.o: metro_ticket.c
	gcc -c metro_ticket.c
adding_station.o: adding_station.c
	gcc -c adding_station.c
location.o: location.c
	gcc -c location.c
view_map.o: view_map.o
	gcc -c view_map.c
ticket_fare.o: ticket_fare.c
	gcc -c ticket_fare.c
clean: 
	rm *.exe *.o
