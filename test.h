#pragma once
#include <stdio.h>
#include<assert.h>

#include"sequence.h"
#include"queue.h"
#include"stack.h"

#include"linked_list.h"
#include"dynamic_array.h"

#include"array_sequence.h"
#include"array_queue.h"
#include"array_stack.h"

#include"list_sequence.h"
#include"list_queue.h"
#include"list_stack.h"

#include"errors.h"

void test_array_queue_enqueue();
void test_array_queue_dequeue();
void test_array_queue_get_front();
void test_array_queue_concat();
void test_array_queue_sub_queue();
void test_array_queue_clear();

void test_list_queue_enqueue();
void test_list_queue_dequeue();
void test_list_queue_get_front();
void test_list_queue_concat();
void test_list_queue_sub_queue();
void test_list_queue_clear();

void test_array_stack_push();
void test_array_stack_pop();
void test_array_stack_top();
void test_array_stack_concat();
void test_array_stack_sub_stack();
void test_array_stack_clear();

void test_list_stack_push();
void test_list_stack_pop();
void test_list_stack_top();
void test_list_stack_concat();
void test_list_stack_sub_stack();
void test_list_stack_clear();