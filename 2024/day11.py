def p1():
    with open("input.txt", "r") as file:
        stones = []
        for s in file:
            stones = [int(i) for i in s.split(" ")]

        for _ in range(75):
            newl = []
            for i in stones:
                if i == 0:
                    newl.append(1)
                elif len(str(i)) % 2 == 0:
                    newl.append(int(str(i)[:int(len(str(i))/2)]))
                    newl.append(int(str(i)[int(len(str(i))/2):]))
                else:
                    newl.append(i*2024)
                # print( _ , i)
            stones = newl
        print(len(newl))

def p2():
    with open("input.txt", "r") as file:
        stones = []
        for s in file:
            stones = [int(i) for i in s.split(" ")]

        cache = {}
        def dfs(num, depth):
            if depth == 75:
                return 1
            if num in cache and depth in cache[num]:
                return cache[num][depth]
            total = 0
            a = 0
            if num == 0:
                a = dfs(1, depth+1)
            elif len(str(num)) %2 == 0:
                s = str(num)
                a = dfs(int(s[:int(len(s)/2)]), depth+1) + dfs(int(s[int(len(s)/2):]), depth+1)
            else:
                a = dfs(num*2024, depth+1)
            total += a
            if num not in cache:
                cache[num] = {}
            cache[num][depth] = a
            return total

        ans = 0
        for i in stones:
            ans += dfs(i, 0)
        print(ans)

if __name__ == "__main__":
    p2()