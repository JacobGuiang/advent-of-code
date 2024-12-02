import os

dir = os.path.dirname(os.path.abspath(__file__))
input = open(os.path.join(dir, "input.txt"), "r")
output = open(os.path.join(dir, "output.txt"), "w")


def solve1():
    pass


def solve2():
    pass


def main():
    output.write(str(solve1()) + "\n")
    input.seek(0)
    output.write(str(solve2()) + "\n")

    input.close()
    output.close()


if __name__ == "__main__":
    main()
