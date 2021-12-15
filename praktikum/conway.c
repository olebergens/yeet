#define X_DIMENSION 20
#define Y_DIMENSION 20

#define ALIVE '#'
#define DEAD ' '

int live_neighbour_cell(char f[X_DIMENSION][Y_DIMENSION], int r, int c) {
    int i, j , count = 0;
    for (i = r - 1; i <= r + 1; i++) {
        for (j = c - 1; j <= c + 1; j++) {
            if ((i == r && j == c) || (i < 0 || j < 0) || (i >= X_DIMENSION || j >= Y_DIMENSION)) continue;
            if (f[i][j] == ALIVE){
                count++;
            }
        }
    }
    return count;
}

char next_cell_state(int x, int y, char f[X_DIMENSION][Y_DIMENSION]) {
    int count;
    count = live_neighbour_cell(f, x, y);
    if (f[x][y] == ALIVE && (count == 2 || count == 3)) return ALIVE;
    else if (f[x][y] == DEAD && count == 3) return ALIVE;
    else return DEAD;
}

void step_field(char f[X_DIMENSION][Y_DIMENSION]) {
    char tmp[X_DIMENSION][Y_DIMENSION];
    int x, y;
    for (x = 0; x < X_DIMENSION; x++) {
        for (y = 0; y < Y_DIMENSION; y++) {
            tmp[x][y] = next_cell_state(x, y, f);
        }
    }
    for (x = 0; x < X_DIMENSION; x++) {
        for (y = 0; y < Y_DIMENSION; y++) {
            f[x][y] = tmp[x][y];
        }
    }
}

void init_field(char f[X_DIMENSION][Y_DIMENSION]) {
    for (int i = 0; i < X_DIMENSION; i++) {
        for (int j = 0; j < Y_DIMENSION; j++) {
            if (rand() % 2 == 0) f[i][j] = DEAD;
            else f[i][j] = ALIVE;
        }
    }
}

void row() {
    printf("\n");
    for (int i = 0; i < X_DIMENSION; i++) printf(" ---");
    printf("\n");
}

void print_field(char f[X_DIMENSION][Y_DIMENSION]) {
    row();
    for (int i = 0; i < X_DIMENSION; i++) {
        printf(":");
        for (int j = 0; j < Y_DIMENSION; j++) printf(" %c :", f[i][j]);
        row();
    }
}