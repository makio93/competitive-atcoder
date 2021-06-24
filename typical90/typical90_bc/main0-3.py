# Pythonで自力実装2、WA

import math

n, p, q = map(int, input().split())
a = list(map(int, input().split()))

# edict = dict()
mulsl = [ dict(), dict(), dict(), dict(), dict() ]
mulsr = [ dict(), dict(), dict(), dict(), dict() ]
l = int(n / 2)

for li1 in range(l):
    m1 = a[li1] % p
    mulsl[0][m1] = mulsl[0].get(m1, 0) + 1
    for li2 in range(li1+1, l):
        m2 = m1 * a[li2] % p
        mulsl[1][m2] = mulsl[1].get(m2, 0) + 1
        for li3 in range(li2+1, l):
            m3 = m2 * a[li3] % p
            mulsl[2][m3] = mulsl[2].get(m3, 0) + 1
            for li4 in range(li3+1, l):
                m4 = m3 * a[li4] % p
                mulsl[3][m4] = mulsl[3].get(m4, 0) + 1
                for li5 in range(li4+1, l):
                    m5 = m4 * a[li5] % p
                    if m5 == q:
                        mulsl[4][m5] = mulsl[4].get(m5, 0) + 1

for li1 in range(l, n):
    m1 = a[li1] % p
    mulsr[0][m1] = mulsr[0].get(m1, 0) + 1
    for li2 in range(li1+1, n):
        m2 = m1 * a[li2] % p
        mulsr[1][m2] = mulsr[1].get(m2, 0) + 1
        for li3 in range(li2+1, n):
            m3 = m2 * a[li3] % p
            mulsr[2][m3] = mulsr[2].get(m3, 0) + 1
            for li4 in range(li3+1, n):
                m4 = m3 * a[li4] % p
                mulsr[3][m4] = mulsr[3].get(m4, 0) + 1
                for li5 in range(li4+1, n):
                    m5 = m4 * a[li5] % p
                    if m5 == q:
                        mulsr[4][m5] = mulsr[4].get(m5, 0) + 1

res = mulsl[4].get(q, 0) + mulsr[4].get(q, 0)

for li in range(1, 5):
    ri = 5 - li
    for ldi in mulsl[li-1].keys():
        sum = 0
        for rdi in mulsr[ri-1].keys():
            if ldi * rdi % p == q:
                sum += mulsr[ri-1][rdi]
                if q != 0:
                    break
        res += mulsl[li-1][ldi] * sum

print(res)
