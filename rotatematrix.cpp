template<typename T>
void rotate90Left(vector<vector<T>> &A)
{
    const int N = (int)A.size();
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            int temp = A[i][j];
            A[i][j] = A[N - 1 - j][i];
            A[N - 1 - j][i] = A[N - 1 - i][N - 1 - j];
            A[N - 1 - i][N - 1 - j] = A[j][N - 1 - i];
            A[j][N - 1 - i] = temp;
        }
    }
}