#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 10000000;

// Set this to true if you wish the arrays to be printed.
const bool OUTPUT_DATA = false;


void ReadInput(string& sortAlg, int& size);

void GenerateSortedData(int data[], int size);
void GenerateNearlySortedData(int data[], int size);
void GenerateReverselySortedData(int data[], int size);
void GenerateRandomData(int data[], int size);
void Sort(int data[], int size, string sortAlg, char* dataType);
void InsertionSort(int data[], int size);
void MergeSort(int data[], int lo, int hi);
void QuickSort(int data[], int lo, int hi,int depth);
void LibSort(int data[], int size);
void Swap(int &x, int &y);
bool IsSorted(int data[], int size);
void printData(int data[], int size, string title);

//Devshree Start
int max_depth=0;
void RandQSort(int data[], int lo, int hi,int depth);// Quick sort with random Pivot.
void MedThreeQSort(int data[], int lo, int hi,int depth);// Quick sort with median of three partiiton.
void RecInsertQSort(int data[], int lo, int hi,int depth);// Quick Sort with recusrive Insert sort.
void TailQuickSort(int data[], int lo, int hi,int depth);// Quick Sort with Tail recursion.
int Partition(int data[],int lo,int hi);
int RandPart(int data[],int lo,int hi);// Random partition
int MedThreePart(int data[],int lo,int hi);// Partition with median of three
//Devshree End

int main(void)
{
	int size;
	string sortAlg;
	ReadInput(sortAlg, size);
	
	int * data = new int[size];
	if( data == NULL)
	{
		cout << "\n Memory allocation error." << endl;
		exit(1);
	}
	
	GenerateSortedData(data, size);
	Sort(data, size, sortAlg,(char*)"Sorted Data");

	GenerateNearlySortedData(data, size);
	Sort(data, size, sortAlg,(char*)"Nearly Sorted Data");
	
	GenerateReverselySortedData(data, size);
	Sort(data, size, sortAlg,(char*)"Reversely Sorted Data");
	
	GenerateRandomData(data, size);
	Sort(data, size, sortAlg,(char*)"Random Data");
		
	cout << "\nProgram Completed Successfully." << endl;;
	
	delete [] data;
	
	return 0;
}
/********************************************************************/




void ReadInput(string& sortAlg, int& size)
{
    //Devshree Start
    	cout << "To select Sort from below, please enter the code associated with it:" << endl;
    //Devshree Ends
	cout << "  I:\tInsertion Sort" << endl;
	cout << "  M:\tMergeSort" << endl;
	cout << "  Q:\tQuickSort" << endl;
	cout << "  L:\tLibSort" << endl;
	//Devshree start
	cout << "  R:\tRandQSort" << endl;
	cout << "  S:\tMedThreeQSort" << endl;
	cout << "  T:\tRecInsertQSort" << endl;
	cout << "  U:\tTailQuickSort" << endl;
	//Devshree End
	cout << "Enter sorting algorithm: ";

	cin >> sortAlg;
	string sortAlgName;
	if(sortAlg == "I")
		sortAlgName = "Insertion Sort";
	else if(sortAlg == "M")
		sortAlgName = "MergeSort";
	else if(sortAlg == "Q")
		sortAlgName = "QuickSort";
	else if(sortAlg == "L")
		sortAlgName = "LibSort";
	else if(sortAlg == "R")
		sortAlgName = "RandQSort";
	else if(sortAlg == "S")
		sortAlgName = "MedThreeQSort";
	else if(sortAlg == "T")
		sortAlgName = "RecInsertQSort";
		else if(sortAlg == "U")
		sortAlgName = "TailQuickSort";
	else {
		cout << "\nUnrecognized sorting algorithm Code: " << sortAlg << endl;
		exit(1);
	}
	
	cout << "Enter input size: ";
	cin >> size;
	
	cout << "\nSorting Algorithm: " << sortAlgName;
	cout << "\nInput Size = " << size << endl;
	cout << endl;
	
}
/******************************************************************************/




void GenerateSortedData(int data[], int size)
{
	int i;
	
	for(i=0; i<size; i++)
		data[i] = i * 3 + 5;
}
/*****************************************************************************/



void GenerateNearlySortedData(int data[], int size)
{
	int i;
	
	GenerateSortedData(data, size);
	
	for(i=0; i<size; i++)
		if(i % 10 == 0)
			if(i+1 < size)
				data[i] = data[i+1] + 7;
}
/*****************************************************************************/



void GenerateReverselySortedData(int data[], int size)
{
	int i;
	
	for(i = 0; i < size; i++)
		data[i] = (size-i) * 2 + 3;
}
/*****************************************************************************/



void GenerateRandomData(int data[], int size)
{
	int i;
	
	for(i = 0; i < size; i++)
		data[i] = rand();
}
/*****************************************************************************/


void Sort(int data[], int size, string sortAlg, char* dataType)
{
	
	cout << endl << dataType << ":";
	
	
	if (OUTPUT_DATA)
		printData(data, size, "Data before sorting:");
	
	
	
	// Sorting is about to begin ... start the timer!
	clock_t start = clock();
	
	
	if(sortAlg == "I")
		InsertionSort(data, size);
	else if(sortAlg == "M")
		MergeSort(data, 0, size-1);
	else if(sortAlg == "L")
		LibSort(data, size);
		//Devshree Start
	else if(sortAlg == "Q"){
		max_depth=0;
		QuickSort(data, 0, size-1,0);
		cout<<"\nRecurssion depth = " <<max_depth<<"\n";	
	}
	else if(sortAlg == "R"){
		max_depth=0;
		RandQSort(data, 0, size-1,0);
		cout<<"\nRecurssion depth = " <<max_depth<<"\n";	
	}
	else if(sortAlg == "S"){
		max_depth=0;
		MedThreeQSort(data, 0, size-1, 0);
		cout<<"\nRecurssion depth = " <<max_depth<<"\n";	
	}
	else if(sortAlg == "T"){
		max_depth=0;
		RecInsertQSort(data, 0, size-1,0);
		cout<<"\nRecurssion depth = " <<max_depth<<"\n";	
	}
	
		else if(sortAlg == "U"){
		max_depth=0;
		TailQuickSort(data, 0, size-1,0);
		cout<<"\nRecurssion depth = " <<max_depth<<"\n";	
	}
	//Devshree End
	else
	{
		cout << "Invalid sorting algorithm!" << endl;
		exit(1);
	}
	
	// Sorting has finished ... stop the timer!
	clock_t end = clock();
	double elapsed = (((double) (end - start)) / CLOCKS_PER_SEC) * 1000;
	
	
	
	if (OUTPUT_DATA)
		printData(data, size, "Data after sorting:");
	
	
	if (IsSorted(data, size))
    {
		cout << "\nCorrectly sorted " << size << " elements in " << elapsed << "ms";
    }
	else
		cout << "ERROR!: INCORRECT SORTING!" << endl;
	cout << "\n-------------------------------------------------------------\n";
}
/*****************************************************************************/




bool IsSorted(int data[], int size)
{
	int i;
	
	for(i=0; i<(size-1); i++)
	{
		if(data[i] > data[i+1])
			return false;
	}
	return true;
}
/*****************************************************************************/




void InsertionSort(int data[], int size)
{
int i,j,key;
	for(j=1;j<size;j++){
		key=data[j];
		i=j-1;
		while(i>=0 && data[i]>key){
			data[i+1]=data[i];
			i=i-1;
		}
		data[i+1]=key;
	}
	
}
/*****************************************************************************/

void Merge(int data[],int lo,int mid,int hi){
	int mid1=mid-lo+1;
	int mid2=hi-mid;		
	int L[mid1+1],R[mid2+1];
	int i=0,j=0,k=0;
	
	for(i=0;i<mid1;i++){
		L[i]=data[lo+i];
	}
	for(i=0;i<mid2;i++){
		R[i]=data[mid+1+i];
	}
	if( L[mid1-1]>R[mid2-1]){
		L[mid1]=L[mid1-1]+1;
		R[mid2]=L[mid1-1]+1;
	}
	else{
		L[mid1]=R[mid2-1]+1;
		R[mid2]=R[mid2-1]+1;
	}
	
	i=0;
	for(k=lo;k<=hi;k++){
		if(L[i]<R[j]){
			data[k]=L[i];
			i++;
		}
		else{
			data[k]=R[j];
			j++;
		}
	}
	 
			
}

void MergeSort(int data[], int lo, int hi)
{
	if(lo>=hi){
		return;
	}
	int mid;
	mid=(lo+hi)/2;
	MergeSort(data,lo,mid);
	MergeSort(data,mid+1,hi);
	Merge(data,lo,mid,hi);
	
}
/*****************************************************************************/


int Partition(int data[],int lo,int hi)
{
	int i;
	int pivot = data[hi];
	int j = lo-1;

	for(i = lo;i <= (hi - 1); i++){
		if(data[i] < pivot){
			Swap(data[i],data[j+1]);
			j++;
		}
	}
	Swap(data[hi],data[j+1]);
	return (j+1);
}

void QuickSort(int data[], int lo, int hi,int depth)
{	
	int q=0;
	if(lo>=hi){
	    return;
	}
	
	if (depth>max_depth){
		max_depth=depth;
	}
	q = RandPart(data,lo,hi);
	QuickSort(data,lo,q-1,depth+1);
	QuickSort(data,q+1,hi,depth+1);	
}

/*****************************************************************************/



void LibSort(int data[], int size)
{
		sort(data,data+size);
	
}
/*****************************************************************************/
//Devshree Start


int RandPart(int data[],int lo,int hi){
	int random ,i;
	random=rand()%(hi-lo+1)+lo; 
	
	Swap(data[hi],data[random]);  	

	int pivot = data[hi];
	int j = lo-1;

	for(i = lo;i <= (hi - 1); i++){
		if(data[i] < pivot){
			Swap(data[i],data[j+1]);
			j++;
		}
	}
	Swap(data[hi],data[j+1]);
	return (j+1);
}
/***************************************************************************/


int MedThreePart(int data[],int lo,int hi){
	int i,median;

    int	p= (rand() % (hi - lo + 1)) + lo;
    int q = (rand() % (hi - lo + 1)) + lo;
    int r = (rand() % (hi - lo + 1)) + lo;
    
	if(((data[p]-data[q]) * (data[r]-data[p]))>=0)
		median = p;
	else if(((data[q]-data[p]) * (data[r]-data[q]))>=0)
		median = q;
	else 
		median = r;
			
	Swap(data[hi],data[median]);   
	int pivot = data[hi];
	int j = lo-1;

	for(i = lo;i <= (hi - 1); i++){
		if(data[i] < pivot){
			Swap(data[i],data[j+1]);
			j++;
		}
	}
	Swap(data[hi],data[j+1]);
	return (j+1);

}


/*************************************************************************/


void InsSortQHelper(int data[], int lo, int hi){

	int size = hi - lo + 1;
	int i,j,key;
	for(j= lo + 1;j <= hi;j++){
		key=data[j];
		i=j-1;
		while(i>=lo && data[i]>key){
			data[i+1]=data[i];
			i=i-1;
		}
		data[i+1]=key;
	}
}

/*****************************************************************************/


void RandQSort(int data[], int lo, int hi,int depth){
	int q=0;
	if(lo>=hi){
	    return;
	}
	
	if (depth>max_depth){
		max_depth=depth;
	}
	q = RandPart(data,lo,hi);
	RandQSort(data,lo,q-1,depth+1);
	RandQSort(data,q+1,hi,depth+1);	
}

/*****************************************************************************/
void MedThreeQSort(int data[], int lo, int hi,int depth){
	int q=0;
	if(lo>=hi){
	    return;
	}
	
	if (depth>max_depth){
		max_depth=depth;
	}
	q = MedThreePart(data,lo,hi);
	MedThreeQSort(data,lo,q-1,depth+1);
	MedThreeQSort(data,q+1,hi,depth+1);	
}

/***************************************************************************/
void RecInsertQSort(int data[], int lo, int hi,int depth)
{	
	int q=0;
	if(lo>=hi){
	    return;
	}
	
	int size = hi-lo+1;  
	
	if(size <=40){
		InsSortQHelper(data, lo, hi);
		return;
	}
	if (depth>max_depth){
		max_depth=depth;
	}
	q = RandPart(data,lo,hi);
	RecInsertQSort(data,lo,q-1,depth+1);
	RecInsertQSort(data,q+1,hi,depth+1);	
}

/**************************************************************************/


//Devshree End

//new Start
void TailQuickSort(int data[], int lo, int hi, int depth) 
{ 
    while (lo < hi) 
    { 
        int pi = RandPart(data, lo, hi); 
  
        if (depth>max_depth){
		max_depth=depth;
	}
        if (pi - lo < hi - pi) 
        { 
            TailQuickSort(data, lo, pi - 1,depth+1); 
            lo = pi + 1; 
        } 
  
        else
        { 
            TailQuickSort(data, pi + 1, hi,depth+1); 
            hi = pi - 1; 
        } 
    } 
} 
//new end

/*****************************************************************************/




void Swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}
/*****************************************************************************/




void printData(int data[], int size, string title) {
	int i;

	cout << endl << title << endl;
	for(i=0; i<size; i++)
	{
		cout << data[i] << " ";
		if(i%10 == 9 && size > 10)
			cout << endl;
	}
}

