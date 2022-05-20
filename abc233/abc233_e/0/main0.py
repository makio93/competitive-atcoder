# 本番WA

strx = input()

nval = 0
res = 0

for i in range(len(strx)):
    nval = nval * 10 + int(strx[i:i+1])
    res += nval

print(res)
