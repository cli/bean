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

#include <xam.h>

void do_DUP(struct VMTHREAD *thread)
{
#ifdef DEBUG
    printf("\tDUP\n");
#endif
}

void do_DUP_X1(struct VMTHREAD *thread)
{
#ifdef DEBUG
    printf("\tDUP_X1\n");
#endif
}

void do_DUP_X2(struct VMTHREAD *thread)
{
#ifdef DEBUG
    printf("\tDUP_X2\n");
#endif
}

void do_DUP2(struct VMTHREAD *thread)
{
#ifdef DEBUG
    printf("\tDUP2\n");
#endif
}

void do_DUP2_X1(struct VMTHREAD *thread)
{
#ifdef DEBUG
    printf("\tDUP2_X1\n");
#endif
}

void do_DUP2_X2(struct VMTHREAD *thread)
{
#ifdef DEBUG
    printf("\tDUP2_X2\n");
#endif
}
