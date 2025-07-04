
#include <stdio.h>
#include <stdlib.h> // Cần thiết cho malloc và free

// ====================================================================
// A. DANH SÁCH LIÊN KẾT ĐƠN (SINGLY LINKED LIST)
// ====================================================================

// Định nghĩa cấu trúc Node cho danh sách liên kết đơn
typedef struct SinglyNode {
    int data;             // Dữ liệu của nút
    struct SinglyNode *next; // Con trỏ tới nút kế tiếp
} SinglyNode;

// Hàm tạo một nút mới cho danh sách đơn
SinglyNode* create_singly_node(int data) {
    SinglyNode* newNode = (SinglyNode*)malloc(sizeof(SinglyNode));
    if (newNode == NULL) {
        perror("Failed to allocate memory for SinglyNode");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Duyệt và in danh sách liên kết đơn
void traverse_singly_list(SinglyNode* head) {
    printf("Singly Linked List: ");
    SinglyNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Chèn nút mới vào đầu danh sách đơn
SinglyNode* insert_singly_at_beginning(SinglyNode* head, int data) {
    SinglyNode* newNode = create_singly_node(data);
    newNode->next = head;
    return newNode; // Nút mới trở thành head
}

// Chèn nút mới vào cuối danh sách đơn
SinglyNode* insert_singly_at_end(SinglyNode* head, int data) {
    SinglyNode* newNode = create_singly_node(data);
    if (head == NULL) {
        return newNode; // Nếu danh sách rỗng, nút mới là head
    }
    SinglyNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Chèn nút mới sau một nút có giá trị cụ thể trong danh sách đơn
SinglyNode* insert_singly_after_value(SinglyNode* head, int value_to_find, int data_to_insert) {
    if (head == NULL) {
        printf("Danh sach rong, khong the chen sau.\n");
        return NULL;
    }
    SinglyNode* current = head;
    while (current != NULL && current->data != value_to_find) {
        current = current->next;
    }
    if (current != NULL) { // Tìm thấy nút cần chèn sau
        SinglyNode* newNode = create_singly_node(data_to_insert);
        newNode->next = current->next;
        current->next = newNode;
        printf("Da chen %d sau %d.\n", data_to_insert, value_to_find);
    } else {
        printf("Khong tim thay %d de chen sau.\n", value_to_find);
    }
    return head;
}


// Xóa nút đầu tiên trong danh sách đơn
SinglyNode* delete_singly_at_beginning(SinglyNode* head) {
    if (head == NULL) {
        printf("Danh sach rong, khong co gi de xoa.\n");
        return NULL;
    }
    SinglyNode* temp = head;
    head = head->next; // Nút kế tiếp trở thành head mới
    printf("Da xoa nut %d tu dau danh sach.\n", temp->data);
    free(temp); // Giải phóng bộ nhớ của nút đã xóa
    return head;
}

// Xóa nút có giá trị cụ thể trong danh sách đơn
SinglyNode* delete_singly_by_value(SinglyNode* head, int data_to_delete) {
    if (head == NULL) {
        printf("Danh sach rong, khong co gi de xoa.\n");
        return NULL;
    }

    SinglyNode* current = head;
    SinglyNode* prev = NULL;

    // Nếu nút cần xóa là head
    if (current != NULL && current->data == data_to_delete) {
        head = current->next;
        printf("Da xoa nut %d.\n", current->data);
        free(current);
        return head;
    }

    // Tìm nút cần xóa và nút trước đó
    while (current != NULL && current->data != data_to_delete) {
        prev = current;
        current = current->next;
    }

    // Nếu không tìm thấy nút
    if (current == NULL) {
        printf("Khong tim thay nut %d de xoa.\n", data_to_delete);
        return head;
    }

    // Bỏ qua nút hiện tại (nút cần xóa)
    prev->next = current->next;
    printf("Da xoa nut %d.\n", current->data);
    free(current);
    return head;
}

// Giải phóng toàn bộ bộ nhớ của danh sách đơn
void free_singly_list(SinglyNode* head) {
    SinglyNode* current = head;
    SinglyNode* next_node;
    while (current != NULL) {
        next_node = current->next; // Lưu lại con trỏ tới nút kế tiếp
        free(current);             // Giải phóng nút hiện tại
        current = next_node;       // Di chuyển sang nút kế tiếp
    }
    printf("Da giai phong bo nho cua danh sach lien ket don.\n");
}

// ====================================================================
// B. DANH SÁCH LIÊN KẾT ĐÔI (DOUBLY LINKED LIST)
// ====================================================================

// Định nghĩa cấu trúc Node cho danh sách liên kết đôi
typedef struct DoublyNode {
    int data;
    struct DoublyNode *prev; // Con trỏ tới nút trước đó
    struct DoublyNode *next; // Con trỏ tới nút kế tiếp
} DoublyNode;

// Hàm tạo một nút mới cho danh sách đôi
DoublyNode* create_doubly_node(int data) {
    DoublyNode* newNode = (DoublyNode*)malloc(sizeof(DoublyNode));
    if (newNode == NULL) {
        perror("Failed to allocate memory for DoublyNode");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Duyệt và in danh sách liên kết đôi (tiến và lùi)
void traverse_doubly_list(DoublyNode* head) {
    printf("Doubly Linked List (Forward): ");
    DoublyNode* current = head;
    DoublyNode* tail = NULL; // Dùng để in ngược
    while (current != NULL) {
        printf("%d <-> ", current->data);
        tail = current; // Cập nhật tail để biết nút cuối cùng
        current = current->next;
    }
    printf("NULL\n");

    printf("Doubly Linked List (Backward): ");
    current = tail; // Bắt đầu từ nút cuối cùng
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

// Chèn nút mới vào đầu danh sách đôi
DoublyNode* insert_doubly_at_beginning(DoublyNode* head, int data) {
    DoublyNode* newNode = create_doubly_node(data);
    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
    return newNode; // Nút mới là head
}

// Chèn nút mới vào cuối danh sách đôi
DoublyNode* insert_doubly_at_end(DoublyNode* head, int data) {
    DoublyNode* newNode = create_doubly_node(data);
    if (head == NULL) {
        return newNode; // Nếu danh sách rỗng, nút mới là head
    }
    DoublyNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Xóa nút có giá trị cụ thể trong danh sách đôi
DoublyNode* delete_doubly_by_value(DoublyNode* head, int data_to_delete) {
    if (head == NULL) {
        printf("Danh sach rong, khong the xoa.\n");
        return NULL;
    }

    DoublyNode* current = head;

    // Tìm nút cần xóa
    while (current != NULL && current->data != data_to_delete) {
        current = current->next;
    }

    // Nếu không tìm thấy
    if (current == NULL) {
        printf("Khong tim thay nut %d de xoa.\n", data_to_delete);
        return head;
    }

    // Nếu nút cần xóa là head
    if (current->prev == NULL) { // current là head
        head = current->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    }
    // Nếu nút cần xóa không phải head
    else {
        current->prev->next = current->next; // Nút trước đó trỏ tới nút sau của current
        if (current->next != NULL) {        // Nếu current không phải nút cuối
            current->next->prev = current->prev; // Nút sau đó trỏ ngược lại nút trước của current
        }
    }
    printf("Da xoa nut %d.\n", current->data);
    free(current);
    return head;
}

// Giải phóng toàn bộ bộ nhớ của danh sách đôi
void free_doubly_list(DoublyNode* head) {
    DoublyNode* current = head;
    DoublyNode* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    printf("Da giai phong bo nho cua danh sach lien ket doi.\n");
}


// ====================================================================
// C. DANH SÁCH LIÊN KẾT VÒNG (CIRCULAR LINKED LIST)
// ====================================================================

// Định nghĩa cấu trúc Node cho danh sách liên kết vòng (giống đơn)
typedef struct CircularNode {
    int data;
    struct CircularNode *next;
} CircularNode;

// Hàm tạo một nút mới cho danh sách vòng
CircularNode* create_circular_node(int data) {
    CircularNode* newNode = (CircularNode*)malloc(sizeof(CircularNode));
    if (newNode == NULL) {
        perror("Failed to allocate memory for CircularNode");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL; // Ban đầu vẫn NULL
    return newNode;
}

// Duyệt và in danh sách liên kết vòng (cẩn thận vòng lặp vô hạn!)
void traverse_circular_list(CircularNode* head) {
    printf("Circular Linked List: ");
    if (head == NULL) {
        printf("EMPTY\n");
        return;
    }
    CircularNode* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head); // Duyệt cho đến khi quay lại head
    printf("(Back to %d)\n", head->data); // Chỉ ra rằng nó vòng về head
}

// Chèn nút mới vào đầu danh sách vòng
CircularNode* insert_circular_at_beginning(CircularNode* head, int data) {
    CircularNode* newNode = create_circular_node(data);
    if (head == NULL) {
        newNode->next = newNode; // Nếu danh sách rỗng, nó trỏ vào chính nó
    } else {
        CircularNode* tail = head;
        while (tail->next != head) { // Tìm nút cuối cùng
            tail = tail->next;
        }
        newNode->next = head; // Nút mới trỏ tới head cũ
        tail->next = newNode; // Nút cuối cùng trỏ tới nút mới
    }
    return newNode; // Nút mới trở thành head
}

// Chèn nút mới vào cuối danh sách vòng
CircularNode* insert_circular_at_end(CircularNode* head, int data) {
    CircularNode* newNode = create_circular_node(data);
    if (head == NULL) {
        newNode->next = newNode; // Nếu danh sách rỗng, nó trỏ vào chính nó
        return newNode;
    } else {
        CircularNode* tail = head;
        while (tail->next != head) { // Tìm nút cuối cùng
            tail = tail->next;
        }
        tail->next = newNode; // Nút cuối cùng trỏ tới nút mới
        newNode->next = head; // Nút mới trỏ tới head
    }
    return head;
}

// Xóa nút có giá trị cụ thể trong danh sách vòng
CircularNode* delete_circular_by_value(CircularNode* head, int data_to_delete) {
    if (head == NULL) {
        printf("Danh sach rong, khong the xoa.\n");
        return NULL;
    }

    CircularNode* current = head;
    CircularNode* prev = NULL;

    // Xử lý trường hợp chỉ có một nút
    if (head->data == data_to_delete && head->next == head) {
        printf("Da xoa nut %d.\n", head->data);
        free(head);
        return NULL; // Danh sách trở thành rỗng
    }

    // Nếu nút cần xóa là head (có nhiều hơn một nút)
    if (head->data == data_to_delete) {
        // Tìm nút cuối cùng
        CircularNode* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        head = head->next; // Nút kế tiếp trở thành head mới
        tail->next = head; // Nút cuối cùng trỏ tới head mới
        printf("Da xoa nut %d (head).\n", current->data);
        free(current);
        return head;
    }

    // Tìm nút cần xóa và nút trước đó
    do {
        prev = current;
        current = current->next;
        if (current->data == data_to_delete) {
            break; // Tìm thấy nút cần xóa
        }
    } while (current != head); // Duyệt cho đến khi quay lại head

    // Nếu không tìm thấy nút
    if (current == head) { // Đã duyệt hết và quay lại head mà không tìm thấy
        printf("Khong tim thay nut %d de xoa.\n", data_to_delete);
        return head;
    }

    // Bỏ qua nút hiện tại (nút cần xóa)
    prev->next = current->next;
    printf("Da xoa nut %d.\n", current->data);
    free(current);
    return head;
}


// Giải phóng toàn bộ bộ nhớ của danh sách vòng
void free_circular_list(CircularNode* head) {
    if (head == NULL) {
        printf("Danh sach lien ket vong rong, khong co gi de giai phong.\n");
        return;
    }
    CircularNode* current = head->next;
    CircularNode* temp;
    while (current != head) { // Duyệt cho đến khi quay lại head
        temp = current;
        current = current->next;
        free(temp);
    }
    free(head); // Giải phóng nút head cuối cùng
    printf("Da giai phong bo nho cua danh sach lien ket vong.\n");
}


// ====================================================================
// HÀM MAIN: Chạy các ví dụ
// ====================================================================
int main() {
    printf("****************************************\n");
    printf("* Danh sach Lien ket Don (Singly Linked List) *\n");
    printf("****************************************\n");

    SinglyNode* s_head = NULL; // Khởi tạo danh sách rỗng

    s_head = insert_singly_at_beginning(s_head, 30); // 30
    s_head = insert_singly_at_beginning(s_head, 20); // 20 -> 30
    s_head = insert_singly_at_end(s_head, 40);       // 20 -> 30 -> 40
    s_head = insert_singly_at_end(s_head, 50);       // 20 -> 30 -> 40 -> 50
    traverse_singly_list(s_head);

    s_head = insert_singly_at_beginning(s_head, 10); // 10 -> 20 -> 30 -> 40 -> 50
    traverse_singly_list(s_head);

    s_head = insert_singly_after_value(s_head, 30, 35); // 10 -> 20 -> 30 -> 35 -> 40 -> 50
    traverse_singly_list(s_head);

    s_head = delete_singly_at_beginning(s_head); // Xoa 10: 20 -> 30 -> 35 -> 40 -> 50
    traverse_singly_list(s_head);

    s_head = delete_singly_by_value(s_head, 40); // Xoa 40: 20 -> 30 -> 35 -> 50
    traverse_singly_list(s_head);

    s_head = delete_singly_by_value(s_head, 99); // Khong tim thay 99
    traverse_singly_list(s_head);

    s_head = delete_singly_by_value(s_head, 20); // Xoa 20 (head moi): 30 -> 35 -> 50
    traverse_singly_list(s_head);

    free_singly_list(s_head);
    s_head = NULL; // Đặt head về NULL sau khi giải phóng

    printf("\n****************************************\n");
    printf("* Danh sach Lien ket Doi (Doubly Linked List) *\n");
    printf("****************************************\n");

    DoublyNode* d_head = NULL;

    d_head = insert_doubly_at_beginning(d_head, 300); // 300
    d_head = insert_doubly_at_beginning(d_head, 200); // 200 <-> 300
    d_head = insert_doubly_at_end(d_head, 400);       // 200 <-> 300 <-> 400
    d_head = insert_doubly_at_end(d_head, 500);       // 200 <-> 300 <-> 400 <-> 500
    traverse_doubly_list(d_head);

    d_head = delete_doubly_by_value(d_head, 300); // Xoa 300: 200 <-> 400 <-> 500
    traverse_doubly_list(d_head);

    d_head = delete_doubly_by_value(d_head, 200); // Xoa 200 (head moi): 400 <-> 500
    traverse_doubly_list(d_head);

    d_head = delete_doubly_by_value(d_head, 500); // Xoa 500: 400
    traverse_doubly_list(d_head);

    d_head = delete_doubly_by_value(d_head, 400); // Xoa 400 (danh sach rong)
    traverse_doubly_list(d_head);

    d_head = delete_doubly_by_value(d_head, 100); // Xoa tren danh sach rong
    traverse_doubly_list(d_head);

    free_doubly_list(d_head);
    d_head = NULL;


    printf("\n****************************************\n");
    printf("* Danh sach Lien ket Vong (Circular Linked List) *\n");
    printf("****************************************\n");

    CircularNode* c_head = NULL;

    c_head = insert_circular_at_beginning(c_head, 1000); // 1000 (tro vao chinh no)
    traverse_circular_list(c_head);

    c_head = insert_circular_at_end(c_head, 2000); // 1000 <-> 2000 <-> 1000
    traverse_circular_list(c_head);

    c_head = insert_circular_at_beginning(c_head, 500); // 500 <-> 1000 <-> 2000 <-> 500
    traverse_circular_list(c_head);

    c_head = delete_circular_by_value(c_head, 1000); // Xoa 1000: 500 <-> 2000 <-> 500
    traverse_circular_list(c_head);

    c_head = delete_circular_by_value(c_head, 500); // Xoa 500 (head): 2000 <-> 2000
    traverse_circular_list(c_head);

    c_head = delete_circular_by_value(c_head, 2000); // Xoa 2000 (danh sach rong)
    traverse_circular_list(c_head);

    c_head = delete_circular_by_value(c_head, 777); // Xoa tren danh sach rong
    traverse_circular_list(c_head);

    free_circular_list(c_head); // Gọi hàm free (sẽ không làm gì nếu c_head là NULL)
    c_head = NULL;

    return 0;
}
