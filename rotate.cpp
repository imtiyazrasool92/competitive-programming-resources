template<class T>
void rotateRight(T &A,int d){
    const int N = (int)A.size();
    reverse(A.begin(),A.begin() + N - d);
    reverse(A.begin() + N - d,A.end());
    reverse(A.begin(),A.end());
}

template<class T>
void rotateLeft(T &A,int d){
    const int N = (int)A.size();
    reverse(A.begin(),A.end());
    reverse(A.begin(),A.begin() + N - d);
    reverse(A.begin() + N - d,A.end());
}