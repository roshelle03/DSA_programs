def display_array(arr):
    for item in arr:
        print(item, end=" ")
    print()

def insert_element(arr, element, position):
    arr.insert(position, element)
    print(f"Inserted {element} at position {position}")

def delete_element(arr, element):
    if element in arr:
        arr.remove(element)
        print(f"Deleted {element}")
    else:
        print(f"{element} not found in the array")

def search_element(arr, element):
    if element in arr:
        print(f"{element} found in the array at position {arr.index(element)}")
    else:
        print(f"{element} not found in the array")

def main():
    arr = []
    while True:
        print("\nMenu:")
        print("1. Insert element")
        print("2. Delete element")
        print("3. Traverse array")
        print("4. Search element")
        print("5. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            element = int(input("Enter element to insert: "))
            position = int(input("Enter position to insert: "))
            insert_element(arr, element, position)
        elif choice == 2:
            element = int(input("Enter element to delete: "))
            delete_element(arr, element)
        elif choice == 3:
            print("Array elements:")
            display_array(arr)
        elif choice == 4:
            element = int(input("Enter element to search: "))
            search_element(arr, element)
        elif choice == 5:
            print("Exiting program.")
            break
        else:
            print("Invalid choice. Please enter a valid option.")

if __name__ == "__main__":
    main()
