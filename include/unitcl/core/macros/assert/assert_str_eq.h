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

#ifndef UNITCL_CORE_MACROS_ASSERT_ASSERT_STR_EQ
#define UNITCL_CORE_MACROS_ASSERT_ASSERT_STR_EQ

#include <string.h>

#include <unitcl/core/enums.h>
#include <unitcl/core/macros/assert/fail.h>

/**
 * Macro that verifies if two strings are the same, if they differ, it will fail
 * and stop the test case.
 *
 * @param str1 first string
 * @param str2 second string
 */
#define ASSERT_STR_EQ(str1, str2)						\
	do {												\
		if (strcmp(str1, str2)) {						\
			FAIL()										\
		}												\
	} while (0);

#endif