#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void introduction();
void chapterOne();
void chapterTwo();
void chapterThree();
void investigateRoom();
void exploreHouse();
void openChest();
void fightMonster();
void runAway();
void secretPassage();
void explorePassage();
void encounterGhost();
void fleeGhost();
void gameOver();
void victory();

int main() {
    srand(time(NULL)); // Seed random number generator
    introduction();
    chapterOne();
    return 0;
}

void introduction() {
    printf("Welcome to the Text Adventure Game!\n");
    printf("You wake up in a mysterious house...\n");
    printf("You need to find a way out. Good luck!\n\n");
}

void chapterOne() {
    char choice[20];

    printf("Chapter One: The Beginning\n");
    printf("You wake up in a dimly lit room.\n");
    printf("You see a door and a window.\n");
    printf("What do you want to do? (door/window)\n");
    scanf("%s", choice);

    if (strcmp(choice, "door") == 0) {
        chapterTwo();
    } else if (strcmp(choice, "window") == 0) {
        printf("You look out of the window and see nothing but darkness.\n");
        printf("Suddenly, you hear a noise coming from the door...\n");
        chapterThree();
    } else {
        printf("Invalid choice. Try again.\n");
        chapterOne();
    }
}

void chapterTwo() {
    char choice[20];

    printf("\nChapter Two: The Door\n");
    printf("You approach the door.\n");
    printf("It's locked!\n");
    printf("What do you want to do? (kick/look around)\n");
    scanf("%s", choice);

    if (strcmp(choice, "kick") == 0) {
        printf("You kick the door, but it doesn't budge.\n");
        printf("You hear a faint noise coming from the other side...\n");
        chapterThree();
    } else if (strcmp(choice, "look") == 0) {
        investigateRoom();
    } else {
        printf("Invalid choice. Try again.\n");
        chapterTwo();
    }
}

void chapterThree() {
    char choice[20];

    printf("\nChapter Three: The Noise\n");
    printf("You brace yourself as the noise grows louder...\n");
    printf("What do you want to do? (hide/face)\n");
    scanf("%s", choice);

    if (strcmp(choice, "hide") == 0) {
        gameOver();
    } else if (strcmp(choice, "face") == 0) {
        fightMonster();
    } else {
        printf("Invalid choice. Try again.\n");
        chapterThree();
    }
}

void investigateRoom() {
    char choice[20];

    printf("\nYou look around the room.\n");
    printf("You notice a chest in the corner and a rug covering something shiny.\n");
    printf("What do you want to do? (chest/rug)\n");
    scanf("%s", choice);

    if (strcmp(choice, "chest") == 0) {
        openChest();
    } else if (strcmp(choice, "rug") == 0) {
        secretPassage();
    } else {
        printf("Invalid choice. Try again.\n");
        investigateRoom();
    }
}

void openChest() {
    printf("\nYou open the chest and find a sword!\n");
    printf("You equip the sword and feel more confident.\n");
    chapterTwo(); // Go back to chapter two
}

void secretPassage() {
    char choice[20];

    printf("\nYou lift the rug and find a trapdoor underneath.\n");
    printf("Do you want to explore the passage? (yes/no)\n");
    scanf("%s", choice);

    if (strcmp(choice, "yes") == 0) {
        explorePassage();
    } else if (strcmp(choice, "no") == 0) {
        printf("You decide not to explore the passage and return to the room.\n");
        chapterTwo(); // Go back to chapter two
    } else {
        printf("Invalid choice. Try again.\n");
        secretPassage();
    }
}

void explorePassage() {
    printf("\nYou descend into the dark passage.\n");
    printf("As you explore, you feel a chill down your spine...\n");
    encounterGhost();
}

void encounterGhost() {
    char choice[20];

    printf("\nYou encounter a ghostly figure blocking your path!\n");
    printf("What do you want to do? (fight/flee)\n");
    scanf("%s", choice);

    if (strcmp(choice, "fight") == 0) {
        printf("You try to fight the ghost, but your attacks pass through it.\n");
        printf("It seems you can't defeat it with physical means.\n");
        fleeGhost();
    } else if (strcmp(choice, "flee") == 0) {
        fleeGhost();
    } else {
        printf("Invalid choice. Try again.\n");
        encounterGhost();
    }
}

void fleeGhost() {
    printf("\nYou decide to flee from the ghost.\n");
    printf("You run back to the room, heart pounding.\n");
    printf("You return to the room and catch your breath.\n");
    chapterTwo(); // Go back to chapter two
}

void fightMonster() {
    int random = rand() % 2; // Generate random number (0 or 1)

    printf("\nYou face the noise and encounter a fearsome monster!\n");

    if (random == 0) {
        printf("You engage in combat and defeat the monster!\n");
        victory();
    } else {
        printf("The monster overwhelms you in combat...\n");
        printf("You must find another way to escape!\n");
        chapterTwo(); // Go back to chapter two
    }
}

void gameOver() {
    printf("\nGame Over!\n");
    printf("You hide, but it's too late...\n");
    printf("The darkness consumes you.\n");
}

void victory() {
    printf("\nCongratulations!\n");
    printf("You defeat the monster and escape from the house!\n");
    printf("You have survived the Text Adventure Game!\n");
}
