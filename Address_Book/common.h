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
} addressbook;

int add_contact(contact_info **contacts, int size);
int save_contact(addressbook *);
int list_contact(addressbook *book);

#endif
