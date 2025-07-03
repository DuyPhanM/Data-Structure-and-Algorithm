#include <stdio.h> // Thư viện chuẩn cho các hàm nhập/xuất (ví dụ: printf)
#include <stdbool.h> // Thư viện cho kiểu dữ liệu bool (từ C99 trở lên)

int main() {
    // 1. int (Integer - Số nguyên)
    printf("--- Integer (int) Examples ---\n");
    int studentCount = 30;
    int productId = 7890;
    int userAge = 25;
    printf("Student Count: %d\n", studentCount);
    printf("Product ID: %d\n", productId);
    printf("User Age: %d\n", userAge);
    printf("\n");

    // 2. float (Floating-point - Số thực đơn)
    printf("--- Float (float) Examples ---\n");
    float itemPrice = 99.99f; // 'f' để chỉ rõ đây là float
    float currentTemperature = 28.5f;
    printf("Item Price: %.2f\n", itemPrice); // .2f để hiển thị 2 chữ số thập phân
    printf("Current Temperature: %.1f Celcius\n", currentTemperature);
    printf("\n");

    // 3. double (Double Floating-point - Số thực kép)
    printf("--- Double (double) Examples ---\n");
    double totalRevenue = 150000.75;
    double discountRate = 0.15; // 15%
    double personHeight = 1.75; // meters
    printf("Total Revenue: %.2lf VND\n", totalRevenue); // .2lf cho double
    printf("Discount Rate: %.2lf (15%%)\n", discountRate);
    printf("Person Height: %.2lf meters\n", personHeight);
    printf("\n");

    // 4. char (Character - Ký tự)
    printf("--- Character (char) Examples ---\n");
    char gender = 'M'; // Male
    char menuChoice = 'C';
    char paymentStatus = 'P'; // P: Paid, U: Unpaid
    printf("Gender: %c\n", gender);
    printf("Menu Choice: %c\n", menuChoice);
    printf("Payment Status: %c\n", paymentStatus);
    printf("\n");

    // 5. bool (Boolean - Đúng/Sai, yêu cầu #include <stdbool.h>)
    printf("--- Boolean (bool) Examples ---\n");
    bool isLoggedIn = true; // true = 1
    bool hasError = false;   // false = 0
    printf("Is User Logged In?: %d (1=true, 0=false)\n", isLoggedIn);
    printf("Has System Error?: %d (1=true, 0=false)\n", hasError);
    printf("\n");

    // 6. Array (Mảng - Tập hợp các phần tử cùng kiểu dữ liệu)
    printf("--- Array Examples ---\n");

    // Mảng số nguyên
    int studentScores[5] = {85, 90, 78, 92, 88};
    printf("Student Scores: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", studentScores[i]);
    }
    printf("\n");

    // Mảng ký tự (Chuỗi)
    char customerName[30] = "Alice Smith"; // Tự động thêm '\0' ở cuối
    printf("Customer Name: %s\n", customerName);

    // Mảng số thực
    float dailyTemperatures[7] = {25.5f, 26.0f, 27.2f, 28.0f, 26.8f, 25.0f, 24.5f};
    printf("Daily Temperatures (Week): ");
    for (int i = 0; i < 7; i++) {
        printf("%.1f ", dailyTemperatures[i]);
    }
    printf("\n");
    printf("\n");

    // 7. Con trỏ (Pointers)
    printf("--- Pointer Examples ---\n");

    int myVariable = 10;          // Khai báo một biến kiểu int
    int *pointerToVariable;       // Khai báo một con trỏ kiểu int

    pointerToVariable = &myVariable; // Gán địa chỉ của myVariable cho con trỏ

    printf("Value of myVariable: %d\n", myVariable);
    printf("Address of myVariable: %p\n", (void*)&myVariable); // In địa chỉ của biến
    printf("Value of pointerToVariable (address it holds): %p\n", (void*)pointerToVariable); // In địa chỉ mà con trỏ đang giữ
    printf("Value at the address pointerToVariable points to (*pointerToVariable): %d\n", *pointerToVariable); // In giá trị tại địa chỉ đó

    // Thay đổi giá trị của biến thông qua con trỏ
    *pointerToVariable = 25; // Bây giờ myVariable cũng sẽ là 25
    printf("New value of myVariable after changing via pointer: %d\n", myVariable);
    printf("\n");


    return 0; // Trả về 0 báo hiệu chương trình kết thúc thành công
}
