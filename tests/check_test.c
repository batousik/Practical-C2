#include <check.h>
#include <time.h>
#include "../src/treenode.h"

// DECLARE VARS
TreeBase tree_base_int_1, *ptr_tree_base_int_1;
TreeNode tree_node, *ptr_tree_node;
int *int_arr_ptr;
int arr_size = 25;

void setup(void) {
    int_arr_ptr = malloc(arr_size*sizeof(*int_arr_ptr));
    ptr_tree_base_int_1 = new_base(comp_ints, clean_ints, print_ints);
    ptr_tree_node = new_node(&arr_size,NULL,NULL);
    if(int_arr_ptr==NULL || ptr_tree_base_int_1==NULL || ptr_tree_node==NULL) {
        printf("Error allocating memory in test Setup\n");
        fflush(stdout);
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
    ck_assert_int_eq(ptr_tree_base_int_1->size, 0);
    free(ptr_tree_base_int_1);
    free(ptr_tree_node);
}

START_TEST(test_CHECK) {
        ck_assert_int_eq(true, 1);
        ck_assert_int_eq(false, 0);
        ck_assert_int_eq(5, 5);
} END_TEST

START_TEST(test_INSERT) {
        int *a, *b;
        a = int_arr_ptr+1;
        a = int_arr_ptr+2;
        *a = 5;
        *b = 6;
        ck_assert_int_eq(freeTree(ptr_tree_base_int_1), true);
        if (ptr_tree_base_int_1 == NULL)
            ck_abort_msg("tree_base was NULL");
        if (ptr_tree_base_int_1->base != NULL)
            ck_abort_msg("tree_base->base was not NULL, expected NULL");
        bool isValid = insert(ptr_tree_base_int_1, a);
        ck_assert_int_eq(isValid, true);
        if (ptr_tree_base_int_1->base == NULL)
            ck_abort_msg("tree_base->base was NULL, expected assigned node");
        ck_assert_int_eq(1, ptr_tree_base_int_1->size);
        if (ptr_tree_base_int_1->base->left != NULL && ptr_tree_base_int_1->base->right != NULL)
            ck_abort_msg("tree_base->base->children wasnt NULL, expected NULL");
        isValid = insert(ptr_tree_base_int_1, b);
        ck_assert_int_eq(isValid, true);
        int z = *(int*)(ptr_tree_base_int_1->base->right->value);
        ck_assert_int_eq(z, 6);
    } END_TEST

START_TEST(test_BST_AND_INSERT_BST) {
        for (int i = 0; i < arr_size; i++) {
            insert(ptr_tree_base_int_1, (int_arr_ptr + i));
        }
        printTree(ptr_tree_base_int_1);
//        bool isValid =
//        ck_assert_int_eq(isValid, true);
    } END_TEST

START_TEST(test_COMP_INTS) {
        int a,b,c;
        a = b = c = 123;
        ck_assert_int_eq(comp_ints(&a,&b), 0);
        ck_assert_int_eq(comp_ints(&a,&c), 0);
        ck_assert_int_eq(comp_ints(&c,&b), 0);
        b = 234;
        c = 345;
        ck_assert_int_eq(comp_ints(&a,&b), -1);
        ck_assert_int_eq(comp_ints(&a,&c), -1);
        ck_assert_int_eq(comp_ints(&c,&b), 1);
        ck_assert_int_eq(comp_ints(&b,&a), 1);
        ck_assert_int_eq(comp_ints(&c,&a), 1);
        ck_assert_int_eq(comp_ints(&b,&c), -1);
        ck_assert_int_eq(comp_ints(&a,&a), 0);
        ck_assert_int_eq(comp_ints(&b,&b), 0);
        ck_assert_int_eq(comp_ints(&c,&c), 0);
    } END_TEST

START_TEST(test_CLEAN_INTS) {
        ck_assert_int_eq(5, 5);
    } END_TEST

START_TEST(test_NODE_DUBLICATES) {
        ck_assert_int_eq(5, 5);
    } END_TEST


Suite *tree_program_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("TreeProgramSuite");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_checked_fixture(tc_core, setup, teardown);
    tcase_add_test(tc_core, test_CHECK);
    tcase_add_test(tc_core, test_INSERT);
	tcase_add_test(tc_core, test_BST_AND_INSERT_BST);
    tcase_add_test(tc_core, test_COMP_INTS);
    tcase_add_test(tc_core, test_CLEAN_INTS);
    tcase_add_test(tc_core, test_NODE_DUBLICATES);
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