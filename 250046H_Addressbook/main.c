/*DOCUMENTATION
DESCRIPTION : ADDRESSBOOK
NAME : B.DIVYA
DATE : 05/01/2025

*/
#include "addressbook.h"

int main() 
{
    int choice;				///Variable to store user menu choice

    struct AddressBook addressBook;			//Declare AddressBook structure 
	pull_file_data(&addressBook,"database.csv");			//Load existing contact data from file 
    addressBook.ir_size = 0;			//index record size

    do 					//menu
    {
	printf("\nAddress Book Menu:\n");
	printf("1. Add/Create contact\n");
	printf("2. Search contact\n");
	printf("3. Edit contact\n");
	printf("4. Delete contact\n");
	printf("5. List all contacts\n");
	printf("6. Exit\n");
	printf("Enter your choice: ");

	scanf("%d", &choice);

	switch (choice) 
	{
	    case 1:
		add_contact(&addressBook); //add contact
		break;
	    case 2:
		search_contact(&addressBook); //search contact details
		break;
	    case 3:
		edit_contact(&addressBook);  //edit contact details
		break;
	    case 4:
		delete_contact(&addressBook); 	//delete contact details 
		break;
	    case 5:
		list_contacts(&addressBook);  //display all contact details
		break;
	    case 6:
		printf("Saving and Exiting...\n"); //save and exit
		push_data_to_file(&addressBook, "database.csv");
		break;
	    default:   //if choose invalid choice
		printf("Invalid choice. Please try again.\n");
	}
} while (choice != 6);  //Loop until exit option is chosen



    return 0;
}
