class Kuhn{
public:
    graph * g;
    int * pa;
    int * pb;
    int * was;
    int n, m;
    int res;
    int iter;
    Kuhn(graph * g, int n, int m){
        this-> g = g;
        this-> n = n;
        this-> m = m;
        walloc1d(&this->pa, n); rep(i, n) this->pa[i] = -1;
        walloc1d(&this->pb, m); rep(i, m) this->pb[i] = -1;
        walloc1d(&this->was, n); rep(i,n) this->was[i] = 0;
        res = 0;
        iter = 0;
    }

    bool dfs(int v){
        was[v] = iter;
        rep[g->edge[v]](u, g->es[v]){
            if(pb[u] == -1){
                pa[v] = u;
                pb[u] = v;
                return true;
            }
        }
        rep[g->edge[v]](u, g->es[v]){
            if(was[pb[u]] != iter && dfs(pb[u])){
                pa[v] = u;
                pb[u] = v;
                return true;
            }
        }
        return false;
    }
    int solve(){
        while(true){
            ++iter;
            int add = 0;
            rep(i, n) if(pa[i] == -1 && dfs(i)) ++add;
            if(add == 0) break;
            res += add;
        }
        return res;
    }
    int run_one(int v){
        if(pa[v] != -1) return 0;
        ++iter;
        return (int) dfs(v);
    }
};
