#include <stdlib.h>

#include "CuTest.h"

#include "utils.h"


void TestMalloc(CuTest *tc)
{
	int *pointer = NULL;

	pointer = Malloc(sizeof(int));

	CuAssertPtrNotNull(tc, pointer);

	free(pointer);
}

void TestCalloc(CuTest *tc)
{
	int *pointer = NULL;

	pointer = Calloc(1, sizeof(int));

	CuAssertPtrNotNull(tc, pointer);

	free(pointer);
}

CuSuite *UtilsGetSuite()
{
	CuSuite *suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, TestMalloc);
	SUITE_ADD_TEST(suite, TestCalloc);
	return suite;
}
