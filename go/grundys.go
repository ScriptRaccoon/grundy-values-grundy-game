package main

import (
	"fmt"
	"time"
)

// Computes the Grundy values of Grundy's Game.
func get_grundys(limit int) []int {
	g := make([]int, limit+1)
	gseen := make([]int, limit+1)

	for n := 0; n <= limit; n++ {
		for a := 1; 2*a < n; a++ {
			x := g[a] ^ g[n-a]
			if 2*x < n {
				gseen[x] = n + 1
			}
		}
		mex := 0
		for gseen[mex] == n+1 {
			mex++
		}
		g[n] = mex
	}
	return g
}

// Performance testing
func main() {
	start := time.Now()
	grundys := get_grundys(100_000)
	fmt.Println(grundys[len(grundys)-1]) // 101
	fmt.Println("Computation time (s):", time.Since(start).Seconds())
	// 1.464782 seconds
}

// Use the command "go fmt grundys.go" for formatting
