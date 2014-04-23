/*
 *  XAM Xerxys Artificial Machine
 *  Copyright (C) 2005-2012 Christian Lins <christian@lins.me>
 *
 *  This Source Code Form is subject to the terms of the Mozilla Public
 *  License, v. 2.0. If a copy of the MPL was not distributed with this
 *  file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <xam.h>
#include <xam_io.h>
#include <xam_link.h>
#include <xam_mem.h>

bool IsNative(struct VMTHREAD * thread, unsigned short methodIndex,
              struct LINKFLAGS * flags);
int LoadJavaClass(IOIdentifier, struct VMCLASS *);

/* Finds, loads and initializes a new class specified by the
     full qualified name. */
struct VMCLASS *FindClassByName(char *qualifiedName)
{
    IOIdentifier fileID;
    struct VMCLASS *class = NULL;
    int n;

    /* Search for already loaded class */
    for (n = 0; n < VM.LocalClassesNum; n++) {
        if (strcmp(qualifiedName, VM.LocalClasses[n]->QualifiedName) == 0) {
#ifdef DEBUG
            printf("Class already loaded.\n");
#endif
            return VM.LocalClasses[n];
        }
    }

    fileID.filename = compose_path(qualifiedName, VM.LibraryPath);
    fileID.filebuffer_len = 0;
    fileID.filebuffer = NULL;

    VM.LocalClassesNum++;
    VM.LocalClasses = (struct VMCLASS **) xam_realloc(VM.LocalClasses,
                                                      sizeof(struct VMCLASS
                                                             *) *
                                                      VM.LocalClassesNum);

    class = (struct VMCLASS *) xam_alloc(sizeof(struct VMCLASS));
    VM.LocalClasses[VM.LocalClassesNum - 1] = class;

    if (LoadJavaClass(fileID, class) == false) {
        return NULL;
    }

    /* We must initialize the class file later */

    return class;
}

struct VMCLASS *FindClassByNameIndex(struct VMCLASS *localClass,
                                     unsigned short nameIndex)
{
    return NULL;
}

/* This method searches in the local constant pool for a method and returns the index
     of the method in the MethodLookupTable. */
struct METHOD *find_method_name(struct VMCLASS *vmclass,
                                const char *qualifiedName)
{
    unsigned short n, nameIndex;
    struct METHOD *method;

#ifdef DEBUG
    printf("Link: finding method %s...", qualifiedName);
#endif

    if (vmclass == NULL) {
        return NULL;
    }

    for (n = 0; n < vmclass->MethodsNum; n++) {
        nameIndex = vmclass->Methods[n].NameIndex - 1;  /* Constant Pool index starts with 1, so we must subtract one */
        if (strcmp
            (qualifiedName,
             ((struct CONSTANT_UTF8_INFO *)
              vmclass->ConstantPool[nameIndex].Data)->Text) == 0) {
            method = (struct METHOD *) xam_alloc(sizeof(struct METHOD));
            method->Method = &(vmclass->Methods[n]);
            method->Class = vmclass;

#ifdef DEBUG
            printf("Found!\n");
#endif

            return method;
        }
    }

#ifdef DEBUG
    printf("NOT found!\n");
#endif

    return NULL;
}

struct METHOD *find_method_nameidx(struct VMCLASS *vmclass,
                                   short methodNameIndex)
{
    unsigned short n;
    struct METHOD *method;

    for (n = 0; n < vmclass->MethodsNum; n++) {
        if (vmclass->Methods[n].NameIndex == methodNameIndex + 1) {     /* +1 ? */
            method = (struct METHOD *) xam_alloc(sizeof(struct METHOD));
            method->Method = &(vmclass->Methods[n]);
            method->Class = vmclass;
            return method;
        }
    }

    return NULL;
}

/*
 * This method tries to find a method by parsing the string identifier
 * and looking for method in local classes.
 */
struct METHOD *find_method_idx(struct VMCLASS *vmclass,
                               struct VMTHREAD *thread,
                               uint16_t methodIndex,
                               struct LINKFLAGS *flags)
{
    struct VMCLASS *methodClass;
    struct METHOD *methodInvoked;
    unsigned short classIndex, classNameIndex, nameTypeIndex,
        methodNameIndex;
    char *className;
    char *methodName;

    /* The Constant Pool Index is indexed beginning with 1 not 0... */
    methodIndex--;

    classIndex =
        ((struct CONSTANT_REF_INFO *) vmclass->
         ConstantPool[methodIndex].Data)->ClassIndex - 1;
    classNameIndex =
        ((struct CONSTANT_CLASS_INFO *) vmclass->
         ConstantPool[classIndex].Data)->NameIndex - 1;
    className =
        ((struct CONSTANT_UTF8_INFO
          *) (vmclass->ConstantPool[classNameIndex].Data))->Text;

    nameTypeIndex =
        ((struct CONSTANT_REF_INFO *) vmclass->
         ConstantPool[methodIndex].Data)->NameAndTypeIndex - 1;
    methodNameIndex =
        ((struct CONSTANT_NAMETYPE_INFO *)
         vmclass->ConstantPool[nameTypeIndex].Data)->NameIndex - 1;
    methodName =
        ((struct CONSTANT_UTF8_INFO *)
         vmclass->ConstantPool[methodNameIndex].Data)->Text;

#ifdef DEBUG
    printf("Find method %s (%d)(%d %d) in %s (%d %d)..\n",
           methodName, methodIndex, nameTypeIndex, methodNameIndex,
           className, classIndex, classNameIndex);
#endif

    if (classIndex + 1 == vmclass->ThisClassIndex) {
        return find_method_nameidx(vmclass, methodNameIndex);
    } else {
        methodClass = FindClassByName(className);
        methodInvoked = find_method_name(methodClass, methodName);      /* Search for method to be invoked */

        if (methodInvoked == NULL) {
            return NULL;
        }

        return methodInvoked;

        if (strcmp(methodClass->QualifiedName, "java/lang/Object") != 0) {
//          /* Find class constructor */
//          methodConstructor = FindMethodByName(methodClass, "<init>");

            /* Push StackFrames */
//          stack_push(&thread->methodStack, clone_stackframe(&methodInvoked->Method->StackFrameRef));
//          stack_push(&thread->methodStack, clone_stackframe(&methodConstructor->Method->StackFrameRef));

            /* The constructor must return to the invoked method, so we edit the return values... */
//          invokeStackFrame->method                    = methodInvoked;
//          invokeStackFrame->instruction_ptr = methodInvoked->Method->CodeInfo->Code;
            /* InvokeStackPush */
//          stack_push(&thread->invokeStack, invokeStackFrame);

//          return methodConstructor;
            dbgmsg("Not implemented");
            return NULL;
        }

        /* Class is the base-of-all java/lang/Object */
        if (strcmp(methodName, "<init>") == 0) {
            flags->AbortInvoke = true;
            return NULL;
        } else
            return methodInvoked;
    }
}

/* Dynamically finds a method to invoke */
struct METHOD *dlink(struct VMTHREAD *thread, unsigned short methodIndex,
                     struct LINKFLAGS *flags)
{
    if (IsNative(thread, methodIndex, flags) == false) {
        return find_method_idx(thread->RunningClass, thread,
                               methodIndex, flags);
    } else {
        dbgmsg("Native linking not yet supported!");
        return NULL;
    }
}
