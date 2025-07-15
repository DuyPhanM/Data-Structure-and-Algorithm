#include <stdio.h>
#include <stdlib.h> // Để sử dụng malloc và free

// --- STACK IMPLEMENTATION ---
#define MAX_STACK_SIZE 100

typedef struct {
    int items[MAX_STACK_SIZE];
    int top;
} Stack;

// Khởi tạo Stack
void initStack(Stack *s) {
    s->top = -1; // -1 nghĩa là stack rỗng
}

// Kiểm tra xem Stack có rỗng không
int isStackEmpty(Stack *s) {
    return s->top == -1;
}

// Kiểm tra xem Stack có đầy không
int isStackFull(Stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}

// Thêm phần tử vào Stack (Push)
void push(Stack *s, int value) {
    if (isStackFull(s)) {
        printf("Lỗi: Stack đầy, không thể thêm phần tử %d\n", value);
        return;
    }
    s->items[++(s->top)] = value;
    printf("Đã thêm %d vào Stack\n", value);
}

// Lấy phần tử từ Stack (Pop)
int pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Lỗi: Stack rỗng, không thể lấy phần tử\n");
        return -1; // Trả về giá trị lỗi
    }
    return s->items[(s->top)--];
}

// Xem phần tử ở đỉnh Stack (Peek)
int peekStack(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Lỗi: Stack rỗng, không có phần tử để xem\n");
        return -1; // Trả về giá trị lỗi
    }
    return s->items[s->top];
}

// --- QUEUE IMPLEMENTATION ---
#define MAX_QUEUE_SIZE 100

typedef struct {
    int items[MAX_QUEUE_SIZE];
    int front; // Chỉ số của phần tử đầu hàng đợi
    int rear;  // Chỉ số của phần tử cuối hàng đợi
    int count; // Số lượng phần tử hiện có
} Queue;

// Khởi tạo Queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

// Kiểm tra xem Queue có rỗng không
int isQueueEmpty(Queue *q) {
    return q->count == 0;
}

// Kiểm tra xem Queue có đầy không
int isQueueFull(Queue *q) {
    return q->count == MAX_QUEUE_SIZE;
}

// Thêm phần tử vào Queue (Enqueue)
void enqueue(Queue *q, int value) {
    if (isQueueFull(q)) {
        printf("Lỗi: Queue đầy, không thể thêm phần tử %d\n", value);
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // Vòng lặp để sử dụng lại không gian mảng
    q->items[q->rear] = value;
    q->count++;
    printf("Đã thêm %d vào Queue\n", value);
}

// Lấy phần tử từ Queue (Dequeue)
int dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Lỗi: Queue rỗng, không thể lấy phần tử\n");
        return -1; // Trả về giá trị lỗi
    }
    int item = q->items[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE; // Vòng lặp
    q->count--;
    return item;
}

// Xem phần tử ở đầu Queue (Front/Peek)
int peekQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Lỗi: Queue rỗng, không có phần tử để xem\n");
        return -1; // Trả về giá trị lỗi
    }
    return q->items[q->front];
}

// --- MAIN FUNCTION ---
int main() {
    printf("--- MINH HỌA STACK ---\n");
    Stack myStack;
    initStack(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Phần tử đỉnh Stack: %d\n", peekStack(&myStack));
    printf("Đã lấy từ Stack: %d\n", pop(&myStack));
    printf("Đã lấy từ Stack: %d\n", pop(&myStack));
    printf("Kiểm tra Stack rỗng? %s\n", isStackEmpty(&myStack) ? "Có" : "Không");
    push(&myStack, 40);
    printf("Đã lấy từ Stack: %d\n", pop(&myStack));
    printf("Đã lấy từ Stack: %d\n", pop(&myStack)); // Thử lấy khi stack rỗng

    printf("\n--- MINH HỌA QUEUE ---\n");
    Queue myQueue;
    initQueue(&myQueue);

    enqueue(&myQueue, 100);
    enqueue(&myQueue, 200);
    enqueue(&myQueue, 300);

    printf("Phần tử đầu Queue: %d\n", peekQueue(&myQueue));
    printf("Đã lấy từ Queue: %d\n", dequeue(&myQueue));
    printf("Đã lấy từ Queue: %d\n", dequeue(&myQueue));
    printf("Kiểm tra Queue rỗng? %s\n", isQueueEmpty(&myQueue) ? "Có" : "Không");
    enqueue(&myQueue, 400);
    printf("Đã lấy từ Queue: %d\n", dequeue(&myQueue));
    printf("Đã lấy từ Queue: %d\n", dequeue(&myQueue)); // Thử lấy khi queue rỗng

    return 0;
}
