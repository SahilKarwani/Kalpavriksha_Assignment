#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "users.txt"


typedef struct
{
    int id;
    int age;
    char name[30];
} User;

int num_records = 0;

void create_user();
int find_user_by_id(int id);
void read_users();
void update_user();
void delete_user();

int main()
{
    int select_choice;

    while (1)
    {
        printf("\nCRUD Operations- User Information\n");
        printf("1. Create (Add User)\n");
        printf("2. Read (Display Users)\n");
        printf("3. Update (Modify User)\n");
        printf("4. Delete (Remove User)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &select_choice);

        switch (select_choice)
        {
        case 1:
            create_user();
            break;
        case 2:
            read_users();
            break;
        case 3:
            update_user();
            break;
        case 4:
            delete_user();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Not Valid choice! Choose again: \n");
        }
    }

    return 0;
}



void create_user()
{
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return;
    }

    User user;
    int isUnique = 0;

    while (!isUnique)
    {
        printf("Enter user ID: ");
        scanf("%d", &user.id);

        if (find_user_by_id(user.id))
        {
            printf("ID already exists. Please enter a unique ID.\n");
        }
        else
        {
            isUnique = 1;
        }
    }
    num_records++; 
    getchar();
    printf("Enter user name: ");
    fgets(user.name, sizeof(user.name), stdin);
    user.name[strcspn(user.name, "\n")] = '\0';

    printf("Enter user age: ");
    scanf("%d", &user.age);

    
    fprintf(file, "%d|%s|%d\n", user.id, user.name, user.age);
    fclose(file);

    printf("User added successfully.\n");
}

int find_user_by_id(int id)
{
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL)
        return 0;

    User user;
    while (fscanf(file, "%d|%[^|]|%d\n", &user.id, user.name, &user.age) != EOF)
    {
        if (user.id == id)
        {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

void read_users()
{
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL)
    {
        printf("file is empty\n");
        return;
    }

    User user;

    // while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) != EOF)
    // {
    //     num_records++;
    // }
    printf("     User Records         \n");
    printf("ID\tName\tAge\n");
    printf("-----------------------\n");
    while (fscanf(file, "%d|%[^|]|%d\n", &user.id, user.name, &user.age) != EOF)
    {
        printf("%d\t%s\t%d\n", user.id, user.name, user.age);
    }
    fclose(file);
}

void update_user()
{

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL)
    {
        printf("File is empty updation is not possible\n");
        return;
    }

    int id, found = 0;
    printf("Enter the ID of the user to update: ");
    scanf("%d", &id);

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL)
    {
        printf("Error: Could not create temporary file.\n");
        fclose(file);
        return;
    }

    User user;
    while (fscanf(file, "%d|%[^|]|%d", &user.id, user.name, &user.age) != EOF)
    {
        if (user.id == id)
        {
            found = 1;
            printf("Enter new name for user (current: %s): ", user.name);
            getchar();
            fgets(user.name, sizeof(user.name), stdin);
            user.name[strcspn(user.name, "\n")] = '\0';
            printf("Enter new age for user (current: %d): ", user.age);
            scanf("%d", &user.age);
        }
        fprintf(temp, "%d|%s|%d\n", user.id, user.name, user.age);
    }

    fclose(file);
    fclose(temp);

    if (found)
    {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("User updated successfully.\n");
    }
    else
    {
        remove("temp.txt");
        printf("User not found with id: %d.\n", id);
    }
}

void delete_user()
{
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL)
    {
        printf("File is empty .\n");
        return;
    }

    int id;
    printf("Enter the ID of the user to delete: ");
    scanf("%d", &id);

    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL)
    {
        printf("Error: Could not create temporary file.\n");
        fclose(file);
        return;
    }

    User user;
    int exist = 0;
    while (fscanf(file, "%d|%[^|]|%d", &user.id, user.name, &user.age) != EOF)
    {
        if (user.id != id)
        {
            fprintf(temp_file, "%d|%s|%d\n", user.id, user.name, user.age);
        }
        else
        {
            exist = 1;
        }
    }

    fclose(file);
    fclose(temp_file);

    if (exist)
    {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("User with id: %d deleted successfully.\n", id);
    }
    else
    {
        printf("Error: User not exist.\n");
        remove("temp.txt");
    }
}
