
vector<pair<int, int>> prime_decomposition(int value) {

    vector<pair<int, int>> primes;

    for (int64_t i = 2; i * i <= value; i++) {
        if (value % i == 0) {
            primes.push_back({i, 0});
        }
        while (value % i == 0)
            primes.back().second++;
    }

    return primes;

}