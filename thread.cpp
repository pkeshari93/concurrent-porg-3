#include "thread.h"
#include <iostream>

using namespace std;

Mutex MyLock;

thread::thread(int pass, int n, int *a, int *swapped)
		:pass(pass), n(n), a(a), swapped(swapped)
{
	ThreadName.seekp(0, ios::beg);
	ThreadName << "eveodd" <<endl;
}

void thread::ThreadFunc(){
	
}

