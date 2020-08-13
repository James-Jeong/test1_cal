#include "local/test1_cal_l.h"

test1_cal_t* test1_cal_create( int val1, int val2){
	int rv;

	test1_cal_t *cal = ( test1_cal_t*)malloc( sizeof( test1_cal_t));
	if( cal == NULL){
		printf("	| ! Fail to allocate test1_cal_t.\n");
		return NULL;
	}

	rv = test1_cal_init( cal, val1, val2); if( rv < 0){
		printf("	| ! Fail to initialize test1_cal_t.\n");
		return NULL;
	}

	return cal;
}

int test1_cal_init( test1_cal_t *cal, int val1, int val2){
	cal->is_div_success = 0;
	cal->val1 = val1;
	cal->val2 = val2;
	cal->result_plus = 0;
	cal->result_minus = 0;
	cal->result_mul = 0;
	cal->result_div = 0;

	return CAL_SUCCESS;
}

void test1_cal_final( test1_cal_t *cal){
}

void test1_cal_destroy( test1_cal_t *cal){
	test1_cal_final( cal);
	free( cal);
}

int test1_cal_plus( test1_cal_t *cal){
	cal->result_plus = cal->val1 + cal->val2;
	return CAL_SUCCESS;
}

int test1_cal_minus( test1_cal_t *cal){
	cal->result_minus = cal->val1 - cal->val2;
	return CAL_SUCCESS;
}

int test1_cal_mul( test1_cal_t *cal){
	cal->result_mul = cal->val1 * cal->val2;
	return CAL_SUCCESS;
}

int test1_cal_div( test1_cal_t *cal){
	if( cal->val2 == 0){
		return CAL_FAIL;
	}
	else{
		cal->result_div = (double)cal->val1 / (double)cal->val2;
		cal->is_div_success++;
	}
	return CAL_SUCCESS;
}

void test1_cal_print_all( test1_cal_t *cal){
	printf("	| @ Input1 : %d / Input2 : %d\n", cal->val1, cal->val2);
	printf("	| @ Plus : %d + %d = %d\n", cal->val1, cal->val2, cal->result_plus);
	printf("	| @ Minus : %d - %d = %d\n", cal->val1, cal->val2, cal->result_minus);
	printf("	| @ Multiply : %d x %d = %d\n", cal->val1, cal->val2, cal->result_mul);
	if( cal->is_div_success == CAL_SUCCESS) printf("	| @ Divide : %d / %d = %0.2f\n", cal->val1, cal->val2, cal->result_div);
	else if( cal->is_div_success == CAL_FAIL) printf("	| ! Fail to calculate divide. val2 is '0' (val1:%d / val2:%d)\n", cal->val1, cal->val2);
}

