def p1():
    with open("input.txt", "r") as file:
        ans = 0
        for str in file:
            cnt = 0
            slots = []
            l = []
            for indx, char in enumerate(str):
                num = int(char)
                if(indx %2 == 0):
                    cnt += num
                    for i in range(num):
                        l.append(indx/2)
                else:
                    for i in range(num):
                        l.append('.')

            ind = 0
            for i, a in enumerate(l[:cnt]):
                if a != '.':
                    ans += int(a) * i
                else:
                    slots.append(i)
            for i in range(len(l) - 1, cnt - 1, -1):
                a = l[i]
                if a != '.':
                    ans += int(a) * slots[ind]
                    ind += 1
            print(ans)

def p2():
    with open("input.txt", "r") as file:
        ans = 0
        l = []
        for str in file:
            l = [int(char) for char in str.strip()]
        slots = []
        ind = 0
        for i, a in enumerate(l):
            if i %2 != 0:
                slots.append((ind, a))
            ind += a
        
        final = [] # index, value, number of times
        for i in range(len(l)-1, -1, -1):
            ind -= l[i]
            if i % 2 == 0:
                num = int(i/2)
                replaced = False
                for slot_ind, (a, b) in enumerate(slots):
                    if a >= ind:
                        break
                    if b >= l[i]:
                        final.append((a, num, l[i]))
                        slots[slot_ind] = (a + l[i], b - l[i])
                        replaced = True
                        break
                if not replaced:
                    final.append((ind, num, l[i]))

        for (index, val, times) in final:
            for i in range(index, index + times, 1):
                ans += i * val               

        # print(final)
        print(ans)
if __name__ == "__main__":
    p2()