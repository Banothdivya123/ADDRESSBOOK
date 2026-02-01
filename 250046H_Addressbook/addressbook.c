/*DOCUMENTATION
DESCRIPTION : ADDRESSBOOK
NAME : B.DIVYA
DATE : 05/01/2025

 */
#include "addressbook.h"
#include<string.h>
// Reads contact details from CSV file and stores them in structure
void pull_file_data(struct AddressBook * addressBook, char * file_name)
{
    FILE *fp = fopen(file_name,"r");            // Open file in read mode
    int i=0;
    addressBook->contactCount = 0;
    fseek(fp,0,SEEK_END);                   // Move file pointer to end
    if(ftell(fp) !=0)                       // Check if file is not empty
    {
        rewind(fp);                               // Move pointer back to start
        while(!feof(fp))                          // Read until end of file
        {
            fscanf(fp,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            i++;                                       // Read name, phone and email
        }
    }
    addressBook->contactCount = i;          // Update total contact count

    fclose(fp);                     //close the file
}
// Writes all contacts from structure into CSV file
void push_data_to_file(struct AddressBook * addressBook, char * file_name)
{
    FILE *fp = fopen(file_name,"w"); //open file in write mode
    for(int i=0;i<addressBook->contactCount;i++)
    {
        fprintf(fp,"%s,",addressBook->contacts[i].name);            // Write each contact in CSV format
        fprintf(fp,"%s,",addressBook->contacts[i].phone);
        fprintf(fp,"%s\n",addressBook->contacts[i].email);
        
    }
    fclose(fp);         //close the file
}
// Validates mobile number
int validate_mob(char *mob)
{
    for(int i=0;i<strlen(mob);i++)
    {
        if(strlen(mob) == 10 && mob[0]> '5' && (mob[i]>= '0' && mob[i]<='9'))
        {
            return 1;     //valid mob number
        }
        else
        {
            return 0;       //invalid mob number
        }
    }
}
//validate email
int validate_email(char *email)
{
    if((email[0] != ' ') && (email[0] != '@') && (email[0] != '\t'))        // First character should not be space or '@'
    {
        char *ptr=strstr(email,"@gmail.com");       // Check domain
        if(strcmp(ptr,"@gmail.com")==0)
        {
            return 1;        //valid email
        }
        
    }
    return 0;       //inavlid email

}
// Add a new contact to address book
void add_contact(struct AddressBook *addressBook)
{
    char name[30];
    char mob[15];
    char email[20];
    printf("Enter name: ");
    scanf("%s",name);
    printf("Enter mobile number: ");
    int flag=1;
    while(flag)
    {
        scanf(" %s",mob);
        if(validate_mob(mob))
        {
            flag=0;             // Exit loop if valid

        }
        else{
            printf("Enter valid mobile number!\n");
        }
    }
    printf("Enter email: ");
    flag=1;
    while(flag)
    {
        scanf("%s",email);
        if(validate_email(email))
        {
            flag=0;
        } 
        else{
            printf("Enter valid email id!\n");
        }
    }
    // Store details in structure
    int i=addressBook->contactCount;
    strcpy(addressBook->contacts[i].name,name);
    strcpy(addressBook->contacts[i].phone,mob);
    strcpy(addressBook->contacts[i].email,email);
    i++;
    addressBook->contactCount++;        // Increment contact count

}
// Searches contact by name / mobile / email
void search_contact(struct AddressBook *addressBook)
{
   int option; 
   addressBook->ir_size=0;          //reset index record size
   printf("1. Search by name\n");     // Search by name and store all matching indexes
   printf("2. Search by mobile\n");
   printf("3. Search by email\n");
   scanf("%d",&option);
   switch(option)
    {
        case 1:
            char name[50];
            printf("Enter name: ");
            scanf(" %[^\n]",name);
            int flag=0;
            for(int i=0;i<addressBook->contactCount;i++)
            {
                if(strcmp(name,addressBook->contacts[i].name) == 0)
                {
                    addressBook->index_record[addressBook->ir_size]=i;
                    addressBook->ir_size++;
                    flag=1;
                }
            }
            if(flag==0)
            {
                printf("Contact not found\n");
                
            }
            else
            {
                for(int i=0;i<addressBook->ir_size;i++)
                {
                    int j=addressBook->index_record[i];
                    printf("%d %s, %s, %s\n",i+1,addressBook->contacts[j].name,addressBook->contacts[j].phone,addressBook->contacts[j].email);
                }
            }
            break;
        case 2:
            char mob[50];
            printf("Enter mobile: ");
            scanf(" %[^\n]",mob);
            int k=0;
            if(validate_mob(mob))
            {
                for(k=0;k<addressBook->contactCount;k++)
                {
                    if(strcmp(mob,addressBook->contacts[k].phone) == 0)
                    {
                        break;
                    }
                }
                printf("%d %s, %s, %s\n",1,addressBook->contacts[k].name,addressBook->contacts[k].phone,addressBook->contacts[k].email);
            }
            else
            {
                printf("Enter valid mobile number\n");
                scanf(" %s",mob);
            }
            break;
        case 3:
            char email[50];
            printf("Enter the email: ");
            scanf(" %[^\n]",email);
            int i=0;
            if(validate_email(email))
            {
                for(i=0;i<addressBook->contactCount;i++)
                {
                    if(strcmp(email,addressBook->contacts[i].email) == 0)
                    {
                        break;
                    }
                }
                printf("%d %s, %s, %s\n",1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            }
            else
            {
                printf("Enter valid email\n");
                scanf(" %s",email);
            }
            break;
        default:
            printf("Invalid option. Please try again.\n");        
    }
}
// Edits selected contact details
void edit_contact(struct AddressBook *addressBook)
{
    if(addressBook->contactCount == 0)
    {
        printf("No data available to edit\n");
        return;
    }
    int option;
    search_contact(addressBook);            // First search contact
    int sno;
    printf("Enter one s.no contact: ");
    scanf("%d",&sno);
    printf("Selected contact : \n");
    printf("%d. %s,%s,%s\n",sno,addressBook->contacts[addressBook->index_record[sno-1]].name, addressBook->contacts[addressBook->index_record[sno-1]].phone, addressBook->contacts[addressBook->index_record[sno-1]].email);

    do                                                      // Provides menu to edit name / mobile / email
    {
        printf("\nEditing Menu:\n");
        printf("1. Edit name\n");
        printf("2. Edit mobile.no\n");
        printf("3. Edit email\n");
        printf("4. Exit\n");
        printf("Enter your option: ");    
        scanf("%d", &option);
        int res;
        switch(option)
        {
            case 1:
            char new_name[50];
            printf("Enter the new name: ");
            scanf("%s",new_name);
            strcpy(addressBook->contacts[addressBook->index_record[sno-1]].name, new_name);
            break;

            case 2:
            char new_mob[15];
            do
            {
                printf("Enter the new mobile number: ");
                scanf("%s",new_mob);

                res = (validate_mob(new_mob));
                if(res)
                {
                    strcpy(addressBook->contacts[addressBook->index_record[sno-1]].phone, new_mob);
                }
                else
                {
                    printf("Invalid number\n");
                }
                
            }while(!res);
            break;

            case 3:
            char new_gmail[15];
            do
            {
            printf("Enter the new gmail: ");
            scanf("%s",new_gmail);
            res= validate_email(new_gmail);
            if(res)
            {
                strcpy(addressBook->contacts[addressBook->index_record[sno-1]].email, new_gmail);
            }
            else
            {
                printf("Invalid email\n");
            }
            }while(!res);
            break;

            case 4:
            printf("Exiting...");
            break;

            default :
            printf("Invalid Choice\n");
        }

    }while(option!=4);

}
//delete a selected contacts
void delete_contact(struct AddressBook *addressBook)
{
    if(addressBook->contactCount == 0)
    {
        printf("No data available to delete\n");
        return;
    }
    int opt;
    search_contact(addressBook);            // Search contact before deletion
    int sno;
    char ch;
    printf("Enter one s.no contact: ");
    scanf("%d",&sno);
    printf("Selected contact : \n");
    printf("%d. %s,%s,%s\n",sno,addressBook->contacts[addressBook->index_record[sno-1]].name, addressBook->contacts[addressBook->index_record[sno-1]].phone, addressBook->contacts[addressBook->index_record[sno-1]].email);
    printf("Are you sure?\n y / n ? ");
    scanf(" %c",&ch);
    if(ch=='n' || ch=='N')
        return;
    else if(ch == 'y' || ch =='Y')
    {
        for(int i= addressBook->index_record[sno-1];i<(addressBook->contactCount)-1;i++)
        {
            addressBook->contacts[i]=addressBook->contacts[i+1];
        }
        addressBook->contactCount--;
    }
    else
    {
        printf("Invalid Option\n");
        return;
    }


}
//display all contacts
void list_contacts(struct AddressBook *addressBook)
{
    if(addressBook->contactCount==0)
    {
        printf("Contacts are not available\n");
    }
    else{
        for(int i=0;i<addressBook->contactCount;i++)
        {
            printf("%s, %s, %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
    }
    
}

