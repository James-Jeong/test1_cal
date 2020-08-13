#include "local/test1_cal_l.h"

int main( int argc, char **argv){
	int rv;

	if( argc != 3){
		printf("	| ! Wrong parameters\n");
		printf("	| ! Usage : (bin) (value1) (value2)\n");
		return CAL_FAIL;
	}

	test1_cal_t *cal = test1_cal_create( atoi( argv[1]), atoi( argv[2]));
	if( cal == NULL){
		return CAL_FAIL;
	}

	rv = test1_cal_plus( cal);
	if( rv < CAL_SUCCESS) printf("	| ! Fail to plus values for test1_cal_t.\n");

	rv = test1_cal_minus( cal);
	if( rv < CAL_SUCCESS)	printf("	| ! Fail to minus values for test1_cal_t.\n");

	rv = test1_cal_mul( cal);
	if( rv < CAL_SUCCESS)	printf("	| ! Fail to multiply values for test1_cal_t.\n");

	rv = test1_cal_div( cal);
	if( rv < CAL_SUCCESS)	printf("	| ! Fail to divide values for test1_cal_t.\n");

	test1_cal_print_all( cal);

	test1_cal_destroy( cal);
}

