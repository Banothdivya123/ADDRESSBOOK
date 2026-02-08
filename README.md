Address Book Management System

Project Overview

The Address Book Management System is a command-line application developed in C that helps users store and manage contact information efficiently. It allows users to add, view, search, modify, and delete contacts, with data permanently stored using file handling. The project follows a modular programming approach to ensure readability, maintainability, and scalability.

Features

-> Add new contact details (Name, Phone Number, Email, etc.)

-> Display all saved contacts

-> Search contacts by name or number

-> Edit existing contact information

-> Delete unwanted contacts

-> Store data permanently using files

-> Menu-driven user interface

Technologies Used

-> Programming Language: C

Concepts Used:

-> Structures

-> File Handling

-> Pointers

-> Functions

-> Modular Programming

-> Input Validation

Project Process

1. Program Initialization

-> The program starts by displaying a menu-driven interface.

-> User is prompted to choose an operation such as Add, View, Search, Edit, Delete, or Exit.

-> All contact data is loaded from the file into memory at the start of execution.

2. Data Structure Design

-> A structure is defined to store contact details such as:

:: Name
:: Phone Number
:: Email ID

-> An array or linked list of structures is used to manage multiple contacts efficiently.

3. Adding a New Contact

-> User enters contact details through standard input.

-> Input validation is performed to avoid invalid data.

-> The new contact is added to memory and written to the file.

-> Confirmation message is displayed after successful addition.

5. Displaying All Contacts

-> All stored contacts are read from the file or memory.

-> Contact details are displayed in a well-formatted manner.

-> If no contacts exist, an appropriate message is shown.

6. Searching a Contact

-> User can search for a contact using:

-> Name

-> Phone number

-> Email

-> The program compares user input with stored records.

-> Matching contact details are displayed if found.

7. Editing Contact Details

-> User selects a contact to edit.

-> Existing details are displayed.

-> User can modify required fields.

-> Updated data replaces old data in the file.

8. Deleting a Contact

-> User selects a contact to delete.

-> The contact is removed from memory.

-> File is updated to reflect the deletion.

-> Success message is displayed after deletion.

9. File Handling and Data Persistence

-> Contact details are stored in a file to ensure data persistence.

-> On every modification (add/edit/delete), the file is updated.

-> On program restart, saved data is reloaded automatically.

10. Error Handling and Validation

-> Checks for:

:: Empty address book

:: Invalid menu choices

:: Incorrect input formats

:: Prevents program crashes and ensures smooth execution.

11. Program Termination

-> User selects the Exit option.

-> All data is saved safely.

-> Program terminates gracefully.

How to Run the Project :

gcc *.c -o address_book
./address_book


Learning Outcomes :

-> Strong understanding of C programming fundamentals

-> Hands-on experience with file handling and structures

-> Improved logical thinking and debugging skills

-> Practical exposure to building real-world CLI applications

Future Enhancements :

-> Add sorting functionality

-> Password-protected address book

-> Support for large datasets

-> Convert CLI to GUI-based application
