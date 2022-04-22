#include <stdio.h>
#include <math.h>


int binarySearch(int numbers[], int left, int right, int target){
	if(left >= right){
		return -1;
	}
	int mid = left + right / 2;
	if(numbers[mid] == target){
		return mid;
	}else if(numbers[mid] < target){
	return binarySearch(numbers, mid + 1, right, target);
	} else {
	return binarySearch(numbers, left, mid - 1, target);
	}
	return -1;
}

int main(){
int nums[] = {1,1, 2, 3, 3 ,3 , 4 ,5, 6, 6};
int index_of_target = binarySearch(nums, 0, 10, 4);
printf("%d", index_of_target);
}
