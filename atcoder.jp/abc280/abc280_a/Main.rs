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
        input!{
            H: isize,
            W: isize,
            S: [Chars; H]
        }
        let mut ans = 0;
        for s in S {
            for c in &s {
                match c {
                    '#' => ans += 1,
                    '.' => ans += 0,
                    _ => unreachable!(),
                }
            }
        }
        println!("{}", &ans);
    }
}

fn main() {
    std::thread::Builder::new().stack_size(64 * 1024 * 1024).spawn(|| Solver::default().solve()).unwrap().join().unwrap();
}
