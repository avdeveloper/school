#include <stdio.h>
#include <stdlib.h>

#define READ_ONLY "r"

typedef struct {
    char state;
    int numNeighbors;
} Cell;

void initialize(int *rows, int *cols, int *generations, int *generationNumber, char **filepath);

Cell*[] populateWorldFrom(char *fp, int cols);

int main(int argc, char *argv[]) {
    int rows, cols, generations, generationNumber;
    char *filepath;
    Cell *world[rows];

    initialize(&rows, &cols, &generations, &generationNumber, &filepath);
    world = populateWorldFrom(filepath, cols);

    return 0;
}

void initialize(int *rows, int *cols,
                int *generations, int *generationNumber, char **filepath) {

    *rows = 10;
    *cols = 10;
    *generations = 10;
    *generationNumber = 0;
    *filepath = "life.txt";
}

(Cell*)[] populateWorldFrom(char *fp, int cols) {
    FILE *file = fopen(fp, READ_ONLY);
    fclose(file);
}
