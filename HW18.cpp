#include <iostream>

template<typename T>
class Stack {
public:

    Stack() {
        arr = new T[1];
        capacity = 1;
    }

    ~Stack() {
        delete[] arr;
    }

    [[nodiscard]] T sizeArr() const {
        return size;
    }

    void addMemory() {
        capacity *= 2;
        T* tmp = arr;
        arr = new T[capacity];
        for (int i = 0; i < size; ++i) arr[i] = tmp[i];
        delete[] tmp;
    }

    void push(const T& value) {
        if (size >= capacity) addMemory();
        arr[size++] = value;
    }

    T pop() {
        T value = arr[size - 1];
        return value;
    }

private:
    T* arr;
    T size{};
    T capacity{};

};

int main()
{
    Stack<int> stack;

    stack.push(5);
    stack.push(6);
    stack.push(8);

    std::cout << stack.sizeArr() << std::endl;
    std::cout << stack.pop() << std::endl;

    return 0;
}

