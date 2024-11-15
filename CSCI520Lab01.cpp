/**
* 3 Sum Problem counter/timer, but I went too far in a few places
*
* @Corrales, Aidan
* @CSCI 520 lab 1
* @09/13/2024
*/

#include <iostream>
#include <ctime>
#include <iomanip>

#define LAYOUT 15

using namespace std;

struct TwoResults { //Struct created so that function can return two values
	double count;
	double time;
};

int* arrayGenerator(int range, int length){ 
	int* arrayGenerated = new int[length]; //Int pointer used to generate arrays of different lengths
	 
	for(int i = 0; i < length; ++i){
		arrayGenerated[i] = rand() % (2 * range + 1) - range; //Fill array will random values in given range
		//cout << arrayGenerated[i] << " "; I used this line for testing to make sure the arrays were being generated correctly
		//cout << endl << endl;
	}
	return arrayGenerated;
}

TwoResults threeDigitCounter(int* a, int N){ //This is the function that counts time and sucessful triplets
	TwoResults item; //Initializing stuct
	clock_t start, end; //Initializing timer
	double time;
	double count;
		
	start = clock(); //The timer only times the intended code based on the lab
	for (int i = 0; i < N; i++) //I made sure not to modify the following code given from the lab
 		for (int j = i+1; j < N; j++)
 			for (int k = j+1; k < N; k++)
 				if (a[i] + a[j] + a[k] == 0)
					count++;
	end = clock();
	
	item.count = count;
	item.time = double(end - start) / CLOCKS_PER_SEC;				
	return item; //Return struct values
}

void theWholeKaboodle(int L){
	int M = 50; //Defines range of random numbers from -M to M (Could technically be a constant)
	int sumTrip = 0;
	double sumTime = 0;
	double meanTrip;
	double meanTime;
	int* arr; //Array to be passed to a in threeDigitCounter
	TwoResults results; //Instance of threeDigitCounter
	int trials[3] = {10, 100, 1000};
	
	for(int i = 0; i < sizeof(trials)/sizeof(int); i++){ //For loop to test 10, 100, and 1000 trials
		for(int j = 1; j <= trials[i]; j++){ //Generates array, passes it to threeDigitCounter, averages succesful triples and time
			arr = arrayGenerator(M,L);
			results = threeDigitCounter(arr,L);
			
			sumTrip += results.count; // Sum triples found
			sumTime += results.time; //Sum time values
			
				if(j == trials[i]){ //Final trial
					meanTrip = sumTrip/trials[i]; //Average triples found
					meanTime = sumTime/trials[i]; //Average time
					cout << setw(LAYOUT) << L << setw(LAYOUT) << trials[i] << setw(LAYOUT) << \
					meanTime << setw(LAYOUT) << meanTrip << setw(LAYOUT) \
					//results.time << setw(LAYOUT) << results.count << setw(LAYOUT) This was from testing code to make sure the averages were close to actual results
					<< endl; //Print values
				}
		}
	}
	cout << endl;
	return;
}

int main(){
	cout << setw(LAYOUT) << "Array Length" << setw(LAYOUT) << "Trials" << setw(LAYOUT) \ 
	<< "Ave. Time" << setw(LAYOUT) << "Ave. Triples" \
	//<< setw(LAYOUT) << "Instance Time" << setw(LAYOUT) << "Instance Triples" From testing code
	<< endl << endl; //Labeling the output table
	
	theWholeKaboodle(100); //Run with length (N) of 100
	theWholeKaboodle(500); //Run with length (N) of 500
	theWholeKaboodle(1000); //Run with length (N) of 1000
	theWholeKaboodle(2000); //Run with length (N) of 2000
	theWholeKaboodle(8000); //Run with length (N) of 8000
	
	return 0;
}