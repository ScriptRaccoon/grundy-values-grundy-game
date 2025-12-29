use std::time::Instant;

// Computes the Grundy values of Grundy's Game.
fn get_grundys(limit: usize) -> Vec<usize> {
    let mut g = vec![0; limit + 1];
    let mut gseen = vec![0; limit + 1];

    for n in 0..=limit {
        for a in 1.. {
            if 2 * a >= n {
                break;
            }
            let x = g[a] ^ g[n - a];
            if 2 * x < n {
                gseen[x] = n + 1;
            }
        }
        let mut mex: usize = 0;
        while gseen[mex] == n + 1 {
            mex += 1;
        }
        g[n] = mex;
    }

    g
}

// Performance test
fn main() {
    let before = Instant::now();
    let grundys = get_grundys(100_000);
    println!("{:?}", grundys.last().unwrap()); // 101
    let after = Instant::now();
    let duration = after.duration_since(before);
    println!("Computation time (s): {}", duration.as_secs_f64());
    // 0.992264 seconds
}