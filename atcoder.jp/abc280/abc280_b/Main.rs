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
            N: usize,
            mut S: [isize; N],
        }
        let mut A = vec![];
        for i in 0..N {
            if i == 0 {
                A.push(S[0]);
            } else {
                A.push(S[i] - S[i - 1]);
            }
        }
        for x in A {
            print!("{} ", x);
        }
        println!();
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
