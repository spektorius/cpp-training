#include <iostream>
#include <exception>

using namespace std;


class AnException : public exception
{
public:
	AnException(const char* errMessage) :m_ErrMessage(errMessage){}
	const char* what() const noexcept{ return m_ErrMessage; }
private:
	const char* m_ErrMessage;
};

const char* const noexc() noexcept {
	return "no exception function is called";
}

void e()
{
	//if something bad
	throw AnException("Exception example");
}

void f()
{
	e();
}

int ex1(int a, int b)
{
	if( b== 0){
		throw "division by zero";
	}
	return a/b;
}

void ex2()
{
	try{
		f();
	}
	catch(...){
		cout << "caught in ex2, pass to next" << endl;
		throw;
	}
}

int main() {

	try{
		cout << ex1(5,0) << endl;
	}
	catch(char const *pStr){
		cout << pStr << endl;
	}
	catch(...){
		cout << "Some exception." << endl;
	}

	try{
		ex2();
	}
	catch(const exception& ex){
		cout << ex.what() << endl;
	}

	cout << noexc() << endl;

/* It works but long time enough
	try {
        int counter = 0;
        int* arr = nullptr;
        int* oldArr = nullptr;
		while(true){
            oldArr = arr;
			arr= new int[10000000u];
            cout << counter++ << ": " << arr;
            if(oldArr != nullptr){
                cout << " diff = " << arr-oldArr << endl;
            }
		}
	}
	catch (exception& e){
		cout << "Standard exception: " << e.what() << endl;
	}
*/
	return 0;
}
