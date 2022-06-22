#include "../../core/defs.h"
#include "../../utils/iter.h"

class simple_graph {
public:
    simple_graph(i32 sz): g(sz) {
    }

    void add_edge(i32 v, i32 u, bool bidirectional=true) {
        g[v].push_back(u);
        if (bidirectional) {
            g[u].push_back(v);
        }
    }

    vec<vec<i32>> connected_components() {
        i32 n = g.size();
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
                for (i32 u: g[v]) {
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
    vec<vec<i32>> g;
};