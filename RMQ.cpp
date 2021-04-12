// The following template is accredited to Neal Wu.
// I have rewritten it so it fits more for cLay
#define default_empty ={}
#define default_zero =0
#define get_query_value  T query_value(int a, int b){  return values[query_index(a, b)];}
template<typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0;
    vector<T> values;
    vector<vector<int>> range_low;
    RMQ(const vector<T> &_values default_empty) {
        if (!_values.empty())
            build(_values);
    }
    RMQ(T * _values default_zero, int sz default_zero){
        vector<T> _v;
        rep(i,sz){
            _v.push_back(_values[i]);
        }
        if(sz > 0)
        {
            build(_v);
        }
    }
    static int highest_bit(int x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    int better_index(int a, int b)  {
        return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
    }
    void build(const vector<T> &_values) {
        values = _values;
        n = int(values.size());
        int levels = highest_bit(n) + 1;
        range_low.resize(levels);
 
        for (int k = 0; k < levels; k++)
            range_low[k].resize(n - (1 << k) + 1);
 
        for (int i = 0; i < n; i++)
            range_low[0][i] = i;
 
        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_low[k][i] = better_index(range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
    }
        // Note: breaks ties by choosing the largest index.
    int query_index(int a, int b) {
        assert(0 <= a && a < b && b <= n);
        int level = highest_bit(b - a);
        return better_index(range_low[level][a], range_low[level][b - (1 << level)]);
    }
    get_query_value;

};
