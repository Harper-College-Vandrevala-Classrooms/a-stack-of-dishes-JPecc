#include <iostream>
#include <array>
#include <string>

class Dish {
private:
    std::string description;

public:
    Dish() : description("unknown dish") {}
    
    Dish(std::string description) {
        this->description = description;
    }

    std::string get_description() {
        return this->description;
    }
};

class DishStack {
private:
    static const int MAX_SIZE = 10;
    std::array<Dish, MAX_SIZE> stack;
    int top;

public:
    DishStack() : top(-1) {}

    void push(const Dish& dish) {
        if (top >= MAX_SIZE - 1) {
            std::cout << "The stack is full. Cannot push another dish." << std::endl;
        } else {
            stack[++top] = dish;
        }
    }

    Dish pop() {
        if (top < 0) {
            throw std::out_of_range("The stack is empty. Cannot pop a dish.");
        }
        return stack[top--];
    }

    Dish peek() const {
        if (top < 0) {
            throw std::out_of_range("The stack is empty. Cannot peek a dish.");
        }
        return stack[top];
    }

    int size() const {
        return top + 1;
    }

    bool is_empty() const {
        return top < 0;
    }
};

int main() {
    DishStack stack;

    Dish one_dish("A dish with one fish pattern on it");
    Dish two_dish("A dish with two fish patterns on it");
    Dish red_dish("A dish with a red fish pattern on it");
    Dish blue_dish("A dish with a blue fish pattern on it");

    // The variable stack_size should equal zero.
    int stack_size = stack.size();
    std::cout << "Initial stack size: " << stack_size << std::endl;

    stack.push(one_dish);
    stack.push(two_dish);
    stack.push(red_dish);
    stack.push(blue_dish);

    // The variable size_after_pushes should equal four.
    int size_after_pushes = stack.size();
    std::cout << "Size after pushes: " << size_after_pushes << std::endl;

    // The variable peeked_dish should have a description of "A dish with a blue fish pattern on it"
    Dish peeked_dish = stack.peek();
    std::cout << "Peeked dish description: " << peeked_dish.get_description() << std::endl;

    // The variable popped_dish should have a description of "A dish with a blue fish pattern on it"
    Dish popped_dish = stack.pop();
    std::cout << "Popped dish description: " << popped_dish.get_description() << std::endl;

    // The variable another_popped_dish should have a description of "A dish with a red fish pattern on it"
    Dish another_popped_dish = stack.pop();
    std::cout << "Another popped dish description: " << another_popped_dish.get_description() << std::endl;

    // The variable final_size should equal two.
    int final_size = stack.size();
    std::cout << "Final stack size: " << final_size << std::endl;

    return 0;
}
