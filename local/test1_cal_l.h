#ifndef __TEST1_CAL_H__
#define __TEST1_CAL_H__

//////////////////////////////////////
// definition & macro for test1_cal_t
//////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

/** 성공 여부 */
#define CAL_SUCCESS 1
/** 실패 여부 */
#define CAL_FAIL 0
/** default value to calculate */
#define DEFAULT_INT INT_MAX
/** max number of calculation */
#define MAX_NCAL 4

typedef struct test1_cal_s test1_cal_t;
typedef int (*calculate_f)( test1_cal_t *cal);

/**@brief test1_cal_t struct */
struct test1_cal_s{
	uint16_t is_div_success;	/**< 나눗셈 계산 성공 여부 */
	int val1;					/**< first value to calculate */
	int val2;					/**< second value to calculate */
	int result_add;				/**< 덧셈 결과 */
	int result_sub;				/**< 뺄셈 결과 */
	int result_mul;				/**< 곱셈 결과 */
	double result_div;			/**< 나눗셈 결과 */
	int seq_list[ MAX_NCAL];	/**< 출력 순서 목록 */
	calculate_f func[MAX_NCAL];	/**< 사칙연산 지정 함수 포인터 */
};

//////////////////////////////////////
// function for test1_cal_t
//////////////////////////////////////
test1_cal_t* test1_cal_create();
int test1_cal_init( test1_cal_t *cal);
void test1_cal_final( test1_cal_t *cal);
void test1_cal_destroy( test1_cal_t **cal);

void test1_cal_print_all( test1_cal_t *cal);
void test_cal_clear( test1_cal_t *cal);

#endif // __TEST1_CAL_H__

