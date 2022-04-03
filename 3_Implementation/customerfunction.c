#include "inc.h"

void showCheckMenu(){

    system("cls");
	printf("Want to inquire by...\n");
	printf("1 - Book Name\n");
	printf("2 - Author\n");
	printf("3 - publisher\n");
	printf("4 - Categories\n");
	printf("5 - All the books\n");
	printf("6 - Exit\n");
	int command = getCommand(2);
	if(command == 6){
        system("cls");
        exit(0);
	}
	checkContent(command);
}


int getCommand(int token)
{

	int command;

	if (token == 1)
	{
		printf(" -> ");
		scanf("%d", &command);
		getchar();

		while(command != 1 && command != 2 && command != 3 && command != 4 && command !=5)
		{
			printf("Invalid command! Enter again -> ");
			scanf("%d", &command);
			getchar();
		}
	}
	else if (token == 2)
	{
		printf("Enter the desired command -> ");
		scanf("%d", &command);
		getchar();

		while(command != 1 && command != 2 && command != 3 && command !=  4 && command != 5 && command != 6)
		{
			printf("Invalid command! Enter again -> ");
			scanf("%d", &command);
			getchar();
		}
	}

	return command;
}

void checkContent(int command)
{
	system("cls");

	int hasFound = 0;

	char book_title[50];
	char author_name[50];
	char publisher[50];
	char price[50];
	char isbn[15];
	char category[20];


	char *picked_content;
	switch(command)
	{
		case 1:
		printf("Enter the title you want to search for: ");
		picked_content = book_title;
		break;

		case 2:
		printf("Enter the author you want to search for: ");
		picked_content = author_name;
		break;

		case 3:
		printf("Enter the publisher you want to search for: ");
		picked_content = publisher;
		break;

		case 4:
		printf("Enter the category you want to search for: ");
		picked_content = category;
		break;

		case 5:
		showAllBooks();
		break;

	}

	char searched_content[50];
	fgets(searched_content,50,stdin);
	printf("\n");

	FILE *f = fopen("data.txt","r");

	char line_break[50];
	while(fgets(line_break,50,f) != NULL)
	{
		fgets(book_title,50,f);
		fgets(author_name,50,f);
		fgets(publisher,50,f);
		fgets(price,15,f);
		fgets(isbn,15,f);
		fgets(category,50,f);

		if (compareString(searched_content,picked_content))
		{
			hasFound = 1;
			printf("Title: %s", book_title);
			printf("Author: %s", author_name);
			printf("publisher: %s",publisher);
			printf("price: %s", price);
			printf("ISBN: %s", isbn);
			printf("Category: %s", category);
			printf("\n");

		}
	}

	fclose(f);

	if (!hasFound)
	{
		printf("No results were found for this search.\n");
	}

	(getAnswer(1)) ? checkContent(command) : (user == 1 ? showMenu() : showCheckMenu()) ;
}


int compareString(char *string_1, char *string_2)
{
	char compare_1[50];
	strcpy(compare_1,string_1);
	char compare_2[50];
	strcpy(compare_2,string_2);

	int i;
	for (i = 0; i < 50; ++i)
	{
		compare_1[i] = tolower(compare_1[i]);
		compare_2[i] = tolower(compare_2[i]);
	}

	compare_1[strlen(compare_1)-1] = '\0';

	if (strstr(compare_2,compare_1) == NULL)
	{
		return 0;
	}

	return 1;
}



void showAllBooks()
{
	system("cls");

	char book_title[50];
	char author_name[50];
	char publisher[50];
	char price[50];
	char isbn[50];
	char category[20];


	char line[50];
	FILE *f = fopen("data.txt","r");

	printf("\n");

	while(fgets(line,50,f) != NULL)
	{
		fgets(book_title,50,f);
		fgets(author_name,50,f);
		fgets(publisher,50,f);
		fgets(price,50,f);
		fgets(isbn,50,f);
		fgets(category,20,f);


		printf("Title: %s", book_title);
		printf("Author: %s", author_name);
		printf("Publisher: %s",publisher);
		printf("Price: %s", price);
		printf("ISBN: %s", isbn);
		printf("Category: %s", category);
		printf("\n");
	}
	fclose(f);

    (getAnswer(2)) ? (getAnswer(3) ? buyBook() : (user == 1 ? showMenu() : showCheckMenu())) : (user == 2 ? (getAnswer(4) ? requestBook() : showCheckMenu()) : showMenu());

}

void buyBook()
{
    int no_of_books;

	char book_title[50];
	char author_name[50];
	char publisher[50];
	int price;
	char isbn[15];
	char category[20];

    printf("\nCopy the ISBN of that Book: ");

	char searched_content[50];

	scanf("%s",searched_content);
	printf("\n");

	FILE *f = fopen("data.txt","r");

	char line_break[50];

		while (fscanf(f, " %[^\n] %[^\n] %[^\n] %d %s %s ", book_title,author_name,publisher,&price,isbn,category) == 6)
        {

		if (strcmp(searched_content,isbn) == 0)
		{
			printf("Title: %s", book_title);
			printf("\nAuthor: %s", author_name);
			printf("\npublisher: %s",publisher);
			printf("\nprice: %d", price);
			printf("\nISBN: %s", isbn);
			printf("\nCategory: %s", category);
			printf("\n");

            printf("How many books : ");
            scanf("%d",&no_of_books);
            printf("\nTotal Cost : %d Rs",price * no_of_books);
            break;
		}


	}

	fclose(f);

	//(getAnswer(1)) ? checkContent(command) : showMenu();

}

void requestBook()
{
    system("cls");

    printf("\nRequesting Book To Admin\n");
	char author_name[50];
	char book_title[50];
	char publisher[25];

	printf("Enter the book name: ");
	gets(book_title);
	//scanf("%s",book_title);
	printf("Enter the author's name: ");
	gets(author_name);
	//scanf("%s",author_name);
	printf("Enter the name of the publisher: ");
	gets(publisher);
	//scanf("%s",publisher);

	getchar();


	FILE *f = fopen("request.txt","a+");
	fprintf(f,"\n%s\n",book_title);
	fprintf(f,"%s\n",author_name);
	fprintf(f,"%s\n",publisher);

	fclose(f);
}
