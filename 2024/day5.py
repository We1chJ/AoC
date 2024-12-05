import re

def p1():
    with open("input.txt", "r") as file:
        rules = {}
        next = False
        ans = 0
        incorrect = []
        for line in file:
            if line == '\n':
                next = True
                continue
            line = line.strip()
            if next == False:
                temp = list(map(int, line.split('|')))
                if temp[0] not in rules:
                    rules[temp[0]] = []
                rules[temp[0]].append(temp[1])
            else:
                pages = list(map(int, line.split(',')))
                seen_pages = set()
                valid = True
                for p in pages:
                    if p in rules:
                        for after in rules[p]:
                            if after in seen_pages:
                                valid = False
                                break
                    if not valid:
                        incorrect.append(pages)
                        break
                    seen_pages.add(p)
                if valid:
                    ans += int(pages[int(len(pages)/2)])
    print(ans)
    
def p2():
    with open("input.txt", "r") as file:
        rules = {}
        next = False
        ans = 0
        incorrect = []
        for line in file:
            if line == '\n':
                next = True
                continue
            line = line.strip()
            if next == False:
                temp = list(map(int, line.split('|')))
                if temp[0] not in rules:
                    rules[temp[0]] = []
                rules[temp[0]].append(temp[1])
            else:
                pages = list(map(int, line.split(',')))
                seen_pages = set()
                valid = True
                for p in pages:
                    if p in rules:
                        for after in rules[p]:
                            if after in seen_pages:
                                valid = False
                                break
                    if not valid:
                        incorrect.append(pages)
                        break
                    seen_pages.add(p)
                if valid:
                    ans += int(pages[int(len(pages)/2)])
    # print(ans)
    ans = 0
    for tc in incorrect:
        res = []
        for a in tc:
            ind = len(res)
            for i in range(len(res) - 1, -1, -1):
                if a in rules and res[i] in rules[a]:
                    ind = i
            res.insert(ind, a)

        ans += res[int(len(res)/2)]
        
    print(ans)

if __name__ == "__main__":
    p2()