#include <check.h>
#include "../src/average.h" // Include the factorial function`
#include <stdio.h>

START_TEST(test_average)
{
    int arr1[] = {3, 4, 5};
    int arr2[] = {3, 4, 5, 6, 2};
    int arr3[] = {1, 2, 3};

    ck_assert_int_eq(average(arr1, 3), 4);
    ck_assert_int_eq(average(arr2, 5), 4);
    ck_assert_int_eq(average(arr3, 3), 2);
}
END_TEST

Suite *average_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("average");

    // core test case
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_average);
    suite_add_tcase(s, tc_core);

    return s;
}

int main()
{
    printf("Calling test average...");
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = average_suite();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? 0 : 1;
}
