#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <stdexcept>
#include<sstream>
#include <memory>
#include <type_traits>
#include"interface.h"


int error_input(int min, int max) {
    std::cout << " " << min << "-" << max << ":\n";
    int value;
    while (true) {
        if (!(std::cin >> value)) {
            errors_detection(Error::INVALID_ARGUMENT);
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (value < min || value > max) {
            errors_detection(Error::INVALID_INDEX);
            continue;
        }
        return value;
    }
}

template<typename T>
T get_input() {
    T value;
    if (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw Error(Error::INVALID_ARGUMENT);
    }
    return value;
}

template<typename T>
std::vector<T> get_input_array() {
    std::vector<T> arr;
    std::cout << "Введите значения через пробел (Enter для завершения):\n";
    if(std::cin.peek() == '\n') {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    T value;
    while (iss >> value) {
        arr.push_back(value);
    }
    return arr;
}

class ContainerInterface {
public:
    virtual ~ContainerInterface() = default;
    virtual void print() const = 0;
    virtual void add_element() = 0;
    virtual void remove_element() = 0;
    virtual ContainerInterface* get_subcontainer() const = 0;
    virtual ContainerInterface* concat(ContainerInterface* other) const = 0;
    virtual std::string get_type() const = 0;
    virtual int get_implementation() const = 0;
};
    
template <typename T>
class SequenceContainer : public ContainerInterface {
    Sequence<T>* sequence;
    int seq_type; // 1 - Array, 2 - List

public:
    SequenceContainer(int type, const std::vector<T>& items = {}){
        seq_type = type;
        if (type == 1) {
            sequence = new Array_sequence<T>();
        } else {
            sequence = new List_sequence<T>();
        }
        for (const auto& item : items) {
            sequence->append(item);
        }
    }

    SequenceContainer(int type, Sequence<T>* other){
        seq_type = type;
        sequence = other->clone();
    }

    ~SequenceContainer() {
        delete sequence;
    }

    void print() const override {
        sequence->print_seq();
        std::cout << " Последовательность ";
        switch(seq_type){
        case 1: std::cout << "(массив)\n"; break;
        case 2: std::cout << "(связный список)\n"; break;
        }
    }

    void add_element() override {
        std::cout << "Введите индекс из диапазона";
        int index = error_input(0, sequence->get_length()-1);
        std::cout << "Введите значение для добавления в последовательность: ";
        T value = get_input<T>();
        sequence->insert_at(value, index);
    }
    

    void remove_element() override {
        if (sequence->get_length() == 0) {
            throw Error(Error::EMPTY_CONTAINER);
        }
        std::cout << "Введите индекс из диапазона";
        int index = error_input(0, sequence->get_length()-1);
        sequence->remove(index);
    }

    ContainerInterface* get_subcontainer() const override {
        if (sequence->get_length() == 0) {
            throw Error(Error::EMPTY_CONTAINER);
        }
        
        std::cout << "Введите начальный индекс из диапазона";
        int start = error_input(0, sequence->get_length()-1);
        
        std::cout << "Введите конечный индекс из диапазона";
        int end = error_input(start, sequence->get_length()-1);
        
        Sequence<T>* sub_seq = sequence->get_sub_sequence(start, end);
        return new SequenceContainer<T>(seq_type, sub_seq);
    }

    ContainerInterface* concat(ContainerInterface* other) const override {
        SequenceContainer<T>* other_seq = dynamic_cast<SequenceContainer<T>*>(other);
        if (!other_seq || other_seq->seq_type != seq_type) {
            throw Error(Error::INCOMPATIBLE_TYPES);
        }
        
        Sequence<T>* concat_seq = sequence->concat(other_seq->sequence);
        return new SequenceContainer<T>(seq_type, concat_seq);
    }

    std::string get_type() const override {
        return "Sequence";
    }

    int get_implementation() const override {
        return seq_type;
    }
};

    
template <typename T>
class QueueContainer : public ContainerInterface {
    Queue<T>* queue;
    int queue_type; // 1 - Array, 2 - List

public:
    QueueContainer(int type, const std::vector<T>& items = {}) : queue_type(type) {
        if (type == 1) {
            queue = new Array_queue<T>();
        } else {
            queue = new List_queue<T>();
        }
        
        for (const auto& item : items) {
            queue->enqueue(item);
        }
    }

    QueueContainer(int type, Queue<T>* other){
    queue_type = type;
    queue = other->clone();
    }

    ~QueueContainer() {
        delete queue;
    }

    void print() const override {
    queue->print_queue();
    std::cout << " Очередь ";
    switch(queue_type){
        case 1: std::cout << "(массив)\n"; break;
        case 2: std::cout << "(связный список)\n"; break;
        }
    }

    void add_element() override {
        std::cout << "Введите значение для добавления в очередь: ";
        T value = get_input<T>();
        queue->enqueue(value);
    }

    void remove_element() override {
        if (queue->is_empty()) {
            throw Error(Error::EMPTY_CONTAINER);
        }
        T removed = queue->dequeue();
        std::cout << "Удален элемент: " << removed << "\n";
    }

    ContainerInterface* get_subcontainer() const override {
        if (queue->is_empty()) {
            throw Error(Error::EMPTY_CONTAINER);
        }
        
        std::cout << "Введите начальный индекс из диапазона";
        int start = error_input(0, queue->count()-1);
        
        std::cout << "Введите конечный индекс из диапазона";
        int end = error_input(start, queue->count()-1);
        
        Queue<T>* sub_queue = queue->sub_queue(start, end);
        return new QueueContainer<T>(queue_type, sub_queue);
    }

    ContainerInterface* concat(ContainerInterface* other) const override {
        QueueContainer<T>* other_queue = dynamic_cast<QueueContainer<T>*>(other);
        if (!other_queue || other_queue->queue_type != queue_type) {
            throw Error(Error::INCOMPATIBLE_TYPES);
        }
        
        Queue<T>* concat_queue = queue->concat(*other_queue->queue);
        return new QueueContainer<T>(queue_type, concat_queue);
    }

    std::string get_type() const override {
        return "Queue";
    }

    int get_implementation() const override {
        return queue_type;
    }
};


template <typename T>
class StackContainer : public ContainerInterface {
    Stack<T>* stack;
    int stack_type; // 1 - Array, 2 - List

public:
    StackContainer(int type, const std::vector<T>& items = {}) : stack_type(type) {
        if (type == 1) {
            stack = new Array_stack<T>();
        } else {
            stack = new List_stack<T>();
        }
        
        for (const auto& item : items) {
            stack->push(item);
        }
    }
   
    StackContainer(int type, Stack<T>* other){
        stack_type = type;
        stack = other->clone();
    }

    ~StackContainer() {
        delete stack;
    }

    void print() const override {
        stack->print_stack();
        std::cout << " Стек ";
        switch(stack_type){
            case 1: std::cout << "(массив)\n"; break;
            case 2: std::cout << "(связный список)\n"; break;
            }
    }

    void add_element() override {
        std::cout << "Введите значение для добавления в стек: ";
        T value = get_input<T>();
        stack->push(value);
    }

    
    void remove_element() override {
        if (stack->is_empty()) {
            throw Error(Error::EMPTY_CONTAINER);
        }
        T removed = stack->pop();
        std::cout << "Удален элемент: " << removed << "\n";
    }

    ContainerInterface* get_subcontainer() const override {
        if (stack->size() == 0) {
            throw Error(Error::EMPTY_CONTAINER);
        }
        
        std::cout << "Введите начальный индекс из диапазона";
        int start = error_input(0, stack->size()-1);
        
        std::cout << "Введите конечный индекс из диапазона";
        int end = error_input(start, stack->size()-1);
        
        Stack<T>* sub_stack = stack->sub_stack(start, end);
        return new StackContainer<T>(stack_type, sub_stack);
    }

    ContainerInterface* concat(ContainerInterface* other) const override {
        StackContainer<T>* other_stack = dynamic_cast<StackContainer<T>*>(other);
        if (!other_stack || other_stack->stack_type != stack_type) {
            throw Error(Error::INCOMPATIBLE_TYPES);
        }
        Stack<T>* concat_stack = stack->concat(*other_stack->stack);
        return new StackContainer<T>(stack_type, concat_stack);
    }

    std::string get_type() const override {
        return "Stack";
    }

    int get_implementation() const override {
        return stack_type;
    }
};


int enter() {
    std::vector<ContainerInterface*> containers;
    while (true) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("cls"); 
        try {
        std::cout << "1 Добавить контейнер\n";
        std::cout << "2 Вывести все контейнеры\n";
        std::cout << "3 Добавить элемент\n";
        std::cout << "4 Удалить элемент\n";
        std::cout << "5 Получить подконтейнер\n";
        std::cout << "6 Конкатенация\n";
        std::cout << "7 Удалить контейнер\n";
        std::cout << "8 Выход\n";
        std::cout << "Выберите действие в диапазоне";
        
        int choice = error_input(1, 8);
        
        switch (choice) {
            case 1: {
                std::cout << "Тип контейнера:\n";
                std::cout << "1 Последовательность\n";
                std::cout << "2 Очередь\n";
                std::cout << "3 Стек\n";
                std::cout << "Выберите значение в диапазоне";
                int container_type = error_input(1, 3);
                
                std::cout << "Реализация:\n";
                std::cout << "1 На массиве\n";
                std::cout << "2 На списке\n";
                std::cout << "Выберите значение в диапазоне";
                int impl_type = error_input(1, 2);
                
                std::cout << "Тип данных:\n";
                std::cout << "1 Целое число\n";
                std::cout << "2 Вещественное число\n";
                std::cout << "3 Строка\n";
                std::cout << "4 Пользовательский тип\n";
                std::cout << "Выберите значение в диапазоне";
                int data_type = error_input(1, 4);
                
                ContainerInterface* new_container = nullptr;
                std::vector<int> int_values;
                std::vector<double> double_values;
                std::vector<std::string> string_values;
                std::vector<User> user_values;
                
                switch (data_type) {
                    case 1: int_values = get_input_array<int>(); break;
                    case 2: double_values = get_input_array<double>(); break;
                    case 3: string_values = get_input_array<std::string>(); break;
                    case 4: user_values = get_input_array<User>(); break;
                }
                
                switch (container_type) {
                    case 1: // Sequence
                        switch (data_type) {
                            case 1: new_container = new SequenceContainer<int>(impl_type, int_values); break;
                            case 2: new_container = new SequenceContainer<double>(impl_type, double_values); break;
                            case 3: new_container = new SequenceContainer<std::string>(impl_type, string_values); break;
                            case 4: new_container = new SequenceContainer<User>(impl_type, user_values); break;
                        }
                        break;
                    case 2: // Queue
                        switch (data_type) {
                            case 1: new_container = new QueueContainer<int>(impl_type, int_values); break;
                            case 2: new_container = new QueueContainer<double>(impl_type, double_values); break;
                            case 3: new_container = new QueueContainer<std::string>(impl_type, string_values); break;
                            case 4: new_container = new QueueContainer<User>(impl_type, user_values); break;
                        }
                        break;
                    case 3: // Stack
                        switch (data_type) {
                            case 1: new_container = new StackContainer<int>(impl_type, int_values); break;
                            case 2: new_container = new StackContainer<double>(impl_type, double_values); break;
                            case 3: new_container = new StackContainer<std::string>(impl_type, string_values); break;
                            case 4: new_container = new StackContainer<User>(impl_type, user_values); break;
                        }
                        break;
                }
                
                containers.push_back(new_container);
                std::cout << "Контейнер добавлен\n";
                break;
            }
            case 2: {
                if (containers.empty()) {
                    std::cout << "Массив пуст\n";
                    break;
                }
                for (size_t i = 0; i < containers.size(); i++) {
                    std::cout << i << " ";
                    containers[i]->print();
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            case 3: {
                if (containers.empty()) {
                    std::cout << "Массив пуст\n";
                    break;
                }
                std::cout << "Введите индекс из диапазона";
                int index = error_input(0, containers.size()-1);
                containers[index]->add_element();
                break;
            }
            case 4: {
                if (containers.empty()) {
                    throw Error(Error::EMPTY_CONTAINER);
                }
                std::cout << "Введите индекс из диапазона";
                int index = error_input(0, containers.size()-1);
                containers[index]->remove_element();
                break;
            }
            case 5: {
                if (containers.empty()) {
                    throw Error(Error::EMPTY_CONTAINER);
                }
                std::cout << "Введите индекс из диапазона";
                int index = error_input(0, containers.size()-1);
                
                ContainerInterface* subcontainer = containers[index]->get_subcontainer();
                std::cout << "Подконтейнер создан:\n";
                subcontainer->print();
                
                std::cout << "Добавить в массив? (1-Да, 0-Нет): ";
                std::cout << "Введите значение в диапазоне";
                int add_choice = error_input(0, 1);
                if (add_choice == 1) {
                    containers.push_back(subcontainer);
                    std::cout << "Подконтейнер добавлен\n";
                } else {
                    delete subcontainer;
                }
                break;
            }
            case 6: {
                if (containers.empty()) {
                    throw Error(Error::EMPTY_CONTAINER);
                }
                std::cout << "Введите индекс первого контейнера из диапазона";
                int index1 = error_input(0, containers.size()-1);
                
                std::cout << "Введите индекс второго контейнера из диапазона";
                int index2 = error_input(0, containers.size()-1);
                
                ContainerInterface* concatenated = containers[index1]->concat(containers[index2]);
                concatenated->print();
                
                std::cout << "Добавить в массив? (1-Да, 0-Нет): ";
                int add_choice = error_input(0, 1);
                if (add_choice == 1) {
                    containers.push_back(concatenated);
                    std::cout << "Контейнер добавлен\n";
                } else {
                    delete concatenated;
                }
                break;
            }
            case 7: {
                if (containers.empty()) {
                    throw Error(Error::EMPTY_CONTAINER);
                }
                std::cout << "Введите индекс из диапазона";
                int index = error_input(0, containers.size()-1);
                
                delete containers[index];
                containers.erase(containers.begin() + index);
                std::cout << "Контейнер удален\n";
                break;
            }
            case 8: {
                for (auto container : containers) {
                    delete container;
                }
                containers.clear();
                return 0;
            }
        }
    }
    catch(Error er) {
        errors_detection(er);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
        }
    }
}
