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

#ifndef STRUCT_METHOD_INFO
#define STRUCT_METHOD_INFO

#include <stdint.h>
#include "classloader.h"
#include "bvm_stack.h"

/* A method, but without running information */
struct method_info_t
{
	uint16_t AccessFlags;
	uint16_t NameIndex;
	uint16_t DescriptorIndex;
	uint16_t AttributesNum;
	struct ATTRIBUTE_INFO*      Attributes;
	struct ATTRIBUTE_INFO_CODE* CodeInfo;   /* Pointer to the Code Attribute */
	struct stackframe_t StackFrameRef;      /* Original stack frame */
};
#endif

#ifndef STRUCT_METHOD
#define STRUCT_METHOD

#include "classloader.h"
#include "bvm_stack.h"

/* Identifies a running method (method "instance", old: METHOD_FQID) */
struct method_t
{
    struct VMCLASS*      class;         /* Pointer to a class */
    struct stackframe_t* frame;         /* Pointer to a StackFrame-copy of this method */
    struct method_info_t*  method_info; /* Pointer to the METHOD_INFO that describes this method */
};
#endif
