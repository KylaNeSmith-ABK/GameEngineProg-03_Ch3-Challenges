// copying from videos (as instructed)

#include <iostream>
#include <thread>

using namespace std;

bool DidQuit = false;

int ThreadVar = 0;

int NumThreadVar1 = 0;
int NumThreadVar2 = 0;

void HelloWorldThread()
{
	while (!DidQuit)
	{
		ThreadVar++;
		if (ThreadVar > 1000)
		{
			ThreadVar = 0;
		}
	}
}

void NumThread1()
{
	while (!DidQuit)
	{
		NumThreadVar1++;
		if (NumThreadVar1 > 1000)
		{
			NumThreadVar1 = 0;
		}
	}
}

void NumThread2()
{
	do
	{
		++NumThreadVar2;
		if (NumThreadVar2 > 1000)
		{
			NumThreadVar2 = 0;
		}
	} while (!DidQuit);
}

int main()
{
	cout << "Hello World" << endl;
	char UserInput;

	std::thread Hello(HelloWorldThread);

	std::thread Num1(NumThread1);
	std::thread Num2(NumThread2);

	while (!DidQuit)
	{
		cout << "Press any key to display counter or q to quit" << endl;
		cin >> UserInput;
		DidQuit = (UserInput == 'q');
		cout << "ThreadVar: " << ThreadVar << endl;
		cout << "NumThreadVar1: " << NumThreadVar1 << endl;
		cout << "NumThreadVar2: " << NumThreadVar2 << endl;
	}
	

	Hello.join();
	Num1.join();
	Num2.join();

	cout << "...Quitting..." << endl;

	return 0;
}