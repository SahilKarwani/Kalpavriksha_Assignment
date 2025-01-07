#include <stdio.h>

int isStartsWithVowel(char firstLetter)
{
    if (firstLetter == 'A' || firstLetter == 'E' || firstLetter == 'I' || firstLetter == '0' || firstLetter == 'U' || firstLetter == 'a' || firstLetter == 'e' || firstLetter == 'i' || firstLetter == 'o' || firstLetter == 'u')
        return 1;
    return 0;
}

int checkingMaximumLengthWord(char arr[])
{
    int counter = 0;
    while (arr[counter] != '\0')
    {
        counter++;
    }
    return counter;
}

int main()
{
    int numOfRows, numOfCols;
    printf("Enter number of rows: ");
    scanf("%d", &numOfRows);
    printf("Enter number of columns: ");
    scanf("%d", &numOfCols);
    char arr[11][102][51];

    int wordsWithVowels = 0, maximumLength = 0;

    for (int i = 0; i < numOfRows; i++)
    {
        for (int j = 0; j < numOfCols; j++)
        {
            printf("Name at (%d,%d):", i, j);
            scanf("%s", arr[i][j]);
            if (isStartsWithVowel(arr[i][j][0]))
                wordsWithVowels++;
            int lengthOfWord = checkingMaximumLengthWord(arr[i][j]);
            if (lengthOfWord > maximumLength)
            {
                maximumLength = lengthOfWord;
            }
        }
    }

    printf("The 2D array of names is:\n");
    for (int i = 0; i < numOfRows; i++)
    {
        for (int j = 0; j < numOfCols; j++)
        {
            printf("%s ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\nNumber of names starting with a vowel: %d\n", wordsWithVowels);

    for (int i = 0; i < numOfRows; i++)
    {
        for (int j = 0; j < numOfCols; j++)
        {

            if (checkingMaximumLengthWord(arr[i][j]) == maximumLength)
            {
                printf("\nThe longest name: %s", arr[i][j]);
                return 0;
            }
        }
    }
}
