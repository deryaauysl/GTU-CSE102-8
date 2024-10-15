#include <stdio.h>
#include <string.h>

#define MAX_ROW_NUM 100
#define MAX_COLUMN_NUM 5
#define MAX_STR_NUM 50

typedef struct /*Descriping structure for determining type of informations*/
{
    char str[MAX_STR_NUM];
    int num;
} data;

/* Function for sorting individuals by age */

void sort_people_by_age(data scientists[MAX_ROW_NUM][MAX_COLUMN_NUM], int row_number)
{
    int i = 0; /* Sorting individuals by age using bubble sort algorithm */
    int j = 0;
    int k = 0;
    int m = 0;

    for (i = 0; i < row_number - 1; i++)
    {
        for (j = 0; j < row_number - i - 1; j++)
        {
            if (scientists[j][2].num > scientists[j + 1][2].num)
            {
                for (k = 0; k < MAX_COLUMN_NUM; k++)
                {
                    data temp[MAX_COLUMN_NUM]; /* Swap elements if age is greater */
                    temp[k] = scientists[j][k];
                    scientists[j][k] = scientists[j + 1][k];
                    scientists[j + 1][k] = temp[k];
                }
            }
        }
    }

    printf("Sorted individuals by age:\n");
    printf("Name  Surname Age  Branch1 Branch2\n"); /* Displaying sorted individuals by age */
    for (k = 0; k < row_number; k++)
    {
        printf("%s, %s, %d, %s %s\n", scientists[k][0].str, scientists[k][1].str, scientists[k][2].num, scientists[k][3].str, scientists[k][4].str);
    }
}

/* Function for sorting individuals by branch */

void sort_people_by_branch(data scientists[MAX_ROW_NUM][MAX_COLUMN_NUM], int row_number)
{

    int result = 0;
    int result1 = 0;
    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; i < row_number - 1; i++)
    {
        for (j = 0; j < row_number - i - 1; j++)
        {
            result = strcmp(scientists[j][3].str, scientists[j + 1][3].str); /*Comparing values for determining result*/
            result1 = strcmp(scientists[j][4].str, scientists[j + 1][4].str);

            if (result > 0)
            {
                for (k = 0; k < MAX_COLUMN_NUM; k++)
                {
                    data temp[MAX_COLUMN_NUM];
                    temp[k] = scientists[j][k];
                    scientists[j][k] = scientists[j + 1][k];
                    scientists[j + 1][k] = temp[k];
                }
            }
            else if (result == 0)
            {

                if (result1 > 0)
                {
                    for (k = 0; k < MAX_COLUMN_NUM; k++)
                    {
                        data temp[MAX_COLUMN_NUM];
                        temp[k] = scientists[j][k];
                        scientists[j][k] = scientists[j + 1][k];
                        scientists[j + 1][k] = temp[k];
                    }
                }

                if (scientists[j][2].num > scientists[j + 1][2].num)
                {
                    for (k = 0; k < MAX_COLUMN_NUM; k++)
                    {
                        data temp[MAX_COLUMN_NUM];
                        temp[k] = scientists[j][k];
                        scientists[j][k] = scientists[j + 1][k];
                        scientists[j + 1][k] = temp[k];
                    }
                }
            }
        }
    }

    printf("Sorted individuals by branch:\n");
    printf("Name  Surname Age  Branch1 Branch2\n"); /* Displaying filtered individuals */
    for (k = 0; k < row_number; k++)
    {
        printf("%s, %s, %d, %s %s\n", scientists[k][0].str, scientists[k][1].str, scientists[k][2].num, scientists[k][3].str, scientists[k][4].str);
    }
}

/* Function for filtering individuals by branch */

void filter_people_by_branch(data scientists[MAX_ROW_NUM][MAX_COLUMN_NUM], int row_number)
{
    int i = 0;
    printf("Name  Surname   Age  Branch1    Branch2\n");
    for (i = 0; i < row_number; i++)
    {
        if (strstr(scientists[i][3].str, "SCIENCE") != NULL || /* Filtering individuals by branch 'SCIENCE' */
            strstr(scientists[i][4].str, "SCIENCE") != NULL)
        {

            printf("%s, %s, %d, %s %s\n",
                   scientists[i][0].str, scientists[i][1].str,
                   scientists[i][2].num, scientists[i][3].str,
                   scientists[i][4].str);
        }
    }
}

/* Function for filtering individuals by profession */

void filter_people_by_profession(data scientists[MAX_ROW_NUM][MAX_COLUMN_NUM], int row_number)
{
    int i = 0;
    printf("Name  Surname   Age  Branch1    Branch2\n");
    for (i = 0; i < row_number; i++)
    {
        if (strstr(scientists[i][3].str, "COMPUTER SCIENCE") != NULL ||
            strstr(scientists[i][4].str, "COMPUTER SCIENCE") != NULL)
        {
            if (!(strstr(scientists[i][4].str, "MATHEMATICS") != NULL))
                printf("%s, %s, %d, %s %s\n", /* Displaying filtered individuals */
                       scientists[i][0].str, scientists[i][1].str,
                       scientists[i][2].num, scientists[i][3].str,
                       scientists[i][4].str);
        }
    }
}
int main()
{

    FILE *file = fopen("input1.txt", "r"); /*Open file*/

    if (file == NULL)
    {
        printf("The file does not exist\n");
        return 0;
    }

    data scientists[MAX_ROW_NUM][MAX_COLUMN_NUM];
    char line[MAX_COLUMN_NUM * MAX_STR_NUM];
    int choice = 0;
    int flag = 1;
    int row_number = 0;

    while (fgets(line, sizeof(line), file)) /* Read the file line by line*/
    {
        sscanf(line, "%[^,],%[^,],%d,%[^,],%[^\n]", scientists[row_number][0].str, scientists[row_number][1].str,
               &scientists[row_number][2].num, scientists[row_number][3].str, scientists[row_number][4].str);
        row_number++;
    }

    fclose(file);

    while (flag) /*Print the menu*/
    {
        printf("Menu\n");
        printf("1. Sort and display all individuals by age\n");
        printf("2. Sort and display individuals in the branch by age\n");
        printf("3. Show individuals with the branch 'SCIENCE'\n");
        printf("4. Show computer scientists who are not mathematicians\n");
        printf("5. Exit\n");

        printf("Enter the choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            sort_people_by_age(scientists, row_number); /*Call all function*/
            break;
        case 2:
            sort_people_by_branch(scientists, row_number);
            break;
        case 3:
            filter_people_by_branch(scientists, row_number);
            break;
        case 4:
            filter_people_by_profession(scientists, row_number);
            break;
        case 5:
            printf("Exiting..\n");
            flag = 0;
            break;
        default:
            printf("Wrong choice!\n");
            flag = 0;
            break;
        }
    }

    return 0;
}