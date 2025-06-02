#include<stdio.h>
#include<string.h>

char cityDestination[50], passengerName[100], cityDestination2[50], passport[10] ;
int newDomestic = 0, newInternational = 0, newDomestic2 = 0, newInternational2 = 0;
int same_city_domestic = 0, same_city_international = 0;
int i;

struct domestic{
	char cityDestination[50];
	char passengerName[100];
	char cityDestination2[50];
};

struct international{
	char cityDestination[50];
	char passengerName[100];
	char cityDestination2[50];
	char passport[10];
};

struct domestic dom[100];
struct international inter[100];

void domesticFlight(){
	printf("Domestic Flight\n");
	printf("=========================\n");
	printf("1. From: Jakarta\tTo: Bandung\n");
	
	for(i = 0; i < newDomestic; i++){
		printf("%d.", i+2);
		printf(" From :Jakarta\tTo :%s\n", dom[i+1].cityDestination);
	}
	printf("\n");
}

void internationalFlight(){
	printf("International Flight\n");
	printf("=========================\n");
	printf("1. From: Jakarta\tTo: Kuala Lumpur\n");
	
	for(i = 0; i < newInternational; i++){
		printf("%d.", i+2);
		printf(" From :Jakarta\tTo :%s\n", inter[i+1].cityDestination);
	}
	printf("\n");
}

void option(){
	printf("\n\nMenu :\n");
	printf("=========================\n");
	printf("1. Create New Flight\n2. Manage Booking\n3. See Passenger\n4. Exit\n");
	printf("Choice : ");
}

void menu1(){
	printf("Create New Flight\n");
	printf("=========================\n");
	
	do{
		printf("City Destination [Bandung / Bali / Medan / Kuala Lumpur / Singapore / Bangkok] :");
		scanf("%[^\n]", &cityDestination); getchar();
	}while(strcmp(cityDestination, "Bandung") != 0 && strcmp(cityDestination, "Bali") != 0 && strcmp(cityDestination, "Medan") != 0 && strcmp(cityDestination, "Kuala Lumpur") != 0 && strcmp(cityDestination, "Singapore") != 0 && strcmp(cityDestination, "Bangkok") != 0);
	
	same_city_domestic = 0;
	same_city_international = 0;
	if(strcmp(cityDestination, "Bandung") == 0 || strcmp(cityDestination, "Kuala Lumpur") == 0){
		printf("There are already flight from Jakarta to %s\n", cityDestination);
	}else if(strcmp(cityDestination, "Medan") == 0 || strcmp(cityDestination, "Bali") == 0){
		newDomestic++;

		for(i = newDomestic; i >= 0; i--){
			if(strcmp(dom[i].cityDestination, cityDestination) == 0){
				same_city_domestic = 1;
				newDomestic-=1;
			}
		}

		for(i = newDomestic; i <= newDomestic; i++){
			if(same_city_domestic != 0){
				printf("There are already Flight from Jakarta to %s\n", cityDestination);
			}else{
				printf("Success Add Flight from Jakarta to %s\n", cityDestination);
			}
		}

		if(same_city_domestic == 0){
			for(i = newDomestic; i <= newDomestic; i++){
				strcpy(dom[i].cityDestination, cityDestination);
			}
		}
	}
		
	else if(strcmp(cityDestination, "Kuala Lumpur") == 0 || strcmp(cityDestination, "Singapore") == 0 || strcmp(cityDestination, "Bangkok") == 0){
			newInternational++;
			for(i = newInternational; i >= 0; i--){
				if(strcmp(inter[i].cityDestination, cityDestination) == 0){
					same_city_international = 1;
					newInternational--;
				}
			}

			for(i = newInternational; i <= newInternational; i++){
				if(same_city_international != 0){
					printf("There are already Flight from Jakarta to %s\n", cityDestination);
				}else{
					printf("Success Add Flight from Jakarta to %s\n", cityDestination);
				}
			}

			if(same_city_international == 0){
				for(i = newInternational; i <= newInternational; i++){
					strcpy(inter[i].cityDestination, cityDestination);
				}
			}
	}
}

void menu2(){
	do{
		printf("Passenger name [3..20]: ");
		scanf("%[^\n]", &passengerName); getchar();
	}while(strlen(passengerName) < 3 || strlen(passengerName) > 20);
	do{
		printf("City Destination [Bandung / Bali / Medan / Kuala Lumpur / Singapore / Bangkok] : ");
		scanf("%[^\n]", &cityDestination2); getchar();
	}while(strcmp(cityDestination2, "Bandung") != 0 && strcmp(cityDestination2, "Bali") != 0 && strcmp(cityDestination2, "Medan") != 0 && strcmp(cityDestination2, "Kuala Lumpur") != 0 && strcmp(cityDestination2, "Singapore") != 0 && strcmp(cityDestination2, "Bangkok") != 0);	
	
	if(strcmp(cityDestination2, "Bali") == 0 || strcmp(cityDestination2, "Bandung") == 0 || strcmp(cityDestination2, "Medan") == 0){
			newDomestic2++;
			for(i = newDomestic2; i <= newDomestic2; i++){
				strcpy(dom[i].cityDestination2, cityDestination2);
				strcpy(dom[i].passengerName, passengerName);
			}
	}else if(strcmp(cityDestination2, "Kuala Lumpur") == 0 || strcmp(cityDestination2, "Singapore") == 0 || strcmp(cityDestination2, "Bangkok") == 0){
			newInternational2++;
			for(i = newInternational2; i <= newInternational2; i++){
				strcpy(inter[i].cityDestination2, cityDestination2);
				strcpy(inter[i].passengerName, passengerName);
			}
		}
	if(strcmp(cityDestination2, "Kuala Lumpur") == 0 || strcmp(cityDestination2, "Singapore") == 0 || strcmp(cityDestination2, "Bangkok") == 0){
		do{
			printf("Passport Number [6]: ");
			scanf("%[^\n]", &passport);
		}while(strlen(passport) != 6);
	}
	
	printf("Success Add Passenger\n");
}

void menu3(){
	printf("Our Passenger\n");
	printf("Domestic Flight\n");
	printf("=========================\n");
	if(newDomestic2 == 0){
		printf("No Data\n");
	}else{
		for(i = 1; i <= newDomestic2; i++){
			printf("%d.\tName\t\t: %s\n", i, dom[i].passengerName);
			printf("\tFrom\t\t: Jakarta\n");
			printf("\tTo\t\t: %s\n", dom[i].cityDestination2);
		}
	}
	
	printf("\nInternational Flight\n");
	printf("=========================\n");
	if(newInternational2 == 0){
		printf("No Data\n\n");
	}else{
		for(i = 1; i <= newInternational2; i++){
			printf("%d.\tName\t\t: %s\n", i, inter[i].passengerName);
			printf("\tFrom\t\t: Jakarta\n");
			printf("\tTo\t\t: %s\n", inter[i].cityDestination2);
			printf("\tPaspor\t\t: %s\n", passport);
		}
	}
}


int main(){
	int choice;
	
	do{
		do{
			domesticFlight();
			internationalFlight();
			option();
			scanf("%d", &choice); getchar();
		
			switch(choice){
				case 1:
					menu1();
					break;
				case 2:
					menu2();
					break;
				case 3:
					menu3();
					break;
				case 4:
					return 0;
					break;
			}
		}while(choice < 1 && choice > 4);
	}while(choice!=4);
	
	return 0;
}
