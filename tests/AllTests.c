#include <stdio.h>

#include "CuTest.h"

CuSuite *UtilsGetSuite();
CuSuite *VectorGetSuite();

void RunAllTests(void)
{
	CuString *output = CuStringNew();
	CuSuite* suite = CuSuiteNew();

	CuSuiteAddSuite(suite, UtilsGetSuite());
	CuSuiteAddSuite(suite, VectorGetSuite());

	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);

	CuStringDelete(output);
	CuSuiteDelete(suite);
}

int main(void)
{
	RunAllTests();

	return 0;
}
