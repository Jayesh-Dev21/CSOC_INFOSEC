fn bubble_sort(slice: &mut [i32]){
    let size_arr = slice.len();
    for i in 0..(size_arr-1) {
        for j in 0..(size_arr - i - 1) {
            if slice[j] > slice[j + 1] {
                slice.swap(j, j + 1);
            }
        }
    }
}


fn main(){
    let mut arr: [i32; 7] = [5, 2, 9, 1, 5, 6, 3];
    println!("Original array: {:?}", arr);
    bubble_sort(&mut arr);
    println!("Sorted array: {:?}", arr);
}
