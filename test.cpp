#include <iostream>
#include <cassert>
#include"test.h"


void test_array_queue_enqueue() {
    std::cout << "Тест Array_queue.enqueue()" << std::endl;
    
    int arr[] = {10, 20};
    Array_sequence<int> expected_seq(arr, 2);
    Array_queue<int> expected_queue(expected_seq);
    
    Array_queue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    
    assert(queue == expected_queue);
    std::cout << "Тест пройден!\n" << std::endl;
}

void test_array_queue_dequeue() {
    std::cout << "Тест Array_queue.dequeue()" << std::endl;
    
    int expected_arr[] = {20, 30};
    Array_sequence<int> expected_seq(expected_arr, 2);
    Array_queue<int> expected_queue(expected_seq);
    
    int arr[] = {10, 20, 30};
    Array_sequence<int> init_seq(arr,3);
    Array_queue<int> queue(init_seq);
    
    queue.dequeue();
    
    assert(queue == expected_queue);
    std::cout << "Тест пройден!\n" << std::endl;
}

void test_array_queue_get_front() {
    std::cout << "Тест Array_queue.get_front()" << std::endl;
    int arr[] = {10, 20, 30};
    Array_sequence<int> init_seq(arr,3);
    Array_queue<int> queue(init_seq);
    assert(queue.get_front() == 10);
    std::cout << "Тест пройден!\n" << std::endl;
}

void test_array_queue_concat(){
    std::cout << "Тест Array_queue.concat()" << std::endl;

    int expected_arr[] = {2, 3, 4, 5};
    Array_sequence<int> expected_seq(expected_arr, 4);
    Array_queue<int> expected_queue(expected_seq);
    
    int arr1[] = {2, 3};
    Array_sequence<int> seq1(arr1,2);
    Array_queue<int> queue(seq1);

    int arr2[] = {4, 5};
    Array_sequence<int> seq2(arr2,2);
    Array_queue<int> queue2(seq2);
    
    Queue<int>* queue_res = queue.concat(queue2);
    
    assert(*queue_res == expected_queue);
 
    std::cout << "Тест пройден!\n" << std::endl;
}

void test_array_queue_sub_queue(){
    std::cout << "Тест Array_queue.sub_queue()" << std::endl;

    int expected_arr[] = {2, 3};
    Array_sequence<int> expected_seq(expected_arr, 2);
    Array_queue<int> expected_queue(expected_seq);
    
    int arr1[] = {1, 2, 3, 4, 5};
    Array_sequence<int> seq1(arr1,5);
    Array_queue<int> queue(seq1);

    Queue<int>* queue_res = queue.sub_queue(1, 2);
    
    assert(*queue_res == expected_queue);
 
    std::cout << "Тест пройден!\n" << std::endl;
}

void test_array_queue_clear() {
    std::cout << "Тест Array_queue.clear()" << std::endl;
    
    Array_sequence<int> expected_seq(0);
    Array_queue<int> expected_queue(expected_seq);

    int init_arr[] = {1, 2, 3};
    Array_sequence<int> init_seq(init_arr, 3);
    Array_queue<int> queue(init_seq);
    
    queue.clear();
    
    assert(queue == expected_queue);
    std::cout << "Тест пройден!\n" << std::endl;
}


void test_list_queue_enqueue() {
    std::cout << "Тест List_queue.enqueue()" << std::endl;
    
    std::string expected_arr[] = {"a", "b"};
    List_sequence<std::string> expected_seq(expected_arr, 2);
    List_queue<std::string> expected_queue(expected_seq);

    List_queue<std::string> queue;
    queue.enqueue("a");
    queue.enqueue("b");
    
    assert(queue == expected_queue);
    std::cout << "Тест пройден!\n" << std::endl;
}

void test_list_queue_dequeue() {
    std::cout << "Тест List_queue.dequeue()" << std::endl;
    
    int expected_arr[] = {10, 15};
    List_sequence<int> expected_seq(expected_arr, 2);
    List_queue<int> expected_queue(expected_seq);

    int init_arr[] = {5, 10, 15};
    List_sequence<int> init_seq(init_arr, 3);
    List_queue<int> queue(init_seq);
    
    queue.dequeue();
    
    assert(queue == expected_queue);
    std::cout << "Тест пройден!\n" << std::endl;
}

void test_list_queue_get_front(){
    std::cout << "Тест List_queue.get_front()" << std::endl;

    int init_arr[] = {5, 6, 8};
    List_sequence<int> init_seq(init_arr, 3);
    List_queue<int> queue(init_seq);
    assert(queue.get_front() == 5);
    std::cout << "Тест пройден!\n" << std::endl;
}

void test_list_queue_concat(){
    std::cout << "Тест List_queue.concat()" << std::endl;

    int expected_arr[] = {2, 3, 4, 5};
    List_sequence<int> expected_seq(expected_arr, 4);
    List_queue<int> expected_queue(expected_seq);
    
    int arr1[] = {2, 3};
    List_sequence<int> seq1(arr1,2);
    List_queue<int> queue(seq1);

    int arr2[] = {4, 5};
    List_sequence<int> seq2(arr2,2);
    List_queue<int> queue2(seq2);
    
    Queue<int>* queue_res = queue.concat(queue2);
    
    assert(*queue_res == expected_queue);
 
    std::cout << "Тест пройден!\n" << std::endl;
}

void test_list_queue_sub_queue(){
    std::cout << "Тест List_queue.sub_queue()" << std::endl;

    int expected_arr[] = {2, 3};
    List_sequence<int> expected_seq(expected_arr, 2);
    List_queue<int> expected_queue(expected_seq);
    
    int arr1[] = {1, 2, 3, 4, 5};
    List_sequence<int> seq1(arr1,5);
    List_queue<int> queue(seq1);

    Queue<int>* queue_res = queue.sub_queue(1, 2);
    
    assert(*queue_res == expected_queue);
 
    std::cout << "Тест пройден!\n" << std::endl;
}

void test_list_queue_clear() {
    std::cout << "Тест List_queue.clear()" << std::endl;
    
    List_sequence<int> expected_seq;
    List_queue<int> expected_queue(expected_seq);

    int init_arr[] = {1, 2, 3};
    List_sequence<int> init_seq(init_arr, 3);
    List_queue<int> queue(init_seq);
    
    queue.clear();
    
    assert(queue == expected_queue);
    std::cout << "Тест пройден!\n" << std::endl;
}

void test_array_stack_push() {
    std::cout << "Тест Array_stack.push()" << std::endl;
    
    int arr[] = {10, 20}; 
    Array_sequence<int> expected_seq(arr, 2);
    Array_stack<int> expected_stack(expected_seq);
    
    Array_stack<int> stack;
    stack.push(10);
    stack.push(20);
    
    assert(stack == expected_stack);
    std::cout << "Тест пройден!\n" << std::endl;
}

void test_array_stack_pop() {
    std::cout << "Тест Array_stack.pop()" << std::endl;
    
    int expected_arr[] = {20};
    Array_sequence<int> expected_seq(expected_arr, 1);
    Array_stack<int> expected_stack(expected_seq);
    
    int arr[] = {20, 10};
    Array_sequence<int> init_seq(arr, 2);
    Array_stack<int> stack(init_seq);
    
    assert(stack.pop() == 10);
    assert(stack == expected_stack);
    std::cout << "Тест пройден!\n" << std::endl;
}

void test_array_stack_top() {
    std::cout << "Тест Array_stack.top()" << std::endl;
    
    int arr[] = {30, 20, 10};
    Array_sequence<int> init_seq(arr, 3);
    Array_stack<int> stack(init_seq);
    
    assert(stack.top() == 10); 
    std::cout << "Тест пройден!\n" << std::endl;
}

void test_array_stack_concat() {
    std::cout << "Тест Array_stack.concat()" << std::endl;

    int expected_arr[] = {2, 3, 4, 5};
    Array_sequence<int> expected_seq(expected_arr, 4);
    Array_stack<int> expected_stack(expected_seq);
    
    int arr1[] = {2, 3};
    Array_sequence<int> seq1(arr1, 2);
    Array_stack<int> stack1(seq1);

    int arr2[] = {4, 5};
    Array_sequence<int> seq2(arr2, 2);
    Array_stack<int> stack2(seq2);
    
    Stack<int>* stack_res = stack1.concat(stack2);
    
    assert(*stack_res == expected_stack);
    delete stack_res;
    std::cout << "Тест пройден!\n" << std::endl;
}

void test_array_stack_sub_stack() {
    std::cout << "Тест Array_stack.sub_stack()" << std::endl;

    int expected_arr[] = {5, 4, 3}; 
    Array_sequence<int> expected_seq(expected_arr, 3);
    Array_stack<int> expected_stack(expected_seq);
    
    int arr[] = {5, 4, 3, 2, 1};
    Array_sequence<int> seq(arr, 5);
    Array_stack<int> stack(seq);

    Stack<int>* stack_res = stack.sub_stack(0, 2); 
    
    assert(*stack_res == expected_stack);
    delete stack_res;
    std::cout << "Тест пройден!\n" << std::endl;
}

void test_array_stack_clear() {
    std::cout << "Тест Array_stack.clear()" << std::endl;
    
    Array_sequence<int> expected_seq;
    Array_stack<int> expected_stack(expected_seq);
    
    int arr[] = {1, 2, 3};
    Array_sequence<int> init_seq(arr, 3);
    Array_stack<int> stack(init_seq);
    
    stack.clear();
    assert(stack == expected_stack);
    std::cout << "Тест пройден!\n" << std::endl;
}

void test_list_stack_push() {
    std::cout << "Тест List_stack.push()" << std::endl;
    
    int arr[] = {2, 3};
    List_sequence<int> expected_seq(arr, 2);
    List_stack<int> expected_stack(expected_seq);
    
    List_stack<int> stack;
    stack.push(2);
    stack.push(3);
    
    assert(stack == expected_stack);
    std::cout << "Тест пройден!\n" << std::endl;
}

void test_list_stack_pop() {
    std::cout << "Тест List_stack.pop()" << std::endl;
    
    double expected_arr[] = {3.7, 2.5};
    List_sequence<double> expected_seq(expected_arr, 2);
    List_stack<double> expected_stack(expected_seq);
    
    double arr[] = {3.7, 2.5, 1.3};
    List_sequence<double> init_seq(arr, 3);
    List_stack<double> stack(init_seq);
    
    assert(stack.pop() == 1.3); 
    assert(stack == expected_stack);
    std::cout << "Тест пройден!\n" << std::endl;
}

void test_list_stack_top() {
    std::cout << "Тест List_stack.top()" << std::endl;
    
    char arr[] = {'c', 'b', 'a'};
    List_sequence<char> init_seq(arr, 3);
    List_stack<char> stack(init_seq);
    
    assert(stack.top() == 'a');
    std::cout << "Тест пройден!\n" << std::endl;
}

void test_list_stack_concat() {
    std::cout << "Тест List_stack.concat()" << std::endl;

    int expected_arr[] = {2, 3, 4, 5, 3, 4};
    List_sequence<int> expected_seq(expected_arr, 6);
    List_stack<int> expected_stack(expected_seq);
    
    int arr1[] = {2, 3 ,4, 5};
    List_sequence<int> seq1(arr1, 4);
    List_stack<int> stack1(seq1);

    int arr2[] = {3, 4};
    List_sequence<int> seq2(arr2, 2);
    List_stack<int> stack2(seq2);
    
    Stack<int>* stack_res = stack1.concat(stack2);
    
    assert(*stack_res == expected_stack);
    delete stack_res;
    std::cout << "Тест пройден!\n" << std::endl;
}

void test_list_stack_sub_stack() {
    std::cout << "Тест List_stack.sub_stack()" << std::endl;

    int expected_arr[] = {3, 2};
    List_sequence<int> expected_seq(expected_arr, 2);
    List_stack<int> expected_stack(expected_seq);
    
    int arr[] = {5, 4, 3, 2, 1};
    List_sequence<int> seq(arr, 5);
    List_stack<int> stack(seq);

    Stack<int>* stack_res = stack.sub_stack(2, 3);
    
    assert(*stack_res == expected_stack);
    delete stack_res;
    std::cout << "Тест пройден!\n" << std::endl;
}

void test_list_stack_clear() {
    std::cout << "Тест List_stack.clear()" << std::endl;
    
    List_sequence<int> expected_seq;
    List_stack<int> expected_stack(expected_seq);
    
    int arr[] = {1, 2, 3};
    List_sequence<int> init_seq(arr, 3);
    List_stack<int> stack(init_seq);
    
    stack.clear();
    assert(stack == expected_stack);
    std::cout << "Тест пройден!\n" << std::endl;
}

int main() {
    test_array_queue_enqueue();
    test_array_queue_dequeue();
    test_array_queue_get_front();
    test_array_queue_concat();
    test_array_queue_sub_queue();
    test_array_queue_clear();
    
    test_list_queue_enqueue();
    test_list_queue_dequeue();
    test_list_queue_get_front();
    test_list_queue_concat();
    test_list_queue_sub_queue();
    test_list_queue_clear();

    test_array_stack_push();
    test_array_stack_pop();
    test_array_stack_top();
    test_array_stack_concat();
    test_array_stack_sub_stack();
    test_array_stack_clear();
    
    test_list_stack_push();
    test_list_stack_pop();
    test_list_stack_top();
    test_list_stack_concat();
    test_list_stack_sub_stack();
    test_list_stack_clear();

    std::cout << "Все тесты успешно пройдены!" << std::endl;
    return 0;
}