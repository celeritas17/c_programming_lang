#include <stdio.h>

#define LENGTH 1000000
 
int binsearch(int x, int v[], int n);
int __binsearch(int x, int v[], int n); 

int main(int argc, char *argv[]){
	int i, nums[LENGTH];
	for (i = 0; i < LENGTH; i++)
		nums[i] = i;
	// first version of binsearch 
	printf("%d\n", binsearch(5, nums, LENGTH));
	
	// second version of binsearch 
	printf("%d\n", __binsearch(5, nums, LENGTH));

	return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n - 1] */
int binsearch(int x, int v[], int n){
	long int low, high, mid;
	mid = 0;
	low = 0;
	high = n - 1;
	while (low <= high){
		mid = (low + high)/2;	
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else    /* found match */
			return mid;
	}
	return -1;      /* no match */
}

/* __binsearch: find x in v[0] <= v[1] <= ... <= v[n - 1],
   one comparison in while loop */
int __binsearch(int x, int v[], int n){
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high){
		mid = (low + high)/2;	
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	if (x == mid || x == mid - 1 || x == mid + 1 ){
		return x;
	}
	return -1;     
}
