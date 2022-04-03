#ifndef __INC_H__
#define __INC_H__

#include<stdio.h>
#include<string.h>
#include <stdlib.h>

#define PASS 1
#define FAIL 0

void showMenu();//admin function menu
void addBook();//to add book
int getAnswer();//
void checkContent(int);
void showCheckMenu();//to check the book
void showAllBooks(); //to show all books
void eraseBooks(); // erase all the books
void setCategory();//set category for added book
int getCommand(int);
void requestBook();//request book to admin
void seeRequest();
int compareString();
void buyBook();
void requestBook();
//define user 1;
int user = 1; //Global Variable

#endif // __INC_H__


