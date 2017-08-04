
#include "header.h"

int main()
{

   mainmain();

//updateRoute();
return 0;

}
void mainmain()
{
    char ch,choice;
    do
	{

		system("cls");
		printf("\n********* MENU ***********");
		printf("\n1. Create new Bus Route: ");
		printf("\n2. Display Existing Bus Routes: ");
		printf("\n3. Search Bus Routes by Route ID: ");
		//printf("\n4. Search Bus Routes by Date: ");
		printf("\n4. Update existing Bus Route");
		printf("\n\nEnter your choice: ");
		fflush(stdin);
		scanf("%c",&choice);

		switch(choice)
		{
		case '1': addBus();
				break;

		case '2': displayRoutes();
				break;

        case '3': searchRouterbyId();
				break;

		case '4':updateRoute();
				break;

		default:
		    printf("Wrong Option Selected!!!");
				break;
		}
		fflush(stdin);
		printf("\nDo you want to continue[y/n]: ");
		scanf(" %c",&ch);
	}
	while(ch=='y' || ch=='Y');
}
