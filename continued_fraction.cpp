double solveContinuedFraction(vector<double> A) {
    const int N = (int)A.size();
    for (auto &a : A)
        cin >> a;
    for (int i = N - 2; i >= 0; i--) {
        A[i] += 1 / A[i + 1];
    }
    return A[0];
}