#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void createFile(const char *filename);
void openFile(const char *filename);
void readFile(const char *filename);
void writeFile(const char *filename);
void deleteFile(const char *filename);
void renameFile(const char *oldname, const char *newname);
void createDirectory(const char *dirname);
void deleteDirectory(const char *dirname);
void renameDirectory(const char *oldname, const char *newname);
void showCounts();

int fileCount = 0;
int dirCount = 0;

int main() {
    int choice;
    char filename[100], dirname[100], newname[100];

    while (1) {
        printf("\nFile Management System\n");
        printf("1. Create File\n");
        printf("2. Open File\n");
        printf("3. Read File\n");
        printf("4. Write to File\n");
        printf("5. Rename File\n");
        printf("6. Delete File\n");
        printf("7. Create Directory\n");
        printf("8. Rename Directory\n");
        printf("9. Delete Directory\n");
        printf("10. Show Counts\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter filename to create: ");
                scanf("%s", filename);
                createFile(filename);
                break;
            case 2:
                printf("Enter filename to open: ");
                scanf("%s", filename);
                openFile(filename);
                break;
            case 3:
                printf("Enter filename to read: ");
                scanf("%s", filename);
                readFile(filename);
                break;
            case 4:
                printf("Enter filename to write: ");
                scanf("%s", filename);
                writeFile(filename);
                break;
            case 5:
                printf("Enter current filename: ");
                scanf("%s", filename);
                printf("Enter new filename: ");
                scanf("%s", newname);
                renameFile(filename, newname);
                break;
            case 6:
                printf("Enter filename to delete: ");
                scanf("%s", filename);
                deleteFile(filename);
                break;
            case 7:
                printf("Enter directory name to create: ");
                scanf("%s", dirname);
                createDirectory(dirname);
                break;
            case 8:
                printf("Enter current directory name: ");
                scanf("%s", dirname);
                printf("Enter new directory name: ");
                scanf("%s", newname);
                renameDirectory(dirname, newname);
                break;
            case 9:
                printf("Enter directory name to delete: ");
                scanf("%s", dirname);
                deleteDirectory(dirname);
                break;
            case 10:
                showCounts();
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 11.\n");
        }
    }

    return 0;
}

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        fclose(file);
        printf("File '%s' created successfully.\n", filename);
        fileCount++;
    } else {
        printf("Failed to create file '%s'.\n", filename);
    }
}

void openFile(const char *filename) {
    char ch;
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        printf("\nFile '%s' opened successfully.\n", filename);
        printf("File content:\n");
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
        }
        fclose(file);
    } else {
        printf("Failed to open file '%s'. File may not exist.\n", filename);
    }
}

void readFile(const char *filename) {
    char buffer[1000];
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("%s", buffer);
        }
        fclose(file);
    } else {
        printf("File '%s' not found.\n", filename);
    }
}

void writeFile(const char *filename) {
    char content[1000];
    printf("\nEnter content to write (Enter '.' on a new line to save and exit):\n");
    FILE *file = fopen(filename, "a");
    if (file != NULL) {
        while (fgets(content, sizeof(content), stdin) != NULL && content[0] != '.') {
            fputs(content, file);
        }
        fclose(file);
        printf("Content written to file '%s' successfully.\n", filename);
    } else {
        printf("Failed to write to file '%s'.\n", filename);
    }
}


void deleteFile(const char *filename) {
    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
        fileCount--;
    } else {
        printf("Failed to delete file '%s'.\n", filename);
    }
}

void renameFile(const char *oldname, const char *newname) {
    if (rename(oldname, newname) == 0) {
        printf("File '%s' renamed to '%s' successfully.\n", oldname, newname);
    } else {
        printf("Failed to rename file '%s' to '%s'.\n", oldname, newname);
    }
}

void createDirectory(const char *dirname) {
    if (mkdir(dirname) == 0) {
        printf("Directory '%s' created successfully.\n", dirname);
        dirCount++;
    } else {
        printf("Failed to create directory '%s'.\n", dirname);
    }
}

void renameDirectory(const char *oldname, const char *newname) {
    if (rename(oldname, newname) == 0) {
        printf("Directory '%s' renamed to '%s' successfully.\n", oldname, newname);
    } else {
        printf("Failed to rename directory '%s' to '%s'.\n", oldname, newname);
    }
}

void deleteDirectory(const char *dirname) {
    if (rmdir(dirname) == 0) {
        printf("Directory '%s' deleted successfully.\n", dirname);
        dirCount--;
    } else {
        printf("Failed to delete directory '%s'.\n", dirname);
    }
}

void showCounts() {
    printf("\nNumber of files created: %d\n", fileCount);
    printf("Number of directories created: %d\n", dirCount);
}
