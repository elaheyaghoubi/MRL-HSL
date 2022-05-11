#include <iostream>
#include <stdlib.h>
using namespace std;
class sorter{
    int index,tmp,*array,size;
    public:
        void initialize();
		void printer();
		void bubble_sort();
		void selection_sort();
		void insertion_sort();
		void quick_sort(int *,int,int);	
		int divider(int *,int,int);	
		void merge_sort(int *,int,int);
		void merger(int *,int,int,int);
		void swap(int *,int *);
		int* get_array();
		int get_size();
		sorter();
		sorter(int, int, int *, int);
		sorter(const sorter&);
		~sorter();
};

void sorter :: initialize(){
	int number,random;
	cout<<"Enter the size of array : ";cin>>size;
	cout<<"Enter the numbers of array : ";cin>>number;
	array = new int[size];

	for(int i=2;i<size;i++){
		cin>> array[i];
	}
}

void sorter :: printer(){
	int status;
    cout << "the array in ascending order: \n";
    for (int i=0; i<size; i++){
       cout << array[i] << " ";
    }
    cout << endl;
}

int* sorter :: get_array(){
	return array;
}
int sorter :: get_size(){
	return size;
}

int sorter :: divider(int *array,int begin,int end){
    int anchorpoint=begin;
    int anchor=array[end];
    for(int i=begin;i<end;i++)
    {
        if(array[i]<anchor)
        {
            swap(&array[anchorpoint],&array[i]);
            anchorpoint++;
        }
    }
    swap(&array[anchorpoint],&array[end]);
    return anchorpoint;
}

void sorter :: quick_sort(int *array,int begin,int end){
    if(begin >= end)
        return;
    int anchorpoint=divider(array,begin,end);
    quick_sort(array,begin,anchorpoint-1);
    quick_sort(array,anchorpoint+1,end);
}

void sorter :: merger(int *array, int left_side, int middle, int right_side){
  
  int n1 = middle - left_side + 1;
  int n2 = right_side - middle;

  int left_array[n1], right_array[n2];

  for (int i = 0; i < n1; i++)
    left_array[i] = array[left_side + i];
  for (int j = 0; j < n2; j++)
    right_array[j] = array[middle + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = left_side;

  while (i < n1 && j < n2) {
    if (left_array[i] <= right_array[j]) {
      array[k] = left_array[i];
      i++;
    } else {
      array[k] = right_array[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    array[k] = left_array[i];
    i++;
    k++;
  }
  while (j < n2) {
    array[k] = right_array[j];
    j++;
    k++;
  }
}

void sorter :: merge_sort(int *array, int begin, int end) {
  if (begin < end) {
    int middle = begin + (end - begin) / 2;

    merge_sort(array, begin, middle);
    merge_sort(array, middle + 1, end);
    merger(array, begin, middle, end);
  }
}

void sorter :: bubble_sort(){
	for(int i=0;i<size-1;i++)
		for(int j=0;j<size-1;j++)
			if(array[j]>array[j+1]){
				tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
			}
}

void sorter :: swap(int *min_array, int *array) { 
    tmp = *min_array; 
    *min_array = *array; 
    *array = tmp; 
} 

void sorter :: selection_sort(){
	for(int i=0;i<size;i++){
		index = i;
		for(int j=i+1;j<size;j++)
			if(array[j]<array[index])
			index = j;
		swap(&array[index], &array[i]);
	}
}

void sorter :: insertion_sort(){
    for (int i = 1; i < size; i++){
        tmp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > tmp){
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = tmp;
    }
}

sorter::sorter(){
    index = 0;
	tmp = 0;
	array = 0;
	size = 0;
}
sorter :: sorter(int inx,int tp,int *arr,int sz){
	index = inx;
	tmp = tp;
	array = arr;
	size = sz;
}
sorter :: sorter(const sorter &sample){
	index = sample.index;
	tmp = sample.tmp;
	array = sample.array;
	size = sample.size;
}
sorter::~sorter(){};
int main(){
    char checker;
    sorter sample;
    sample.initialize();
    cout << "which sorter do you want:(b,q,m,i,s)\n";
    cin >> checker;
    switch (checker){
        case 'b':
            sample.bubble_sort();
            break;

        case 'q':
           sample.quick_sort(sample.get_array(),0,sample.get_size()-1);	
           break;

        case 'm':
           sample.merge_sort(sample.get_array(),0,sample.get_size()-1);
           break;
        case 'i':
            sample.insertion_sort();
            break;
        case 's':
            sample.selection_sort();
            break;
        default:
            cout << "the sorter is not correct.";
            break;
    }
    sample.printer();
    return 0;
};
