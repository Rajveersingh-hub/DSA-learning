class MyCircularDeque {
    int *arr;
    int front;
    int rear;
    int size;

public:
    MyCircularDeque(int k) {
        size = k;
        arr = new int[size];
        front = rear = -1;
    }

    bool insertFront(int value) {
        // Check for full condition
        if ((front == 0 && rear == size - 1) ||
            (front == rear + 1)) {
            return false;
        }

        // First insertion
        else if (front == -1 && rear == -1) {
            front = rear = 0;
            arr[front] = value;
        }

        // Cyclic nature
        else if (front == 0) {
            front = size - 1;
            arr[front] = value;
        }

        // Normal case
        else {
            front--;
            arr[front] = value;
        }

        return true;
    }

    bool insertLast(int value) {
        // Check for full condition
        if ((front == 0 && rear == size - 1) ||
            (front == rear + 1)) {
            return false;
        }

        // First insertion
        else if (front == -1 && rear == -1) {
            front = rear = 0;
            arr[rear] = value;
        }

        // Cyclic nature
        else if (rear == size - 1) {
            rear = 0;
            arr[rear] = value;
        }

        // Normal case
        else {
            rear++;
            arr[rear] = value;
        }

        return true;
    }

    bool deleteFront() {
        // Check for empty
        if (front == -1 && rear == -1) {
            return false;
        }

        // Single element
        else if (front == rear) {
            front = rear = -1;
        }

        // Cyclic nature
        else if (front == size - 1) {
            front = 0;
        }

        // Normal case
        else {
            front++;
        }

        return true;
    }

    bool deleteLast() {
        // Check for empty
        if (front == -1 && rear == -1) {
            return false;
        }

        // Single element
        else if (front == rear) {
            front = rear = -1;
        }

        // Cyclic nature
        else if (rear == 0) {
            rear = size - 1;
        }

        // Normal case
        else {
            rear--;
        }

        return true;
    }

    int getFront() {
        if (front == -1 && rear == -1) {
            return -1;
        }

        return arr[front];
    }

    int getRear() {
        if (front == -1 && rear == -1) {
            return -1;
        }

        return arr[rear];
    }

    bool isEmpty() {
        if (front == -1 && rear == -1) {
            return true;
        }

        return false;
    }

    bool isFull() {
        if ((front == 0 && rear == size - 1) ||
            (front == rear + 1)) {
            return true;
        }

        return false;
    }
};