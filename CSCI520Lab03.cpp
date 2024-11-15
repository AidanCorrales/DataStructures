/**
* Selection and insertion sort counting swaps and comparisons
*
* @Corrales, Aidan
* @CSCI 520 lab 03
* @date 10/09/2024
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Node{ 										//Nodes for our array
      int x; 
      int y; 
      int z;  
};

struct Arr{											//For creating arrays and counters
	Node arr8k[8000];
	Node arr16k[16000];
	int arrSize;
	int xCompare, yCompare, zCompare, swaps;
};

int randNumRange(int low, int high){				//Random number function with max and min
  return rand()%(high-low+1)+low;
}

Arr arrayRandomizer(int length){					//Generate random values for the arrays
	Arr newArray;
	if(length==8000){								//If you want an array size 8000

		newArray.arrSize = length;					//Defining a length variable makes for loops easier

		for(int i=0;i<newArray.arrSize;i++){		//Random x,y,z values for each item in array
			newArray.arr8k[i].x = randNumRange(0,30);
			newArray.arr8k[i].y = randNumRange(5,60);
			newArray.arr8k[i].z = randNumRange(10,90);
		}
	}
	else if(length==16000){							//If you want an array size 16000

		newArray.arrSize = length;					//Defining a length variable makes for loops easier

		for(int i=0;i<newArray.arrSize;i++){		//Random x,y,z values for each item in array
			newArray.arr16k[i].x = randNumRange(0,30);
			newArray.arr16k[i].y = randNumRange(5,60);
			newArray.arr16k[i].z = randNumRange(10,90);
		}
	}
	return newArray;								//Return randomized array
}

Arr selectionSort8k(Arr array){						//Selection sort for size 8000 array
	array.xCompare = 0;								//Counting variables
	array.yCompare = 0;
	array.zCompare = 0;
	array.swaps = 0;
	
	for (int i = 0; i < array.arrSize; i++)			//Selection sort algorithm
	{
	   int min = i;
	   for (int j = i+1; j < array.arrSize; j++){	
	        if (array.arr8k[j].x < array.arr8k[min].x){
	        	array.xCompare++;					//Compare x
				min = j;							//Comparison count
			}
			else if(array.arr8k[j].x == array.arr8k[min].x && array.arr8k[j].y < array.arr8k[min].y){
			 	array.yCompare++;					//Compare y
				min = j;							//Comparison count
			}
			else if(array.arr8k[j].x == array.arr8k[min].x && array.arr8k[j].y == array.arr8k[min].y && array.arr8k[j].z < array.arr8k[min].z){
			 	array.zCompare++;					//Compare z
				min = j;							//Comparison count
			}
		}
		swap(array.arr8k[i], array.arr8k[min]); 	//Swap
		array.swaps++;								//Swap count
	}
	cout<<"Selection Sort for length "<<array.arrSize<<" array\n"\
	<<"Swaps:\t\t\t"<<array.swaps\
	<<"\nx-Values Compared:\t"<<array.xCompare\
	<<"\ny-Values Compared:\t"<<array.yCompare\
	<<"\nz-Values Compared:\t"<<array.zCompare\
	<<"\nTotal Comparisons:\t"<<array.xCompare + array.yCompare + array.zCompare\
	<<endl<<endl;
	return array;									//Return sorted array
}

Arr selectionSort16k(Arr array){					//Selection sort for size 16000 array
	array.xCompare = 0;								//Counting variables
	array.yCompare = 0;
	array.zCompare = 0;
	array.swaps = 0;
	
	for (int i = 0; i < array.arrSize; i++)			//Selection sort algorithm
	{
	   int min = i;
	   for (int j = i+1; j < array.arrSize; j++){
	        if (array.arr16k[j].x < array.arr16k[min].x){
	        	array.xCompare++;					//Compare x
				min = j;							//Comparison count
			}
			else if(array.arr16k[j].x == array.arr16k[min].x && array.arr16k[j].y < array.arr16k[min].y){
			 	array.yCompare++;					//Compare y
				min = j;							//Comparison count
			}
			else if(array.arr16k[j].x == array.arr16k[min].x && array.arr16k[j].y == array.arr16k[min].y && array.arr16k[j].z < array.arr16k[min].z){
			 	array.zCompare++;					//Compare z
				min = j;							//Comparison count
			}
		}
		swap(array.arr16k[i], array.arr16k[min]); 	//Swap
		array.swaps++;								//Swap count
	}
	cout<<"Selection Sort for length "<<array.arrSize<<" array\n"\
	<<"Swaps:\t\t\t"<<array.swaps\
	<<"\nx-Values Compared:\t"<<array.xCompare\
	<<"\ny-Values Compared:\t"<<array.yCompare\
	<<"\nz-Values Compared:\t"<<array.zCompare\
	<<"\nTotal Comparisons:\t"<<array.xCompare + array.yCompare + array.zCompare\
	<<endl<<endl;
	return array;									//Return sorted array
}

Arr insertionSort8k(Arr array){						//Insertion sort for size 8000 array
	array.xCompare = 0;								//Counting variables
	array.yCompare = 0;
	array.zCompare = 0;
	array.swaps = 0;
	for (int i = 0; i < array.arrSize; i++){			//Insertion sort algorithm
	    for (int j = i; j > 0; j--)
	        if (array.arr8k[j].x < array.arr8k[j-1].x){
	        	array.xCompare++;					//x comparison and count
	            swap(array.arr8k[j], array.arr8k[j-1]);
	            array.swaps++;						//Swap count
	        }
			else if (array.arr8k[j].x == array.arr8k[j-1].x && array.arr8k[j].y < array.arr8k[j-1].y){
	            array.yCompare++;					//y comparison and count
	            swap(array.arr8k[j], array.arr8k[j-1]);
				array.swaps++;						//Swap count
	        }
			else if (array.arr8k[j].x == array.arr8k[j-1].x && array.arr8k[j].y == array.arr8k[j-1].y && array.arr8k[j].z < array.arr8k[j-1].z){
	            array.zCompare++;					//z comparison and count
	            swap(array.arr8k[j], array.arr8k[j-1]);
				array.swaps++;						//Swap count
	        }
	        else break;
	}
	cout<<"Insertion Sort for length "<<array.arrSize<<" array\n"\
	<<"Swaps:\t\t\t"<<array.swaps\
	<<"\nx-Values Compared:\t"<<array.xCompare\
	<<"\ny-Values Compared:\t"<<array.yCompare\
	<<"\nz-Values Compared:\t"<<array.zCompare\
	<<"\nTotal Comparisons:\t"<<array.xCompare + array.yCompare + array.zCompare\
	<<endl<<endl;
	return array;									//Return sorted array
}

Arr insertionSort16k(Arr array){					//Insertion sort for size 16000 array
	array.xCompare = 0;								//Counting variables
	array.yCompare = 0;
	array.zCompare = 0;
	array.swaps = 0;
	for (int i = 0; i < array.arrSize; i++){		//Insertion sort algorithm
	    for (int j = i; j > 0; j--)
	        if (array.arr16k[j].x < array.arr16k[j-1].x){
	        	array.xCompare++;					//x comparison and count
	            swap(array.arr16k[j], array.arr16k[j-1]);
	            array.swaps++;						//Swap count
	        }
			else if (array.arr16k[j].x == array.arr16k[j-1].x && array.arr16k[j].y < array.arr16k[j-1].y){
	            array.yCompare++;					//y comparison and count
	            swap(array.arr16k[j], array.arr16k[j-1]);
				array.swaps++;						//Swap count
	        }
			else if (array.arr16k[j].x == array.arr16k[j-1].x && array.arr16k[j].y == array.arr16k[j-1].y && array.arr16k[j].z < array.arr16k[j-1].z){
	            array.zCompare++;					//z comparison and count
	            swap(array.arr16k[j], array.arr16k[j-1]);
				array.swaps++;						//Swap count
	        }
	        else break;
	}
	cout<<"Insertion Sort for length "<<array.arrSize<<" array\n"\
	<<"Swaps:\t\t\t"<<array.swaps\
	<<"\nx-Values Compared:\t"<<array.xCompare\
	<<"\ny-Values Compared:\t"<<array.yCompare\
	<<"\nz-Values Compared:\t"<<array.zCompare\
	<<"\nTotal Comparisons:\t"<<array.xCompare + array.yCompare + array.zCompare\
	<<endl<<endl;
	return array;									//Return sorted array
}

void printArray(Arr a, int num, int length, string sortType){	//Print array values to a given num
	cout<<"Here are the first "<<num/2<<" and last "<<num/2<<" items out of "<<length<<" from "<<sortType<<":\n";
	if(length == 8000){								//If 8000 array
		cout<<"{";
		for(int i = 0; i < num/2; i++){				//For a given length num/2 print first half
			cout<<"["<<setw(2)<<a.arr8k[i].x<<","<<setw(2)<<a.arr8k[i].y<<","<<setw(2)<<a.arr8k[i].z<<"]";
			if(i==((num/2)-1)){						//Print x,y,z in sets with formatting
				cout<<",\n..."<<endl;
			}
			else if((i+1)%5==0){
				cout<<","<<endl;
			}
			else{
				cout<<",\t";
			}
		}
		for(int i = length-(num/2); i < length; i++){//For a given length num/2 print last half
			cout<<"["<<setw(2)<<a.arr8k[i].x<<","<<setw(2)<<a.arr8k[i].y<<","<<setw(2)<<a.arr8k[i].z<<"]";
			if(i==(length-1)){						//Print x,y,z in sets with formatting
				cout<<"}"<<endl;
			}
			else if((i+1)%5==0){
				cout<<","<<endl;
			}
			else{
				cout<<",\t";
			}
		}
	}
	else if(length == 16000){						//If 16000 array
		cout<<"{";
		for(int i = 0; i < num/2; i++){				//For a given length num
			cout<<"["<<setw(2)<<a.arr16k[i].x<<","<<setw(2)<<a.arr16k[i].y<<","<<setw(2)<<a.arr16k[i].z<<"]";
			if(i==((num/2)-1)){						//Print x,y,z in sets with formatting
				cout<<",\n..."<<endl;
			}
			else if((i+1)%5==0){
				cout<<","<<endl;
			}
			else{
				cout<<",\t";
			}
		}
		for(int i = length-(num/2); i < length; i++){//For a given length num
			cout<<"["<<setw(2)<<a.arr16k[i].x<<","<<setw(2)<<a.arr16k[i].y<<","<<setw(2)<<a.arr16k[i].z<<"]";
			if(i==(length-1)){						//Print x,y,z in sets with formatting
				cout<<"}"<<endl;
			}
			else if((i+1)%5==0){
				cout<<","<<endl;
			}
			else{
				cout<<",\t";
			}
		}
	}
	cout<<endl<<endl;
}

int main(){
	int n = 100;
	
	Arr list8k = arrayRandomizer(8000);			//Create randomized arrays
	Arr list16k = arrayRandomizer(16000);				
	
	Arr ss8k = selectionSort8k(list8k);			//Selection sort arrays
	Arr ss16k = selectionSort16k(list16k);
	
	Arr is8k = insertionSort8k(list8k);			//Insertion sort arrays
	Arr is16k = insertionSort16k(list16k);
	
	printArray(list8k,n,8000,"Unsorted");		//Print unsorted array
	printArray(ss8k,n,8000,"Selection Sort");	//Print selection sorted array	
	printArray(is8k,n,8000,"Insertion Sort");	//Print insertion sorted array
	printArray(list16k,n,16000,"Unsorted");		//Repeat
	printArray(ss16k,n,16000,"Selection Sort");
	printArray(is16k,n,16000,"Insertion Sort");

	return 0;
}