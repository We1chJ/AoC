import re

def main():
    with open("input.txt", "r") as file:
        pattern = re.compile(r"mul\((\d{1,3}),(\d{1,3})\)")
        ans = 0
        big_line = ''.join(file.readlines())
        groups = big_line.split('don\'t()')
        for g in groups:
            if groups.index(g) != 0:
                ind = g.find('do()')
                if ind == -1:
                    continue
                g = g[ind + len('do()'):]

            matches = pattern.findall(g)
            for match in matches:
                ans += int(match[0]) * int(match[1])
        print(ans)

if __name__ == "__main__":
    main()