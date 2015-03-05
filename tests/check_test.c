#include <check.h>
#include <stdlib.h>
#include "../src/treenode.h"

// Testing size 3 square only

// Declare vars
// MAGICSQUARE msCompl, msIncompl, msIncompl1, msIncompl2, msInvalid, msInvalid2, ms5, msD1,msD2;
// int size3;

void setup(void) {
	// size3 = 3;
	// magic_sum = init_magic_sum();
	// if (SIZE == size3){
	// 	msCompl = return_square(4,9,2,3,5,7,8,1,6);
	// 	msInvalid = return_square(9,5,2,3,4,7,8,1,6);
	// 	msInvalid2 = return_square(9,4,2,3,5,7,8,1,6);
	// 	msIncompl = return_square(4,0,2,3,0,7,8,1,6);
	// 	msIncompl1 = return_square(0,1,2,4,0,0,5,0,6);
	// 	msIncompl2 = return_square(4,0,0,0,9,3,8,0,0);
	// 	msD1 = return_square(4,0,4,10,9,3,2,0,2);
	// 	msD2 = return_square(4,0,4,0,9,3,2,0,1);
	// 	ms5 = return_square(5,5,5,5,5,5,5,5,5);
	// }
}

void teardown(void){
	//free(p_ms5);
}

START_TEST(test_one) {   
    ck_assert_int_eq(5, 5);
} END_TEST

// START_TEST(test_magic_sum) {   
//     ck_assert_int_eq((SIZE * (SIZE * SIZE + 1)) / 2, init_magic_sum());
// } END_TEST

// START_TEST(test_magic_check_square) {
// 	if (SIZE == size3) {
// 	    ck_assert_int_eq(INVALID, check_square(msInvalid));
// 	    ck_assert_int_eq(COMPLETE, check_square(msCompl));
// 	    ck_assert_int_eq(INCOMPLETE, check_square(msIncompl));
// 	    ck_assert_int_eq(COMPLETE, check_square(ms5));
// 	}
// } END_TEST

// START_TEST(test_check_nonempty) {
// 	if (SIZE == size3) {
// 	    ck_assert_int_eq(true, check_nonempty(msInvalid));
// 	    ck_assert_int_eq(true, check_nonempty(msCompl));
// 	    ck_assert_int_eq(false, check_nonempty(msIncompl));
// 	    ck_assert_int_eq(false, check_nonempty(msIncompl1));
// 	    ck_assert_int_eq(false, check_nonempty(msIncompl2));
// 	    ck_assert_int_eq(true, check_nonempty(ms5));
// 	}
// } END_TEST

// START_TEST(test_check_diag) {
// if (SIZE == size3) {   
// 	    ck_assert_int_eq(true, check_diag(msD1));
// 	    ck_assert_int_eq(false, check_diag(msD2));
// 	    ck_assert_int_eq(true, check_diag(msCompl));
// 	    ck_assert_int_eq(false, check_diag(msIncompl));
// 	    ck_assert_int_eq(true, check_diag(ms5));
// 	}
// } END_TEST

// START_TEST(test_check_columns) {
// 	if (SIZE == size3) {
// 	    ck_assert_int_eq(true, check_columns(msCompl));
// 	    ck_assert_int_eq(false, check_columns(msIncompl));
// 	    ck_assert_int_eq(false, check_columns(msInvalid));
// 	    ck_assert_int_eq(false, check_columns(msIncompl1));
// 	    ck_assert_int_eq(false, check_columns(msIncompl2));
// 	    ck_assert_int_eq(true, check_columns(ms5));
// 	    ck_assert_int_eq(false, check_columns(msD1));
// 	    ck_assert_int_eq(false, check_columns(msD2));
// 	    ck_assert_int_eq(false, check_columns(msInvalid2));
// 	}
// } END_TEST

// START_TEST(test_check_rows) {
// 	if (SIZE == size3) {   
// 	    ck_assert_int_eq(true, check_rows(msCompl));
// 	    ck_assert_int_eq(false, check_rows(msIncompl));
// 	    ck_assert_int_eq(false, check_rows(msInvalid));
// 	    ck_assert_int_eq(false, check_rows(msIncompl1));
// 	    ck_assert_int_eq(false, check_rows(msIncompl2));
// 	    ck_assert_int_eq(true, check_rows(ms5));
// 	    ck_assert_int_eq(false, check_rows(msD1));
// 	    ck_assert_int_eq(false, check_rows(msD2));
// 	    ck_assert_int_eq(true, check_rows(msInvalid2));
// 	}
// } END_TEST

// START_TEST(test_size5) {
// 	if(SIZE == 5){
// 		MAGICSQUARE msCompl5;
// 		for (int i = 0; i < SIZE; i++) {
// 			for (int j = 0; j < SIZE; j++) {
// 				msCompl5.arr[i][j] = 13;
// 			}
// 		}
// 		ck_assert_int_eq(65, init_magic_sum());
// 	    ck_assert_int_eq(true, check_diag(msCompl5));
// 		ck_assert_int_eq(true, check_square(msCompl5));
// 		ck_assert_int_eq(true, check_nonempty(msCompl5));
// 	    ck_assert_int_eq(false, check_columns(msCompl5));
// 		ck_assert_int_eq(true, check_rows(msCompl5));
// 	}
// } END_TEST

// START_TEST(test_any_ms_size) {
// 	MAGICSQUARE msAnySize;
// 	for (int i = 0; i < SIZE; i++) {
// 		for (int j = 0; j < SIZE; j++) {
// 			msAnySize.arr[i][j] = 1;
// 		}
// 	}
// 	ck_assert_int_eq(msAnySize.arr[SIZE+1][SIZE+1], 0);
// 	magic_sum = SIZE;
// 	ck_assert_int_eq(COMPLETE, check_square(msAnySize));
// 	ck_assert_int_eq(true, check_diag(msAnySize));
// 	ck_assert_int_eq(true, check_nonempty(msAnySize));
//     ck_assert_int_eq(true, check_columns(msAnySize));
// 	ck_assert_int_eq(true, check_rows(msAnySize));

// } END_TEST




// START_TEST(test_swap_in_directed) {
// 	if (SIZE == size3){
// 	DIRECTEDMAGICSQUARE dms = {
// 		{
		
// 			{
// 				{1,(-1)},
// 				{2,(+1)},
// 				{3,(+1)}
// 			},
// 			{
// 				{4,(+1)},
// 				{5,(-1)},
// 				{6,(-1)}
// 			},
// 			{
// 				{7,(-1)},
// 				{8,(-1)},
// 				{9,(-1)}
// 			}
// 		}
// 	};
// 	swap (&dms, 1);
// 	swap (&dms, 2);
// 	swap (&dms, 3);
// 	swap (&dms, 7);
// 	swap (&dms, 6);

	
// 	ck_assert_int_eq(dms.arr[0][0][0],1);
// 	ck_assert_int_eq(dms.arr[0][1][0],3);
// 	ck_assert_int_eq(dms.arr[0][2][0],4);
// 	ck_assert_int_eq(dms.arr[1][0][0],5);
// 	ck_assert_int_eq(dms.arr[1][1][0],2);
// 	ck_assert_int_eq(dms.arr[1][2][0],8);
// 	ck_assert_int_eq(dms.arr[2][0][0],6);
// 	ck_assert_int_eq(dms.arr[2][1][0],7);
// 	ck_assert_int_eq(dms.arr[2][2][0],9);
// }
// } END_TEST

// START_TEST(test_update_in_direction) {
// 	if (SIZE == size3){
// 	DIRECTEDMAGICSQUARE dms = {
// 		{
		
// 			{
// 				{1,(-1)},
// 				{2,(-1)},
// 				{3,(-1)}
// 			},
// 			{
// 				{4,(-1)},
// 				{5,(-1)},
// 				{6,(-1)}
// 			},
// 			{
// 				{7,(-1)},
// 				{8,(-1)},
// 				{9,(-1)}
// 			}
// 		}
// 	};

// 	swapDirection(&dms, 5);

// 	ck_assert_int_eq(dms.arr[0][0][1],(-1));
// 	ck_assert_int_eq(dms.arr[0][1][1],(-1));
// 	ck_assert_int_eq(dms.arr[0][2][1],(-1));
// 	ck_assert_int_eq(dms.arr[1][0][1],(-1));
// 	ck_assert_int_eq(dms.arr[1][1][1],(-1));
// 	ck_assert_int_eq(dms.arr[1][2][1],(1));
// 	ck_assert_int_eq(dms.arr[2][0][1],(1));
// 	ck_assert_int_eq(dms.arr[2][1][1],(1));
// 	ck_assert_int_eq(dms.arr[2][2][1],(1));
// }
// } END_TEST

// START_TEST(test_is_mobile) {
// 	if (SIZE == size3){
// 	DIRECTEDMAGICSQUARE dms = {
// 		{
		
// 			{
// 				{9,(-1)},
// 				{2,(-1)},
// 				{3,(-1)}
// 			},
// 			{
// 				{4,(-1)},
// 				{5,(1)},
// 				{6,(-1)}
// 			},
// 			{
// 				{7,(-1)},
// 				{8,(-1)},
// 				{1,(-1)}
// 			}
// 		}
// 	};

// 	int i,j,a;
// 	a = 0;
// 	i = a/3;
// 	j = a%3;
// 	ck_assert_int_eq(i,0);
// 	ck_assert_int_eq(j,0);
// 	a = 1;
// 	i = a/3;
// 	j = a%3;
// 	ck_assert_int_eq(i,0);
// 	ck_assert_int_eq(j,1);
// 	ck_assert_int_eq(isMobile(dms, i, j, a),false);
// 	a = 2;
// 	i = a/3;
// 	j = a%3;
// 	ck_assert_int_eq(i,0);
// 	ck_assert_int_eq(j,2);
// 	ck_assert_int_eq(isMobile(dms, i, j, a),true);
// 	a = 3;
// 	i = a/3;
// 	j = a%3;
// 	ck_assert_int_eq(i,1);
// 	ck_assert_int_eq(j,0);
// 	ck_assert_int_eq(isMobile(dms, i, j, a),true);
// 	a = 4;
// 	i = a/3;
// 	j = a%3;
// 	ck_assert_int_eq(i,1);
// 	ck_assert_int_eq(j,1);
// 	ck_assert_int_eq(isMobile(dms, i, j, a),false);
// 	a = 5;
// 	i = a/3;
// 	j = a%3;
// 	ck_assert_int_eq(i,1);
// 	ck_assert_int_eq(j,2);
// 	ck_assert_int_eq(isMobile(dms, i, j, a),true);
// 	a = 6;
// 	i = a/3;
// 	j = a%3;
// 	ck_assert_int_eq(i,2);
// 	ck_assert_int_eq(j,0);
// 	ck_assert_int_eq(isMobile(dms, i, j, a),true);
// 	a = 7;
// 	i = a/3;
// 	j = a%3;
// 	ck_assert_int_eq(i,2);
// 	ck_assert_int_eq(j,1);
// 	ck_assert_int_eq(isMobile(dms, i, j, a),true);
// 	a = 8;
// 	i = a/3;
// 	j = a%3;
// 	ck_assert_int_eq(i,2);
// 	ck_assert_int_eq(j,2);
// 	ck_assert_int_eq(isMobile(dms, i, j, a),false);
// }
// } END_TEST

// START_TEST( test_dms_on_extreme){
// 	if (SIZE == size3){
// 		DIRECTEDMAGICSQUARE dms = {
// 		{
		
// 			{
// 				{1,(-1)},
// 				{9,(-1)},
// 				{2,(-1)}
// 			},
// 			{
// 				{3,(-1)},
// 				{4,(-1)},
// 				{5,(-1)}
// 			},
// 			{
// 				{6,(-1)},
// 				{7,(-1)},
// 				{8,(-1)}
// 			}
// 		}
// 	};

// int index = -1;
// int value = -1;
// // print_d_square(dms);

// findLargestMobile(dms, &index, &value);
// ck_assert_int_eq(9,value);
// ck_assert_int_eq(1,index);
// swap (&dms, index);
// // print_d_square(dms);
// // printf("val %d index %d\n", value, index);
// swapDirection(&dms, value);
// // print_d_square(dms);

// index = -1;
// value = -1;



// findLargestMobile(dms, &index, &value);
// ck_assert_int_eq(8,value);
// ck_assert_int_eq(8,index);
// swap (&dms, index);
// //print_d_square(dms);
// ///printf("val %d index %d\n", value, index);
// swapDirection(&dms, value);
// //print_d_square(dms);

// index = -1;
// value = -1;



// findLargestMobile(dms, &index, &value);
// ck_assert_int_eq(9,value);
// ck_assert_int_eq(0,index);
// swap (&dms, index);
// //print_d_square(dms);
// //printf("val %d index %d\n", value, index);
// swapDirection(&dms, value);
// //print_d_square(dms);

// for (int i = 0; i < 7; i++)
// {
// 	index = -1;
// 	value = -1;
// 	findLargestMobile(dms, &index, &value);
// 	swap (&dms, index);
// 	//print_d_square(dms);
// }
// }

// } END_TEST

// START_TEST(test_complete_4) {
// 	if(SIZE == 4) {
// 		//test works but wont compile with size other than 4
// 	// 	DIRECTEDMAGICSQUARE dms = {
// 	// 		{
			
// 	// 			{
// 	// 				{1,(-1)},
// 	// 				{8,(-1)},
// 	// 				{13,(-1)},
// 	// 				{12,(-1)}
// 	// 			},
// 	// 			{
// 	// 				{14,(-1)},
// 	// 				{11,(-1)},
// 	// 				{2,(-1)},
// 	// 				{7,(-1)}
// 	// 			},
// 	// 			{
// 	// 				{4,(-1)},
// 	// 				{5,(-1)},
// 	// 				{16,(-1)},
// 	// 				{9,(-1)}
// 	// 			},
// 	// 			{
// 	// 				{15,(-1)},
// 	// 				{10,(-1)},
// 	// 				{3,(-1)},
// 	// 				{6,(-1)}
// 	// 			}
// 	// 		}
// 	// 	};
// 	// ck_assert_int_eq(true, isValidDms(dms));
// 	}
// } END_TEST

// START_TEST(test_solve_the_ms_problem) {
// 	ck_assert_int_eq(solve_msProblem(),true);
// } END_TEST




Suite * magic_square_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("MagicSquare");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_checked_fixture(tc_core, setup, teardown);
    tcase_add_test(tc_core, test_one);
 //    tcase_add_test(tc_core, test_magic_sum);
	// tcase_add_test(tc_core, test_magic_check_square);
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

	s = magic_square_suite();
	sr = srunner_create(s);

	srunner_set_log (sr, "test.log");
	srunner_run_all(sr, CK_VERBOSE);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}