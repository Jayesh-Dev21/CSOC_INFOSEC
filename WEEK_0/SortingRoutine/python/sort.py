import random

def generate_random_array(size, lower=1, upper=99):
    return [random.randint(lower, upper) for _ in range(size)]

def bubble_sort(arr):
    
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr

def insertion_sort(arr):
    
    for i in range(1, len(arr)):
        key = arr[i]
        j = i-1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

def print_array(arr):
    print(" ".join(map(str, arr)))


def choose_sorting_algorithm():
    print("Choose sorting algorithm:")
    print("1. Bubble Sort")
    print("2. Insertion Sort")
    try:
        choice = int(input("Enter your choice: "))
    except ValueError:
        choice = -1
    return choice


def choosed_sorting_algorithm(choice, array):
    if choice == 1:
        bubble_sort(array)
    elif choice == 2:
        insertion_sort(array)
    else:
        print("Invalid choice")
        return -1
    return 0


def main():
    size = random.randint(3, 10)
    array = generate_random_array(size, 1, 99)
    print("Original array:")
    print_array(array)

    choice = choose_sorting_algorithm()
    result = choosed_sorting_algorithm(choice, array)

    if result == -1:
        print("Error in sorting")
        return

    print("Sorted array:")
    print_array(array)
    print(f"Sorting algorithm {choice} completed successfully.")


if __name__ == "__main__":
    main()
