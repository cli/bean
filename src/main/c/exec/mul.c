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

/* Integer multiplication */
void do_IMUL(struct VMTHREAD *thread)
{
    int *value1;
    int *value2;
    int *result = xam_alloc(sizeof(int));
    dbgmsg("IMUL");

    stack_pop(&(current_frame(thread)->operandStack), (void **) &value2);
    stack_pop(&(current_frame(thread)->operandStack), (void **) &value1);

    *result = (*value1) * (*value2);

    stack_push(&(current_frame(thread)->operandStack), result);
}

/* Long integer multiplication */
void do_LMUL(struct VMTHREAD *thread)
{
    int64_t *value1;
    int64_t *value2;
    int64_t *result = xam_alloc(sizeof(int64_t));
    dbgmsg("LMUL");

    stack_pop(&(current_frame(thread)->operandStack), (void **) &value2);
    stack_pop(&(current_frame(thread)->operandStack), (void **) &value1);

    *result = (*value1) * (*value2);

    stack_push(&(current_frame(thread)->operandStack), result);
}

/* Float multiplication */
void do_FMUL(struct VMTHREAD *thread)
{
    float *value1;
    float *value2;
    float *result = xam_alloc(sizeof(float));
    dbgmsg("FMUL");

    stack_pop(&(current_frame(thread)->operandStack), (void **) &value2);
    stack_pop(&(current_frame(thread)->operandStack), (void **) &value1);

    *result = (*value1) * (*value2);

    stack_push(&(current_frame(thread)->operandStack), result);
}

/* Double multiplication */
void do_DMUL(struct VMTHREAD *thread)
{
    double *value1;
    double *value2;
    double *result = xam_alloc(sizeof(double));
    dbgmsg("DMUL");

    stack_pop(&(current_frame(thread)->operandStack), (void **) &value2);
    stack_pop(&(current_frame(thread)->operandStack), (void **) &value1);

    *result = (*value1) * (*value2);

    stack_push(&(current_frame(thread)->operandStack), result);
}
