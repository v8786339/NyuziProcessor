//
// Copyright 2016 Jeff Bush
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#pragma once

#include "list.h"

#define PAGE_STRUCTURES_SIZE(memory_size) (sizeof(struct vm_page) * (memory_size \
    / PAGE_SIZE))
#define PAGE_SIZE 0x1000
#define PAGE_ALIGN(x) (x & ~(PAGE_SIZE - 1))

struct vm_page
{
    struct list_node list_entry;
};

extern unsigned int memory_size;

void vm_page_init(unsigned int memory_size);
unsigned int vm_allocate_page(void);
void vm_free_page(unsigned int addr);
struct vm_page *page_for_address(unsigned int addr);
