#include "macro.h"

#define DATACLASS_1(class_name, var_type_1, var_name_1) struct class_name {\
    var_type_1 var_name_1;\
\
    class_name() {\
    }\
\
    class_name(var_type_1 var_name_1): var_name_1(var_name_1) {\
    }\
\
    bool operator==(const class_name& other) const {\
        return var_name_1 == other.var_name_1;\
    }\
\
    bool operator!=(const class_name& other) const {\
        return !(*this == other);\
    }\
\
    bool operator<(const class_name& other) const {\
        if (var_name_1 < other.var_name_1) {\
            return true;\
        }\
        if (var_name_1 > other.var_name_1) {\
            return false;\
        }\
        return false;\
    }\
\
    bool operator>(const class_name& other) const {\
        return *this != other && !(*this < other);\
    }\
}

#define DATACLASS_2(class_name, var_type_1, var_name_1, var_type_2, var_name_2) struct class_name {\
    var_type_1 var_name_1;\
    var_type_2 var_name_2;\
\
    class_name() {\
    }\
\
    class_name(var_type_1 var_name_1, var_type_2 var_name_2): var_name_1(var_name_1), var_name_2(var_name_2) {\
    }\
\
    bool operator==(const class_name& other) const {\
        return var_name_1 == other.var_name_1 && var_name_2 == other.var_name_2;\
    }\
\
    bool operator!=(const class_name& other) const {\
        return !(*this == other);\
    }\
\
    bool operator<(const class_name& other) const {\
        if (var_name_1 < other.var_name_1) {\
            return true;\
        }\
        if (var_name_1 > other.var_name_1) {\
            return false;\
        }\
        if (var_name_2 < other.var_name_2) {\
            return true;\
        }\
        if (var_name_2 > other.var_name_2) {\
            return false;\
        }\
        return false;\
    }\
\
    bool operator>(const class_name& other) const {\
        return *this != other && !(*this < other);\
    }\
}

#define _GET_DATACLASS_NAME(_1, _2, _3, _4, _5, NAME, ...) NAME
#define DATACLASS(...) _GET_DATACLASS_NAME(__VA_ARGS__, DATACLASS_2, DATACLASS_2, DATACLASS_1, DATACLASS_1)(__VA_ARGS__)
