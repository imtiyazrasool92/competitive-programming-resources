template<typename T1> T1 power(T1 a, T1 b){
    T1 result = 1;
    while(b > 0){
        if(b&1)result*=a;
        a*=a;
        b/=2;
    }
    return result;
}