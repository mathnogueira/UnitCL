#include <unitcl/core/lists/test_list.h>
#include <unitcl/core/test.h>

void UnitCL_TestCase_List_Destructor(struct UnitCL_TestCase* test) {
	free(test);
}

// Generate the implementation for the functions of the list
LIST_IMPL(struct UnitCL_TestCase, UnitCL_TestCase, UnitCL_TestCase_List_Destructor);