def p1():
    with open("input.txt", "r") as file:
        ans = 0
        for line in file:
            arr = line.split(' ')
            arr = [x.strip() for x in arr]
            arr[0] = arr[0][:-1]
            arr = [int(x) for x in arr]
            n = len(arr)-2
            for i in range(1 << n):
                sum = arr[1]
                for ind in range(n):
                    if sum > ans:
                        break
                    # 1 is mult
                    if (1 << ind) & i:
                        sum *= arr[2+ind]
                    # 0 is add
                    else:
                        sum += arr[2+ind]
                if sum == arr[0]:
                    ans += sum
                    break
        print(ans)

def p2():
    with open("input.txt", "r") as file:
        ans = 0
        for line in file:
            arr = line.split(' ')
            arr = [x.strip() for x in arr]
            arr[0] = arr[0][:-1]
            arr = [int(x) for x in arr]
            n = len(arr)-2
            for i in range(3 ** n):
                sum = arr[1]
                for ind in range(n):
                    bit = int((i / (3**ind)) % 3)
                    if sum > arr[0]:
                        break
                    # 1 is mult
                    if bit == 1:
                        sum *= arr[2+ind]
                    # 0 is add
                    elif bit == 0:
                        sum += arr[2+ind]
                    # 2 is comb
                    else:
                        sum = int(str(sum) + str(arr[2+ind]))                        

                if sum == arr[0]:
                    ans += sum
                    break
        print(ans)


if __name__ == "__main__":
    p2()