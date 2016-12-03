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

#include <unitcl/core/list.h>
#include <stdlib.h>

struct UnitCL_List_Node* UnitCL_List_Node_Init(void *content);

/**
 * Create a new empty list.
 *
 * @return pointer to the list.
 */
struct UnitCL_List* UnitCL_List_Init() {
	struct UnitCL_List* list = (struct UnitCL_List*) malloc(sizeof(list));
	list->head = NULL;
	list->size = 0;
	return list;
}

/**
 * Destroy a list and all of its children.
 *
 * @param list list to be destroyed.
 */
void UnitCL_List_Destroy(struct UnitCL_List* list) {
	free(list);
}

/**
 * Add an element to the list.
 *
 * @param element element that will be added to the list.
 * @param list list that will hold the element.
 */
void UnitCL_List_Push(void *element, struct UnitCL_List* list) {
	struct UnitCL_List_Node* node = UnitCL_List_Node_Init(element);
	list->size++;
	if (list->head == NULL) {
		list->head = node;
		return;
	}
	struct UnitCL_List_Node *current = list->head;
	while (current->next != NULL) current = current->next;
	current->next = node;
}

/**
 * Retrieve an element from the list.
 *
 * @param position integer that represents the position in the list.
 * @param list list where the element is located.
 * @return element that is located at the specified position.
 */
void* UnitCL_List_Retrieve(unsigned int position, struct UnitCL_List* list) {
	unsigned int counter = 0;
	struct UnitCL_List_Node *current = list->head;
	while (counter++ < position && current != NULL) current = current->next;
	return current != NULL ? current->content : NULL;
}

/**
 * Create a new list node and set its content.
 *
 * @param content content of the node.
 * @return pointer to the node.
 */
struct UnitCL_List_Node* UnitCL_List_Node_Init(void *content) {
	struct UnitCL_List_Node *node = (struct UnitCL_List_Node*) malloc(sizeof(node));
	node->content = content;
	node->next = NULL;
	return node;
}