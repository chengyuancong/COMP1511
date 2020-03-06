// Assignment 1 19T3 COMP1511: CS Paint
// This program was written by Yuancong Cheng (z5285978)
// on 26 Feb 2020

#include <stdio.h>
#include <math.h>

// The dimensions of the canvas (20 rows x 36 columns).
#define N_ROWS 20
#define N_COLS 36

// Shades (assuming your terminal has a black background).
#define BLACK 0
#define WHITE 4

// Direction of a certain angle
#define UP 0
#define RIGHT 90
#define DOWN 180
#define LEFT 270
#define TOP_RIGHT 45
#define BOTTOM_RIGHT 135
#define BOTTOM_LEFT 225
#define TOP_LEFT 315

// Display the canvas.
void displayCanvas(int canvas[N_ROWS][N_COLS]);

// Clear the canvas by setting every pixel to be white.
void clearCanvas(int canvas[N_ROWS][N_COLS]);

// Calculate the distance between two points.
double distance(int row1, int col1, int row2, int col2);

// Draw ellipse.
void drawEllipse(int canvas[N_ROWS][N_COLS], int color);

// Draw lines.
void drawLine(int canvas[N_ROWS][N_COLS], int color);

// Draw squares.
void fillSquare(int canvas[N_ROWS][N_COLS], int color);

// Change color of shades by adding.
int changeShade(int color);

// Copy a certain canvas ans paste on elsewhere.
void copyPaste(int canvas[N_ROWS][N_COLS]);

// Check if the input in draw line or draw square function is valid.
int check(int start_row, int start_col, int length, int direction);

// Check if the input in copy and paste function is valid.
int copycheck(int start_row, int start_col, int length, int direction, int target_row, int target_col);

// Scan in instruction and run cooresponding function to draw or change color.
int main(void) {
    int canvas[N_ROWS][N_COLS];
    clearCanvas(canvas);
    int color = BLACK;  // Initialise color to black.
    int instruction;
    while (scanf("%d", &instruction) != EOF) {   // Scan the instructions until last line. 
        if (instruction == 0){
            drawEllipse(canvas, color);
        } else if (instruction == 1) {
            drawLine(canvas, color);
        } else if (instruction == 2) {
            fillSquare(canvas, color);
        } else if (instruction == 3) {
            color = changeShade(color);  // Change the value of color.
        } else if (instruction == 4) {
            copyPaste(canvas);
        }
    }    
    displayCanvas(canvas);
    return 0;
}

// Draw ellipse, by measuring if a certain pixel of the canvas
// satisfy the requirement that it is in the ellipse.
// All pixels in canvas will be tested.
void drawEllipse(int canvas[N_ROWS][N_COLS], int color) {
    
    int focus_1_row, focus_1_col, focus_2_row, focus_2_col, fill;
    double length;
    scanf("%d %d %d %d %lf %d", &focus_1_row, &focus_1_col, &focus_2_row, &focus_2_col, &length, &fill);
    
    int i = 0;
    while (i < N_ROWS) {
        int j = 0;
        while (j < N_COLS) {
            if (distance(focus_1_row, focus_1_col, i, j) + distance(focus_2_row, focus_2_col, i, j) <= 2 * length) {
                canvas[i][j] = color;    
            }
            j++;   
        }
        i++;
    }
}

// Draw lines, by changing value of elements that satisfy the requirement.
void drawLine(int canvas[N_ROWS][N_COLS], int color) {
    
    int start_row, start_col, length, direction;
    scanf("%d %d %d %d",&start_row, &start_col, &length, &direction);

    // Transfer length and direction to standard value before input test.
    if (length < 0) {
        length = length * (-1);
        direction = direction + 180;
    } 
    direction = direction % 360;
    
    // Test and decide draw or not.
    int valid = check(start_row, start_col, length, direction);
    if (valid == 1) {
        if (direction == DOWN ) {
            int i = 0;
            while (i < length) {
                canvas[start_row + i][start_col] = color;
                i++;
            }
        } else if (direction == UP ) {
            int i = 0;
            while (i < length) {
                canvas[start_row - i][start_col] = color;
                i++;
            }
        } else if (direction == RIGHT ) {
            int i = 0;
            while (i < length) {
                canvas[start_row][start_col + i] = color;
                i++;
            }
        } else if (direction == LETF ) {
            int i = 0;
            while (i < length) {
                canvas[start_row][start_col - i] = color;
                i++;
            }
        } else if (direction == TOP_RIGHT ) {
            int i = 0;
            while (i < length) {
                canvas[start_row - i][start_col + i] = color;
                i++;
            }  
        } else if (direction == BOTTOM_LEFT) {
            int i = 0;
            while (i < length) {
                canvas[start_row + i][start_col - i] = color;
                i++;
            }
        } else if (direction == TOP_LEFT) {
            int i = 0;
            while (i < length) {
                canvas[start_row - i][start_col - i] = color;
                i++;
            }
        } else if (direction == BOTTOM_RIGHT) {
            int i = 0;
            while (i < length) {
                canvas[start_row + i][start_col + i] = color;
                i++;
            }
        } 
    }    
}

// Draw squares, by changing value of elements that satisfy the requirement.
void fillSquare(int canvas[N_ROWS][N_COLS], int color) {
    
    int start_row, start_col, length, direction;
    scanf("%d %d %d %d", &start_row, &start_col, &length, &direction);

    // Transfer length and direction to standard value before input test.
    if (length < 0) {
        length = length * (-1);
        direction = direction + 180;
    } 
    direction = direction % 360;
    
    // Test and decide draw or not.
    int valid = check(start_row, start_col, length, direction);
    if (valid == 1) {
        if (direction == DOWN) {
            int i = 0;
            while (i < length) {
                canvas[start_row + i][start_col] = color;
                i++;
            }
        } else if (direction == UP) {
            int i = 0;
            while (i < length) {
                canvas[start_row - i][start_col] = color;
                i++;
            }
        } else if (direction == RIGHT) {
            int i = 0;
            while (i < length) {
                canvas[start_row][start_col + i] = color;
                i++;
            }
        } else if (direction == LETF) {
            int i = 0;
            while (i < length) {
                canvas[start_row][start_col - i] = color;
                i++;
            }
        } else if (direction == TOP_RIGHT) {
            int i = 0;
            while (i < length) {
                int j = 0;
                while (j < length) {
                    canvas[start_row - i][start_col + j] = color;
                    j++;
                }
                i++;
            }
        } else if (direction == BOTTOM_LEFT) {
            int i = 0;
            while (i < length) {
                int j = 0;
                while (j < length) {
                    canvas[start_row + i][start_col - j] = color;
                    j++;
                }
                i++;
            }
        } else if (direction == TOP_LEFT) {
            int i = 0;
            while (i < length) {
                int j = 0;
                while (j < length) {
                    canvas[start_row - i][start_col - j] = color;
                    j++;
                }
                i++;
            }
        } else if (direction == BOTTOM_RIGHT) {
            int i = 0;
            while (i < length) {
                int j = 0;
                while (j < length) {
                    canvas[start_row + i][start_col + j] = color;
                    j++;
                }
                i++;
            }
        }   
    }   
}

// Change color of shades by adding.
int changeShade(int color) {
    int new_shade;
    scanf("%d", &new_shade);
    if (color + new_shade >= 0 && color + new_shade <= 4) {
        color = color + new_shade;  
    } 
    return color;
}

// Copy a certain canvas ans paste on elsewhere.
void copyPaste(int canvas[N_ROWS][N_COLS]) {
    
    int start_row, start_col, length, direction, target_row, target_col;
    scanf("%d %d %d %d %d %d", &start_row, &start_col, &length, &direction, &target_row, &target_col);

    // Transfer length and direction to standard value before input test.
    if (length < 0) {
        length = length * (-1);
        direction = direction + 180;
    } 
    direction = direction % 360;
    
    // Test and decide if they can be copied and pasted.
    int copyValid = copycheck(start_row, start_col, length, direction, target_row, target_col);
    if (copyValid == 1) {
        if (direction == DOWN) {
            int i = 0;
            while (i < length) {
                canvas[target_row + i][target_col] = canvas[start_row + i][start_col];
                i++;
            }
        } else if (direction == UP) {
            int i = 0;
            while (i < length) {
                canvas[target_row - i][target_col] = canvas[start_row - i][start_col];
                i++;
            }
        } else if (direction == RIGHT) {
            int i = 0;
            while (i < length) {
                canvas[target_row][target_col + i] = canvas[start_row][start_col + i];
                i++;
            }
        } else if (direction == LETF) {
            int i = 0;
            while (i < length) {
                canvas[target_row][target_col - i] = canvas[start_row][start_col - i];
                i++;
            }
        } else if (direction == TOP_RIGHT) {
            int i = 0;
            while (i < length) {
                int j = 0;
                while (j < length) {
                    canvas[target_row - i][target_col + j] = canvas[start_row - i][start_col + j];
                    j++;
                }
            i++;
            }
        } else if (direction == BOTTOM_LEFT) {
            int i = 0;
            while (i < length) {
                int j = 0;
                while (j < length) {
                    canvas[target_row + i][target_col - j] = canvas[start_row + i][start_col - j];
                    j++;
                }
            i++;
            }
        } else if (direction == TOP_LEFT) {
            int i = 0;
            while (i < length) {
                int j = 0;
                while (j < length) {
                    canvas[target_row - i][target_col - j] = canvas[start_row - i][start_col - j];
                    j++;
                }
            i++;
            }
        } else if (direction == BOTTOM_RIGHT) {
            int i = 0;
            while (i < length) {
                int j = 0;
                while (j < length) {
                    canvas[target_row + i][target_col + j] = canvas[start_row + i][start_col + j];
                    j++;
                }
            i++;
            }
        }    
    }   
}

// Check if inputs in draw line and square are valid.
// if any pixel in the operation of certain angle and length would be outside the canvas,
// the input is invalid. 
int check(int start_row, int start_col, int length, int direction) {
    if (start_row >= 0 && start_row < N_ROWS && start_col >= 0 && start_col < N_COLS) {
        if (direction == DOWN && start_row + length <= N_ROWS) {
            return 1;
        } else if (direction == UP && start_row - length >= -1) {
            return 1;
        } else if (direction == RIGHT && start_col + length <= N_COLS) {
            return 1;
        } else if (direction == LETF && start_col - length >= -1) {
            return 1;
        } else if (direction == TOP_RIGHT && start_row - length >= -1 && start_col + length <= N_COLS) {
            return 1;
        } else if (direction == BOTTOM_LEFT && start_row + length <= N_ROWS && start_col - length >= -1) {
            return 1;
        } else if (direction == TOP_LEFT && start_row - length >= 0 && start_col - length >= -1) {
            return 1;
        } else if (direction == BOTTOM_RIGHT && start_row + length <= N_ROWS && start_col + length <= N_COLS) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

// Check if the inputs in copy and paste are valid.
// if any pixel in the operation of certain angle and length would be outside the canvas,
// the input is invalid.
int copycheck(int start_row, int start_col, int length, int direction, int target_row, int target_col) {
    if (start_row >= 0 && start_row < N_ROWS && start_col >= 0 && start_col < N_COLS 
     && target_row >= 0 && target_row < N_ROWS && target_col >= 0 && target_col < N_COLS) {
        if (direction == DOWN && start_row + length <= N_ROWS && target_row + length <= N_ROWS) {
            return 1;    
        } else if (direction == UP && start_row - length >= -1 && target_row - length >= -1) {
            return 1;
        } else if (direction == RIGHT && start_col + length <= N_COLS && target_col + length <= N_COLS) {
            return 1;
        } else if (direction == LETF && start_col - length >= -1 && target_col - length >= -1) {
            return 1;
        } else if (direction == TOP_RIGHT && start_row - length >= -1 && start_col + length <= N_COLS
                && target_row - length >= -1 && target_col + length <= N_COLS) {
            return 1;
        } else if (direction == BOTTOM_LEFT && start_row + length <= N_ROWS && start_col - length >= -1
                && target_row + length <= N_ROWS && target_col - length >= -1) {
            return 1;
        } else if (direction == TOP_LEFT && start_row - length >= -1 && start_col - length >= -1
                && target_row - length >= -1 && target_col - length >= -1) {
            return 1;
        } else if (direction == BOTTOM_RIGHT && start_row + length <= N_ROWS && start_col + length <= N_COLS
                && target_row + length <= N_ROWS && target_col + length <= N_COLS) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

// Displays the canvas, by printing the integer value stored in
// each element of the 2-dimensional canvas array.
void displayCanvas(int canvas[N_ROWS][N_COLS]) {
    int row = 0;
    while (row < N_ROWS) {
        int col = 0;
        while (col < N_COLS) {
            printf("%d ", canvas[row][col]);
            col++;
        }
        row++;
        printf("\n");
    }
}

// Sets the entire canvas to be blank, by setting each element in the
// 2-dimensional canvas array to be WHITE.
void clearCanvas(int canvas[N_ROWS][N_COLS]) {
    int row = 0;
    while (row < N_ROWS) {
        int col = 0;
        while (col < N_COLS) {
            canvas[row][col] = WHITE;
            col++;
        }
        row++;
    }
}

// Calculate the distance between two points (row1, col1) and (row2, col2).
double distance(int row1, int col1, int row2, int col2) {
    int row_dist = row2 - row1;
    int col_dist = col2 - col1;
    return sqrt((row_dist * row_dist) + (col_dist * col_dist));
}

