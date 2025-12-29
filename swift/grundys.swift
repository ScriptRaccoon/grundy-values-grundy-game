/**
 * Computes the Grundy values of Grundy's Game.
 */
func get_grundys(limit: Int) -> [Int] {
    var g = [Int](repeating: 0, count: limit + 1)
    var gseen = [Int](repeating: 0, count: limit + 1)
    
    for n in 3...limit {
        // we start from n = 3 since we have g(0) = g(1) = g(2) = 0 anyway
        // and Swift requires that the lower bound for a range is less than
        // or equal to the upper bound
        for a in 1...(n-1)/2 {
            let x = g[a] ^ g[n - a]
            if 2 * x < n {
                gseen[x] = n + 1
            }
        }

        var mex = 0
        while gseen[mex] == n + 1 {
            mex += 1
        }
        g[n] = mex
    }
    
    return g
}

// Performance test
let clock = ContinuousClock()
let elapsed = clock.measure {
    let g = get_grundys(limit: 100_000)
    print(g.last!) // 101
}
print("Computation time (s):", elapsed) // 1.697 seconds