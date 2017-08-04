
#include<stdio.h>
#include<stdlib.h>


struct Bus
{
	int Route_ID,TotalSeats,AvailableSeats;
	char Source[20],Destination[20],Time[10],Date[20],Type[20];
	float Cost;
};


void addBus();  //
void displayRoutes(); //
//void sort();
void searchRouterbyId();

//void searchRoutebyDate();
void updateRoute();


