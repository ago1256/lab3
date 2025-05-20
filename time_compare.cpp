#include <iostream>
#include <chrono>
#include "time_compare.h"

using namespace std;
using clk = std::chrono::high_resolution_clock;
using ms = std::chrono::duration<double, std::milli>;


void test_sequences(int count) {
    cout << "Sequence\n";
    
    {
        Array_sequence<int> seq;
        auto start = clk::now();
        for (int i = 0; i < count; i++) {
            seq.append(i);
        }
        auto end = clk::now();
        cout << "Array_sequence append: " 
             << ms(end - start).count() << " ms\n";

        start = clk::now();
        for (int i = 0; i < count; i++) {
            seq.remove(seq.get_length()-1);
        }
        end = clk::now();
        cout << "Array_sequence remove: " 
             << ms(end - start).count() << " ms\n";
    }

    {
        List_sequence<int> seq;
        auto start = clk::now();
        for (int i = 0; i < count; i++) {
            seq.append(i);
        }
        auto end = clk::now();
        cout << "List_sequence append: " 
             << ms(end - start).count() << " ms\n";

        start = clk::now();
        for (int i = 0; i < count; i++) {
            seq.remove(seq.get_length()-1);
        }
        end = clk::now();
        cout << "List_sequence remove: " 
             << ms(end - start).count() << " ms\n";
    }
}

void test_queues(int count) {
    cout << "\nQueue\n";
    
    {
        Array_queue<int> q;
        auto start = clk::now();
        for (int i = 0; i < count; i++) {
            q.enqueue(i);
        }
        auto end = clk::now();
        cout << "Array_queue enqueue: " 
             << ms(end - start).count() << " ms\n";

        start = clk::now();
        for (int i = 0; i < count; i++) {
            q.dequeue();
        }
        end = clk::now();
        cout << "Array_queue dequeue: " 
             << ms(end - start).count() << " ms\n";
    }

    {
        List_queue<int> q;
        auto start = clk::now();
        for (int i = 0; i < count; i++) {
            q.enqueue(i);
        }
        auto end = clk::now();
        cout << "List_queue enqueue: " 
             << ms(end - start).count() << " ms\n";

        start = clk::now();
        for (int i = 0; i < count; i++) {
            q.dequeue();
        }
        end = clk::now();
        cout << "List_queue dequeue: " 
             << ms(end - start).count() << " ms\n";
    }
}

void test_stacks(int count) {
    cout << "\nStack\n";
    
    {
        Array_stack<int> s;
        auto start = clk::now();
        for (int i = 0; i < count; i++) {
            s.push(i);
        }
        auto end = clk::now();
        cout << "Array_stack push: " 
             << ms(end - start).count() << " ms\n";

        start = clk::now();
        for (int i = 0; i < count; i++) {
            s.pop();
        }
        end = clk::now();
        cout << "Array_stack pop: " 
             << ms(end - start).count() << " ms\n";
    }

    {
        List_stack<int> s;
        auto start = clk::now();
        for (int i = 0; i < count; i++) {
            s.push(i);
        }
        auto end = clk::now();
        cout << "List_stack push: " 
             << ms(end - start).count() << " ms\n";

        start = clk::now();
        for (int i = 0; i < count; i++) {
            s.pop();
        }
        end = clk::now();
        cout << "List_stack pop: " 
             << ms(end - start).count() << " ms\n";
    }
}

int main() {
    int count;
    cout << "Введите количество значений для тестирования: ";
    cin >> count;

    test_sequences(count);
    test_queues(count);
    test_stacks(count);
    return 0;
}