//working_memory=100m
int  n,q, a[3d5+10], L[], R[], g[], cnt[], ans[];
class getmax{
public:   
    int mx;
    getmax(){
        mx = 0;
    }
    int& ct(int x){
        return cnt[x+4];
    }
    void addval(int x){ 
        --ct(g[x]);
        ++g[x];
        ++ct(g[x]);
        if(g[x] > mx) mx = g[x];
    }
    void delval(int x){
        --ct(g[x]);
        if(g[x] == mx && ct(g[x]) == 0) mx = g[x]-1;
        --g[x];
        ++ct(g[x]);
    }
    void change(int pos, int x){
        if(x == 1){
            x = a[pos];
            addval(x);
        }else{
            x = a[pos];
            delval(x); 
        }
    }
    void modify(int pos, int x, int l, int r){

    }
};


{
    rd(n, q, a(n), (L--,R--)(q));
    sqrt_decomp<getmax> sdg;
    sdg.sinit(q+30, sqrt(n),0);
    sdg.transfer(q, L, R, NULL);
    int id = 0;
    int l = 1, r = 0, cl = 0, cr= 0;
    while((id = sdg.next(l, r, cl ,cr)) != -1){
        int ivl = R[id] - L[id] + 1; 
        int moc = sdg.a->mx;
        ans[id] = 1;
        ans[id] >?= moc - (ivl -moc);
    }
    rep(i, q) wt(ans[i]);
}
