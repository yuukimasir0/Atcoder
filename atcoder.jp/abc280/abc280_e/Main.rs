#![allow(non_snake_case)]
#![allow(unused_imports)]
#![allow(unused_macros)]
#![allow(dead_code)]
use proconio::{
    input,
    marker::{Chars, Usize1},
};

fn modpow(mut a:usize, mut n:usize, MOD:usize) -> usize {
    let mut res:usize = 1;
    while n > 0 {
        if n & 1 == 1 {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        n >>= 1;
    }
    return res;
}

#[derive(Default)]
struct Solver {}
impl Solver {
    fn solve(&mut self) {
        input! {
            N: usize,
            P: usize,
        }
        let MOD = 998244353_usize;
        let mut dp = vec![0_usize; N + 1];
        dp[1] = 1;
        let inv100 = modpow(100, MOD - 2, MOD);
        for i in 2..=N {
            dp[i] = (dp[i - 2] + 1) % MOD * P % MOD * inv100 % MOD + (dp[i - 1] + 1) % MOD * (100 - P) % MOD * inv100 % MOD;            dp[i] %= MOD;
            dp[i] %= MOD;
        }
        println!("{}", dp[N]);
    }
}

fn main() {
    std::thread::Builder::new()
        .stack_size(64 * 1024 * 1024)
        .spawn(|| Solver::default().solve())
        .unwrap()
        .join()
        .unwrap();
}