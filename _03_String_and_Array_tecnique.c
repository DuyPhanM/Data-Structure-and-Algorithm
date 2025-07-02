#include <stdio.h>  // Thư viện chuẩn cho nhập/xuất (printf, scanf)
#include <string.h> // Thư viện cho các hàm xử lý chuỗi (strlen, strcpy, strcmp)
#include <stdlib.h> // Thư viện cho các hàm tiện ích (malloc, free, qsort)
#include <stdbool.h> // Cho kiểu dữ liệu bool

// --- Hàm tiện ích để in mảng ---
void print_array(int arr[], int size, const char *msg) {
    printf("%s [", msg);
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// --- Hàm tiện ích để in chuỗi ---
void print_string(const char *str, const char *msg) {
    printf("%s \"%s\"\n", msg, str);
}

// ====================================================================
// A. THAO TÁC CƠ BẢN VỚI MẢNG
// ====================================================================

// --- 1. Duyệt mảng (Traversal) ---
void array_traversal(int arr[], int size) {
    printf("\n--- Array Traversal (Duyet Mang) ---\n");
    print_array(arr, size, "Original Array:");
    printf("Elements (forward): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nElements (backward): ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// --- 2. Tìm kiếm (Searching) ---
// Tìm kiếm tuyến tính: Duyệt từng phần tử một
int linear_search(int arr[], int size, int target) {
    printf("\n--- Array Searching (Tim Kiem Mang) ---\n");
    printf("Searching for %d...\n", target);
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Trả về chỉ số nếu tìm thấy
        }
    }
    return -1; // Trả về -1 nếu không tìm thấy
}

// --- 3. Cập nhật (Updating) ---
// Thay đổi giá trị của một phần tử tại một chỉ số cụ thể
void array_update(int arr[], int size, int index, int new_value) {
    printf("\n--- Array Updating (Cap Nhat Mang) ---\n");
    if (index >= 0 && index < size) {
        print_array(arr, size, "Array before update:");
        arr[index] = new_value;
        print_array(arr, size, "Array after update:");
        printf("Updated element at index %d to %d.\n", index, new_value);
    } else {
        printf("Error: Invalid index %d for array of size %d.\n", index, size);
    }
}

// --- 4. Chèn/Xóa (Insertion/Deletion) ---
// Các thao tác này tốn kém vì có thể cần dịch chuyển nhiều phần tử

// Chèn một phần tử vào vị trí cụ thể (cần mảng có đủ không gian)
// arr: Mảng đích, size: Kích thước hiện tại, capacity: Sức chứa tối đa
int array_insert(int arr[], int *size, int capacity, int index, int value) {
    printf("\n--- Array Insertion (Chen Phan Tu) ---\n");
    if (*size >= capacity) {
        printf("Error: Array is full, cannot insert.\n");
        return *size;
    }
    if (index < 0 || index > *size) { // index == *size là chèn vào cuối
        printf("Error: Invalid index %d for insertion.\n", index);
        return *size;
    }

    print_array(arr, *size, "Array before insertion:");

    // Dịch chuyển các phần tử từ index về sau sang phải
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value; // Chèn giá trị mới
    (*size)++;          // Tăng kích thước thực tế của mảng

    print_array(arr, *size, "Array after insertion:");
    printf("Inserted %d at index %d.\n", value, index);
    return *size;
}

// Xóa một phần tử tại vị trí cụ thể
int array_delete(int arr[], int *size, int index) {
    printf("\n--- Array Deletion (Xoa Phan Tu) ---\n");
    if (*size <= 0) {
        printf("Error: Array is empty, cannot delete.\n");
        return *size;
    }
    if (index < 0 || index >= *size) {
        printf("Error: Invalid index %d for deletion.\n", index);
        return *size;
    }

    print_array(arr, *size, "Array before deletion:");

    // Dịch chuyển các phần tử từ index+1 về sau sang trái
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--; // Giảm kích thước thực tế của mảng

    print_array(arr, *size, "Array after deletion:");
    printf("Deleted element at index %d.\n", index);
    return *size;
}


// ====================================================================
// B. THAO TÁC CƠ BẢN VỚI CHUỖI
// ====================================================================

// --- 1. Duyệt chuỗi (Traversal) ---
void string_traversal(char *str) {
    printf("\n--- String Traversal (Duyet Chuoi) ---\n");
    print_string(str, "Original String:");
    printf("Characters (forward): ");
    for (int i = 0; str[i] != '\0'; i++) { // Duyệt cho đến ký tự null
        printf("'%c' ", str[i]);
    }
    printf("\n");
}

// --- 2. Tìm kiếm ký tự (Searching Character) ---
int char_search(char *str, char target_char) {
    printf("\n--- String Character Searching (Tim Kiem Ky Tu) ---\n");
    printf("Searching for character '%c'...\n", target_char);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == target_char) {
            return i; // Trả về chỉ số nếu tìm thấy
        }
    }
    return -1; // Trả về -1 nếu không tìm thấy
}

// --- 3. Cập nhật ký tự (Updating Character) ---
void string_update_char(char *str, int index, char new_char) {
    printf("\n--- String Character Updating (Cap Nhat Ky Tu) ---\n");
    int len = strlen(str);
    if (index >= 0 && index < len) {
        print_string(str, "String before update:");
        str[index] = new_char;
        print_string(str, "String after update:");
        printf("Updated character at index %d to '%c'.\n", index, new_char);
    } else {
        printf("Error: Invalid index %d for string of length %d.\n", index, len);
    }
}

// ====================================================================
// C. KỸ THUẬT NÂNG CAO
// ====================================================================

// --- 1. Kỹ thuật hai con trỏ (Two Pointers Technique) ---
// Thường dùng để đảo ngược mảng/chuỗi, kiểm tra palindrome, tìm cặp tổng bằng K.

// Ví dụ: Đảo ngược một mảng
void reverse_array_two_pointers(int arr[], int size) {
    printf("\n--- Two Pointers: Reverse Array ---\n");
    print_array(arr, size, "Original Array:");
    int left = 0;
    int right = size - 1;
    while (left < right) {
        // Hoán đổi phần tử tại left và right
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
    print_array(arr, size, "Reversed Array:");
}

// Ví dụ: Kiểm tra chuỗi palindrome (đối xứng)
bool is_palindrome_two_pointers(char *str) {
    printf("\n--- Two Pointers: Check Palindrome ---\n");
    print_string(str, "Checking Palindrome for:");
    int left = 0;
    int right = strlen(str) - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// --- 2. Kỹ thuật cửa sổ trượt (Sliding Window Technique) ---
// Thường dùng để tìm tập con (sub-array/sub-string) có thuộc tính nhất định
// trong một mảng/chuỗi lớn một cách hiệu quả.

// Ví dụ: Tìm tổng con lớn nhất của kích thước K trong mảng
int max_subarray_sum_sliding_window(int arr[], int size, int k) {
    printf("\n--- Sliding Window: Max Subarray Sum of Size K ---\n");
    if (k <= 0 || k > size) {
        printf("Invalid K value.\n");
        return -1;
    }
    print_array(arr, size, "Original Array:");
    printf("Finding max sum of subarray of size %d.\n", k);

    int current_sum = 0;
    // Tính tổng của cửa sổ đầu tiên (k phần tử đầu tiên)
    for (int i = 0; i < k; i++) {
        current_sum += arr[i];
    }

    int max_sum = current_sum;

    // Trượt cửa sổ: Trừ phần tử đầu tiên của cửa sổ cũ, cộng phần tử mới
    for (int i = k; i < size; i++) {
        current_sum += arr[i] - arr[i - k]; // Cộng phần tử mới, trừ phần tử cũ
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    printf("Maximum subarray sum of size %d: %d\n", k, max_sum);
    return max_sum;
}


// ====================================================================
// HÀM MAIN: Chạy các ví dụ
// ====================================================================
int main() {
    // --- Khởi tạo mảng ban đầu ---
    #define MAX_ARRAY_CAPACITY 10 // Sức chứa tối đa của mảng cho ví dụ chèn/xóa
    int my_array[MAX_ARRAY_CAPACITY] = {10, 20, 30, 40, 50};
    int current_array_size = 5; // Kích thước hiện tại của mảng

    // --- Khởi tạo chuỗi ban đầu ---
    char my_string[] = "hello world";
    char palindrome_str1[] = "madam";
    char palindrome_str2[] = "racecar";
    char non_palindrome_str[] = "programming";

    printf("****************************************\n");
    printf("* Demonstrating Array and String Operations *\n");
    printf("****************************************\n");

    // --- A. Thao tác cơ bản với Mảng ---
    array_traversal(my_array, current_array_size);

    int found_at_index = linear_search(my_array, current_array_size, 30);
    if (found_at_index != -1) {
        printf("Found 30 at index: %d\n", found_at_index);
    } else {
        printf("30 not found.\n");
    }
    found_at_index = linear_search(my_array, current_array_size, 99);
    if (found_at_index != -1) {
        printf("Found 99 at index: %d\n", found_at_index);
    } else {
        printf("99 not found.\n");
    }

    array_update(my_array, current_array_size, 2, 35); // Cập nhật arr[2] từ 30 -> 35

    current_array_size = array_insert(my_array, &current_array_size, MAX_ARRAY_CAPACITY, 1, 15); // Chèn 15 vào index 1
    current_array_size = array_insert(my_array, &current_array_size, MAX_ARRAY_CAPACITY, current_array_size, 60); // Chèn 60 vào cuối

    current_array_size = array_delete(my_array, &current_array_size, 3); // Xóa phần tử tại index 3 (giá trị 35 hoặc 40 tùy theo ví dụ)
    current_array_size = array_delete(my_array, &current_array_size, 0); // Xóa phần tử đầu tiên


    // --- B. Thao tác cơ bản với Chuỗi ---
    string_traversal(my_string);

    int char_idx = char_search(my_string, 'o');
    if (char_idx != -1) {
        printf("Character 'o' found at index: %d\n", char_idx);
    } else {
        printf("Character 'o' not found.\n");
    }

    string_update_char(my_string, 6, 'W'); // Thay 'w' bằng 'W'


    // --- C. Kỹ thuật nâng cao ---
    printf("\n\n****************************************\n");
    printf("* Demonstrating Advanced Techniques *\n");
    printf("****************************************\n");

    // Kỹ thuật hai con trỏ: Đảo ngược mảng
    int reverse_arr[] = {1, 2, 3, 4, 5, 6};
    reverse_array_two_pointers(reverse_arr, sizeof(reverse_arr) / sizeof(reverse_arr[0]));

    // Kỹ thuật hai con trỏ: Kiểm tra palindrome
    printf("\nIs '%s' a palindrome? %s\n", palindrome_str1, is_palindrome_two_pointers(palindrome_str1) ? "Yes" : "No");
    printf("Is '%s' a palindrome? %s\n", palindrome_str2, is_palindrome_two_pointers(palindrome_str2) ? "Yes" : "No");
    printf("Is '%s' a palindrome? %s\n", non_palindrome_str, is_palindrome_two_pointers(non_palindrome_str) ? "Yes" : "No");


    // Kỹ thuật cửa sổ trượt: Tổng con lớn nhất
    int window_arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    max_subarray_sum_sliding_window(window_arr, sizeof(window_arr) / sizeof(window_arr[0]), 3);
    max_subarray_sum_sliding_window(window_arr, sizeof(window_arr) / sizeof(window_arr[0]), 4);


    return 0;
}
