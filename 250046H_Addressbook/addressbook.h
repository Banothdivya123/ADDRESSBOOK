#ifndef CONTACT_H
#define CONTACT_H
#include <stdio.h>


struct Contact{
    char name[50];              //contact name
    char phone[15];                //contact mobile number
    char email[50];                 //contact email
};

struct AddressBook {
    struct Contact contacts[100];       // Array of contacts
    int contactCount;                // Total number of contacts
    int index_record[100];          // Size of index_record array
    int ir_size;                // Size of index_record array
};
void pull_file_data(struct AddressBook *, char *);              //Load contact data from file into address book 
void push_data_to_file(struct AddressBook *, char *);              //Save address book data into file 
void add_contact(struct AddressBook *addressBook);                  //add new contact
void search_contact(struct AddressBook *addressBook);               //Search contact by name / phone / email 
void edit_contact(struct AddressBook *addressBook);                    //Edit an existing contact
void delete_contact(struct AddressBook *addressBook);                  //delete a contact
void list_contacts(struct AddressBook *addressBook);                    //display all contacts
int validate_mob(char *mob);                                        //validate mobile number
int validate_email(char *email);                            //validate email id
#endif
