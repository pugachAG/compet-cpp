#ifndef LCA_TREE_H
#define LCA_TREE_H

#include "../../core/defs.h"
#include "../../utils/rng.h"

class lca_tree {
public:
    lca_tree(i32 n): _g(n), _bin_anc(n), _vis(n) {
    }

    void add_edge(i32 v, i32 u) {
        _g[v].push_back(u);
        _g[u].push_back(v);
    }

    void init_lca(i32 root = 0) {
        _dfs(root, -1);
    }

    bool is_ancestor(i32 p, i32 v) {
        i32 tm_v = _vis[v].first;
        auto vis_p = _vis[p];
        return vis_p.first <= tm_v && tm_v < vis_p.second;
    };

    bool lca(i32 v, i32 u) {
        return _lift(v, u);
    }

private:
    i32 _tm = 0;
    vec<vec<i32>> _g;
    vec<vec<i32>> _bin_anc;
    vec<pair<i32, i32>> _vis;

    void _dfs(i32 v, i32 p) {
        _vis[v].first = _tm++;
        auto &ps = _bin_anc[v];
        i32 cur_p = p;
        while (cur_p != -1) {
            i32 pw = ps.size();
            ps.emplace_back(cur_p);
            auto &nxt_ps = _bin_anc[cur_p];
            if (pw < nxt_ps.size()) {
                cur_p = nxt_ps[pw];
            } else {
                cur_p = -1;
            }
        }
        for (auto u: _g[v]) {
            if (u != p) {
                _dfs(u, v);
            }
        }
        _vis[v].second = _tm;
    }

    i32 _lift(i32 v, i32 u) {
        if (is_ancestor(v, u)) {
            return v;
        }
        i32 cur = v;
        for (i32 pw: rev(rng(_bin_anc[v].size()))) {
            auto &ps = _bin_anc[cur];
            if (ps.size() <= pw) {
                continue;
            }
            i32 nxt = ps[pw];
            if (is_ancestor(nxt, u)) {
                continue;
            }
            cur = nxt;
        }
        return _bin_anc[cur][0];
    }
};

#endif