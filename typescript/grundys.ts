/**
 * Computes the Grundy values of Grundy's Game.
 */
function get_grundys(limit: number): number[] {
	const g = new Uint32Array(limit + 1)
	const gseen = new Uint32Array(limit + 1)

	for (let n = 0; n <= limit; n++) {
		for (let a = 1; 2 * a < n; a++) {
			const x = g[a] ^ g[n - a]
			if (2 * x < n) gseen[x] = n + 1
		}
		let mex = 0
		while (gseen[mex] === n + 1) mex++
		g[n] = mex
	}
	return [...g]
}

// Performance test
const before = performance.now()
const grundys = get_grundys(100_000)
console.info(grundys.at(-1)) // 101
const after = performance.now()
console.info('Computation time (s):', (after - before) / 1000) // 2.393 seconds
