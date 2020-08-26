#include "local/test1_cal_l.h"

/**
 * @fn int main()
 * @brief test1_cal_t 모듈 구동을 위한 main 프로그램
 * @return 반환값 없음
 */
void main(){
	test1_cal_t *cal = test1_cal_create();
	if( cal == NULL){
		return ;
	}
	test1_cal_print_all( cal);
	test1_cal_destroy( &cal);
}

