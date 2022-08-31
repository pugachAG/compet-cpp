#ifndef SIMPLE_GRAPH_H
#define SIMPLE_GRAPH_H

#include "../../core/defs.h"
#include "../../utils/rng.h"

class simple_graph {
public:
    simple_graph(i32 sz): _g(sz) {
    }

    void add_edge(i32 v, i32 u, bool bidirectional=true) {
        _g[v].push_back(u);
        if (bidirectional) {
            _g[u].push_back(v);
        }
    }

    vec<i32>& adj(i32 v) {
        return _g[v];
    }

    vec<vec<i32>> connected_components() {
        i32 n = _g.size();
        vec<bool> visited(n);
        vec<vec<i32>> ans;
        for (i32 v0: rng(n)) {
            if (visited[v0]) {
                continue;
            }
            visited[v0] = true;
            vec<i32> cur = {v0};
            for (i32 i = 0; i < cur.size(); i++) {
                i32 v = cur[i];
                for (i32 u: _g[v]) {
                    if (!visited[u]) {
                        cur.push_back(u);
                        visited[u] = true;
                    }
                }
            }
            ans.push_back(std::move(cur));
        }
        return ans;
    }

private:
    vec<vec<i32>> _g;
};

#endif