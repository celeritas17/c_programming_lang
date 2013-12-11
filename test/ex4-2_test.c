#include <assert.h>
#include <ctype.h>
#include "c_test.h"

int main(){
	assert(__atof("1e6") == 1000000.0);
	assert(__atof("1E6") == 1000000.0);
	assert(__atof("1.0e-6") == 0.000001);
	printf("%f\n", __atof("2.01e-3"));
	assert(__atof("2.01e-3") == 0.002010);
	assert(__atof("0000912") == 912);
	assert(__atof("     10") == 10);
	assert(__atof("1E") == 1);
	return 0;
}