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
            S: Chars,
        }
        let mut ans:usize = 0;
        for c in S.iter() {
            match c {
                'v' => ans += 1,
                'w' => ans += 2,
                _ => unreachable!(),
            }
        }
        println!("{}", ans);
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
