# Pythonで自力実装1、TLE

n, p, q = map(int, input().split())
a = list(map(int, input().split()))

cnt = 0
for i1 in range(n):
    m1 = a[i1] % p
    for i2 in range(i1+1, n):
        m2 = m1 * a[i2] % p
        for i3 in range(i2+1, n):
            m3 = m2 * a[i3] % p
            for i4 in range(i3+1, n):
                m4 = m3 * a[i4] % p
                for i5 in range(i4+1, n):
                    m5 = m4 * a[i5] % p
                    if m5 == q:
                        cnt += 1
print(cnt)
