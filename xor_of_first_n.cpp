template<typename T> T xor_of_first_n(T n) {
    assert(n >= 0);
 
    switch (n % 4) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        case 3: return 0;
    }
 
    assert(false);
}