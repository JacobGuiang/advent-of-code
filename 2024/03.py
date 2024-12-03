import os
import re

dir = os.path.dirname(os.path.abspath(__file__))
input = open(os.path.join(dir, "input.txt"), "r")
output = open(os.path.join(dir, "output.txt"), "w")


def solve1():
    res = 0
    matches = re.findall("mul\\(\\d+,\\d+\\)", input.read())
    for m in matches:
        a = int(m[4 : m.find(",")])
        b = int(m[m.find(",") + 1 : m.find(")")])
        res += a * b
    return res


def solve2():
    res = 0
    do = True
    matches = re.findall("mul\(\d+,\d+\)|do\(\)|don't\(\)", input.read())
    for m in matches:
        if m == "do()":
            do = True
        elif m == "don't()":
            do = False
        elif do:
            a = int(m[4 : m.find(",")])
            b = int(m[m.find(",") + 1 : m.find(")")])
            res += a * b
    return res


def main():
    output.write(str(solve1()) + "\n")
    input.seek(0)
    output.write(str(solve2()) + "\n")

    input.close()
    output.close()


if __name__ == "__main__":
    main()
