#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

// Computes the Grundy values of Grundy's Game.
vector<int> grundy_numbers(int limit) {
	vector<int> g(limit + 1, 0);
	vector<int> gseen(limit + 1, 0);

	for (int n = 0; n <= limit; n++) {
		for (int a = 1; 2 * a < n; a++) {
			int x = g[a] ^ g[n - a];
			gseen[x] = n + 1;
		}

		int mex = 0;
		while (gseen[mex] == n + 1) {
			mex++;
		}
		g[n] = mex;
	}

	return g;
}

// Peformance testing
int main() {
	int limit = 100'000;
	auto start = chrono::high_resolution_clock::now();

	vector<int> grundys = grundy_numbers(limit);
	cout << grundys[limit] << endl;
	// 101

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end - start;
	cout << "Computation time (s): " << elapsed.count() << endl;
	// 0.430713 seconds
}
