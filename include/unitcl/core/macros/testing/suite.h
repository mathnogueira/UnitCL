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

#ifndef UNITCL_CORE_MACROS_TESTING_SUITE
#define UNITCL_CORE_MACROS_TESTING_SUITE

/**
 * Create a new test suite and create a build function that will be called
 * by the EXECUTE_SUITE macro.
 *
 * @param suite name of the test suite
 */
#define UNITCL_SUITE(suite)												\
	struct UnitCL_TestSuite *UnitCL_TestSuite__##suite = NULL;			\
	void UnitCL_TestSuite_##suite##_Fn(struct UnitCL_TestSuite *_suite)

/**
 * Shorten macro name for UNICL_SUITE
 *
 * @param suite name of the test suite.
 */
#define SUITE(suite) UNITCL_SUITE(suite)

#define SUITE_INIT(suite)												\
	if (UnitCL_TestSuite__##suite == NULL) {							\
		UnitCL_TestSuite__##suite = UnitCL_TestSuite_Init();			\
		UnitCL_TestSuite_##suite##_Fn(UnitCL_TestSuite__##suite);		\
	}

/**
 * Add a test case to the suite.
 *
 * @param suite name of the suite.
 * @param test name of the test.
 */
#define ADD_TEST(suite, test)																\
	UnitCL_TestSuite_AddTestFromFunction(suite##__##test, UnitCL_TestSuite__##suite);

/**
 * Add a child suite to be executed.
 *
 * @param child child suite that will be executed.
 * @param suite parent suite.
 */
#define ADD_SUITE(child, suite)																\
	SUITE_INIT(child);																		\
	SUITE_INIT(suite);																		\
	UnitCL_TestSuite_AddSuite(UnitCL_TestSuite__##child, UnitCL_TestSuite__##suite);



/**
 * Run a suite and all of its tests.
 *
 * @param suite name of the test suite.
 */
#define RUN_SUITE(suite)																	\
	SUITE_INIT(suite);																		\
	UnitCL_TestSuite_Execute(UnitCL_TestSuite__##suite);									\
	if (UnitCL_TestSuite__##suite->root) {													\
		return UnitCL_TestSuite__##suite->status == Failed ? 1 : 0;							\
	}
	

#endif