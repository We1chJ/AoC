def valid(pattern, towels):
    if len(pattern) == 0:
        return True
    for a in towels:
        if pattern.startswith(a):
            if valid(pattern[len(a):], towels):
                return True
    return False

def main():
    with open("input.txt", "r") as file:
        lines = file.readlines()
        towels = [ a.strip() for a in lines[0].split(", ")]
        cnt = 0
        for line in lines[2:]:
            if valid(line.strip(), towels):
                cnt += 1
        print(cnt)
if __name__ == "__main__":
    main()
