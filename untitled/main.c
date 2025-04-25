#include <stdio.h>
#include <string.h>
#include <time.h>

struct task {
    int id;
    char name[32];
    char description[32];
};

int main(void) {
    FILE *fptr;
    int option;

    while (option != 4) {
        printf("Option: \n");
        printf("1. Add\n");
        printf("2. View\n");
        printf("3. Delete\n");
        printf("4. Exit\n");
        scanf("%d", &option);
        getchar();

        fptr = fopen("tasks.txt", "r");
        char readFile[1000];
        int current_id = 1;
        while (fgets(readFile, 1000, fptr)) {
            current_id++;
        }
        fclose(fptr);

        switch (option) {
            case 1: {
                struct task task;

                printf("Enter the task name: ");
                fgets(task.name, sizeof(task.name), stdin);
                task.name[strcspn(task.name, "\n")] = '\0';

                printf("Enter the task description: ");
                fgets(task.description, sizeof(task.description), stdin);
                task.description[strcspn(task.description, "\n")] = '\0';

                fptr = fopen("tasks.txt", "a");
                if (fptr == NULL) {
                    printf("Error opening file!\n");
                    return 1;
                }
                fprintf(fptr, "%d|%s|%s\n", current_id, task.name, task.description);
                fclose(fptr);
                printf("Task added successfully!\n");
                break;
            }

            case 2:
                fptr = fopen("tasks.txt", "r");
                while (fgets(readFile, 1000, fptr)) {
                    printf("%s", readFile);
                }
                fclose(fptr);
                break;

            case 3: {
                int task_id_to_delete;
                printf("Enter the task ID to delete: ");
                scanf("%d", &task_id_to_delete);
                getchar();  // To consume the newline character from the input

                // Open the original file to read and the temporary file to write
                FILE *temp_fptr = fopen("temp_tasks.txt", "w");
                fptr = fopen("tasks.txt", "r");

                if (fptr == NULL || temp_fptr == NULL) {
                    printf("Error opening file!\n");
                    return 1;
                }

                // Read and write tasks, skipping the task with the given ID
                while (fgets(readFile, 1000, fptr)) {
                    int id;
                    char name[32], description[32];
                    sscanf(readFile, "%d|%31[^|]|%31[^\n]", &id, name, description);

                    // Write to the temporary file only if the task id does not match the one to delete
                    if (id != task_id_to_delete) {
                        fprintf(temp_fptr, "%d|%s|%s\n", id, name, description);
                    }
                }

                fclose(fptr);
                fclose(temp_fptr);

                // Remove the original file and rename the temporary file to the original name
                remove("tasks.txt");
                rename("temp_tasks.txt", "tasks.txt");

                printf("Task deleted successfully!\n");
                break;
            }
        }
    }
    return 0;
}
