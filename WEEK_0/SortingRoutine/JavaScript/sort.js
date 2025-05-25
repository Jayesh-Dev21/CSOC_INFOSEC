function bubbleSort(arr, n){
    for(let i = 0; i < n - 1; i++){
        for(let j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]) {
                let temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}

function insertSort(arr, n){
    for(let i = 1; i < n; i++){
        let key = arr[i];
        let j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return arr;
}

let array = [5, 3, 8, 4, 2];
n = array.length;

console.log("Original array:");
console.log(array);

console.log("Sorted array:");
console.log(bubbleSort(array, n));
