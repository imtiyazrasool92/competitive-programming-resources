vector<string> compress_matrix(vector<string> &T){
    const int N = (int)T.size();
    int x1 = 300,y1 = 300,x2 = -1,y2 = -1;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(T[i][j] == '#'){
                x1 = min(x1,i);
                x2 = max(x2,i);
                y1 = min(y1,j);
                y2 = max(y2,j);
            }
        }
    }
    vector<string> out(x2 - x1 + 1);
    for(int i = 0 ;i < (x2 - x1 + 1);i++){
        out[i] = string(T[x1].begin() + y1,T[x1].begin() + y2 + 1);x1++;
    }
    return out;
}