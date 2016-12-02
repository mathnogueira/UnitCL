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

#ifndef UNITCL_SUITE_TESTSUITE
#define UNITCL_SUITE_TESTSUITE

#include <unitcl/core/test.h>
#include <unitcl/core/enums.h>
#include <unitcl/core/types.h>
#include <unitcl/core/lists/test_list.h>

struct UnitCL_TestSuite {
	struct ListOf_UnitCL_TestCase *testcases;
	enum UnitCL_Test_Status status;
	unsigned int number_tests;
	unsigned int number_errors;
};

/**
 * Create a new empty test suite.
 *
 * @return pointer to the new test suite.
 */
struct UnitCL_TestSuite* UnitCL_TestSuite_Init();

/**
 * Destroy a test suite and all of its tests.
 *
 * @param suite test suite that will be destroyed.
 */
void UnitCL_TestSuite_Destroy(struct UnitCL_TestSuite* suite);

/**
 * Add a new test case to the test suite.
 *
 * @param testcase case that will be appended to the suite.
 * @param suite suite that will execute the test.
 */
void UnitCL_TestSuite_AddTest(struct UnitCL_TestCase *testcase, struct UnitCL_TestSuite *suite);

/**
 * Add a new test case from a function that follows the test case signature.
 *
 * @param testcase function that executes the test.
 * @param suite suite that will execute the test.
 */
void UnitCL_TestSuite_AddTestFromFunction(UnitCL_TestCaseFunct testcase, struct UnitCL_TestSuite *suite);

/**
 * Execute all test cases associated with a test suite.
 *
 * @param suite test suite that will be executed.
 */
void UnitCL_TestSuite_Execute(struct UnitCL_TestSuite *suite);

#endif