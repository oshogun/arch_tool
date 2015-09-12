#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define RESET "\033[0m"

void update_system();
void remove_orphans();
void remove_unused();
void clear_cache();
void optimize_pacman();
void menu();

int main() {
    int command;
    menu();
    while(scanf("%d",&command) != 1 || (command < 1 || command > 6)) {
        system("clear");
        printf(KRED "\n\nINVALID OPTION!!!!!!\n\n" RESET);
        menu();
        scanf("%*s");
    }
    switch(command) {
                case 1:
                    update_system();
                    return 0;
                case 2:
                    remove_orphans();
                    return 0;
                case 3:
                    remove_unused();
                    return 0;
                case 4:
                    clear_cache();
                    return 0;
                case 5:
                    optimize_pacman();
                    return 0;
                case 6:
                    return 0;

    }
    return 0;
}
void update_system() {
    system("pacman -Syu");
}
void remove_orphans() {
    system("pacman -Rns $(pacman -Qtdq)");
}
void remove_unused() {
    printf("Do that yourself lol\n");
}
void clear_cache() {
    system("pacman -Sc");
}
void optimize_pacman() {
    system("pacman-optimize");
}
void menu(){
    printf(KGRN "\nWelcome to the arch linux mainteance script!\n" RESET);
    printf("\n\nWhat would you like to do?\n\n");
    printf(KGRN "1. Update the system\n2. Remove orphaned packages\n3. Remove unused packages\n4. Clean the package cache\n"RESET);
    printf(KGRN "5. Optimize pacman database\n6. Exit\n" RESET); 
}
