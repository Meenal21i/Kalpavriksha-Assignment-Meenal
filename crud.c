#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "users.txt"

typedef struct
{
    int id;
    char name[30];
    int age;
} User;

// Checking if User Already Exists
int userAlreadyExists(int id)
{
    FILE *f_ptr = fopen(FILE_NAME, "r");
    if (!f_ptr)
        return 0;

    User user;
    while (fscanf(f_ptr, "%d %29s %d", &user.id, user.name, &user.age) == 3)
    {
        if (user.id == id)
        {
            fclose(f_ptr);
            return 1;
        }
    }
    fclose(f_ptr);
    return 0;
}

// CREATE USER
void createUser()
{
    FILE *f_ptr = fopen(FILE_NAME, "a+");
    if (!f_ptr)
    {
        printf("File cannot be opened\n");
        return;
    }

    User user;
    printf("Enter User ID: ");
    scanf("%d", &user.id);

    if (userAlreadyExists(user.id))
    {
        printf("ID: %d user already exists.\n", user.id);
        fclose(f_ptr);
        return;
    }

    printf("Enter Name of User: ");
    scanf(" %[^\n]s", user.name);
    printf("Enter Age of User: ");
    scanf("%d", &user.age);

    fprintf(f_ptr, "%d %s %d\n", user.id, user.name, user.age);
    printf("User added successfully.\n");
    fclose(f_ptr);
}

// DISPLAY USERS
void readUsers()
{
    FILE *f_ptr = fopen(FILE_NAME, "r");
    if (!f_ptr)
    {
        printf("File cannot be opened\n");
        return;
    }

    User user;
    printf("\n%-10s %-20s %-10s\n", "User ID", "User Name", "User Age");
    while (fscanf(f_ptr, "%d %29s %d", &user.id, user.name, &user.age) == 3)
    {
        printf("%-10d %-20s %-10d\n", user.id, user.name, user.age);
    }
    fclose(f_ptr);
}

// UPDATE USER
void updateUser()
{
    int id;
    printf("Enter User ID you wish to update: ");
    if (scanf("%d", &id) != 1)
    {
        while (getchar() != '\n')
            ; 
        printf("Invalid input.\n");
        return; 
    }

    FILE *f_ptr = fopen(FILE_NAME, "r");
    FILE *tempF = fopen("temp.txt", "w");
    if (!f_ptr || !tempF)
    {
        printf("Error opening file\n");
        return;
    }

    User user;
    int found = 0;
    while (fscanf(f_ptr, "%d %29s %d", &user.id, user.name, &user.age) == 3)
    {
        if (user.id == id)
        {
            printf("Enter new name: ");
            scanf(" %[^\n]s", user.name);
            printf("Enter new age: ");
            scanf("%d", &user.age);
            found = 1;
        }
        fprintf(tempF, "%d %s %d\n", user.id, user.name, user.age);
    }

    fclose(f_ptr);
    fclose(tempF);

    if (!found)
    {
        printf("ID: %d user not found.\n", id);
        remove("temp.txt");
    }
    else
    {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("User updated successfully.\n");
    }
}

// DELETE USER
void deleteUser()
{
    int id;
    printf("Enter User ID you wish to delete: ");
    if (scanf("%d", &id) != 1)
    {
        while (getchar() != '\n')
            ;
        printf("Invalid input.\n");
        return; 
    }

    FILE *f_ptr = fopen(FILE_NAME, "r");
    FILE *tempF = fopen("temp.txt", "w");
    if (!f_ptr || !tempF)
    {
        printf("Error opening file\n");
        return;
    }

    User user;
    int found = 0;
    while (fscanf(f_ptr, "%d %29s %d", &user.id, user.name, &user.age) == 3)
    {
        if (user.id == id)
        {
            found = 1;
            continue; // skipping the user to delete
        }
        fprintf(tempF, "%d %s %d\n", user.id, user.name, user.age);
    }

    fclose(f_ptr);
    fclose(tempF);

    if (!found)
    {
        printf("User with ID %d not found.\n", id);
        remove("temp.txt");
    }
    else
    {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("User deleted successfully.\n");
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\nUser Management System\n");
        printf("1. Create User\n");
        printf("2. Display All Users\n");
        printf("3. Update User (Using ID)\n");
        printf("4. Delete User (Using ID)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createUser();
            break;
        case 2:
            readUsers();
            break;
        case 3:
            updateUser();
            break;
        case 4:
            deleteUser();
            break;
        case 5:
            printf("You have successfully exited.\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
