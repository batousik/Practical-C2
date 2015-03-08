#include <check.h>
#include <time.h>
#include "../src/treenode.h"

// DECLARE VARS
TreeBase tree_base_int_1, *ptr_tree_base_int_1;
TreeNode *ptr_tree_node;
int *int_arr_ptr;
int arr_size = 25;
int int_arr [25];
bool isValid;

void setup(void) {
    int_arr_ptr = calloc(arr_size, (sizeof(int)));
    ptr_tree_base_int_1 = new_base(comp_ints, clean_ints, print_ints);
    if(!ptr_tree_base_int_1 || !int_arr_ptr) {
        printf("Error allocating memory in test Setup\n");
        fflush(stdout);
        assert(NULL);
    }
    for (int i = 0; i < arr_size; ++i) {
        int r = rand() % 20000;
        *(int_arr_ptr+i) = r;
    }
}

void teardown(void){
    if (ptr_tree_base_int_1){
        isValid = freeTree(ptr_tree_base_int_1);
        ck_assert_int_eq(isValid, true);
        free(ptr_tree_base_int_1);
        ptr_tree_base_int_1 = NULL;
    }
    if(int_arr_ptr){
        free(int_arr_ptr);
        int_arr_ptr = NULL;
    }
}

//START_TEST(test_COMP_INTS) {
//        int a,b,c;
//        a = b = c = -234;
//        ck_assert_int_eq(comp_ints(&a,&b), 0);
//        ck_assert_int_eq(comp_ints(&a,&c), 0);
//        ck_assert_int_eq(comp_ints(&c,&b), 0);
//        b = 234;
//        c = 345;
//        ck_assert_int_eq(comp_ints(&a,&b), -1);
//        ck_assert_int_eq(comp_ints(&a,&c), -1);
//        ck_assert_int_eq(comp_ints(&c,&b), 1);
//        ck_assert_int_eq(comp_ints(&b,&a), 1);
//        ck_assert_int_eq(comp_ints(&c,&a), 1);
//        ck_assert_int_eq(comp_ints(&b,&c), -1);
//        ck_assert_int_eq(comp_ints(&a,&a), 0);
//        ck_assert_int_eq(comp_ints(&b,&b), 0);
//        ck_assert_int_eq(comp_ints(&c,&c), 0);
//    } END_TEST
//
//START_TEST(test_CLEAN_INTS) {
//        int *a = malloc(sizeof(int));
//        // check if memory was allocated
//        if(a) {
//            *a = 234;
//            ck_assert_int_eq(*a, 234);
//            clean_ints(a);
//            a = NULL;
//            if(a) {
//                ck_abort_msg("FAILED freeing pointer\n");
//            }
//        }
//    } END_TEST
//
//START_TEST(test_PRINT_INTS) {
//        int *a = malloc(sizeof(int));
//        // check if memory was allocated
//        if(a) {
//            *a = 234;
//            ck_assert_int_eq(*a, 234);
//            printf("!!!Next line has to be:\"234\"\n");
//            fflush(stdout);
//            print_ints(a);
//            clean_ints(a);
//        }
//    } END_TEST
//
//START_TEST(test_CHECK) {
//        ck_assert_int_eq(true, 1);
//        ck_assert_int_eq(false, 0);
//        ck_assert_int_eq(5, 5);
//} END_TEST
//
//START_TEST(test_INSERT) {
//        int *a, *b;
//        a = malloc(sizeof(int));
//        b = malloc(sizeof(int));
//        *a = 5;
//        *b = 6;
//        isValid = freeTree(ptr_tree_base_int_1);
//        ck_assert_int_eq(isValid, true);
//        if (!ptr_tree_base_int_1)
//            ck_abort_msg("tree_base was NULL\n");
//        if (ptr_tree_base_int_1->base)
//            ck_abort_msg("tree_base->base was not NULL, expected NULL\n");
//        isValid = insert(ptr_tree_base_int_1, a);
//        ck_assert_int_eq(isValid, true);
//        if (!(ptr_tree_base_int_1->base))
//            ck_abort_msg("tree_base->base was NULL, expected assigned node\n");
//        ck_assert_int_eq(1, ptr_tree_base_int_1->size);
//        if (ptr_tree_base_int_1->base->left || ptr_tree_base_int_1->base->right)
//            ck_abort_msg("tree_base->base->children wasnt NULL, expected NULL\n");
//        isValid = insert(ptr_tree_base_int_1, b);
//        ck_assert_int_eq(isValid, true);
//        int z = *(int*)(ptr_tree_base_int_1->base->right->value);
//        ck_assert_int_eq(z, 6);
//    } END_TEST
//
//START_TEST(test_BST_AND_INSERT_BST) {
//        int *ptr;
//        for (int i = 0; i < arr_size; i++) {
//            ptr = malloc(sizeof(int));
//            memcpy(ptr, (int_arr_ptr + i), sizeof(int));
//            insert(ptr_tree_base_int_1, ptr);
//        }
//        isValid = printTree(ptr_tree_base_int_1);
//        ck_assert_int_eq(isValid, true);
//    } END_TEST
//
//
//START_TEST(test_NODE_DUBLICATES_AND_COUNTERS) {
//        int *a, *b, *c;
//        a = malloc(sizeof(int));
//        b = malloc(sizeof(int));
//        c = malloc(sizeof(int));
//        *a = 5;
//        *b = 5;
//        *c = 6;
//
//        ck_assert_int_eq(ptr_tree_base_int_1->size, 0);
//        ck_assert_int_eq(ptr_tree_base_int_1->total_num, 0);
//
//        isValid = insert(ptr_tree_base_int_1, a);
//        ck_assert_int_eq(isValid, true);
//        ck_assert_int_eq(ptr_tree_base_int_1->size, 1);
//        ck_assert_int_eq(ptr_tree_base_int_1->total_num, 1);
//        ck_assert_int_eq(ptr_tree_base_int_1->base->cnt_dublicates, 1);
//
//        isValid = insert(ptr_tree_base_int_1, b);
//        ck_assert_int_eq(isValid, false);
//        ck_assert_int_eq(ptr_tree_base_int_1->size, 1);
//        ck_assert_int_eq(ptr_tree_base_int_1->base->cnt_dublicates, 2);
//        ck_assert_int_eq(ptr_tree_base_int_1->total_num, 2);
//
//        isValid = insert(ptr_tree_base_int_1, c);
//        ck_assert_int_eq(isValid, true);
//
//        ck_assert_int_eq(ptr_tree_base_int_1->total_num, 3);
//        ck_assert_int_eq(ptr_tree_base_int_1->size, 2);
//        ck_assert_int_eq(ptr_tree_base_int_1->base->cnt_dublicates, 2);
//        ck_assert_int_eq(ptr_tree_base_int_1->base->right->cnt_dublicates, 1);
//        // no need to free allocations, will be done in tear down
//    } END_TEST

START_TEST(test_START_EMPTY_TREE_TREEBASE_PRINT_FREETREE_TEST) {
        printf("_________START_EMPTY_TREE/TREEBASE_PRINT/FREETREE_TEST__________\n");
        fflush(stdout);

        int *ptr;
        for (int i = 0; i < arr_size; i++) {
            ptr = malloc(sizeof(int));
            memcpy(ptr, (int_arr_ptr + i), sizeof(int));
            isValid = insert(ptr_tree_base_int_1, ptr);
            ck_assert_int_eq(isValid, true);
        }
//        // should print tree
//        printf("!!!Next lines has to be tree printed out\n");
//        fflush(stdout);
//        isValid = printTree(ptr_tree_base_int_1);
//        ck_assert_int_eq(isValid, true);
//        fflush(stdout);
//        printf("_____________________\n");
//        fflush(stdout);
//
//        // No output
//        isValid = freeTree(ptr_tree_base_int_1);
//        ck_assert_int_eq(isValid, true);
//        // should print cannot free empty tree
//        printf("!!!Next line has to be:\"cannot free empty tree\"\n");
//        fflush(stdout);
//        isValid = freeTree(ptr_tree_base_int_1);
//        ck_assert_int_eq(isValid, true);
//        fflush(stdout);
//
//        // should print cannot print empty tree
//        printf("!!!Next line has to be:\"cannot print empty tree\"\n");
//        fflush(stdout);
//        isValid = printTree(ptr_tree_base_int_1);
//        ck_assert_int_eq(isValid, false);
//        fflush(stdout);
//        printf("_____________________\n");
//        fflush(stdout);
//        ck_assert_int_eq(ptr_tree_base_int_1->size, 0);
//        free(ptr_tree_base_int_1);
//        ptr_tree_base_int_1 = NULL;
//
//        // should print cannot free empty tree base
//        printf("!!!Next line has to be:\"cannot free empty tree base\"\n");
//        fflush(stdout);
//        isValid = freeTree(ptr_tree_base_int_1);
//        ck_assert_int_eq(isValid, true);
//        fflush(stdout);
//
//        // should print cannot print empty tree base
//        printf("!!!Next line has to be:\"cannot print empty tree base\"\n");
//        fflush(stdout);
//        isValid = printTree(ptr_tree_base_int_1);
//        ck_assert_int_eq(isValid, false);
//        fflush(stdout);
//        printf("_____________________\n");
//        fflush(stdout);
//
//        free(int_arr_ptr);
//        int_arr_ptr = NULL;
//        printf("freeing the array...\n");
//        fflush(stdout);
//        printf("________END_____________\n");
//        fflush(stdout);
    } END_TEST

//START_TEST(test_TREE_QUERY) {
//        int temp_arr_size = 17;
//        int *a_arr = malloc(temp_arr_size * sizeof(int));
//        int *b_arr = malloc(temp_arr_size * sizeof(int));
//
//
//        if (!a_arr || !b_arr)
//            ck_abort_msg("FAILED memory allocation\n");
//
//        *(a_arr + 0) = 34;
//        *(a_arr + 1) = 23;
//        *(a_arr + 2) = 74;
//        *(a_arr + 3) = 312;
//        *(a_arr + 4) = 39;
//        *(a_arr + 5) = 25;
//        *(a_arr + 6) = 222;
//        *(a_arr + 7) = 21;
//        *(a_arr + 8) = 12;
//        *(a_arr + 9) = 345;
//        *(a_arr + 10) = 90;
//        *(a_arr + 11) = 99;
//        *(a_arr + 12) = 9454;
//        *(a_arr + 13) = 9994;
//        *(a_arr + 14) = -9998;
//        *(a_arr + 15) = -234;
//        *(a_arr + 16) = -4554;
//
//        for (int i = 0; i < temp_arr_size; ++i) {
//            isValid = insert(ptr_tree_base_int_1, (a_arr+i));
//            ck_assert_int_eq(isValid, true);
//        }
//
//        memcpy(b_arr, a_arr, temp_arr_size*(sizeof(int)));
//
//        for (int i = 0; i < temp_arr_size; ++i) {
//            *(b_arr+i)=*(b_arr+i)+1;
//        }
//
//        for (int i = 0; i < temp_arr_size; ++i) {
//            ptr_tree_node = query(ptr_tree_base_int_1, (a_arr + i));
//            ck_assert_int_eq(isValid, true);
//        }
//
//        ptr_tree_node = NULL;
//
//        for (int i = 0; i < temp_arr_size; ++i) {
//            ptr_tree_node = query(ptr_tree_base_int_1, (a_arr + i));
//            if (!ptr_tree_node)
//                ck_abort_msg("Value exists, query returned NULL\n");
//            ptr_tree_node = NULL;
//        }
//
//        for (int i = 0; i < temp_arr_size; ++i) {
//            ptr_tree_node = query(ptr_tree_base_int_1, (b_arr + i));
//            if (ptr_tree_node)
//                ck_abort_msg("Value does not exist, query didn't return NULL\n");
//            ptr_tree_node = NULL;
//        }
//        if(b_arr){
//            free(b_arr);
//        }
//    } END_TEST


Suite *tree_program_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("TreeProgramSuite");

    /* Core test case */
    tc_core = tcase_create("Core");

  //  tcase_add_checked_fixture(tc_core, setup, teardown);
  //  tcase_add_test(tc_core, test_COMP_INTS);
   // tcase_add_test(tc_core, test_CLEAN_INTS);
   // tcase_add_test(tc_core, test_PRINT_INTS);
   // tcase_add_test(tc_core, test_CHECK);
    //tcase_add_test(tc_core, test_INSERT);
	//tcase_add_test(tc_core, test_BST_AND_INSERT_BST);
    tcase_add_test(tc_core, test_START_EMPTY_TREE_TREEBASE_PRINT_FREETREE_TEST);
	//tcase_add_test(tc_core, test_TREE_QUERY);
	//tcase_add_test(tc_core, test_NODE_DUBLICATES_AND_COUNTERS);
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

    // setting to no fork()
	s = tree_program_suite();
	sr = srunner_create(s);

    srunner_set_fork_status(sr, CK_NOFORK);

	srunner_set_log (sr, "test.log");
	srunner_run_all(sr, CK_VERBOSE);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
    sr = NULL;
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}