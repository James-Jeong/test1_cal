#include "local/test1_cal_l.h"

/**
 * @fn int main( int argc, char **argv)
 * @brief test1_cal_t 모듈 구동을 위한 main 프로그램
 * @return none
 * @param argc none
 * @param argv none
 */
int main( int argc, char **argv){
	test1_cal_t *cal = test1_cal_create();
	if( cal == NULL){
		return CAL_FAIL;
	}
	test1_cal_print_all( cal);
	test1_cal_destroy( &cal);
}

