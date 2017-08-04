
#include "header.h"

void addBus()
{
	struct Bus *temp;
	int i,size;char ch1;
	char str[20],ch;
	FILE *fp1;
	temp=(struct Bus*)malloc(sizeof(struct Bus)); //Dynamic memory allocation

	if(temp==NULL)
	{
		printf("NO memory allocated..!!!");
		exit(0);
	}
	else
	{
		//printf("\nRoute ID");
		//scanf("%d",&temp->Route_ID);

        printf("\nRoute ID:");
        temp->Route_ID=creatRoutId();// gets a new rout id
        printf("%d\n",temp->Route_ID);

		//printf("\nSource : ");
		//scanf("%s",temp->Source);
		do{
			printf("\nEnter Source: ");
			fflush(stdin);
            scanf("%s",temp->Source);
            i=validateSD(temp->Source,strlen(temp->Source));
	        if(i==0)
	        {
				printf("\tEnter a valid Source");
		    }
           }while(i==0);

		//printf("\nDestination: ");
		//scanf("%s",temp->Destination);
		do{
			printf("\nEnter Destination: ");
			fflush(stdin);
            scanf("%s",temp->Destination);
            i=validateSD(temp->Destination,strlen(temp->Destination));
	        if(i==0)
	        {
				printf("\tEnter a valid Destination");
		    }
           }while(i==0);

		//printf("\nTotalSeats : ");
		//scanf("%d",&temp->TotalSeats);
		do{
			printf("\nTotalSeats:");
			fflush(stdin);
            scanf("%s",str);//Enter the phno. as String.
		    size=strlen(str);
		    i=TotalSeats(str,strlen(str));
	        if(i==0)
	        {
			   printf("\nEnter the valid TotalSeats");
		    }
        }while(i==0);
        temp->TotalSeats=atoi(str);// atoi() function to convert string to number.


        do{
			printf("\nTotal AvailableSeats:");
			fflush(stdin);
            scanf("%s",str);//Enter the phno. as String.
		    size=strlen(str);
		    i=TotalSeats(str,strlen(str));
	        if(i==0)
	        {
			   printf("\nEnter the valid TotalSeats");
		    }
        }while(i==0);
        temp->AvailableSeats=atoi(str);
        while(1)
		{
		printf("\nType :\n1.Sleeper With A/C\n2.Semi Sleeper With A/C\n3.Non Sleeper With A/C\n4.Sleeper With out A/C\n5.Semi Sleeper With out A/C\n6.Non Sleeper With out A/C\nEnter choice : ");
		fflush(stdin);
		scanf("%c",&ch1);
		if(ch1=='1')
		{
			strcpy(temp->Type,"Sleeper With A/C.");
			break;
		}
		else if(ch1=='2')
		{
			strcpy(temp->Type,"Semi Sleeper With A/C.");
			break;
		}
		else if(ch1=='3')
		{
			strcpy(temp->Type,"Non Sleeper With A/C.");
			break;
		}
		else if(ch1=='4')
		{
			strcpy(temp->Type,"Sleeper With out A/C.");
			break;
		}
		else if(ch1=='5')
		{
			strcpy(temp->Type,"Semi Sleeper With out A/C.");
			break;
		}
		else if(ch1=='6')
		{
			strcpy(temp->Type,"Non Sleeper With out A/C.");
			break;
		}
		else
		{
			printf("Invalid Choice.\n");
		}
		}


        //printf("\nDate : ");
		//scanf("%s",temp->Date);
		do{
			printf("\nDate : ");
			fflush(stdin);
            scanf("%s",temp->Date);
            i=ValidateDate(temp->Date,strlen(temp->Date));
	        if(i==0)
	        {
				printf("\nEnter a valid Time.Example 09/06/12.");
		    }
           }while(i==0);

		/*printf("\nTime : ");
		scanf("%s",temp->Time);*/
          do{
			printf("\nTime : ");
			fflush(stdin);
            scanf("%s",temp->Time);
            i=ValidateTime(temp->Time,strlen(temp->Time));
	        if(i==0)
	        {
				printf("\nEnter a valid Time.Example 22:30");
		    }
           }while(i==0);



		//printf("\nCost : ");
		//scanf("%f",&temp->Cost);
		do{
			printf("\nCost:");
			fflush(stdin);
            scanf("%s",str);//Enter the phno. as String.
		    size=strlen(str);
		    i=ValidateCost(str,strlen(str));
	        if(i==0)
	        {
			   printf("\nEnter a valid cost");
		    }
        }while(i==0);
        temp->Cost=atoi(str);//

		fflush(stdin);
		printf("\nDo you want to Save [y/n]: ");
		scanf(" %c",&ch);

        if(ch=='y' || ch=='Y')
		{
		     fp1=fopen("consumer1.dat","a");
            if(fp1==NULL)
            {
                printf("\n\aFile not created..!!!!");
                exit(1);
            }
            else
            {
                fprintf(fp1,"%d , %s , %s , %d , %d , %s , %s , %f , %s\n",temp->Route_ID,temp->Source,temp->Destination,temp->TotalSeats,temp->AvailableSeats,temp->Time,temp->Date,temp->Cost,temp->Type);
            }
            fclose(fp1);
            printf("\nNew Route Successfully saved with ID:%d",temp->Route_ID);
		}
		else
        {
            printf("\nRoute Got Deleted Successfully");

		}

		printf("\n");
	}

}

int creatRoutId()
{
	struct Bus *temp;
	int id2;
	FILE *fp1;
	temp=(struct Bus*)malloc(sizeof(struct Bus));
		fp1=fopen("consumer1.dat","r");
		//printf("\nFile open in read mode\n");
		temp->Route_ID=400000;
		id2=fscanf(fp1,"%d , %s , %s , %d , %d , %s , %s , %f , %[^\n]s\n",&temp->Route_ID,temp->Source,temp->Destination,&temp->TotalSeats,&temp->AvailableSeats,temp->Time,temp->Date,&temp->Cost,temp->Type);
		if(id2==9)
		{
			while(id2==9)
			{
				//printf("%d , %s , %s , %d , %d , %s , %s , %s , %.2f\n",temp->Route_ID,temp->Source,temp->Destination,temp->TotalSeats,temp->AvailableSeats,temp->Type,temp->Time,temp->Date,temp->Cost);
				id2=fscanf(fp1,"%d , %s , %s , %d , %d , %s , %s , %f , %[^\n]s\n",&temp->Route_ID,temp->Source,temp->Destination,&temp->TotalSeats,&temp->AvailableSeats,temp->Time,temp->Date,&temp->Cost,temp->Type);
			}
		}
		fclose(fp1);
		return(temp->Route_ID+1);
}


void displayRoutes()
{
	struct Bus *temp;
	int id2;
	FILE *fp1;
	temp=(struct Bus*)malloc(sizeof(struct Bus));
		fp1=fopen("consumer1.dat","r");
		//printf("\nFile open in read mode\n");
		id2=fscanf(fp1,"%d , %s , %s , %d , %d , %s , %s , %f , %[^\n]s\n",&temp->Route_ID,temp->Source,temp->Destination,&temp->TotalSeats,&temp->AvailableSeats,temp->Time,temp->Date,&temp->Cost,temp->Type);
		if(id2==9)
		{
			while(id2==9)
			{
				printf("%d , %s , %s , %d , %d , %s , %s , %s , %.2f\n",temp->Route_ID,temp->Source,temp->Destination,temp->TotalSeats,temp->AvailableSeats,temp->Type,temp->Time,temp->Date,temp->Cost);
				id2=fscanf(fp1,"%d , %s , %s , %d , %d , %s , %s , %f , %[^\n]s\n",&temp->Route_ID,temp->Source,temp->Destination,&temp->TotalSeats,&temp->AvailableSeats,temp->Time,temp->Date,&temp->Cost,temp->Type);
			}
		}
		else
		{
			printf("\nFile is empty");
		}
		fclose(fp1);
}

int isExistingRoute(int IDno)
{
    int ret=0;
	struct Bus *temp;
	int id2;
	FILE *fp1;

	//temp=ptr->first;

	temp=(struct Bus*)malloc(sizeof(struct Bus));
		fp1=fopen("consumer1.dat","r");

		id2=fscanf(fp1,"%d , %s , %s , %d , %d , %s , %s , %f , %[^\n]s\n",&temp->Route_ID,temp->Source,temp->Destination,&temp->TotalSeats,&temp->AvailableSeats,temp->Time,temp->Date,&temp->Cost,temp->Type);
		while(id2==9)
		{
			if(IDno==temp->Route_ID)
			{
				//printf("%d , %s , %s , %d , %d , %s , %s , %s , %.2f\n",temp->Route_ID,temp->Source,temp->Destination,temp->TotalSeats,temp->AvailableSeats,temp->Type,temp->Time,temp->Date,temp->Cost);
				ret=1;
				break;
            }
				id2=fscanf(fp1,"%d , %s , %s , %d , %d , %s , %s , %f , %[^\n]s\n",&temp->Route_ID,temp->Source,temp->Destination,&temp->TotalSeats,&temp->AvailableSeats,temp->Time,temp->Date,&temp->Cost,temp->Type);
		}

		fclose(fp1);
	return(ret);
}

void searchRouterbyId()
{
	int IDno;
	struct Bus *temp;
	int id2,flag=1;
	FILE *fp1;
	printf("\nEnter the Route ID no: ");
	scanf("%d",&IDno);
	//temp=ptr->first;

	temp=(struct Bus*)malloc(sizeof(struct Bus));
		fp1=fopen("consumer1.dat","r");

		id2=fscanf(fp1,"%d , %s , %s , %d , %d , %s , %s , %f , %[^\n]s\n",&temp->Route_ID,temp->Source,temp->Destination,&temp->TotalSeats,&temp->AvailableSeats,temp->Time,temp->Date,&temp->Cost,temp->Type);
		while(id2==9)
		{
			if(IDno==temp->Route_ID)
			{
				printf("%d , %s , %s , %d , %d , %s , %s , %s , %.2f\n",temp->Route_ID,temp->Source,temp->Destination,temp->TotalSeats,temp->AvailableSeats,temp->Type,temp->Time,temp->Date,temp->Cost);
				flag=0;
				break;
            }
				id2=fscanf(fp1,"%d , %s , %s , %d , %d , %s , %s , %f , %[^\n]s\n",&temp->Route_ID,temp->Source,temp->Destination,&temp->TotalSeats,&temp->AvailableSeats,temp->Time,temp->Date,&temp->Cost,temp->Type);
		}
        if(flag)
        printf("Route dose not exists with ID:%d",IDno);
		fclose(fp1);
		printf("\n");
}

void updateCost(int IDno,float cost)
{
    struct Bus *temp;
	int id2;
	FILE *fp1,*fp2;
	temp=(struct Bus*)malloc(sizeof(struct Bus));
		fp1=fopen("consumer1.dat","r");
		fp2=fopen("newUp.dat","w");
		//printf("\nFile open in read mode\n");
		id2=fscanf(fp1,"%d , %s , %s , %d , %d , %s , %s , %f , %[^\n]s\n",&temp->Route_ID,temp->Source,temp->Destination,&temp->TotalSeats,&temp->AvailableSeats,temp->Time,temp->Date,&temp->Cost,temp->Type);
		if(id2==9)
		{
			while(id2==9)
			{
			    if(temp->Route_ID==IDno)
                {
                   temp->Cost=cost;
                    fprintf(fp2,"%d , %s , %s , %d , %d , %s , %s , %f , %s\n",temp->Route_ID,temp->Source,temp->Destination,temp->TotalSeats,temp->AvailableSeats,temp->Time,temp->Date,temp->Cost,temp->Type);
                }
                else
                {
                    fprintf(fp2,"%d , %s , %s , %d , %d , %s , %s , %f , %s\n",temp->Route_ID,temp->Source,temp->Destination,temp->TotalSeats,temp->AvailableSeats,temp->Time,temp->Date,temp->Cost,temp->Type);
				}
				id2=fscanf(fp1,"%d , %s , %s , %d , %d , %s , %s , %f , %[^\n]s\n",&temp->Route_ID,temp->Source,temp->Destination,&temp->TotalSeats,&temp->AvailableSeats,temp->Time,temp->Date,&temp->Cost,temp->Type);
			}
		}
		else
		{
			printf("\nFile is empty");
		}
		fclose(fp1);
		fclose(fp2);
		remove("consumer1.dat");
		rename("newUp.dat","consumer1.dat");

}

void updateDate(int IDno,char * date)
{
    struct Bus *temp;
	int id2;
	FILE *fp1,*fp2;
	temp=(struct Bus*)malloc(sizeof(struct Bus));
		fp1=fopen("consumer1.dat","r");
		fp2=fopen("newUp.dat","w");
		//printf("\nFile open in read mode\n");
		id2=fscanf(fp1,"%d , %s , %s , %d , %d , %s , %s , %f , %[^\n]s\n",&temp->Route_ID,temp->Source,temp->Destination,&temp->TotalSeats,&temp->AvailableSeats,temp->Time,temp->Date,&temp->Cost,temp->Type);
		if(id2==9)
		{
			while(id2==9)
			{
			    if(temp->Route_ID==IDno)
                {
                    strcpy(temp->Date,date);
                    fprintf(fp2,"%d , %s , %s , %d , %d , %s , %s , %f , %s\n",temp->Route_ID,temp->Source,temp->Destination,temp->TotalSeats,temp->AvailableSeats,temp->Time,temp->Date,temp->Cost,temp->Type);
                }
                else
                {
                    fprintf(fp2,"%d , %s , %s , %d , %d , %s , %s , %f , %s\n",temp->Route_ID,temp->Source,temp->Destination,temp->TotalSeats,temp->AvailableSeats,temp->Time,temp->Date,temp->Cost,temp->Type);
				}
				id2=fscanf(fp1,"%d , %s , %s , %d , %d , %s , %s , %f , %[^\n]s\n",&temp->Route_ID,temp->Source,temp->Destination,&temp->TotalSeats,&temp->AvailableSeats,temp->Time,temp->Date,&temp->Cost,temp->Type);
			}
		}
		else
		{
			printf("\nFile is empty");
		}
		fclose(fp1);
		fclose(fp2);
		remove("consumer1.dat");
		rename("newUp.dat","consumer1.dat");
}

void updateTime(int IDno,char * time)
{
    struct Bus *temp;
	int id2;
	FILE *fp1,*fp2;
	temp=(struct Bus*)malloc(sizeof(struct Bus));
		fp1=fopen("consumer1.dat","r");
		fp2=fopen("newUp.dat","w");
		//printf("\nFile open in read mode\n");
		id2=fscanf(fp1,"%d , %s , %s , %d , %d , %s , %s , %f , %[^\n]s\n",&temp->Route_ID,temp->Source,temp->Destination,&temp->TotalSeats,&temp->AvailableSeats,temp->Time,temp->Date,&temp->Cost,temp->Type);
		if(id2==9)
		{
			while(id2==9)
			{
			    if(temp->Route_ID==IDno)
                {
                    strcpy(temp->Time,time);
                    fprintf(fp2,"%d , %s , %s , %d , %d , %s , %s , %f , %s\n",temp->Route_ID,temp->Source,temp->Destination,temp->TotalSeats,temp->AvailableSeats,temp->Time,temp->Date,temp->Cost,temp->Type);
                }
                else
                {
                    fprintf(fp2,"%d , %s , %s , %d , %d , %s , %s , %f , %s\n",temp->Route_ID,temp->Source,temp->Destination,temp->TotalSeats,temp->AvailableSeats,temp->Time,temp->Date,temp->Cost,temp->Type);
				}
				id2=fscanf(fp1,"%d , %s , %s , %d , %d , %s , %s , %f , %[^\n]s\n",&temp->Route_ID,temp->Source,temp->Destination,&temp->TotalSeats,&temp->AvailableSeats,temp->Time,temp->Date,&temp->Cost,temp->Type);
			}
		}
		else
		{
			printf("\nFile is empty");
		}
		fclose(fp1);
		fclose(fp2);
		remove("consumer1.dat");
		rename("newUp.dat","consumer1.dat");
}

void updateRoute()
{
	struct Bus *temp;
	int i,size;
	char str[20],choice;
	temp=(struct Bus*)malloc(sizeof(struct Bus));


	printf("\n1.Update Cost");
	printf("\n2.Update Time");
	printf("\n2.Update Date");
	printf("\nEnter choice :");
	fflush(stdin);
	scanf("%c",&choice);
	switch(choice)
	{
	case '1':
	    do{
        printf("\nEnter Route ID to be updated:");
        fflush(stdin);
        scanf("%s",str);
        size=strlen(str);
        i=validate_route_Id(str,strlen(str));
        if(i==0)
        {
           printf("\nEnter a valid Route ID");
        }
        }while(i==0);
        temp->Route_ID=atoi(str);
        if(isExistingRoute(temp->Route_ID))
        {
            do{
                printf("\nEnter New Cost:");
                fflush(stdin);
                scanf("%s",str);//Enter the phno. as String.
                size=strlen(str);
                i=ValidateCost(str,strlen(str));
                if(i==0)
                {
                   printf("\nEnter a valid cost");
                }
            }while(i==0);
            temp->Cost=atoi(str);
            updateCost(temp->Route_ID,temp->Cost);
        }
        else
        {
           printf("Route dose not exists with ID:%d",temp->Route_ID);
        }
		break;
	case '2':
	    do{
        printf("\nEnter Route ID to be updated:");
        fflush(stdin);
        scanf("%s",str);
        size=strlen(str);
        i=validate_route_Id(str,strlen(str));
        if(i==0)
        {
           printf("\nEnter a valid Route ID");
        }
        }while(i==0);
        temp->Route_ID=atoi(str);
        if(isExistingRoute(temp->Route_ID))
        {
           do{
			printf("\nNew Time : ");
			fflush(stdin);
            scanf("%s",temp->Time);
            i=ValidateTime(temp->Time,strlen(temp->Time));
	        if(i==0)
	        {
				printf("\nEnter a valid Time.Example 22:30");
		    }
           }while(i==0);
            updateTime(temp->Route_ID,temp->Time);
        }
        else
        {
           printf("Route dose not exists with ID:%d",temp->Route_ID);
        }
		break;
    case '3':
	    do{
        printf("\nEnter Route ID to be updated:");
        fflush(stdin);
        scanf("%s",str);
        size=strlen(str);
        i=validate_route_Id(str,strlen(str));
        if(i==0)
        {
           printf("\nEnter a valid Route ID");
        }
        }while(i==0);
        temp->Route_ID=atoi(str);
        if(isExistingRoute(temp->Route_ID))
        {
           do{
			printf("\nDate : ");
			fflush(stdin);
            scanf("%s",temp->Date);
            i=ValidateDate(temp->Date,strlen(temp->Date));
	        if(i==0)
	        {
				printf("\nEnter a valid Time.Example 09/06/12.");
		    }
           }while(i==0);
            updateTime(temp->Route_ID,temp->Date);
        }
        else
        {
           printf("Route dose not exists with ID:%d",temp->Route_ID);
        }
		break;
	default:
		printf("Wrong choice");
		break;

	}

}

/*
void searchRoutebyDate()
{
	char date1[10];
	struct Bus *temp;
	int id2;
	FILE *fp1;
	printf("\nEnter the Bill Month: ");
	scanf("%s",date1);
//	temp=ptr->first;
	temp=(struct Bus*)malloc(sizeof(struct Bus));
	fp1=fopen("consumer1.dat","r");
	id2=fscanf(fp1,"%d , %s , %s , %d , %s , %s , %f , %[^\n]s\n",&temp->Route_ID,temp->Source,temp->Destination,&temp->TotalSeats,temp->Time,temp->Date,&temp->Cost,temp->Type);
	while(id2==8)
	{
		if(strcmp(date1,temp->Date)==0)
		{
			printf("%d , %s , %s , %d , %s , %s , %s , %f\n",temp->Route_ID,temp->Source,temp->Destination,temp->TotalSeats,temp->Type,temp->Time,temp->Date,temp->Cost);
		}
			id2=fscanf(fp1,"%d , %s , %s , %d , %s , %s , %f , %[^\n]s\n",&temp->Route_ID,temp->Source,temp->Destination,&temp->TotalSeats,temp->Time,temp->Date,&temp->Cost,temp->Type);
	}
	fclose(fp1);
	printf("\n");
}
*/
//validation for route
int validate_route_Id(char *str,int size)
{
 int j,i=0,flag=1;
 char c;
 if(size!=6)
	flag=0;
 else
 while(size!=0)
 {
  j=str[i];
  if(j<48||j>57)
  {
	  flag=0;
      break;
  }else
  {
	  size--;
      i++;
  }
 }
 return flag;
}

//validation for source,Destination
int validateSD(char *cust_name,int size)
{
    int i,flag=1;

    for(i=0;i<size;i++)
	{
        if((cust_name[i]>=65&&cust_name[i]<=90||cust_name[i]>=97&&cust_name[i]<=122) && size>=3 && size<=15)
        {
            flag=1;
        }
        else
        {
            flag=0;
            break;
        }
	}
	return flag;
}

//validation for TotalSeats
int TotalSeats(char *str,int size)
{
 int j,i=0,flag=1;
 char c;
 if(size!=1 && size!=2)
	flag=0;
 else
 while(size!=0)
 {
  j=str[i];
  if(j<48||j>57)
  {
	  flag=0;
      break;
  }else
  {
	  size--;
      i++;
  }
 }
 return flag;
}

//validation for time
int ValidateTime(char *time,int size)
{
	int i,flag=1,flag1=0;
	if(size!=5)
	{
		flag=0;
	}
	else if(time[2]!=58)
	{
		flag=0;
	}
	else if(time[0]<48||time[0]>50)
	{
		flag=0;
	}
	else if(time[1]<48||time[1]>57)
	{
		flag=0;
	}
	else if(time[3]<48||time[3]>53)
	{
		flag=0;
	}
	else if(time[4]<48||time[4]>57)
	{
		flag=0;
	}
	if(time[0]==50)
	{
		if(time[1]<48||time[1]>52)
		flag=0;
	}
	return flag;
}

//validation for Date
int ValidateDate(char *date,int size)
{
	int i,flag=1,flag1=0;
	if(size!=8)
	{
		flag=0;
	}
	else if(date[2]!=47)
	{
		flag=0;
	}
	else if(date[5]!=47)
	{
		flag=0;
	}
	else if(date[0]<48||date[0]>51)
	{
		flag=0;
	}
	else if(date[1]<48||date[1]>57)
	{
		flag=0;
	}
	else if(date[3]<48||date[3]>49)
	{
		flag=0;
	}
	else if(date[4]<49||date[4]>57)
	{
		flag=0;
	}
	else if(date[6]<48||date[6]>57)
	{
		flag=0;
	}
	else if(date[7]<48||date[7]>57)
	{
		flag=0;
	}

	if(date[0]==51)
	{
		if(date[1]<48||date[1]>49)
		flag=0;
	}
	if(date[3]==49)
	{
		if(date[4]<48||date[4]>50)
		flag=0;
	}
	return flag;
}

//validation for cost
int ValidateCost(char *str,int size)
{
 int j,i=0,flag=1;
 char c;
 if(size>=3 && size<=7)
	flag=1;
 else if(size!=0)
	 flag=0;
 else
 {
 while(size!=0)
 {
  j=str[i];
  if(j<48||j>57)
  {
	  flag=0;
      break;
  }
  else if(j==45)
  {
	 flag=0;
  }
  else
  {
	  size--;
      i++;
  }
 }
 }
 return flag;
}


