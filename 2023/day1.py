# def main():
#     with open("input.txt", "r") as file:
#         ans = 0
#         for line in file:
#             d1 = ''
#             d2 = ''
#             for c in line:
#                 if c.isdigit():
#                     if d1 == '':
#                         d1 = c
#                         break
#             for c in reversed(line):
#                 if c.isdigit():
#                     if d2 == '':
#                         d2 = c
#                         break
#             ans += int(d1 + d2)
#         print(ans)


# if __name__ == "__main__":
#     main()

import re

def main():
    words_to_numbers = {
                    'one': 1, 'two': 2, 'three': 3, 'four': 4, 'five': 5,
                    'six': 6, 'seven': 7, 'eight': 8, 'nine': 9
                }
    with open("input.txt", "r") as file:
        ans = 0
        pattern = re.compile(r"(?=(\d|one|two|three|four|five|six|seven|eight|nine))")
        for line in file:
            matches = pattern.findall(line)
            n1 = -1
            n2 = -1
            if matches[0].isdigit():
                n1 = int(matches[0])
            else:
                n1 = words_to_numbers.get(matches[0], 0)
            
            if matches[-1].isdigit():
                n2 = int(matches[-1])
            else:
                n2 = words_to_numbers.get(matches[-1], 0)
            ans += int(str(n1) + str(n2))
        print(ans)


if __name__ == "__main__":
    main()