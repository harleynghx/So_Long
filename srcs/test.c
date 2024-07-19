#include <stdio.h>
#include <unistd.h> // for usleep function

#define ROWS 10
#define COLS 19

// Initial map definition
char map[ROWS][COLS+1] = {
    "1111111111111111111",
    "111111P111111111111",
    "1111110111111111111",
    "1000C00000C0000C001",
    "1000000000000000001",
    "1C0000C00000C000001",
    "1000C11111100000001",
    "111111111111100C111",
    "1111111111111E11111",
    "1111111111111111111"
};

// Directions arrays for moving up, down, left, right
int dRow[] = {-1, 1, 0, 0};
int dCol[] = {0, 0, -1, 1};

// Struct to represent a point on the map
typedef struct {
    int row;
    int col;
} Point;

// Function to check if a cell is valid for moving into
int isValid(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS && map[row][col] != '1');
}

// Function to print the current state of the map
void printMap() {
    for (int i = 0; i < ROWS; i++) {
        printf("%s\n", map[i]);
    }
    printf("\n");
    usleep(500000); // sleep for 500 milliseconds
}

// Iterative flood fill algorithm using only while loops
int floodFillIterative(int startRow, int startCol) {
    // Queue implementation to store points to visit
    Point queue[ROWS * COLS];
    int front = 0, rear = 0;
    
    // Start from the player's position
    queue[rear++] = (Point){startRow, startCol};
    map[startRow][startCol] = '1';  // Mark as visited
    printMap(); // Print the map after marking the start point
    
    while (front < rear) {
        Point current = queue[front++];
        
        // Check if the exit is found
        if (map[current.row][current.col] == 'E') return 1;
        
        // Manually check each of the four directions
        int dir = 0;
        while (dir < 4) {
            int newRow = current.row + dRow[dir];
            int newCol = current.col + dCol[dir];
            if (isValid(newRow, newCol)) {
                if (map[newRow][newCol] == 'E') return 1;  // Exit found
                map[newRow][newCol] = '1';  // Mark as visited
                queue[rear++] = (Point){newRow, newCol};
                printMap(); // Print the map after marking each new point
            }
            dir++;
        }
    }
    
    return 0;  // No path to exit found
}

int main() {
    int playerRow, playerCol;
    
    // Find the player's starting position using while loops
    int i = 0, j = 0;
    int found = 0;
    while (i < ROWS && !found) {
        j = 0;
        while (j < COLS && !found) {
            if (map[i][j] == 'P') {
                playerRow = i;
                playerCol = j;
                found = 1;
            }
            j++;
        }
        i++;
    }
    
    // Check if there is a valid path from the player to the exit
    if (floodFillIterative(playerRow, playerCol)) {
        printf("There is a valid path from the player to the exit.\n");
    } else {
        printf("There is no valid path from the player to the exit.\n");
    }

    return 0;
}