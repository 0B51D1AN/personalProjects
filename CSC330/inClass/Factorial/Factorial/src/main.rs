use std::env;
fn factorial_recursive (n: u64) -> u64 {
    match n {
        0 => 1,
        _ => n * factorial_recursive(n-1)
    }
}

fn factorial_iterative(n: u64) -> u64 {
    (1..=n).product()
}

fn main () {
    let args: Vec<String> = env::args().collect();
    let my_int: u64 = args[1].parse().unwrap();
    println!("Recursive:");
    for i in 1..my_int {
        println!("{}", factorial_recursive(i))
    }
    println!("Iterative:");
    for i in 1..my_int {
        println!("{}", factorial_iterative(i))
    }
}

