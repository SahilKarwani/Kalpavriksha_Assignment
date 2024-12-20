#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Max_expression_size = 100;

int isdigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

int isspace(char ch)
{
    return ch == ' ' || ch == '\t' || ch == '\n';
}

int checkOperator(char ch)
{
    return ch == '*' || ch == '/' || ch == '+' || ch == '-';
}

int checkPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int operation(int operand2, int operand1, char operator)
{
    switch (operator)
    {
    case '+':
        return operand2 + operand1;
    case '-':
        return operand2 - operand1;
    case '*':
        return operand2 * operand1;
    case '/':
        return operand1 != 0 ? operand2 / operand1 : 0;
    }
    return 0;
}

int solveExpression(const char *input, int *output)
{
    int values[Max_expression_size];     // Stack for numbers
    char operators[Max_expression_size]; // Stack for operators
    int valuesTop = -1, operatorsTop = -1;

    for (int i = 0; i < strlen(input); i++)
    {

        if (isspace(input[i]))
        {
            continue;
        }

        if (isdigit(input[i]))
        {
            int value = 0;
            while (i < strlen(input) && isdigit(input[i]))
            {
                value = value * 10 + (input[i] - '0');
                i++;
            }
            values[++valuesTop] = value;
            i--;
        }
        else if (checkOperator(input[i]))
        {

            while (operatorsTop >= 0 && checkPrecedence(operators[operatorsTop]) >= checkPrecedence(input[i]))
            {
                int operand1 = values[valuesTop--];
                int operand2 = values[valuesTop--];
                char operator= operators[operatorsTop--];

                if (operation == '/' && operand1 == 0)
                {
                    return 1;
                }

                values[++valuesTop] = operation(operand2, operand1, operator);
            }

            operators[++operatorsTop] = input[i];
        }
        else
        {
            return 2;
        }
    }

    while (operatorsTop >= 0)
    {
        int b = values[valuesTop--];
        int a = values[valuesTop--];
        char op = operators[operatorsTop--];

        if (op == '/' && b == 0)
        {
            return 1;
        }

        values[++valuesTop] = Operation(a, b, op);
    }

    *output = values[valuesTop];
    return 0;
}

int main()
{
    char input[Max_expression_size];
    printf("Enter a mathematical expression: ");
    scanf("%[^\n]", input);

    int output;
    int status = solveExpression(input, &output);

    if (status == 0)
    {
        printf("%d\n", output);
    }
    else if (status == 1)
    {
        printf("Error: Division by zero.\n");
    }
    else
    {
        printf("Error: Invalid expression.\n");
    }

    return 0;
}