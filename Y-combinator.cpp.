// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html

#define Arguments ...Args
#define all_defined_y_combo     template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
#define arguments_y_combo     template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
#define template_for_y_comb template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    all_defined_y_combo ;
    arguments_y_combo;
};

template_for_y_comb;
