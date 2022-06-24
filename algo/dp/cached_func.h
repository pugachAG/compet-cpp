#include "../../core/defs.h"

/*
struct comb: func_cache<comb, i32, i32, i32> {
	i32 impl(i32 i, i32 j) {
		if (i == j || j == 0) {
			return 1;
		}
		return calc(i-1, j) + calc(i-1, j-1);
	}
};
*/

template <class IMPL, class RET, class... ARGS>
class func_cache {
public:
    func_cache() {
    }

	RET calc(ARGS... args) {
		auto args_tuple = std::make_tuple(args...);
		auto it = _cache.find(args_tuple);
		if (it != _cache.end()) {
			return it->second;
		}
		RET result = static_cast<IMPL*>(this)->impl(args...);
		_cache[args_tuple] = result;
		return result;
	}
 
private:
	hash_map<std::tuple<ARGS...>, RET> _cache;
};