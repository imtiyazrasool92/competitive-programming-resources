template<typename T_container>
Mint modular_lcm(T_container A) {
    const int N = (int)A.size();
    map<int, int>highest_power;
    for (int i = 0; i < N; i++) {
        map<int, int> current_power;
        for (int j = 2; j * (long long)j <= A[i]; j++) {
            while (A[i] > 1 && A[i] % j == 0) {
                A[i] /= j;
                current_power[j]++;
            }
        }
        if (A[i] > 1) {
            current_power[A[i]]++;
        }
        for (auto powers : current_power)
            highest_power[powers.first] = max(highest_power[powers.first], powers.second);
    }
    Mint out = 1;
    for (auto P : highest_power) {
        out *= power(Mint(P.first), P.second);
    }
    return out;
}