#include <stdio.h>    // Thư viện chuẩn cho các hàm nhập/xuất (printf)
#include <stdlib.h>   // Cho malloc, free, qsort
#include <time.h>     // Cho clock() để đo thời gian
#include <math.h>     // Cho log2 (mặc dù không dùng trực tiếp trong ví dụ O(log n) này, nó minh họa ý tưởng)

// --- Hàm tiện ích để đo thời gian ---
// Trả về thời gian đã trôi qua tính bằng giây
double get_elapsed_time(clock_t start_time, clock_t end_time) {
    return ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
}

// --- 1. O(1) - Constant Time (Thời gian hằng số) ---
// Thời gian thực thi không phụ thuộc vào kích thước đầu vào N.
// Luôn mất một lượng thời gian cố định.
void example_O1(int n_input) {
    printf("\n--- O(1) Example (Constant Time) ---\n");
    clock_t start_time = clock();

    // Truy cập một phần tử trong mảng theo chỉ số cố định
    int arr[5] = {10, 20, 30, 40, 50}; // Kích thước mảng cố định
    // Dù n_input lớn hay nhỏ, thao tác này vẫn luôn chỉ là truy cập arr[0]
    int first_element = arr[0];

    clock_t end_time = clock();
    double time_used = get_elapsed_time(start_time, end_time);

    printf("  Action: Accessing the first element.\n");
    printf("  Result: %d\n", first_element);
    printf("  Time for N=%d: %.10f seconds (Time is constant, independent of N)\n", n_input, time_used);
}

// --- 2. O(log n) - Logarithmic Time (Thời gian Logarit) ---
// Thời gian thực thi tăng rất chậm khi N tăng.
// Kích thước bài toán giảm đi một nửa sau mỗi bước.
// (Ví dụ: Tìm kiếm nhị phân trên mảng đã sắp xếp)
// Để minh họa, chúng ta sẽ dùng một vòng lặp chia đôi giá trị
void example_Ologn(int n_input) {
    printf("\n--- O(log n) Example (Logarithmic Time) ---\n");
    clock_t start_time = clock();

    int count = 0;
    // Vòng lặp này chạy log2(n_input) lần
    // (ví dụ: N=1000, log2(1000) ~ 10 lần lặp)
    // Mỗi lần lặp, 'i' nhân đôi, nhanh chóng đạt đến N
    for (int i = 1; i < n_input; i *= 2) {
        count++;
    }

    clock_t end_time = clock();
    double time_used = get_elapsed_time(start_time, end_time);

    printf("  Action: Loop where counter doubles each step.\n");
    printf("  Result: Loop ran %d times.\n", count);
    printf("  Time for N=%d: %.10f seconds (Time increases very slowly with N)\n", n_input, time_used);
}


// --- 3. O(n) - Linear Time (Thời gian Tuyến tính) ---
// Thời gian thực thi tăng tỷ lệ thuận với kích thước đầu vào N.
// Nếu N tăng gấp đôi, thời gian thực thi cũng tăng gấp đôi.
// (Ví dụ: Duyệt qua tất cả các phần tử của một mảng một lần)
void example_On(int n_input) {
    printf("\n--- O(n) Example (Linear Time) ---\n");
    clock_t start_time = clock();

    long long sum = 0; // Dùng long long để tránh tràn số với N lớn
    // Vòng lặp này chạy N lần
    for (int i = 0; i < n_input; i++) {
        sum += i; // Mỗi lần lặp là một thao tác cố định
    }

    clock_t end_time = clock();
    double time_used = get_elapsed_time(start_time, end_time);

    printf("  Action: Summing numbers from 0 to N-1.\n");
    printf("  Result: Sum = %lld\n", sum);
    printf("  Time for N=%d: %.10f seconds (Time directly proportional to N)\n", n_input, time_used);
}

// --- 4. O(n^2) - Quadratic Time (Thời gian Bình phương) ---
// Thời gian thực thi tăng theo bình phương của kích thước đầu vào N.
// Nếu N tăng gấp đôi, thời gian thực thi tăng gấp bốn lần.
// (Ví dụ: Hai vòng lặp lồng nhau)
void example_On2(int n_input) {
    printf("\n--- O(n^2) Example (Quadratic Time) ---\n");
    if (n_input > 5000) { // Giới hạn N để tránh chạy quá lâu trên máy tính thông thường
        printf("  Action: Skipped for N=%d (too large for practical O(n^2) demo).\n", n_input);
        return;
    }

    clock_t start_time = clock();

    long long count = 0;
    // Hai vòng lặp lồng nhau, mỗi vòng lặp chạy N lần
    // Tổng số thao tác là N * N
    for (int i = 0; i < n_input; i++) {
        for (int j = 0; j < n_input; j++) {
            count++; // Mỗi lần lặp trong cùng là một thao tác
        }
    }

    clock_t end_time = clock();
    double time_used = get_elapsed_time(start_time, end_time);

    printf("  Action: Nested loops (N x N operations).\n");
    printf("  Result: Total operations = %lld\n", count);
    printf("  Time for N=%d: %.10f seconds (Time increases quadratically with N)\n", n_input, time_used);
}

// --- 5. O(2^n) - Exponential Time (Thời gian Mũ) ---
// Thời gian thực thi tăng theo cấp số nhân với kích thước đầu vào N.
// Cực kỳ chậm, chỉ khả thi với N rất nhỏ.
// (Ví dụ: Hàm Fibonacci đệ quy không tối ưu)
long long fibonacci_recursive(int k) {
    if (k <= 1) {
        return k;
    }
    return fibonacci_recursive(k - 1) + fibonacci_recursive(k - 2); // Mỗi lời gọi tạo ra 2 lời gọi mới
}

void example_O2n(int n_input) {
    printf("\n--- O(2^n) Example (Exponential Time) ---\n");
    if (n_input > 35) { // Giới hạn N để tránh chờ đợi quá lâu
        printf("  Action: Skipped for N=%d (too large for practical O(2^n) demo, would take too long).\n", n_input);
        return;
    }

    clock_t start_time = clock();

    long long result = fibonacci_recursive(n_input);

    clock_t end_time = clock();
    double time_used = get_elapsed_time(start_time, end_time);

    printf("  Action: Recursive Fibonacci(%d).\n", n_input);
    printf("  Result: Fibonacci(%d) = %lld\n", n_input, result);
    printf("  Time for N=%d: %.10f seconds (Time explodes exponentially with N)\n", n_input, time_used);
}

// --- Hàm Main để chạy các ví dụ ---
int main() {
    // Để thấy rõ sự khác biệt về thời gian, chúng ta sẽ thử với một vài giá trị N
    // Các giá trị N này được chọn để minh họa rõ nhất sự tăng trưởng của mỗi Big O
    int test_Ns[] = {10, 100, 1000, 10000, 20000, 30000};
    int num_tests = sizeof(test_Ns) / sizeof(test_Ns[0]);

    printf("Starting Big O Performance Demonstrations...\n");
    printf("Note: Time measurements are indicative and can vary due to system load.\n");

    for (int i = 0; i < num_tests; i++) {
        int current_N = test_Ns[i];
        printf("\n============================================\n");
        printf("Testing with Input Size N = %d\n", current_N);
        printf("============================================\n");

        example_O1(current_N);      // Luôn nhanh
        example_Ologn(current_N);   // Rất nhanh
        example_On(current_N);      // Tăng tuyến tính
        example_On2(current_N);     // Tăng bình phương (sẽ chậm với N lớn)
        example_O2n(current_N);     // Tăng theo cấp số nhân (chỉ chạy với N rất nhỏ)
    }

    // Thử thêm một giá trị N rất nhỏ cho O(2^n) để nó có thể chạy
    printf("\n============================================\n");
    printf("Additional test for O(2^n) with N=35 (will be slow!)\n");
    printf("============================================\n");
    example_O2n(35);


    printf("\nBig O Demonstrations Completed.\n");
    return 0;
}
