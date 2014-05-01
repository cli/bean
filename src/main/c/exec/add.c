/*
 *  Bean Java VM
 *  Copyright (C) 2005-2014 Christian Lins <christian@lins.me>
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

#include <bvm.h>
#include <bvm_mem.h>

/* TODO: Perhaps it's possible to merge this file with sub.c ... */

void do_IADD(struct VMTHREAD *thread)
{
    dbgmsg("IADD");
    int *value1;
    int *value2;
    struct stackframe_t *frame = current_frame(thread);

    /* Retrieving values from operand stack */
    stack_pop(&(frame->operandStack), (void **) &value2);
    value1 = (int *) frame->operandStack.top->data;

    /* Subtracting */
    *value1 = (*value1) + (*value2);

    /* As we're modifying the stack top directly, we do not need to push
     * the result back. But we should free value2. */
    xam_free(value2);
}

void do_LADD(struct VMTHREAD *thread)
{
    dbgmsg("LADD");
    int64_t *value1;
    int64_t *value2;
    struct stackframe_t *frame = current_frame(thread);

    /* Retrieving values from operand stack */
    stack_pop(&(frame->operandStack), (void **) &value2);
    value1 = (int64_t *) frame->operandStack.top->data;

    /* Subtracting */
    *value1 = (*value1) + (*value2);

    /* As we're modifying the stack top directly, we do not need to push
     * the result back. But we should free value2. */
    xam_free(value2);
}

void do_FADD(struct VMTHREAD *thread)
{
    dbgmsg("FADD");
    float *value1;
    float *value2;
    struct stackframe_t *frame = current_frame(thread);

    /* Retrieving values from operand stack */
    stack_pop(&(frame->operandStack), (void **) &value2);
    value1 = (float *) frame->operandStack.top->data;

    /* Subtracting */
    *value1 = (*value1) + (*value2);

    /* As we're modifying the stack top directly, we do not need to push
     * the result back. But we should free value2. */
    xam_free(value2);
}

void do_DADD(struct VMTHREAD *thread)
{
    dbgmsg("DADD");
    double *value1;
    double *value2;
    struct stackframe_t *frame = current_frame(thread);

    /* Retrieving values from operand stack */
    stack_pop(&(frame->operandStack), (void **) &value2);
    value1 = (double *) frame->operandStack.top->data;

    /* Subtracting */
    *value1 = (*value1) + (*value2);

    /* As we're modifying the stack top directly, we do not need to push
     * the result back. But we should free value2. */
    xam_free(value2);
}