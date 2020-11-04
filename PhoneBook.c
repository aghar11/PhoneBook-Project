#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define fileName "PhoneBook.txt"

// Structure for holding Phonebook contact data
typedef struct contact {
    char lName[20], fName[20], phNumber[15], address[50];

    struct contact *prev, *next;

} contact_p;

// Functions
void initialize(char *, int *, contact_p *);
int homePage(char *, int ,contact_p *);
void addContact(int *, contact_p *);
void deleteContact(int *, contact_p *);
void modifyContact(contact_p *);

void main() {
    char owner[30];
    int numEntries=0;
    contact_p *head = (contact_p *) malloc(sizeof(contact_p));
    head->prev = NULL;
    head->next = NULL;

    initialize(owner, &numEntries, head);
    
    int menuChoice = homePage(owner, numEntries, head);

    switch (menuChoice)
    {
        case 1:
            addContact(&numEntries, head);
            break;
        
        case 2:
            deleteContact(&numEntries, head);
            break;

        case 3:
            modifyContact(head);
            break;

        default:
            break;
    }
    
}

void initialize(char *Owner, int *NumEntries, contact_p *Head) {
    FILE *fp = fopen(fileName, "r");
    char last[20], first[20], phone[15], homeAddress[50];

    contact_p *current = Head;

    fgets(Owner, 30, fp);
    strtok(Owner, "\n");
    fscanf(fp, "%d", NumEntries);

    while(!feof(fp)) {
        fscanf(fp, "%s%*c %s%*c %s%*c %s", first, last, phone, homeAddress);

        strcpy(current->lName, last);
        strcpy(current->fName, first);
        strcpy(current->phNumber, phone);
        strcpy(current->address, homeAddress);

        current->next = (contact_p*) malloc(sizeof(contact_p));
        current = current->next;
        current->next = NULL;

    }

    fclose(fp);

}

int homePage(char *Owner, int numEntries, contact_p *Head) {    
    contact_p *current = Head;
    
    printf(" %s's Phonebook Homepage\n\nEntries", Owner);
    printf("\n--------------------------------------------------------------------------------------");
    printf("\n First Name\t| Last Name\t| Phone Number\t| Address");
    printf("\n--------------------------------------------------------------------------------------");

    for (contact_p *current = Head; current!=NULL; current=current->next) {
        printf("\n %s\t| %s\t| %s\t| %s", current->fName, current->lName, current->phNumber, current->address);

    }

    printf("\n Menu Options:\n 1. Add Contact\t 2. Delete Contact\n 3. Modify Contact");

    int choice;

    do {
        printf("\n\n Please enter a number between 1 and 3 indicating your selection...\n");
        scanf("%d", &choice);
    } while (choice<1 || choice>3);

    return choice;
}

void addContact(int *NumEntries, contact_p *Head) {
    printf("\n\nAdding Contact\n\n");
}

void deleteContact(int *NumEntries, contact_p *Head) {
    printf("\n\nDeleting Contact\n\n");
}

void modifyContact(contact_p *Head) {
    printf("\n\nModifying Contact\n\n");
}
