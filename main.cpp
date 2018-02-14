#include <iostream> //for input/output
#include <vector>
#include "thread.h"
#include <string.h>

using namespace std;

int main(int argc, char** argv){

	int x[2048];
	int n;
	int i, k;
	int *a;
	int s=0;
	int *swapped = &s;

	a = new int[22528];

	thread *threads[2048];


	// read everything from standard input
    cin >> n;
    cout << "Number of input data = "<< n << endl;

    for(i = 0; i < n; i++){
        cin >> x[i];
    }    

    cout << "Input array:" << endl;
    cout << "\t" ;

    for(i = 0; i < n; i++){
        cout <<  x[i] << "  " ;
    }
    cout << endl;

    for(i = 0; i < n; i++){
        a[i] = x[i];
    } 


 
    while (swapped){
    	swapped = &s;

    	//even 
    	for(i=n/2; i<n; i++){
    		threads[i] = new thread(0, n, a, swapped); 
            threads[i]->Begin();
    	}

    	//odd
    	for(i=0; i<n/2; i++){
    		threads[i] = new thread(1, n, a, swapped); 
            threads[i]->Begin();
    	}

    	//even 
    	for(i=n/2; i<n; i++){
            threads[i]->Join();
    	}

    	//odd
    	for(i=0; i<n/2; i++){ 
            threads[i]->Join();
    	}
    }

    // 	// create n/2 threads
    //     cout << "Iteration i: " << endl;
    //     MyLock.Lock();
    //     for(k = 0; k < n/2; k++){
    //         threads[k] = new thread(k, swapped, n, x); 
    //         threads[k]->Begin();
    //     }
    //     MyLock.Unlock();
    //     // wait for all threads
    //     for(k = 0; k < n; n++){
    //         threads[n]->Join();
    //     }

    //     MyLock.Lock();


    //     cout << endl;
    //     MyLock.Unlock();
    // }


    return 0;
}