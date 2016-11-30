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

#include <unitcl/suite/test_suite.h>
#include <unitcl/core/test.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Create a new empty test suite.
 *
 * @return pointer to the new test suite.
 */
struct UnitCL_TestSuite* UnitCL_TestSuite_Init() {
	struct UnitCL_TestSuite *suite = (struct UnitCL_TestSuite*) malloc(sizeof(suite));
	suite->number_tests = 0;
	suite->number_errors = 0;
	suite->status = New;
	suite->testcases = ListOf_UnitCL_TestCase_Init();
	return suite;
}

/**
 * Destroy a test suite and all of its tests.
 *
 * @param suite test suite that will be destroyed.
 */
void UnitCL_TestSuite_Destroy(struct UnitCL_TestSuite* suite) {
	ListOf_UnitCL_TestCase_Destroy(suite->testcases);
	free(suite);
}

/**
 * Add a new test case to the test suite.
 *
 * @param testcase case that will be appended to the suite.
 * @param suite suite that will execute the test.
 */
void UnitCL_TestSuite_AddTest(struct UnitCL_TestCase *testcase, struct UnitCL_TestSuite *suite) {
	ListOf_UnitCL_TestCase_Push(testcase, suite->testcases);
	printf("Numero de testes: %d\n", ListOf_UnitCL_TestCase_Size(suite->testcases));
}

/**
 * Execute all test cases associated with a test suite.
 *
 * @param suite test suite that will be executed.
 */
void UnitCL_TestSuite_Execute(struct UnitCL_TestSuite *suite) {
	unsigned int count = 0;
	unsigned int testcases = ListOf_UnitCL_TestCase_Size(suite->testcases);
	struct UnitCL_TestCase *test = NULL;
	for (; count < testcases; ++count) {
		test = ListOf_UnitCL_TestCase_Retrieve(count, suite->testcases);
		UnitCL_TestCase_Run(test);
		if (test->status == Failed)
			suite->status = Failed;
	}
	if (suite->status != Failed)
		suite->status = Success;
}