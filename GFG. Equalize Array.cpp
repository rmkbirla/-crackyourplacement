const int MOD = 1000000007;

int equalizeArray(int N, int k, int A[]) {
  
    int* A_copy = new int[N];
    for (int i = 0; i < N; i++) {
        A_copy[i] = A[i];
    }
    std::sort(A_copy, A_copy + N);
    int target = A_copy[N / 2];
    delete[] A_copy;

    int totalMoves = 0;
    for (int i = 0; i < N; i++) {
        int moves = abs(A[i] - target) / k;
        if (abs(A[i] - target) % k != 0) {
            return -1; // It is not possible to make all elements equal
        }
        totalMoves = (totalMoves+ moves) %MOD;
    }

    return totalMoves % MOD;
}
