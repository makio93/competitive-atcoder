# Pythonで自力実装2、WA

import math

n, p, q = map(int, input().split())
a = list(map(int, input().split()))

# edict = dict()
mulsl = [ dict(), dict(), dict(), dict() ]
mulsr = [ dict(), dict(), dict(), dict() ]
l = int(n / 2)
cnt1 = 0
cnt2 = 0

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
                        cnt1 += 1

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
                        cnt2 += 1

sumr = [ 0, 0, 0, 0 ]
for ri in range(4):
    for rdv in mulsr[ri].values():
        sumr[ri] += rdv

res = cnt1 + cnt2

for li in range(1, 5):
    ri = 5 - li
    for ldi in mulsl[li-1].keys():
        if ldi != 0:
            g = math.gcd(ldi, p)
            if g == 1:
                rdi = q * int(pow(ldi, -1, p)) % p
                if (len(mulsr[ri-1]) > 0) and (rdi in mulsr[ri-1].keys()):
                    res += mulsl[li-1][ldi] * mulsr[ri-1][rdi]
            elif q % g == 0:
                l2, q2, p2 = [ ldi//g, q//g, p//g ]
                rdi = q2 * int(pow(l2, -1, p2)) % p
                if (len(mulsr[ri-1]) > 0) and (rdi in mulsr[ri-1].keys()):
                    res += mulsl[li-1][ldi] * mulsr[ri-1][rdi]
        else:
            if q == 0:
                res += mulsl[li-1][ldi] * sumr[ri-1]

print(res)
