#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEFAULT_FILE				"address_book.csv"

/* Length of a contact name  */
#define NAME_LEN					32
/* Length of a phone number */
#define NUMBER_LEN					32
/* Length of an email address */
#define EMAIL_ID_LEN				32

/* Maximum number of Names per contact, Just for easy design */
#define NAME_COUNT					1
/* Maximum number of phones per contact */
#define PHONE_NUMBER_COUNT			5
/* Maximum number of email addresses per contact */
#define EMAIL_ID_COUNT				5

#define FIELD_DELIMITER				','
#define NEXT_ENTRY					'\n'


typedef enum
{
	SUCCESS,
	FAILURE,
}status;

typedef struct
{
	char name[NAME_LEN];
	char phone_numbers[NUMBER_LEN];
	char email_addresses[EMAIL_ID_LEN];
	int sl_no;
}contact_info;

typedef struct
{
	FILE *fp;
	contact_info *list;

	int count;	
}addressbook;

typedef struct node
{
	int address;
	struct node *prev;
	struct node *next;
}Cursor;

int add_contact(contact_info **contacts, int size, addressbook *);
int save_contact(addressbook *, int);
void list_contact(void);
int insert_last(Cursor **head, Cursor **tail, int data);
int traversing_function();
int editt();
int searchh(int callcount);
int edit_contact(char *changes, int location, int flag);
int search_contact(FILE * f1, char *serch_name);
int display_m_names(Cursor *head);
#endif
