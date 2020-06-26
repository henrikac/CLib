#include <stdio.h>

#include "CuTest.h"

CuSuite *VectorInitGetSuite();
CuSuite *VectorAddGetSuite();
CuSuite *VectorPopGetSuite();
CuSuite *VectorReserveGetSuite();
CuSuite *VectorTrimGetSuite();
CuSuite *VectorSizeGetSuite();
CuSuite *VectorCapacityGetSuite();
CuSuite *VectorCapacity2GetSuite();
CuSuite *VectorDestroyGetSuite();

void RunAllTests(void)
{
	CuString *output = CuStringNew();
	CuSuite* suite = CuSuiteNew();

	CuSuiteAddSuite(suite, VectorInitGetSuite());
	CuSuiteAddSuite(suite, VectorAddGetSuite());
	CuSuiteAddSuite(suite, VectorPopGetSuite());
	CuSuiteAddSuite(suite, VectorReserveGetSuite());
	CuSuiteAddSuite(suite, VectorTrimGetSuite());
	CuSuiteAddSuite(suite, VectorSizeGetSuite());
	CuSuiteAddSuite(suite, VectorCapacityGetSuite());
	CuSuiteAddSuite(suite, VectorCapacity2GetSuite());
	CuSuiteAddSuite(suite, VectorDestroyGetSuite());

	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
}

int main(void)
{
	RunAllTests();

	return 0;
}
