#![allow(non_snake_case)]

fn pass_val_by_val(mut i:i32) -> i32 {
    print!("\n  pass_val_by_val");
    i += 3;
    print!("\n  mutated value, i = {:?}", i);
    i
}

fn pass_val_by_ref(i:&mut i32) -> i32 {
    print!("\n  pass_val_by_ref");
    *i += 3;
    print!("\n  mutated value, i = {:?}", i);
    *i
}

fn pass_ref_by_val(mut r:Box<String>) {
    print!("\n  pass_ref_by_val");
    r.push_str("xyz");
    print!("\n  mutated ref, r = {:?}", r);
    r = Box::new("def".to_string()); 
    print!("\n  new ref object = {:?}",r);
}

fn pass_ref_by_ref(r:&mut Box<String>) {
    print!("\n  pass_ref_by_ref");
    (*r).push_str("xyz");
    print!("\n  mutated string, s = {:?}", r);
    *r = Box::new("stu".to_string());
    print!("\n  new ref object = {:?}", r);
}

fn main() {

    let j = 5;
    print!("\n  input value, j = {:?}", j);
    let k = pass_val_by_val(j);
    print!("\n  return value = {:?}", k);
    print!("\n  j  = {:?}\n", j);

    let mut j = 5;
    print!("\n  input value, j = {:?}", j);
    let k = pass_val_by_ref(&mut j);
    print!("\n  return value = {:#}", k);
    print!("\n  j  = {:?}\n", j);

    let s:String = "abc".to_string();
    let r:Box<String> = Box::new(s);
    print!("\n  input value r = {:?}", r);
    pass_ref_by_val(r.clone());
    print!("\n  r = {:?}\n", r);

    let t:String = "abc".to_string();
    let mut r:Box<String> = Box::new(t);
    print!("\n  input value r = {:?}", r);
    pass_ref_by_ref(&mut r);
    print!("\n  r = {:?}\n", r);
}
