#include<stdio.h>
#include<malloc.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
	  int i,j;//两个数组的下标
	  i = nums1Size > nums2Size ? (nums1Size + nums2Size - 1) / 2 : 0;//i赋初值
	  if(nums1Size == 0 || nums2Size == 0){
		  if(nums1Size){
			  if(nums1Size % 2 == 0) return (nums1[i] + nums1[i+1])/2.0;//为偶数个元素
			  else return nums1[i];
		  }
		  else {
			  j = (nums1Size + nums2Size - 1) / 2;
			  if(nums2Size % 2 == 0) return (nums2[j] + nums2[j+1])/2.0;
			  else return nums2[j];
		  }
	  }//如果有数组为空
	  if(!i) {//如果nums2更长,则另i = 0，j将数组nums2均分
		  j = (nums1Size + nums2Size - 1) / 2;//j赋初值
		  while(i < nums1Size){
			  if(nums1[i] < nums2[j]){//i指向的是数组nums1左半部分的下一个元素，j指向的是nums2左半部分的最后一个元素
				i++;
				j--;//如果i指向的元素比j指向的元素小，则i右移，j左移，使得i、j将两个数组整体仍均分为两部分
			  }
			  else break;
		  }
		  if((nums1Size + nums2Size) % 2 != 0){//如果整体有奇数个元素
			  if(i == 0) return nums2[j];
			  else return nums1[i-1] > nums2[j] ? nums1[i-1] : nums2[j];
		  }
		  else{//如果有偶数个元素
			  if(j == nums2Size - 1 && i == 0) return (nums2[j] + nums1[i])/2.0;
			  else if(i == nums1Size && j == -1) return (nums2[j+1] + nums1[i-1])/2.0;
			  else if(j == -1) return (nums1[i-1] + (nums2[j+1] > nums1[i] ? nums1[i] : nums2[j+1])) / 2.0;
			  else if(i == 0) return (nums2[j]  + (nums2[j+1] > nums1[i] ? nums1[i] : nums2[j+1])) / 2.0;
			  else if(j == nums2Size - 1) return (nums1[i] + (nums2[j] < nums1[i-1] ? nums1[i-1] : nums2[j])) / 2.0;
			  else if(i == nums1Size) return (nums2[j+1]  + (nums2[j] < nums1[i-1] ? nums1[i-1] : nums2[j])) / 2.0;
			  else return ((nums2[j] > nums1[i-1] ? nums2[j] : nums1[i-1])  + (nums2[j+1] > nums1[i] ? nums1[i] : nums2[j+1])) / 2.0;
		  }
	  }
	  else{//如果nums1更长，则另j = 0，将数组nums1均分
		  j = 0;//j赋初值
		  while(j < nums2Size){
			  if(nums2[j] < nums1[i]){
				i--;
				j++;//如果i指向的元素比j指向的元素小，则i右移，j左移，使得i、j将两个数组整体仍均分为两部分
			  }
			  else break;
		  }
		  if((nums1Size + nums2Size) % 2 != 0){//如果整体有奇数个元素
			  if(j == 0) return nums1[i];
			  else return nums2[j-1] > nums1[i] ? nums2[j-1] : nums1[i];
		  }
		  else{//如果元素有偶数个
			  if(i == nums1Size - 1 && j == 0) return (nums1[i] + nums2[j])/2.0;
			  else if(j == nums2Size && i == -1) return (nums1[i+1] + nums2[j-1])/2.0;
			  else if(i == -1) return (nums2[j-1] + (nums1[i+1] > nums2[j] ? nums2[j] : nums1[i+1])) / 2.0;
			  else if(j == 0) return (nums1[i]  + (nums1[i+1] > nums2[j] ? nums2[j] : nums1[i+1])) / 2.0;
			  else if(i == nums1Size - 1) return (nums2[j] + (nums1[i] < nums2[j-1] ? nums2[j-1] : nums1[i])) / 2.0;
			  else if(j == nums2Size) return (nums1[i+1]  + (nums1[i] < nums2[j-1] ? nums2[j-1] : nums1[i])) / 2.0;
			  else return ((nums1[i] > nums2[j-1] ? nums1[i] : nums2[j-1]) + (nums1[i+1] > nums2[j] ? nums2[j] : nums1[i+1])) / 2.0;
		  }
	  }
}

int main(){
	int nums1[] = {2,3};
	int nums2[] = {1};
	double result  = findMedianSortedArrays(nums1,2,nums2,sizeof(nums2)/4);
	printf("%f",result);
	return 0;
}