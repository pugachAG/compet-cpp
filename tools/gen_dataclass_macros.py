CLASS_NAME = "class_name"

def var_type(i):
    return f"var_type_{i+1}"

def var_name(i):
    return f"var_name_{i+1}"

def macro_name(i=None):
    return "DATACLASS" + ("" if i is None else f"_{i+1}")

def other_param():
    return f"const {CLASS_NAME}& other"

def operator_with_other_decl(operator, return_type="bool"):
    return f"{return_type} operator{operator}({other_param()}) const"

def join_params(ps):
    return ', '.join(ps)

def flatten(l):
    return sum(l, [])

class Generator:
    def __init__(self) -> None:
        self.lines = list()

    def gen_file(self):
        self.add_line('#include "macro.h"')
        self.add_empty_line()
        var_cnt = 2
        for var_cnt in range(1, var_cnt+1):
            self.gen_dataclass(var_cnt)
            self.add_empty_line()
        self.gen_selector(var_cnt)
    
    def gen_selector(self, var_cnt):
        seq = [f"_{i+1}" for i in range(2*var_cnt + 1)]
        get_name_helper = "_GET_DATACLASS_NAME"
        self.add_line(
            f"#define {get_name_helper}({join_params(seq)}, NAME, ...) NAME"
        )
        names = reversed(flatten([2*[macro_name(i)] for i in range(var_cnt)]))
        self.add_line(
            f"#define DATACLASS(...) {get_name_helper}(__VA_ARGS__, {join_params(names)})(__VA_ARGS__)"
        )
    
    def gen_dataclass(self, var_cnt):
        vars = flatten([var_type(i), var_name(i)] for i in range(var_cnt))
        self.add_macro_line(
            f"#define DATACLASS_{var_cnt}({CLASS_NAME}, {join_params(vars)}) struct {CLASS_NAME} {{",
            ident=0
        )
        for i in range(var_cnt):
            self.add_macro_line(
                f"{var_type(i)} {var_name(i)};",
                ident=1
            )
        self.add_macro_empty_line()
        self.gen_contstructor(var_cnt)
        self.add_macro_empty_line()
        self.gen_eq_operator(var_cnt)
        self.add_macro_empty_line()
        self.gen_not_eq_operator()
        self.add_macro_empty_line()
        self.gen_less_operator(var_cnt)
        self.add_macro_line("}", ident=0, last=True)

    def gen_contstructor(self, var_cnt):
        params = join_params(f"{var_type(i)} {var_name(i)}" for i in range(var_cnt))
        inits = join_params(f"{var_name(i)}({var_name(i)})" for i in range(var_cnt))
        self.start_func(f"{CLASS_NAME}({params}): {inits}")
        self.end_func()
    
    def gen_eq_operator(self, var_cnt):
        self.start_func(operator_with_other_decl("=="))
        eq = " && ".join(f"{var_name(i)} == other.{var_name(i)}" for i in range(var_cnt))
        self.add_macro_line(
            f"return {eq};",
            ident=2
        )
        self.end_func()

    def gen_not_eq_operator(self):
        self.start_func(operator_with_other_decl("!="))
        self.add_macro_line(
            f"return !(*this == other);",
            ident=2
        )
        self.end_func()

    def gen_less_operator(self, var_cnt):
        self.start_func(operator_with_other_decl("<"))
        for i in range(var_cnt):
            var = var_name(i)
            for (op, res) in [("<", "true"), (">", "false")]:
                self.add_macro_line(
                    f"if ({var} {op} other.{var}) {{",
                    ident=2
                )
                self.add_macro_line(f"return {res};", ident=3);
                self.add_macro_line("}", ident=2);
        self.add_macro_line("return false;", ident=2);
        self.end_func()

    def start_func(self, decl):
        self.add_macro_line(decl + " {", ident=1)

    def end_func(self):
        self.add_macro_line("}", ident=1)

    def add_macro_line(self, ln, ident, last=False):
        self.add_line(ln if last else ln + "\\" , ident)

    def add_macro_empty_line(self):
        self.add_macro_line("", 0)

    def add_line(self, ln, ident=0):
        self.lines.append("    " * ident + ln)

    def add_empty_line(self):
        self.add_line("", 0)


def write_lines(filename, lines):
    with open(filename, "w") as file:
        file.writelines(line + "\n" for line in lines)

def main():
    gen = Generator()
    gen.gen_file()
    write_lines("utils/dataclass.h", gen.lines)


if __name__ == '__main__':
    main()