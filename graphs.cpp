/*Allowing Dynamically adding edges*/

void clear_edge(graph *g){
    int N = g->N;
    rep(i,N) g->es[i] = 0;
}
void add_edge(graph *g, int x, int y){
    int ** edge = g->edge;
    int * es = g->es;
    edge[x][es[x]++] = y;
    edge[y][es[y]++] = x;
}

/*Bipartite Fixes: original code didn't take into account of changing variable i.e. the code use the same variable for the bfs and looping*/

int bipartite(int res[] = NULL, void *mem = wmem){
  int i;
  int j;
  int k;
  int x;
  int*st;
  int sts;
  if(res==NULL){
    walloc1d(&res, N, &mem);
  }
  walloc1d(&st, N, &mem);
  for(i=(0);i<(N);i++){
    res[i] = -1;
  }
  for(i=(0);i<(N);i++){
    if(res[i]==-1){
      res[i] = 0;
      sts = 0;
      st[sts++] = i;
      while(sts){
        x = st[--sts];
        for(j=(0);j<(es[x]);j++){
          k = edge[x][j];
          if(res[k]==-1){
            res[k] = 1 - res[x];
            st[sts++] = k;
          }
          if(res[x] + res[k] != 1){
            return 0;
          }
        }
      }
    }
  }
  return 1;
}
