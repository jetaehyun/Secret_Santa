#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

bool doesExist(char **list, char *name, int size) {
    for(int i = 0; i < size; i++) {
        char *per = *(list + i);
        if(strcmp(per, name) == 0) return true; 
    }

    return false;
}

int main(int argc, const char *argv[]) {
    srand(time(NULL));
    char children[10];

    printf("How many children are there? ");
    scanf("%s", children);
    
    int numb = atoi(children);
    char **names = malloc(numb * sizeof(char *));
    char **gifted = malloc(numb * sizeof(char *));


    for(int i = 0; i < numb; i++) {
        char *name = malloc(sizeof(char) * 50);
        printf("Child %d: ", i + 1);
        scanf("%s", name);
        *(names + i) = name;
    }
    printf("\n");
    
    int assigned = 0;
    while(assigned != numb) {
        int random = rand() % numb;
        char *giver = *(names + assigned);
        char *rec = *(names + random);

        if(strcmp(giver, rec) == 0 || doesExist(gifted, rec, assigned)) continue;
        printf("Secret Santa: %s Child: %s\n", giver, rec);
        *(gifted + assigned) = rec;

        assigned++;
    }

    free(names);
    free(gifted);

    return 0;
}