#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

// ������ģ��ʵ�ֵ�����ָ����
template<class T>
class SharedPtr
{
    public:
        // Ĭ�Ϲ��캯��
        SharedPtr(T *ptr = nullptr) : _pPtr(ptr), _pRefCount(new int(1)), _pMutex(new mutex) 
        {
            std::cout << "SharedPtr construct ..., origin init" << std::endl;
        }

        // ��������
        ~SharedPtr()
        {
            std::cout << "SharedPtr destruct ..." << std::endl;
            release();
        }
        
        // �������캯��
        SharedPtr(const SharedPtr<T>& sp) : _pPtr(sp._pPtr), _pRefCount(sp._pRefCount), _pMutex(sp._pMutex)
        {
            std::cout << "SharedPtr construct ..., copy other SharedPtr" << std::endl;
        }

        // ������ֵ�����
        SharedPtr<T>& operator=(const SharedPtr<T>& sp)
        {
            std::cout << "operator=" << std::endl;

            if (_pPtr != sp._pPtr) //��ֹ�Ը�ֵ
            {
                std::cout << "operator= will call release" << std::endl;
                release(); //�ͷŸ�ֵ�������������ָ�����ľ��ڴ���Դ
                _pPtr = sp._pPtr;
                _pRefCount = sp._pRefCount;
                _pMutex = sp._pMutex;
                addRefCount();
            }
            return *this;
        }

        // ���س�Ա���������������ģ�����͵�����
        T& operator*()
        {
            return *_pPtr;
        }

        // ���س�Ա���������������ģ�����͵�ָ��
        T* operator->()
        {
            std::cout << "operator ->" << std::endl;
            return _pPtr;
        }

        T* Get()
        {
            return _pPtr;
        }

    private:
        void addRefCount() //��������1
        {
            _pMutex->lock();
            ++(*_pRefCount);
            std::cout << "addRefCount, now ref count " << (*_pRefCount) << std::endl;
            _pMutex->unlock(); 
        }

        void release() //��������1��Ϊ0ʱ�ͷ���Դ
        {
            std::cout << "release, current _RefCount " << *_pRefCount << std::endl;

            bool deleteFlag = false;
            _pMutex->lock();
            if (--(*_pRefCount) == 0)
            {
                std::cout << "will delete _pPtr " << std::endl;
                delete _pRefCount;
                delete _pPtr;
                deleteFlag = true;
            }
            _pMutex->unlock();
            if (deleteFlag = true)
                delete _pMutex;
        }

    private:
        int *_pRefCount; //���ü���
        T *_pPtr; //ָ�򱻹�������ָ��
        mutex *_pMutex; //�������ڼ����Ӽ����ͷŶ���ȹؼ�����ʱ����
};


// ����ʵ��������ָ��ģ����
class Test {
public:
	Test() {
		std::cout << "Test class construct" << std::endl;
	}
	~Test() {
		std::cout << "Test class destruct" << std::endl;
	}

	void printSomething() {
		std::cout << "Test printSomething" << std::endl;
	}
};

void doSomeTest(SharedPtr<Test> pTest);

int main(int argc, char* argv[]) {

	std::cout << "main start, will init SharedPtr" << std::endl;

	SharedPtr<Test> originPtr(new Test());
    // new��������������(���ù��캯��)�������ڴ�(����ָ������ָ��)
    // Ȼ���ٽ���ָ������ָ�밴ֵ���ݸ�����ָ��ģ����Ĺ��캯����ʵ����ģ�������(�ڶ��η����ڴ�)

	std::cout << "will call doSomeTest" << std::endl;

	doSomeTest(originPtr); //��ֵ���ݲ��������ÿ������캯��
    // shared_ptr ���������������뿽����ֵ�����ǿ���������ж���ָ��ͬһ���ڴ棬�����ᵼ�����ü����Ĵ���

	std::cout << "main end" << std::endl;

	return 0;
}

void doSomeTest(SharedPtr<Test> pTest) {
	std::cout << "doSomeTest call" << std::endl;
	SharedPtr<Test> pInnerTest = pTest; //�������캯��ִ�г�ʼ��
    // �����൱��SharePtr<Test> pInnerTest(pTest)
	
	std::cout << "will make an emptyPtr" << std::endl;
	SharedPtr<Test> pInnerTest2; //Ĭ�Ϲ��캯��
	std::cout << "will set pInnerTest2" << std::endl;
	pInnerTest2 = pTest;
    //�����ȴ��������ٸ�ֵ��д���Ż��õ�������ֵ�����=

	pInnerTest->printSomething();//��doSomeTest����ִ�н�����pTest��pInnerTest���������ھͻ���������������
    // �ȼ�д����pInnerTest.operator->()->printSomething();

	std::cout << "will make one test" << std::endl;
	Test test; //Ĭ�Ϲ��캯��
	test.printSomething();

}