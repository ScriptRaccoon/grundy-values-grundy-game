import time


def get_grundys(limit: int) -> list[int]:
    """
    Computes the Grundy values of Grundy's Game.
    """
    g = [0] * (limit + 1)
    gseen = [0] * (limit + 1)

    for n in range(limit + 1):
        a = 1
        while 2 * a < n:
            x = g[a] ^ g[n - a]
            if 2 * x < n:
                gseen[x] = n + 1
            a += 1

        mex = 0
        while gseen[mex] == n + 1:
            mex += 1

        g[n] = mex

    return g


# performance test
before = time.time()
grundys = get_grundys(100000)
print(grundys[-1])  # 101
after = time.time()
print("computation time (s):", after - before)  # 165 seconds
