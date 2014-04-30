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

#ifndef _XAM_LINK_H_
#define _XAM_LINK_H_

#include "bvm_class.h"
#include "bvm_process.h"

struct LINKFLAGS
{
  unsigned int AbortInvoke : 1; /* Abort the Invoke, e.g. because of a internal handled constructor. */
  unsigned int IsNative    : 1; /* Invoked method is natively handled by the VM. */
};

struct METHOD* dlink(struct VMTHREAD*, unsigned short, struct LINKFLAGS*);
struct METHOD* find_method_name(struct VMCLASS*, const char*);

#endif
