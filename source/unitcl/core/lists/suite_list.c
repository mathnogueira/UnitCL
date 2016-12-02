#include <unitcl/core/lists/suite_list.h>
#include <unitcl/suite/test_suite.h>

void UnitCL_TestSuite_List_Destructor(struct UnitCL_TestSuite* suite) {
	free(suite);
}

// Generate the implementation for the functions of the list
LIST_IMPL(struct UnitCL_TestSuite, UnitCL_TestSuite, UnitCL_TestSuite_List_Destructor);