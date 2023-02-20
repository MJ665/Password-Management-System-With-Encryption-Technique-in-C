#include <stdio.h>
#include <string.h>

void IWillEncrypt(char *StringPtr, int EN)
{
    char *ptr = StringPtr;
    while (*ptr != '\0')
    {
        *ptr = *ptr + EN;
        ptr++;
    };
};

void IWilldecrypt(char *StringPtr, int EN)
{
    char *ptr = StringPtr;
    while (*ptr != '\0')
    {
        *ptr = *ptr - EN;
        ptr++;
    };
};

int main()
{
printf("\n\n\n");
printf("\n\n\n");
    printf("* * * * * Welcome to the Password Management System * * * * *\n");
    printf("\n\n\n");
    char ExitYorN[2];
    do
    {
        FILE *userPtr;
        userPtr = fopen("user.txt", "r");
        if (userPtr == NULL)
        {
            printf("For Security purpose if any of the user.txt  file does not exists you have to creat new username, password and Encryption Number to access your data\n");
            userPtr = fopen("user.txt", "w");
            fprintf(userPtr, "!!!");
            fclose(userPtr);
            printf("You Have To Creat Username and password\n");
            char UserEncryptedStr[11];
            char userNameStr[11];
            char passstr1[11];
            char passstr2[11];
            char UserEncryptedPassword[11];
            printf("Please Dont use Integers\n");
            printf("Type Username of length of 10 :\n");
            scanf("%s", userNameStr);
            printf("Please Dont use Integers\n");
            printf("Type Password  of length 10 \n");
            scanf("%s", passstr1);
            printf("confirm password\n");
            scanf("%s", passstr2);

            while (strcmp(passstr1, passstr2) != 0)
            {
                printf("password & confirm passowrd must be same\n");
                printf("Type Password  of length 10 Please Dont Use Integers\n");
                scanf("%s", passstr1);
                printf("Confirm Password\n");
                scanf("%s", passstr2);
            }

            int EN;
            printf("Enter Encryption Number between 1-15: \n");
            scanf("%d", &EN);
            strcpy(UserEncryptedStr, userNameStr);
            strcpy(UserEncryptedPassword, passstr1);
            IWillEncrypt(UserEncryptedStr, EN);
            IWillEncrypt(UserEncryptedPassword, EN);
            userPtr = fopen("user.txt", "w");
            fprintf(userPtr, "%s\n%s\n%d", UserEncryptedStr, UserEncryptedPassword, EN);
            fclose(userPtr);
        }
        else
        {
            char typeUsername[11];
            char typePassword[11];
            char checkUsername[11];
            char checkPassword[11];
            int EN;

            fscanf(userPtr, "%s %s %d", checkUsername, checkPassword, &EN);
            IWilldecrypt(checkUsername, EN);
            IWilldecrypt(checkPassword, EN);
            printf("Enter Username and Password\n");
            printf("Username\n");
            scanf("%s", typeUsername);
            printf("Password\n");
            scanf("%s", typePassword);
            while ((strcmp(checkUsername, typeUsername) != 0) || strcmp(checkPassword, typePassword) != 0)
            {
                printf("!!!INCORRECT!!!\n");
                printf("Enter CORRECT username & password\n");
                printf("Username\n");
                scanf("%s", typeUsername);
                printf("Password\n");
                scanf("%s", typePassword);
            };

            printf("Type P to access Password\n");
            printf("Type A to Add password\n");
            char PorA[2];
            scanf("%s", PorA);

            if (PorA[0] == 'P')
            {

                printf("Which Website Paassword You Have TO Print:\n");
                char Website[100];
                scanf("%s", Website);
                printf("Password of %s website is:\n", Website);
                FILE *WebsiteFile;
                strcat(Website, ".txt");
                WebsiteFile = fopen(Website, "r");
                char password[100];
                fscanf(WebsiteFile, "%s", password);
                fclose(WebsiteFile);
                IWilldecrypt(password, EN);
                printf("\n\n\n%s\n\n\n\n", password);
            }
            else if (PorA[0] == 'A')
            {

                printf("Enter Website Name You Want to add:\n");
                char website[100];
                char password[100];
                scanf("%s", website);
                strcat(website, ".txt");
                FILE *WebsitePtr;
                WebsitePtr = fopen(website, "w");
                printf("Enter password You Want To Store: \n");
                scanf("%s", password);
                char temp[100];

                IWillEncrypt(password, EN);
                fprintf(WebsitePtr, "%s", password);
                fclose(WebsitePtr);
            };
        };

        printf("DO YOU WANT TO EXIT PROGRAM ?\n");
        printf("Enter y for yes\n");
        printf("Enter n for no\n");
        scanf("%s", &ExitYorN[0]);
        printf("\n\n\n");
    } while (ExitYorN[0] == 'n');

    printf("\n\n\n");
    printf("\n\n\n");

    return 0;
}
