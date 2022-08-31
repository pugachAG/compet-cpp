from os import path
from pathlib import Path

INCLUDE = "#include"
QUOTE = '"'

def read_lines(filename):
    with open(filename) as file:
        return file.readlines()

def write_lines(filename, lines):
    with open(filename, "w") as file:
        file.writelines(lines)

def enter(res, visited, file_path):
    cur_dir = path.dirname(file_path)
    for line in read_lines(file_path):
        if line.startswith(INCLUDE):
            include = line.strip(INCLUDE).strip()
            if include.startswith(QUOTE):
                include_path = path.relpath(path.join(cur_dir, include.strip(QUOTE)))
                if include_path not in visited:
                    visited.add(include_path)
                    res.append(f"//>> include {include_path} start\n")
                    enter(res, visited, include_path)
                    res.append(f"\n//<< include {include_path} end\n")
                continue
        res.append(line)


def main():
    res = list()
    enter(res, set(), "main.cpp")
    Path("out").mkdir(parents=True, exist_ok=True)
    write_lines("out/submit.cpp", res)

if __name__ == '__main__':
    main()