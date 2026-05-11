n = int(input())
for _ in range(n):
    len_s = int(input())
    string_s = input()
    if len_s % 2 == 1:
        print("NO")
    else:
        count_open_bracket = string_s.count('(')
        count_close_bracket = string_s.count(')')
        if count_open_bracket == count_close_bracket:
            print("YES")
        else:
            print("NO")  