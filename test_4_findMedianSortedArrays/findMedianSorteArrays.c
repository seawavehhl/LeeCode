#include<stdio.h>
#include<malloc.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
	  int i,j;//����������±�
	  i = nums1Size > nums2Size ? (nums1Size + nums2Size - 1) / 2 : 0;//i����ֵ
	  if(nums1Size == 0 || nums2Size == 0){
		  if(nums1Size){
			  if(nums1Size % 2 == 0) return (nums1[i] + nums1[i+1])/2.0;//Ϊż����Ԫ��
			  else return nums1[i];
		  }
		  else {
			  j = (nums1Size + nums2Size - 1) / 2;
			  if(nums2Size % 2 == 0) return (nums2[j] + nums2[j+1])/2.0;
			  else return nums2[j];
		  }
	  }//���������Ϊ��
	  if(!i) {//���nums2����,����i = 0��j������nums2����
		  j = (nums1Size + nums2Size - 1) / 2;//j����ֵ
		  while(i < nums1Size){
			  if(nums1[i] < nums2[j]){//iָ���������nums1��벿�ֵ���һ��Ԫ�أ�jָ�����nums2��벿�ֵ����һ��Ԫ��
				i++;
				j--;//���iָ���Ԫ�ر�jָ���Ԫ��С����i���ƣ�j���ƣ�ʹ��i��j���������������Ծ���Ϊ������
			  }
			  else break;
		  }
		  if((nums1Size + nums2Size) % 2 != 0){//���������������Ԫ��
			  if(i == 0) return nums2[j];
			  else return nums1[i-1] > nums2[j] ? nums1[i-1] : nums2[j];
		  }
		  else{//�����ż����Ԫ��
			  if(j == nums2Size - 1 && i == 0) return (nums2[j] + nums1[i])/2.0;
			  else if(i == nums1Size && j == -1) return (nums2[j+1] + nums1[i-1])/2.0;
			  else if(j == -1) return (nums1[i-1] + (nums2[j+1] > nums1[i] ? nums1[i] : nums2[j+1])) / 2.0;
			  else if(i == 0) return (nums2[j]  + (nums2[j+1] > nums1[i] ? nums1[i] : nums2[j+1])) / 2.0;
			  else if(j == nums2Size - 1) return (nums1[i] + (nums2[j] < nums1[i-1] ? nums1[i-1] : nums2[j])) / 2.0;
			  else if(i == nums1Size) return (nums2[j+1]  + (nums2[j] < nums1[i-1] ? nums1[i-1] : nums2[j])) / 2.0;
			  else return ((nums2[j] > nums1[i-1] ? nums2[j] : nums1[i-1])  + (nums2[j+1] > nums1[i] ? nums1[i] : nums2[j+1])) / 2.0;
		  }
	  }
	  else{//���nums1����������j = 0��������nums1����
		  j = 0;//j����ֵ
		  while(j < nums2Size){
			  if(nums2[j] < nums1[i]){
				i--;
				j++;//���iָ���Ԫ�ر�jָ���Ԫ��С����i���ƣ�j���ƣ�ʹ��i��j���������������Ծ���Ϊ������
			  }
			  else break;
		  }
		  if((nums1Size + nums2Size) % 2 != 0){//���������������Ԫ��
			  if(j == 0) return nums1[i];
			  else return nums2[j-1] > nums1[i] ? nums2[j-1] : nums1[i];
		  }
		  else{//���Ԫ����ż����
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