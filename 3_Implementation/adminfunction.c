#include "inc.h"

void showMenu()
{
	system("cls");

	printf("Bookstore System\n\n");
	printf("1 - Add Book\n");
	printf("2 - check book\n");
	printf("3 - erase data\n");
	printf("4 - Requested Books\n");
	printf("5 - Exit\n\n");
	printf("What do you want? ");

	int command = getCommand(1);
	switch(command)
	{
		case 1:
		addBook();
		break;

		case 2:
		showCheckMenu();
		break;

		case 3:
		eraseBooks();
		break;

		case 4:
        seeRequest();
        break;

		case 5:
		system("cls");
		return;
	}
}




void addBook()
{
	system("cls");

	int price,isbn;
	char author_name[50];
	char book_title[50];
	char publisher[25];
	char category[20];

	printf("Enter the book name: ");
	gets(book_title);
	//scanf("%s",book_title);
	printf("Enter the author's name: ");
	gets(author_name);
	//scanf("%s",author_name);
	printf("Enter the name of the publisher: ");
	gets(publisher);
	//scanf("%s",publisher);
	printf("Enter the Book Price: ");
	scanf("%d", &price);
	printf("Enter the ISBN: ");
    scanf("%d", &isbn);

	getchar();

	printf("choose category\n");
	setCategory(category);


	FILE *f = fopen("data.txt","a+");
	fprintf(f,"\n%s\n",book_title);
	fprintf(f,"%s\n",author_name);
	fprintf(f,"%s\n",publisher);
	fprintf(f,"%d\n",price);
	fprintf(f,"%d\n",isbn);
	fprintf(f,"%s\n",category);

	fclose(f);

	(getAnswer(0)) ? addBook() : showMenu();

	return PASS;
}



void setCategory(char *new_book_category)
{

	printf("1 - Non-Fiction\n");
	printf("2 - Fiction\n");
	printf("3 - Educational\n");


	printf("Enter the number -> ");

	int category;
	scanf("%d", &category);
	getchar();

	while (category != 0 && category != 1 && category != 2 && category != 3 )
	{
		printf("Invalid number, please enter again-> ");
		scanf("%d", &category);
		getchar();
	}

	switch(category)
	{

		case 1:
		strcpy(new_book_category,"non-fiction");
		break;

		case 2:
		strcpy(new_book_category,"fiction");
		break;

		case 3:
		strcpy(new_book_category,"educational");
		break;

	}
	return new_book_category;
}


void eraseBooks()
{
	system("cls");
	fclose(fopen("data.txt", "w"));
	//return PASS;
}

int getAnswer(int token)
{
	if (token == 0)
	{
		printf("Book successfully added! Do you want to add another one?");
	}
	else if (token == 1)
	{
		printf("Do you want to consult again?");
	}
	else if (token == 2)
    {
        printf("Book Available ??");
    }
    else if(token == 3)
    {
        printf("Buy Book ??");
    }
    else if(token == 4)
    {
        printf("Request Book ??");
    }

	printf(" (s/n) -> ");

	char answer;
	scanf("%c", &answer);
	getchar();
	answer = tolower(answer);

	while(answer != 's' && answer != 'n')
	{
		printf("\nInvalid command! Enter again ->  ");
		scanf("%c", &answer);
		getchar();
		answer = tolower(answer);
	}

	if (answer == 's')
	{
		return 1;
	}
	else if(answer == 'n')
	{
		return 0;
	}
}



void seeRequest()
{
    printf("\nRequested Books\n");

    char book_title[50];
	char author_name[50];
	char publisher[50];

	char line[50];
	FILE *f = fopen("request.txt","r");

	printf("\n");

	while(fgets(line,50,f) != NULL)
	{
		fgets(book_title,50,f);
		fgets(author_name,50,f);
		fgets(publisher,50,f);

		printf("Title: %s", book_title);
		printf("Author: %s", author_name);
		printf("Publisher: %s",publisher);
		printf("\n");

	}
	fclose(f);
   // return PASS;
}
