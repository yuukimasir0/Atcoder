#![allow(non_snake_case)]
#![allow(unused_imports)]
#![allow(unused_macros)]
#![allow(dead_code)]
use proconio::{
    input,
    marker::{Chars, Usize1},
};

fn modpow(mut a: usize, mut n: usize, MOD: usize) -> usize {
    let mut res: usize = 1;
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
            T: Chars,
        }
        let N: usize = S.len();
        let M: usize = T.len();
        if N < M {
            println!("No");
        } else {
            for i in 0..=(N - M) {
                if S[i] == T[0] {
                    let mut flg: bool = true;
                    for j in 0..T.len() {
                        if S[i + j] != T[j] {
                            flg = false;
                            break;
                        }
                    }
                    if flg == true {
                        println!("Yes");
                        return;
                    }
                }
            }
            println!("No");
        }
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
