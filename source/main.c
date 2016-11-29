#include <stdio.h>
#include <stdlib.h>
#include <unitcl/suite/test_suite.h>

int main(int argc, char **argv) {
	struct UnitCL_TestSuite *suite = UnitCL_TestSuite_Init();
	UnitCL_TestSuite_Destroy(suite);
	return 0;
}