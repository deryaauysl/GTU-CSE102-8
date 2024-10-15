#include <stdio.h>
#include <string.h>

#define MAX_ROW_COUNT 100
#define MAX_COL_COUNT 100
#define MAX_MATCHES 100

void search_p1(char strs[][MAX_COL_COUNT], int num_rows, int matches[][2], int *num_matches)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;
    int match = 0;
    *num_matches = 0; /*Matched number set to 0 in the beginning*/

    const char *pattern = "***++++***++++***";
    int pattern_len = strlen(pattern);

    for (i = 0; i < num_rows; i++)
    {
        for (j = 0; j < MAX_COL_COUNT - pattern_len; j++)
        {
            match = 1;

            /*Check pattern in this location*/
            for (k = 0; k < pattern_len; k++)
            {
                if (strs[i][j + k] != pattern[k])
                {
                    match = 0; /*No match*/
                    break;
                }
            }

            /*If the matched , save the location*/
            if (match)
            {
                matches[*num_matches][0] = i + 1;
                matches[*num_matches][1] = j + 1;
                (*num_matches) += 1;
            }
        }
    }
    for (m = 0; m < *num_matches; m++) /*Print all location*/
    {
        printf("P1 @ (%d, %d)\n", matches[m][0], matches[m][1]);
    }
}

void search_p2(char strs[][MAX_COL_COUNT], int num_rows, int matches[][2], int *num_matches)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;
    int match = 0;
    *num_matches = 0; /*Matched number set to 0 in the beginning*/

    const char *pattern = "+*+*+";
    int pattern_len = strlen(pattern);

    for (i = 0; i < MAX_COL_COUNT - pattern_len; i++)
    {
        for (j = 0; j < num_rows; j++)
        {
            match = 1;

            /*Check pattern in this location*/
            for (k = 0; k < pattern_len; k++)
            {
                if (strs[j + k][i] != pattern[k])
                {
                    match = 0; /*No match*/
                    break;
                }
            }

            /*If the matched , save the location*/
            if (match)
            {
                matches[*num_matches][0] = j + 1;
                matches[*num_matches][1] = i + 1;
                (*num_matches) += 1;
            }
        }
    }
    for (m = 0; m < *num_matches; m++) /*Print all location*/
    {
        printf("P2 @ (%d, %d)\n", matches[m][0], matches[m][1]);
    }
}

void search_p3(char strs[][MAX_COL_COUNT], int num_rows, int matches[][2], int *num_matches)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;
    int match = 0;
    *num_matches = 0; /*Matched number set to 0 in the beginning*/

    const char *pattern = "+**+++****+++**+";
    int pattern_len = strlen(pattern);

    for (i = 0; i < num_rows; i++)
    {

        for (j = 0; j < MAX_COL_COUNT - pattern_len; j++)
        {
            match = 1;

            /*Check pattern in this location*/
            for (k = 0; k < pattern_len; k++)
            {
                if (strs[i + k][j + k] != pattern[k])
                {
                    match = 0; /*No match*/
                    break;
                }
            }

            /*If the matched , save the location*/
            if (match)
            {
                matches[*num_matches][0] = i + 1;
                matches[*num_matches][1] = j + 1;
                (*num_matches) += 1;
            }
        }
    }
    for (m = 0; m < *num_matches; m++) /*Print all location*/
    {
        printf("P3 @ (%d, %d)\n", matches[m][0], matches[m][1]);
    }
}

int main()
{

    FILE *file = fopen("input2.txt", "r"); /*Open file*/

    if (file == NULL)
    {
        printf("The file does not exist\n");
        return 0;
    }

    char str[MAX_ROW_COUNT][MAX_COL_COUNT];
    int row_num = 0;
    int matches[MAX_MATCHES][2];
    int num_matches = 0;

    while (fgets(str[row_num], MAX_COL_COUNT, file)) /*Finding row number*/
    {
        row_num++; /* Read data from the file into the 2D array */
    }

    fclose(file);

    search_p1(str, row_num, matches, &num_matches); /*Call function*/

    search_p2(str, row_num, matches, &num_matches);

    search_p3(str, row_num, matches, &num_matches);

    return 0;
}