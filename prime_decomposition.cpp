vector<int> prime_decomposition(long long N) {
    vector<int> primes;
    for (int i = 2; i * (long long) i <= N; i++) {
        while (N % i == 0) {
            primes.push_back(i);
            N /= i;
        }
    }
    if (N > 1)
        primes.push_back(N);
    return primes;
}