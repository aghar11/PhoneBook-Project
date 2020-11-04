#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define fileName "PhoneBook.txt"

// Structure for holding Phonebook contact data
typedef struct contact {
    char *lName, *fName, *phNumber, *address;

    struct contact *prev, *next;

} contact_p;

// Functions
void initialize();
int homePage();
void addContact();
void deleteContact();
void modifyContact();
void exitPhonebook();

// Global Variable
char owner[30];
int numEntries=0;
contact_p *head;

void main() {
    initialize();
    
    int menuChoice = homePage();

    switch (menuChoice)
    {
        case 1:
            addContact();
            break;
        
        case 2:
            deleteContact();
            break;

        case 3:
            modifyContact();
            break;

        case 4:
            printf("\n Exiting Phonebook...");
            exitPhonebook();
        default:
            break;
    }
    
}

void initialize() {
    FILE *fp = fopen(fileName, "r");
    
    contact_p *current = head;
    current = (contact_p *) malloc(sizeof(contact_p));
    current->prev=NULL;
    current->next=NULL;

    fgets(owner, 30, fp);
    strtok(owner, "\n");
    fscanf(fp, "%d", &numEntries);
    fgetc(fp);

    while(!feof(fp)) {
        char string[120];
                
        fgets(string, 120, fp);
        char *token = strtok(string, "\n");

        token = strtok(string, ",");
        current->fName = token;
        token = strtok(NULL, ",");
        current->lName = token;
        token = strtok(NULL, ",");
        current->phNumber = token;
        token = strtok(NULL, ",");
        current->address = token;

        printf("\n %s\n %s\n %s\n %s\n", current->fName, current->lName, current->phNumber, current->address);


        current->next = (contact_p *) malloc(sizeof(contact_p));
        current->next->prev = current;
        current->next->next = NULL;
        current = current->next;


    }

    fclose(fp);

}

void exitPhonebook() {

}

int homePage() {    
    contact_p *current = head;
    
    system("cls");

    printf(" %s's Phonebook Homepage\n\nEntries", owner);
    printf("\n--------------------------------------------------------------------------------------");
    printf("\n First Name\t| Last Name\t| Phone Number\t| Address");
    printf("\n--------------------------------------------------------------------------------------");

    for (int i=0; i<numEntries; i++) {
        printf("check");
        printf("\n %s\t| %s\t| %s\t| %s", current->fName, current->lName, current->phNumber, current->address);
        current = current->next;
    }

    printf("\n Menu Options:\n 1. Add Contact\t\t 2. Delete Contact\n 3. Modify Contact\t 4. Exit Phonebook");

    int choice;

    do {
        printf("\n\n Please enter a number between 1 and 4 indicating your selection...\n");
        scanf("%d", &choice);
    } while (choice<1 || choice>4);

    return choice;
}

void addContact() {
    contact_p *newEntry = (contact_p *) malloc(sizeof(contact_p));

    system("cls");
       
    printf("\n\nAdding Contact\n");
    printf("\n First Name: ");
    scanf("%s", newEntry->fName);
    printf("\n Last Name: ");
    scanf("%s", newEntry->lName);
    printf("\n Phone Number: ");
    scanf("%s", newEntry->phNumber);
    printf("\n Street Address: ");
    scanf("%s", newEntry->address);
    
    
    newEntry->next = head;
    newEntry->prev = NULL;
    head->prev = newEntry;
    head = newEntry;
    numEntries++;

    printf("\n\n Contact Added\n Returning to homepage...");

    homePage();

}

void deleteContact() {
    printf("\n\nDeleting Contact\n\n");
}

void modifyContact() {
    printf("\n\nModifying Contact\n\n");
}
