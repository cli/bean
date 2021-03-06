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

#ifndef _METHOD_H_
#define _METHOD_H_

#include <stdint.h>
#include <classfile.h>

/* A method, but without running information */
typedef struct Method {
    uint16_t AccessFlags;
    uint16_t NameIndex;
    uint16_t DescriptorIndex;
    uint16_t AttributesNum;
    struct ATTRIBUTE_INFO* Attributes;
    struct ATTRIBUTE_INFO_CODE* CodeInfo; /* Pointer to the Code Attribute */
    uint16_t operandStackSize;
    uint16_t localVarsLen;
    
    // Parsed values from descriptor
    uint16_t nargs; // Number of arguments
} Method;

#endif
