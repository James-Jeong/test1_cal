#ifndef __TEST1_CAL_H__
#define __TEST1_CAL_H__

//////////////////////////////////////
// definition & macro for test1_cal_t
//////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define CAL_SUCCESS 1
#define CAL_FAIL 0

typedef struct test1_cal_s test1_cal_t;
struct test1_cal_s{
	uint16_t is_div_success;
	int val1;
	int val2;
	int result_plus;
	int result_minus;
	int result_mul;
	double result_div;
};

//////////////////////////////////////
// function for test1_cal_t
//////////////////////////////////////
test1_cal_t* test1_cal_create( int val1, int val2);
int test1_cal_init( test1_cal_t *cal, int val1, int val2);
void test1_cal_final( test1_cal_t *cal);
void test1_cal_destroy( test1_cal_t *cal);

int test1_cal_plus( test1_cal_t *cal);
int test1_cal_minus( test1_cal_t *cal);
int test1_cal_mul( test1_cal_t *cal);
int test1_cal_div( test1_cal_t *cal);
void test1_cal_print_all( test1_cal_t *cal);
void test_cal_clear( test1_cal_t *cal);

#endif // __TEST1_CAL_H__

