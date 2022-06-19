#ifndef UTILS_TYPE_TRAITS_H
#define UTILS_TYPE_TRAITS_H

template <typename FUNC>
struct return_of;

template <typename RT, typename... AT>
struct return_of<RT(*)(AT...)> {
    using type = RT;
};

template <typename FUNC>
using return_of_t = typename return_of<FUNC>::type;

template <typename FUNC>
struct second_arg_of;

template <typename RT, typename A1T, typename A2T, typename... AT>
struct second_arg_of<RT(*)(A1T, A2T, AT...)> {
    using type = A2T;
};

template <typename FUNC>
using second_arg_of_t = typename second_arg_of<FUNC>::type;

#endif