#include <stdio.h>
#include <stdlib.h>

#define READ_ONLY "r"
#define ALIVE '*'
#define DEAD '-'
#define NEW_LINE '\n'

/**
 * Fill the world with dead cells initially before adding the ones
 * that will be retreived from a generator file.
 *
 * @param char*[]   world   An empty world that must be filled with cells
 * @param int       numRows The number of rows to fill
 * @param int       numCols The number of columns to fill
 * @return void
 */
void populateWorldWithDeadCells (char *world[], int numRows, int numCols);

/**
 * Free up the memory that is in the world
 *
 * @param char*[] world A world that was once filled with life, but is doomed for extinction
 */
void vaporize(char *world[]);

/**
 * Given the path to the file containing where the live cells are located,
 * add them in to the currently dead world
 *
 * @param char*[]   world       The world that needs life
 * @param char*     filepath    The path to the file containing live cells information
 */
void fillWorldWithLiveCells(char *world[], char *filepath);

/**
 * Show the current state of the world or the current generation?
 *
 * @param char*[]   world       The world we would like to view
 * @param int       generation  The current generation
 */
void showGeneration(char *world[], int generationNumber);

/** 
 * Determine whether each cell lives or die
 *
 * @param char*[] world In a world where cells live or die
 */
void evolve(char *world[]);

int main() {
    // Initialize variables
    int i,
        rows = 10,
        cols = 10,
        generations = 10,
        generationNumber = 0;
    char *world[rows];
    char *filepath = "life.txt";

    populateWorldWithDeadCells(world, rows, cols);
    fillWorldWithLiveCells(world, filepath);

    for (i = 0; i < generations; i++) {
        showGeneration(world, generationNumber++);
        evolve(world);
    }

    vaporize(world);
    return 0;
}

void populateWorldWithDeadCells (char *world[], int numRows, int numCols) {
    int i,j;
    for (i=0; i < numRows; i++) {
        world[i] = (char*) malloc(numCols+1);
        for (j=0; j < numCols; j++) {
            world[i][j] = '-';
        }
        world[i][numCols] = '\0';
    }
}

void vaporize(char *world[]) {
    int i;
    for (i=0; i < sizeof(world); i++) {
        free(world[i]);
    }
}

void fillWorldWithLiveCells(char *world[], char *filepath) {
    FILE *fp = fopen(filepath, READ_ONLY);
    int c,
        i = 0,
        j = 0;

    while ((c = fgetc(fp)) != EOF) {
        if (c == ALIVE) {
            world[i][j] = c;
        }
        else if (c == NEW_LINE) {
            i++;
            j = -1;
        }
        j++;
    }

    fclose(fp);
}

void showGeneration(char *world[], int generationNumber) {
    int i;

    printf("Generation %d:\n================================\n", generationNumber);
    for (i = 0; i < sizeof(world); i++) {
        printf("%s\n", world[i]);
    }
}

void evolve(char *world[]) {
    int y;

    for (y = 0; y < sizeof(world); y++) {
        printf("%s\n", world[y][0]);
    }
}
