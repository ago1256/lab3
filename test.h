#pragma once
#include <stdio.h>
#include<assert.h>

#include"sequence.h"
#include"queue.h"

#include"linked_list.h"
#include"dynamic_array.h"

#include"array_sequence.h"
#include"array_queue.h"

#include"list_sequence.h"
#include"list_queue.h"

#include"errors.h"

void test_array_queue_enqueue();
void test_array_queue_dequeue();
void test_array_queue_get_front();
void test_array_queue_clear();

void test_list_queue_enqueue();
void test_list_queue_dequeue();
void test_list_queue_get_front();
void test_list_queue_clear();