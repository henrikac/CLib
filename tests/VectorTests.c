#include <stdlib.h>

#include "CuTest.h"

#include "vector.h"


void TestVectorInit(CuTest *tc)
{
	vector_t *vec = NULL;
	size_t expected_size = VEC_EMPTY;
	size_t expected_capacity = VEC_INIT_CAP;
	size_t actual_size;
	size_t actual_capacity;

	vector_init(&vec);

	actual_size = vec->size;
	actual_capacity = vec->capacity;

	CuAssertPtrNotNull(tc, vec);
	CuAssertPtrNotNull(tc, vec->items);
	CuAssertIntEquals(tc, expected_size, actual_size);
	CuAssertIntEquals(tc, expected_capacity, actual_capacity);

	vector_destroy(&vec);
}

void TestVectorDestroy(CuTest *tc)
{
	vector_t *vec = NULL;

	vector_init(&vec);
	vector_destroy(&vec);

	CuAssertPtrEquals(tc, NULL, vec);
}

void TestVectorAdd(CuTest *tc)
{
	vector_t *vec = NULL;
	size_t expected_size = 3;
	size_t actual_size;
	int i;

	vector_init(&vec);

	for (i = 0; i < 3; i++)
		vector_add(vec, &i);

	actual_size = vec->size;

	CuAssertPtrNotNull(tc, vec);
	CuAssertIntEquals(tc, expected_size, actual_size);

	vector_destroy(&vec);
}

void TestVectorPop(CuTest *tc)
{
	vector_t *vec = NULL;
	int *popped_item = NULL;
	int expected = 3;
	int actual;
	int i;

	vector_init(&vec);

	for (i = 0; i < 4; i++)
		vector_add(vec, &i);

	popped_item = vector_pop(vec);
	actual = *popped_item;
	
	CuAssertPtrNotNull(tc, vec);
	CuAssertPtrNotNull(tc, popped_item);
	CuAssertIntEquals(tc, expected, actual);

	free(popped_item);
	vector_destroy(&vec);
}

void TestVectorReserve(CuTest *tc)
{
	vector_t *vec = NULL;
	size_t expected_capacity = 14;
	size_t actual_capacity;

	vector_init(&vec);
	vector_reserve(vec, expected_capacity);

	actual_capacity = vec->capacity;

	CuAssertPtrNotNull(tc, vec);
	CuAssertIntEquals(tc, expected_capacity, actual_capacity);

	vector_destroy(&vec);
}

void TestVectorTrim(CuTest *tc)
{
	vector_t *vec = NULL;
	size_t expected = 5;
	size_t actual;
	int i;

	vector_init(&vec);

	for (i = 0; i < 5; i++)
		vector_add(vec, &i);

	vector_trim(vec);

	actual = vec->capacity;

	CuAssertPtrNotNull(tc, vec);
	CuAssertIntEquals(tc, expected, actual);

	vector_destroy(&vec);
}

void TestVectorSize(CuTest *tc)
{
	vector_t *vec = NULL;
	size_t expected_size = 7;
	size_t actual_size;
	int i;

	vector_init(&vec);

	for (i = 0; i < 7; i++)
		vector_add(vec, &i);

	actual_size = (int)vector_size(vec);

	CuAssertPtrNotNull(tc, vec);
	CuAssertIntEquals(tc, expected_size, actual_size);

	vector_destroy(&vec);
}

void TestVectorCapacity(CuTest *tc)
{
	vector_t *vec = NULL;
	size_t expected_capacity = 4;
	size_t actual_capacity;
	int i;

	vector_init(&vec);

	for (i = 0; i < 4; i++)
		vector_add(vec, &i);

	actual_capacity = vector_capacity(vec);

	CuAssertPtrNotNull(tc, vec);
	CuAssertIntEquals(tc, expected_capacity, actual_capacity);

	vector_destroy(&vec);
}

void TestVectorCapacity2(CuTest *tc)
{
	vector_t *vec = NULL;
	size_t expected_capacity = 8;
	size_t actual_capacity;
	int i;

	vector_init(&vec);

	for (i = 0; i < 5; i++)
		vector_add(vec, &i);

	actual_capacity = vector_capacity(vec);

	CuAssertPtrNotNull(tc, vec);
	CuAssertIntEquals(tc, expected_capacity, actual_capacity);

	vector_destroy(&vec);
}

CuSuite *VectorInitGetSuite()
{
	CuSuite *suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, TestVectorInit);
	return suite;
}

CuSuite *VectorAddGetSuite()
{
	CuSuite *suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, TestVectorAdd);
	return suite;
}

CuSuite *VectorPopGetSuite()
{
	CuSuite *suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, TestVectorPop);
	return suite;
}

CuSuite *VectorReserveGetSuite()
{
	CuSuite *suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, TestVectorReserve);
	return suite;
}

CuSuite *VectorTrimGetSuite()
{
	CuSuite *suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, TestVectorTrim);
	return suite;
}

CuSuite *VectorSizeGetSuite()
{
	CuSuite *suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, TestVectorSize);
	return suite;
}

CuSuite *VectorCapacityGetSuite()
{
	CuSuite *suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, TestVectorCapacity);
	return suite;
}

CuSuite *VectorCapacity2GetSuite()
{
	CuSuite *suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, TestVectorCapacity2);
	return suite;
}

CuSuite *VectorDestroyGetSuite()
{
	CuSuite *suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, TestVectorDestroy);
	return suite;
}
