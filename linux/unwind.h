/*
 *
 * honggfuzz - architecture dependent code
 * -----------------------------------------
 *
 * Author: Robert Swiecki <swiecki@google.com>
 *
 * Copyright 2010-2015 by Google Inc. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License. You may obtain
 * a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * permissions and limitations under the License.
 *
 */

#ifndef _HF_LINUX_UNWIND_H_
#define _HF_LINUX_UNWIND_H_

/* String buffer size for function names in stack traces produced from libunwind */
#define _HF_FUNC_NAME_SZ    256 // Should be alright for mangled C++ procs too

#define _HF_MAX_FUNCS 80
typedef struct {
    void *pc;
    char func[_HF_FUNC_NAME_SZ];
    size_t line;
} funcs_t;

extern size_t arch_unwindStack(pid_t pid, funcs_t * funcs);

#endif
