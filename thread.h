#include "ThreadClass.h"
#ifndef _MAIN_H
#define _MAIN_H
#include <iostream>

class thread : public Thread {
   public:
	      thread(int pass, int n, int *a, int *swapped);
	private:
		int pass;
		int n;
		int *a;
		int *swapped;
		void ThreadFunc();
};
#endif