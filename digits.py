
with open('pi500.txt', 'r') as f:
    s = f.read()
    i = 0
    while i < len(s):
        i_str = str(i)
        if(i_str == s[i+1 : i+1+len(i_str)]):
            print(i_str)
        i += 1

f.closed

