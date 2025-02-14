# def valid(pattern, towels):
#     if len(pattern) == 0:
#         return True
#     for a in towels:
#         if pattern.startswith(a):
#             if valid(pattern[len(a):], towels):
#                 return True
#     return False

# def main():
#     with open("input.txt", "r") as file:
#         lines = file.readlines()
#         towels = [ a.strip() for a in lines[0].split(", ")]
#         cnt = 0
#         for line in lines[2:]:
#             if valid(line.strip(), towels):
#                 cnt += 1
#         print(cnt)

cache = {}

def valid(pattern, towels):
    if pattern in cache:
        return cache[pattern]
    if len(pattern) == 0:
        return 1
    cnt = 0
    for a in towels:
        if pattern.startswith(a):
            if pattern in cache:
                res = cache[pattern]
                cnt += res
            else:
                res = valid(pattern[len(a):], towels)
                cnt += res
    cache[pattern] = cnt
    return cnt

def main():
    with open("input.txt", "r") as file:
        lines = file.readlines()
        towels = [ a.strip() for a in lines[0].split(", ")]
        cnt = 0
        for line in lines[2:]:
            cnt += valid(line.strip(), towels)
        print(cnt)

if __name__ == "__main__":
    main()
