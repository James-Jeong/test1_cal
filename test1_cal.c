#include "local/test1_cal_l.h"

//////////////////////////////////////
// Sttic functions for test1_cal_t
//////////////////////////////////////

static void test1_cal_get_values( test1_cal_t *cal);
static void test1_cal_get_seq( test1_cal_t *cal);
static int test1_cal_input_data( int *val);
static int _test1_cal_add( test1_cal_t *cal);
static int _test1_cal_sub( test1_cal_t *cal);
static int _test1_cal_mul( test1_cal_t *cal);
static int _test1_cal_div( test1_cal_t *cal);

//////////////////////////////////////
// Local functions for test1_cal_t
//////////////////////////////////////

/**
 * @fn test1_cal_t* test1_cal_create( int val1, int val2)
 * @brief function to create test1_cal_t struct object
 * @return 할당 성공 시 test1_cal_t 구조체 포인터, 실패 시 NULL 반환
 */
test1_cal_t* test1_cal_create(){
	int return_value = CAL_FAIL;

	test1_cal_t *cal = ( test1_cal_t*)calloc( sizeof( test1_cal_t), 0);
	if( cal == NULL){
		printf("	| ! Fail to allocate test1_cal_t.\n");
		return NULL;
	}

	return_value = test1_cal_init( cal);
	if( return_value < CAL_SUCCESS){
		printf("	| ! Fail to initialize test1_cal_t.\n");
		return NULL;
	}

	return cal;
}

/**
 * @fn int test1_cal_init( test1_cal_t *cal)
 * @brief function to initialize test1_cal_t struct object
 * @param cal test1_cal_t struct object to initialize
 * @return 초기화 성공 시 CAL_SUCCESS, 매개변수가 NULL 이면 CAL_FAIL 을 반환
 */
int test1_cal_init( test1_cal_t *cal){
	if( cal != NULL){
		test1_cal_get_values( cal);
		test1_cal_get_seq( cal);
		cal->func[0] = _test1_cal_add;
		cal->func[1] = _test1_cal_sub;
		cal->func[2] = _test1_cal_mul;
		cal->func[3] = _test1_cal_div;
	}
	else return CAL_FAIL;
	return CAL_SUCCESS;
}

/**
 * @fn void test1_cal_final( test1_cal_t *cal)
 * @brief function to finalize test1_cal_t struct object, destroy memory of member objects
 * @param cal test1_cal_t struct object to finalize
 * @return 반환값 없음
 */
void test1_cal_final( test1_cal_t *cal){
	memset( cal, 0, sizeof( cal));
}

/**
 * @fn void test1_cal_destroy( test1_cal_t **cal)
 * @brief function to detroy memory of test1_cal_t struct object
 * @param cal test1_cal_t struct object to destroy
 * @return 반환값 없음
 */
void test1_cal_destroy( test1_cal_t **cal){
	test1_cal_final( *cal);
	free( *cal);
	*cal = NULL;
}

/**
 * @fn static int _test1_cal_add( test1_cal_t *cal)
 * @brief function to add data of test1_cal_t struct object
 * @param cal test1_cal_t struct object to add
 * @return 덧셈 성공 시 CAL_SUCCESS, 매개변수가 NULL 이면 CAL_FAIL 을 반환
 */
static int _test1_cal_add( test1_cal_t *cal){
	if( cal == NULL) return CAL_FAIL;

	cal->result_add = cal->val1 + cal->val2;
	printf("	| @ Plus	: (%d) + (%d) = %d\n", cal->val1, cal->val2, cal->result_add);
	return CAL_SUCCESS;
}

/**
 * @fn static int _test1_cal_sub( test1_cal_t *cal)
 * @brief function to sub data of test1_cal_t struct object
 * @param cal test1_cal_t struct object to sub
 * @return 뺄셈 성공 시 CAL_SUCCESS, 매개변수가 NULL 이면 CAL_FAIL 을 반환
 */
static int _test1_cal_sub( test1_cal_t *cal){
	if( cal == NULL) return CAL_FAIL;

	cal->result_sub = cal->val1 - cal->val2;
	printf("	| @ Minus	: (%d) - (%d) = %d\n", cal->val1, cal->val2, cal->result_sub);
	return CAL_SUCCESS;
}

/**
 * @fn static int _test1_cal_mul( test1_cal_t *cal)
 * @brief function to multiply data of test1_cal_t struct object
 * @param cal test1_cal_t struct object to multiply
 * @return 곱셈 성공 시 CAL_SUCCESS, 매개변수가 NULL 이면 CAL_FAIL 을 반환
 */
static int _test1_cal_mul( test1_cal_t *cal){
	if( cal == NULL) return CAL_FAIL;

	cal->result_mul = cal->val1 * cal->val2;
	printf("	| @ Multiply	: (%d) x (%d) = %d\n", cal->val1, cal->val2, cal->result_mul);
	return CAL_SUCCESS;
}

/**
 * @fn static int _test1_cal_div( test1_cal_t *cal)
 * @brief function to divide data of test1_cal_t struct object
 * @param cal test1_cal_t struct object to divide
 * @return 나눗셈 성공 시 CAL_SUCCESS, 매개변수가 NULL 이거나 두 번째 수가 0 이면 CAL_FAIL 을 반환
 */
static int _test1_cal_div( test1_cal_t *cal){
	if( cal == NULL) return CAL_FAIL;
	if( cal->val2 == 0){
		return CAL_FAIL;
	}
	else{
		cal->result_div = (double)cal->val1 / (double)cal->val2;
		cal->is_div_success++;
	}

	if( cal->is_div_success == CAL_SUCCESS) printf("	| @ Divide	: (%d) / (%d) = %0.2f\n", cal->val1, cal->val2, cal->result_div);
	else if( cal->is_div_success == CAL_FAIL) printf("	| ! Fail to calculate divide. val2 is '0' (val1:%d / val2:%d)\n", cal->val1, cal->val2);

	return CAL_SUCCESS;
}

/**
 * @fn void test1_cal_print_all( test1_cal_t *cal)
 * @brief function to print data of test1_cal_t struct object
 * @param cal test1_cal_t struct object to print
 * @return 반환값 없음
 */
void test1_cal_print_all( test1_cal_t *cal){
	if( cal == NULL) return ;

	printf("\n\t| @ Input1	: %d / Input2 : %d\n", cal->val1, cal->val2);

	int return_value = 0, i;
	for( i = 0; i < MAX_NCAL; i++){
		return_value = cal->func[ cal->seq_list[i] - 1]( cal);
		if( return_value < CAL_SUCCESS) printf("\t| ! Fail to calculate values for test1_cal_t. (index:%d)\n", i);
	} printf("\n");
}


/**
 * @fn static void test1_cal_get_values( test1_cal_t *cal)
 * @brief 사칙연산 계산을 위한 두 개의 숫자를 입력받는 함수
 * @param cal test1_cal_t struct object to print
 * @return 반환값 없음
 */
static void test1_cal_get_values( test1_cal_t *cal){
	/** return value to check error for val1 */
	/** return value to check error for val2 */
	int return_value_val1 = CAL_FAIL, return_value_val2 = CAL_FAIL;
	cal->val1 = DEFAULT_INT;
	cal->val2 = DEFAULT_INT;

	while( 1){
		if(( cal->val1 == DEFAULT_INT) && ( return_value_val1 == CAL_FAIL)){
			printf("\t| @ Enter first value\t: ");
			return_value_val1 = test1_cal_input_data( &cal->val1);
			if( return_value_val1 < CAL_SUCCESS) continue;
		}

		if(( cal->val2 == DEFAULT_INT) && ( return_value_val2 == CAL_FAIL)){
			printf("\t| @ Enter second value\t: ");
			return_value_val2 = test1_cal_input_data( &cal->val2);
			if( return_value_val2 < CAL_SUCCESS) continue;
			if( cal->val2 == CAL_FAIL){
				printf("| ! Wrong value, value is zero!\n");
				cal->val2 = DEFAULT_INT;
				return_value_val2 = CAL_FAIL;
				continue;
			}
		}

		if(( cal->val1 != DEFAULT_INT) && ( cal->val2 != DEFAULT_INT) && ( return_value_val1 == CAL_SUCCESS) && ( return_value_val2 == CAL_SUCCESS)) break;
	}
}

/**
 * @fn static void test1_cal_get_seq( test1_cal_t *cal)
 * @brief 사칙연산을 출력할 방식(내림차순, 오름차순)을 결정하는(입력받는) 함수
 * @param cal test1_cal_t struct object to print
 * @return 반환값 없음
 */
static void test1_cal_get_seq( test1_cal_t *cal){
	int i;
	/** sequence number to print data for test1_cal_t */
	int seq = DEFAULT_INT;
	/** return value to check error for seq */
	int return_value_seq = CAL_FAIL;
	/** count value for seq */
	int seq_count = CAL_FAIL;

	printf("\n\t| @ Sequence number decision\n");
	printf("\t| @ [1:add] [2:sub] [3:mul] [4:div]\n");
	while( 1){
		if(( seq == DEFAULT_INT) && ( return_value_seq == CAL_FAIL)){
			printf("\t| @ Enter sequence number (%d)\t: ", (seq_count+1));
			return_value_seq = test1_cal_input_data( &seq);
			if( return_value_seq < CAL_SUCCESS) continue;
			if(( seq <= 0) && ( seq > 4)){
				printf("\t| ! Wrong sequence number, value is invalid!\n");
				seq = DEFAULT_INT;
				continue;
			}

			cal->seq_list[seq_count] = seq;
			seq_count++;

			if( seq_count < MAX_NCAL){
				seq = DEFAULT_INT;
				return_value_seq = CAL_FAIL;
			}
		}

		if(( seq != DEFAULT_INT) && ( return_value_seq == CAL_SUCCESS) && ( seq_count == MAX_NCAL)) break;
	}
}

/**
 * @fn static int test1_cal_input_data( int *val)
 * @brief 하나의 숫자를 입력받는 함수
 * @param val 입력 받을 int 포인터 변수
 * @return 숫자 입력 성공 시 입력한 숫자, 문자열 입력 시 CAL_FAIL 을 반환
 */
static int test1_cal_input_data( int *val){
	int return_value = scanf( "%d", val);
	if( return_value == CAL_FAIL){
		printf("\t| ! Wrong value, value is not integer!\n");
		*val = DEFAULT_INT;
		while( getchar() != '\n');
		return return_value;
	}
	return return_value;
}

