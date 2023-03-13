int trap(int* height, int heightSize){
	int i = 0;
	int j = heightSize - 1;//��λָ��
	int sum = 0;//Ҫ���ص�ֵ
	int min = 0;//��¼����λ����Сֵ
	while(i < j){
		if(height[i] < height[j]){
			min = height[i];
			while(i < j && height[i] <= min){
				sum += min - height[i];
				i++;
			}//�����ۼ�
		}//�ҵ���β�е����ֵ�����Ӵ˴�����
		else{
			min = height[j];
			while(i < j && height[j] <= min){
				sum += min - height[j];
				j--;
			}//�����ۼ�
		}
	}//��ʼ����
	return sum;
}