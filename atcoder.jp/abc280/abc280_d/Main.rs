#![allow(non_snake_case)]
#![allow(unused_imports)]
#![allow(unused_macros)]
#![allow(dead_code)]
use proconio::{
    input,
    marker::{Chars, Usize1},
};

#[derive(Default)]
struct Solver {}
impl Solver {
    fn solve(&mut self) {
        input! {
            mut K: usize,
        }
        let mut A = vec![];

        let mut x: usize = K;
        for i in 2..K {
            if i * i > x {
                break;
            }
            if x % i != 0 {
                continue;
            }
            let mut cnt: usize = 0;
            while x % i == 0 {
                x /= i;
                cnt += 1;
            }
            A.push([i, cnt]);
        }
        if x != 1 {
            A.push([x, 1]);
        }
        let mut ok: usize = K;
        let mut ng: usize = 0;
        while ok - ng > 1 {
            let mid: usize = (ok - ng) / 2 + ng;
            let mut flg: bool = true;
            for [p, cnt] in &A {
                if Solver::f(mid, *p) < *cnt {
                    flg = false;
                    break;
                }
            }
            if flg {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        println!("{}", ok);
    }

    fn f(n: usize, p: usize) -> usize {
        if n == 0 {
            return 0;
        }
        let tmp = n / p;
        return tmp + Solver::f(tmp, p);
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
