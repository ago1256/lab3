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

void test_array_queue_clear() {
    std::cout << "Тест Array_queue.clear()" << std::endl;
    
    Array_sequence<int> expected_seq(0);
    Array_queue<int> expected_queue(expected_seq);

    int init_arr[] = {1, 2, 3};
    Array_sequence<int> init_seq(init_arr, 3);
    Array_queue<int> queue(init_seq);
    
    queue.clear();
    
    // Проверка
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


int main() {
    test_array_queue_enqueue();
    test_array_queue_dequeue();
    test_array_queue_get_front();
    test_array_queue_clear();
    
    test_list_queue_enqueue();
    test_list_queue_dequeue();
    test_list_queue_get_front();
    test_list_queue_clear();

    std::cout << "Все тесты успешно пройдены!" << std::endl;
    return 0;
}