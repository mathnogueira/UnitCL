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

#include <unitcl/reporter/default.h>

// Private function
void Default_Print_Suite(struct UnitCL_TestSuite *suite);

/**
 * Default results reporter. 
 *
 * @param suite suite that contains details about the tests that were ran.
 */
void UnitCL_Default_Reporter(struct UnitCL_TestSuite *suite) {
	unsigned int suites = ListOf_UnitCL_TestSuite_Size(suite->suites);
	for (unsigned int i = 0; i < suites; ++i) {
		struct UnitCL_TestSuite *childSuite = ListOf_UnitCL_TestSuite_Retrieve(i, suite->suites);
		Default_Print_Suite(childSuite);
	}
	Default_Print_Suite(suite);
}

void Default_Print_Suite(struct UnitCL_TestSuite *suite) {
	printf("Suite %d\n", suite->number_tests);
}