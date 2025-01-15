#include <iostream>

int** makeMagicSquare(int N, int S) {
    // Allocate a N*N array for the magic square
    int** magic_box = new int*[N];
    for (int i = 0; i < N; i++) {
        magic_box[i] = new int[N] {0}; // Initialize to 0
    }

    // Create standard magic square without target sum
    int num = 1, row = 0, col = N / 2; // Start position

    while (num <= N * N) {
        magic_box[row][col] = num; // Place number

        // Move to the next position
        int newRow = row - 1; if (newRow < 0) newRow = N - 1; // Move up
        int newCol = col + 1; if (newCol >= N) newCol = 0;    // Move right

        // If the position is filled, move down instead
        if (magic_box[newRow][newCol] != 0) row++;
        else { row = newRow; col = newCol; }

        // Increase Num
        num++;
    }

    // Adjust magic square to match  S
    int currentSum = (N * (N * N + 1)) / 2;     // Current magic sum
    int adjustment = (S - currentSum) / N;      // Increase per collunm

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            magic_box[i][j] += adjustment;

    return magic_box;
}

int main_207() {
    int N, S; std::cin >> N >> S;

    int** magic_box = makeMagicSquare(N, S);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << magic_box[i][j] << " ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < N; i++) {
        delete[] magic_box[i];
    }
    delete[] magic_box;

    return 0;
}
