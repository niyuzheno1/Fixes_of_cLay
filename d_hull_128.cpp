const long long is_query_G = -(1LL<<62);
struct line_G{
  __int128 m;
  __int128 b;
  mutable function<const line_G*()> succ;
}
;
bool operator<(const line_G& lhs, const line_G& rhs){
  if (rhs.b != is_query_G){
    return lhs.m < rhs.m;
  }
  const line_G* s = lhs.succ();
  if (!s){
    return 0;
  }
  __int128 x = rhs.m;
  return lhs.b - s->b < (s->m - lhs.m) * x;
}
struct dynamic_hull_max : public multiset<line_G>{
  const long long inf = LLONG_MAX;
  bool bad(void * yy){
    iterator * u = (iterator *)yy;
    iterator y = *u;
    auto z = next(y);
    if (y == begin()){
      if (z == end()){
        return 0;
      }
      return y->m == z->m && y->b <= z->b;
    }
    auto x = prev(y);
    if (z == end()){
      return y->m == x->m && y->b <= x->b;
    }
    __int128 v1 = (x->b - y->b);
    if (y->m == x->m){
      v1 = x->b > y->b ? inf : -inf;
    }
    else{
      v1 /= (y->m - x->m);
    }
    __int128 v2 = (y->b - z->b);
    if (z->m == y->m){
      v2 = y->b > z->b ? inf : -inf;
    }
    else{
      v2 /= (z->m - y->m);
    }
    return v1 >= v2;
  }
  void insert_line(__int128 m, __int128 b){
    auto y = insert({ m, b });
    y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
    if (bad((void*)&y)){
      erase(y);
      return;
    }
    while (next(y) != end()){
      auto yy = next(y);
      if(bad((void*)&yy)){
        erase(next(y));
      }
      else{
        break;
      }
    }
    while (y != begin()){
      auto yy = prev(y);
      if(bad((void*)&yy)){
        erase(prev(y));
      }
      else{
        break;
      }
    }
  }
  __int128 eval(__int128 x){
    line_G tmp;
    tmp.b = is_query_G;
    tmp.m = x;
    auto l = *lower_bound(tmp);
    return l.m * x + l.b;
  }
}
;
struct dynamic_hull_min{
  dynamic_hull_max cht;
  void insert_line(__int128 m, __int128 b){
    cht.insert_line(-m, -b);
  }
  __int128 eval(__int128 x){
    return -cht.eval(x);
  }
}
;
