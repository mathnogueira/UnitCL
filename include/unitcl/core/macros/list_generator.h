// The MIT License (MIT)
//
// Copyright (c) 2016 Matheus Nogueira
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef UNITCL_MACROS_LISTGENERATOR
#define UNITCL_MACROS_LISTGENERATOR

#include <unitcl/core/list.h>
#include <stdlib.h>

/**
 * Macro that create custom implementations of lists based on a type. You specify
 * a type and it will create the struct and all functions to manipulate the new
 * list.
 *
 * @param type type that will be handled by the list.
 * @param destructor function used to destroy the type of the list. NULL if none is needed.
 */
#define LIST_IMPL(type, name, destructor)												\
	struct ListOf_##name {																\
		struct UnitCL_List *list;														\
	};																					\
	struct ListOf_##name* ListOf_##name##_Init() {										\
		struct ListOf_##name* ltype = (struct ListOf_##name*) malloc(sizeof(ltype));	\
		struct UnitCL_List *list = UnitCL_List_Init();									\
		ltype->list = list;																\
		return ltype;																	\
	}																					\
																						\
	void ListOf_##name##_Destroy(struct ListOf_##name *customList) {					\
		struct UnitCL_List_Node *current = customList->list->head;						\
		struct UnitCL_List_Node *aux = NULL;											\
		while (current != NULL) {														\
			aux = current;																\
			current = current->next;													\
			destructor((type*) aux->content);											\
		}																				\
		UnitCL_List_Destroy(customList->list);											\
		free(customList);																\
	}																					\
																						\
	void ListOf_##name##_Push(type * element, struct ListOf_##name *list) {				\
		UnitCL_List_Push((void *) element, list->list);									\
	}																					\
																						\
	type* ListOf_##name##_Retrieve(unsigned int p, struct ListOf_##name *list) {		\
		return UnitCL_List_Retrieve(p, list->list);										\
	}																					\
																						\
	unsigned int ListOf_##name##_Size(struct ListOf_##name *list) {						\
		return list->list->size;														\
	}

#define LIST_HEADER(type, name)															\
	struct ListOf_##name;																\
																						\
	struct ListOf_##name* ListOf_##name##_Init();										\
	void ListOf_##name##_Destroy(struct ListOf_##name *customList);						\
	void ListOf_##name##_Push(type * element, struct ListOf_##name *list);				\
	type* ListOf_##name##_Retrieve(unsigned int p, struct ListOf_##name *list);			\
	unsigned int ListOf_##name##_Size(struct ListOf_##name *list);						\

#endif