#include <check.h>
#include <time.h>
#include "../src/treenode.h"

// DECLARE VARS
TreeBase tree_base_int_1, *ptr_tree_base_int_1;
TreeNode tree_node, *ptr_tree_node;
int *int_arr_ptr;
int arr_size = 100;

void setup(void) {
    int_arr_ptr = malloc(arr_size*sizeof(*int_arr_ptr));
    ptr_tree_base_int_1 = new_base(comp_ints, clean_ints, print_ints);
    ptr_tree_node = new_node(NULL,NULL,NULL);
    if(int_arr_ptr==NULL || ptr_tree_base_int_1==NULL || ptr_tree_node==NULL) {
        printf("Error allocating memory in test Setup");
        assert(NULL);
    }

    for (int i = 0; i < arr_size; ++i) {
        int r = rand() % 20000;
        *(int_arr_ptr + i) = r;
    }
}

void teardown(void){
	free(int_arr_ptr);
    ck_assert_int_eq(freeTree(ptr_tree_base_int_1), true);
    free(ptr_tree_base_int_1);
    free(ptr_tree_node);
}

START_TEST(test_CHECK) {
        ck_assert_int_eq(5, 5);
} END_TEST

START_TEST(test_INSERT) {
        int a,b;
        a = 5;
        b = 6;
        if (ptr_tree_base_int_1 == null)
            ck_abort_msg("tree_base was null");
        if (ptr_tree_base_int_1->base != null)
            ck_abort_msg("tree_base->base was null, expected null");
        ck_assert_int_eq(insert(ptr_tree_base_int_1, &a), true);
        if (ptr_tree_base_int_1->base == null)
            ck_abort_msg("tree_base->base was null, expected assigned node");
        ck_assert_int_eq(1, ptr_tree_base_int_1->size);
        if (ptr_tree_base_int_1->base->left == null && ptr_tree_base_int_1->base->right == null)
            ck_abort_msg("tree_base->base->children wasnt null, expected null");
        ck_assert_int_eq(insert(ptr_tree_base_int_1, &b), true);
        ck_assert_int_eq(ptr_tree_base_int_1->base->right->value, 6);
    } END_TEST

START_TEST(test_BST_AND_INSERT_BST) {
        for (int i = 0; i < arr_size; ++i) {
            insert(ptr_tree_base_int_1, (int_arr_ptr + i));
        }
        ck_assert_int_eq(printTree(ptr_tree_base_int_1), true);
    } END_TEST

START_TEST(test_COMP_INTS) {

    } END_TEST

START_TEST(test_CLEAN_INTS) {

    } END_TEST


Suite * tree_program_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("TreeProgramSuite");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_checked_fixture(tc_core, setup, teardown);
    tcase_add_test(tc_core, test_CHECK);
    tcase_add_test(tc_core, test_INSERT);
	tcase_add_test(tc_core, test_BST_AND_INSERT_BST);
	// tcase_add_test(tc_core, test_check_nonempty);
	// tcase_add_test(tc_core, test_check_diag);
	// tcase_add_test(tc_core, test_check_columns);
	// tcase_add_test(tc_core, test_check_rows);
	// tcase_add_test(tc_core, test_size5);
	// tcase_add_test(tc_core, test_any_ms_size);
	// tcase_add_test(tc_core, test_solve_the_ms_problem);
	// tcase_add_test(tc_core, test_swap_in_directed);
	// tcase_add_test(tc_core, test_update_in_direction);
	// tcase_add_test(tc_core, test_is_mobile);
	// tcase_add_test(tc_core, test_dms_on_extreme);
	// tcase_add_test(tc_core, test_complete_4);

    suite_add_tcase(s, tc_core);

    tcase_set_timeout(tc_core, 150);
    return s;
}

int main(void) {
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = tree_program_suite();
	sr = srunner_create(s);

	srunner_set_log (sr, "test.log");
	srunner_run_all(sr, CK_VERBOSE);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}