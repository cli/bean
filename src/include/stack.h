/*
 *  Bean Java VM
 *  Copyright (C) 2005-2015 Christian Lins <christian@lins.me>
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef _STACK_H_
#define _STACK_H_

#include <stdint.h>
#include <types.h>

#include <method.h>

typedef struct StackElement
{
    void*                data; /* data structure */
    struct StackElement* next; /* ptr to next element */
} StackElement;

typedef struct Stack
{
    unsigned int limit;   /* maximum number of elements */
    unsigned int size;    /* current number of elements */
    StackElement* top;
} Stack;


Stack* Stack_new(unsigned int limit);
void Stack_destroy(Stack* stack);
int Stack_pop(Stack* stack, void** data);
int Stack_push(Stack* stack, void* data);

#endif
