#include <iostream>
#include <boost/thread.hpp>
#include "readerwriterqueue.h"
#include "atomicops.h"

moodycamel::BlockingReaderWriterQueue<int> q;

void producer()
{
	for(int i=0;i<10;i++)
	{	
		sleep(1);
		q.enqueue(i);
	}
}

void consumer()
{	int item;
	for(int i=0;i<10;i++)
	{
		q.wait_dequeue(item);
		sleep(2);
		std::cout<<item<<std::endl;
	}
	

}


int main()
{

	boost::thread cThread(consumer);
	boost::thread pThread(producer);

	pThread.join();
	cThread.join();

	return 0;

}

