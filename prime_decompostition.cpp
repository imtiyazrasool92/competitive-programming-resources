vector<pair<int, int>> prime_decomposition(int64_t A) {
    vector<pair<int, int>> result;
    for (int64_t i = 2; i * i <= A; i++) {
        if (A % i == 0)
            result.push_back({i, 0});
        while (A % i == 0) {
            result.back().second++;
            A /= i;
        }
    }
    if (A > 1)
        result.push_back({A, 1});
    return result;
}