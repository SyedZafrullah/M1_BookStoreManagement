#include "inc.h"
#include "adminfunction.c"
#include "customerfunction.c"

int main ()

{

Login:
    printf("CHOOSE USER\n 1.ADMIN\n 2.CUSTOMER\n");
    scanf("%d",&user);
    if(user == 1)
    {
        char id[50];

UserID:

        printf("Enter your id:\n");

        scanf("%s", &id);

        if (strcmp(id,"admin")!=0)

        {

            printf("You have entered an invalid user id\nPlease enter id again\n");

            goto UserID;

        }


        char pass[50];

Pass:


        printf("Enter your password: ");

        scanf("%s", &pass);

        if(strcmp(pass,"admin121")==0)

        {

            printf("You have successfully logged in into Book Store\n");
            //call admin function
            showMenu();

        }

        else

        {

            printf("You have entered a wrong password\nEnter your password again\n");

            goto Pass;

        }
    }
    else if(user == 2)
    {
        //call customer function
        showCheckMenu();

    }
    else
    {
        printf("CHOOSE THE CORRECT USER\n\n");
        goto Login;

    }

    return 0;

}
