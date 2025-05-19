#include <iostream>
#include <chrono>
#include "time_compare.h"

using namespace std;
using namespace std::chrono;



void test_sequences(int operations) {
    cout << "Sequence\n";
    
    {
        Array_sequence<int> seq;
        auto start = high_resolution_clock::now();
        for (int i = 0; i < operations; i++) {
            seq.append(i);
        }
        auto end = high_resolution_clock::now();
        cout << "Array_sequence append: " 
             << duration_cast<milliseconds>(end - start).count() << " ms\n";

        start = high_resolution_clock::now();
        for (int i = 0; i < operations; i++) {
            seq.remove(seq.get_length()-1);
        }
        end = high_resolution_clock::now();
        cout << "Array_sequence remove: " 
             << duration_cast<milliseconds>(end - start).count() << " ms\n";
    }

    {
        List_sequence<int> seq;
        auto start = high_resolution_clock::now();
        for (int i = 0; i < operations; i++) {
            seq.append(i);
        }
        auto end = high_resolution_clock::now();
        cout << "List_sequence append: " 
             << duration_cast<milliseconds>(end - start).count() << " ms\n";

        start = high_resolution_clock::now();
        for (int i = 0; i < operations; i++) {
            seq.remove(seq.get_length()-1);
        }
        end = high_resolution_clock::now();
        cout << "List_sequence remove: " 
             << duration_cast<milliseconds>(end - start).count() << " ms\n";
    }
}

void test_queues(int operations) {
    cout << "Queue\n";
    
    {
        Array_queue<int> q;
        auto start = high_resolution_clock::now();
        for (int i = 0; i < operations; i++) {
            q.enqueue(i);
        }
        auto end = high_resolution_clock::now();
        cout << "Array_queue enqueue: " 
             << duration_cast<milliseconds>(end - start).count() << " ms\n";

        start = high_resolution_clock::now();
        for (int i = 0; i < operations; i++) {
            q.dequeue();
        }
        end = high_resolution_clock::now();
        cout << "Array_queue dequeue: " 
             << duration_cast<milliseconds>(end - start).count() << " ms\n";
    }

    {
        List_queue<int> q;
        auto start = high_resolution_clock::now();
        for (int i = 0; i < operations; i++) {
            q.enqueue(i);
        }
        auto end = high_resolution_clock::now();
        cout << "List_queue enqueue: " 
             << duration_cast<milliseconds>(end - start).count() << " ms\n";

        start = high_resolution_clock::now();
        for (int i = 0; i < operations; i++) {
            q.dequeue();
        }
        end = high_resolution_clock::now();
        cout << "List_queue dequeue: " 
             << duration_cast<milliseconds>(end - start).count() << " ms\n";
    }
}

void test_stacks(int operations) {
    cout << "\nStack\n";
    
    {
        Array_stack<int> s;
        auto start = high_resolution_clock::now();
        for (int i = 0; i < operations; i++) {
            s.push(i);
        }
        auto end = high_resolution_clock::now();
        cout << "Array_stack push: " 
             << duration_cast<milliseconds>(end - start).count() << " ms\n";

        start = high_resolution_clock::now();
        for (int i = 0; i < operations; i++) {
            s.pop();
        }
        end = high_resolution_clock::now();
        cout << "Array_stack pop: " 
             << duration_cast<milliseconds>(end - start).count() << " ms\n";
    }

    {
        List_stack<int> s;
        auto start = high_resolution_clock::now();
        for (int i = 0; i < operations; i++) {
            s.push(i);
        }
        auto end = high_resolution_clock::now();
        cout << "List_stack push: " 
             << duration_cast<milliseconds>(end - start).count() << " ms\n";

        start = high_resolution_clock::now();
        for (int i = 0; i < operations; i++) {
            s.pop();
        }
        end = high_resolution_clock::now();
        cout << "List_stack pop: " 
             << duration_cast<milliseconds>(end - start).count() << " ms\n";
    }
}

int main() {
    int operations;
    cout << "Enter number of operations to test: ";
    cin >> operations;

    test_queues(operations);
    test_stacks(operations);

    return 0;
}