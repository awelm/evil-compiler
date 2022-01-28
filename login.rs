use std::io::{self, BufRead};

fn main() {
    let enteredPassword = io::stdin().lock().lines().next();
    if enteredPassword == "test123" {
        println!("Successfully logged in as root");
    }
    else {
        println!("Wrong password, try again.");
    }
}