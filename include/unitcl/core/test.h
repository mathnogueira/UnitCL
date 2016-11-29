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

#ifndef UNITCL_CORE_TEST
#define UNITCL_CORE_TEST

#include <unitcl/core/enums.h>

/**
 * Structure that stores information about the testcase, specially about
 * failures.
 */
struct UnitCL_TestCase {
	char *filename;
	unsigned int line;
	enum UnitCL_Test_Status status;
};

/**
 * Create a new test case in the heap.
 *
 * @return pointer to the new test case.
 */
struct UnitCL_TestCase* UnitCL_TestCase_Init();

/**
 * Destroy a test case.
 *
 * @param testcase testcase that will be destroyed.
 */
void UnitCL_TestCase_Destroy(struct UnitCL_TestCase* testcase);

#endif