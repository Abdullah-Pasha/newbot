   CODE FOR SWAPING:
    #include<iostream>
    using namespace std;

    void swap(int*,int*);
    void p_array(int*,int);

    int main(){
	int arr[6]={10,20,30,40,50,60};
	int size=6;

	swap(&arr[0],&arr[5]);
	p_array(arr,size);
	return 0;
   }
    void swap(int* ptr1,int* ptr2){
	int temp=0;
	temp=*ptr1;
	*ptr1=*ptr2;
	*ptr2=temp;
    }
    void p_array(int*ptr,int size){
	for(int i=0;i<size;i++){
		cout<<ptr[i]<<"  "<<endl;
	      }
      }

