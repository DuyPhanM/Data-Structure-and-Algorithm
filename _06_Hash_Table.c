#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Để sử dụng các hàm xử lý chuỗi như strcmp, strcpy

// Định nghĩa kích thước của bảng băm (số lượng bucket)
#define HASH_TABLE_SIZE 10

// Cấu trúc cho mỗi node trong danh sách liên kết (khi xảy ra va chạm)
typedef struct Node {
    char key[50]; // Giả sử key là chuỗi
    int value;    // Giá trị lưu trữ
    struct Node *next;
} Node;

// Cấu trúc cho Hash Table
typedef struct {
    Node *buckets[HASH_TABLE_SIZE]; // Mảng các con trỏ đến Node (đầu danh sách liên kết)
} HashTable;

// --- HASH FUNCTION (Hàm băm) ---
// Hàm băm đơn giản: Tính tổng ASCII của các ký tự trong key và chia lấy dư cho kích thước bảng
unsigned int hashFunction(const char *key) {
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash += key[i];
    }
    return hash % HASH_TABLE_SIZE;
}

// --- KHỞI TẠO HASH TABLE ---
void initHashTable(HashTable *ht) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        ht->buckets[i] = NULL; // Khởi tạo tất cả các bucket là NULL
    }
}

// --- THÊM CẶP KEY-VALUE VÀO HASH TABLE (INSERT) ---
void insert(HashTable *ht, const char *key, int value) {
    unsigned int index = hashFunction(key);

    // Tạo một Node mới
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Lỗi cấp phát bộ nhớ cho Node mới");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->key, key);
    newNode->value = value;
    newNode->next = NULL;

    // Nếu bucket tại index này rỗng, thêm Node mới vào đầu
    if (ht->buckets[index] == NULL) {
        ht->buckets[index] = newNode;
    } else {
        // Xử lý va chạm: Thêm vào đầu danh sách liên kết (có thể thêm vào cuối)
        // Việc thêm vào đầu đơn giản hơn và thường nhanh hơn một chút
        // vì không cần duyệt danh sách.
        newNode->next = ht->buckets[index];
        ht->buckets[index] = newNode;
    }
    printf("Đã thêm: Key=\"%s\", Value=%d tại index %u\n", key, value, index);
}

// --- TÌM KIẾM GIÁ TRỊ THEO KEY TRONG HASH TABLE (LOOKUP) ---
int *lookup(HashTable *ht, const char *key) {
    unsigned int index = hashFunction(key);
    Node *current = ht->buckets[index];

    // Duyệt qua danh sách liên kết tại bucket này để tìm key
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return &(current->value); // Trả về con trỏ đến giá trị
        }
        current = current->next;
    }
    return NULL; // Không tìm thấy key
}

// --- XÓA CẶP KEY-VALUE KHỎI HASH TABLE (DELETE) ---
void delete(HashTable *ht, const char *key) {
    unsigned int index = hashFunction(key);
    Node *current = ht->buckets[index];
    Node *prev = NULL;

    // Duyệt qua danh sách liên kết để tìm key và xóa
    while (current != NULL && strcmp(current->key, key) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Key \"%s\" không tìm thấy để xóa.\n", key);
        return; // Không tìm thấy key
    }

    // Nếu Node cần xóa là Node đầu tiên trong danh sách
    if (prev == NULL) {
        ht->buckets[index] = current->next;
    } else {
        // Nếu Node cần xóa nằm giữa hoặc cuối danh sách
        prev->next = current->next;
    }
    printf("Đã xóa: Key=\"%s\", Value=%d\n", current->key, current->value);
    free(current); // Giải phóng bộ nhớ của Node đã xóa
}

// --- HIỂN THỊ NỘI DUNG HASH TABLE ---
void displayHashTable(HashTable *ht) {
    printf("\n--- HIỂN THỊ HASH TABLE ---\n");
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        Node *current = ht->buckets[i];
        if (current == NULL) {
            printf("Trống\n");
        } else {
            while (current != NULL) {
                printf("(\"%s\":%d) -> ", current->key, current->value);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
    printf("---------------------------\n");
}

// --- GIẢI PHÓNG BỘ NHỚ CỦA HASH TABLE ---
void freeHashTable(HashTable *ht) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Node *current = ht->buckets[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp); // Giải phóng từng Node trong danh sách liên kết
        }
        ht->buckets[i] = NULL; // Đặt lại con trỏ bucket về NULL
    }
    printf("Đã giải phóng bộ nhớ Hash Table.\n");
}

// --- MAIN FUNCTION ---
int main() {
    HashTable myHashTable;
    initHashTable(&myHashTable);

    // Thêm các cặp key-value
    insert(&myHashTable, "apple", 10);
    insert(&myHashTable, "banana", 20);
    insert(&myHashTable, "cherry", 30);
    insert(&myHashTable, "date", 40);
    insert(&myHashTable, "elderberry", 50); // Có thể xảy ra va chạm với 'apple' hoặc 'banana' tùy hàm băm
    insert(&myHashTable, "apricot", 60);    // Có thể va chạm

    displayHashTable(&myHashTable);

    // Tra cứu giá trị
    int *value;
    value = lookup(&myHashTable, "banana");
    if (value != NULL) {
        printf("Tìm thấy \"banana\": %d\n", *value);
    } else {
        printf("Không tìm thấy \"banana\"\n");
    }

    value = lookup(&myHashTable, "grape");
    if (value != NULL) {
        printf("Tìm thấy \"grape\": %d\n", *value);
    } else {
        printf("Không tìm thấy \"grape\"\n");
    }

    value = lookup(&myHashTable, "apricot");
    if (value != NULL) {
        printf("Tìm thấy \"apricot\": %d\n", *value);
    } else {
        printf("Không tìm thấy \"apricot\"\n");
    }

    // Xóa phần tử
    delete(&myHashTable, "cherry");
    delete(&myHashTable, "orange"); // Thử xóa phần tử không tồn tại

    displayHashTable(&myHashTable);

    delete(&myHashTable, "apricot");
    delete(&myHashTable, "apple");

    displayHashTable(&myHashTable);


    // Giải phóng bộ nhớ
    freeHashTable(&myHashTable);

    return 0;
}
