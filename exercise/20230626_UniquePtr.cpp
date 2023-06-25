#include <iostream>
#include <utility>

using namespace std;

template<typename T>
class UniquePtr
{
    private:
        T *ptr_resource = nullptr;

    public:
        // ��ֹ��ʽ����ת����ת�����캯��
        explicit UniquePtr(T *raw_resource) noexcept : ptr_resource(std::move(raw_resource)) { }
        UniquePtr(std::nullptr_t) : ptr_resource(nullptr) { }

        UniquePtr() noexcept : ptr_resource(nullptr) {}
        ~UniquePtr() noexcept
        {
            delete ptr_resource;
        }

        // ���ÿ������캯���뿽����ֵ�����
        UniquePtr(const UniquePtr<T>&) noexcept = delete;
        UniquePtr& operator=(const UniquePtr&) noexcept = delete;

        // �ƶ����캯��
        UniquePtr(UniquePtr&& move) noexcept
        {
            std::cout << "construct for UniquePtr&&" << std::endl;
            move.swap(*this);
        }

        // �ƶ���ֵ�����
        UniquePtr& operator=(UniquePtr&& move) noexcept
        {
            std::cout << "operator= for UniquePtr&&" << std::endl;
            move.swap(*this);
            return *this;
        }

        explicit operator bool() const noexcept
        {
            return this->ptr_resource;
        }

        T* release() noexcept
        {
            return std::exchange(ptr_resource, nullptr); //ʹ���ƺ�Դ���������
        }

        T* get() const noexcept
        {
            return ptr_resource;
        }

        void swap(UniquePtr<T>& resource_ptr) noexcept
        {
            std::swap(ptr_resource, resource_ptr.ptr_resource);
        }

        void reset(T* resource_ptr) noexcept(false)
        {
            if (resource_ptr == nullptr)
                throw std::invalid_argument("An invalid pointer was passed, resources will not be swapped");

            delete ptr_resource;
            ptr_resource = nullptr; //��ʽ�ؽ�ָ����Ϊ��
            std::swap(ptr_resource, resource_ptr);
        }

        // ���س�Ա���������������ģ�����͵�ָ��
        T* operator->() const noexcept
        {
            return this->ptr_resource; //�����൱���и�����ָ��
        }

        // ���س�Ա���������������ģ�����͵�����
        T& operator*() const noexcept
        {
            return *this->ptr_resource;
        }
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
		std::cout << "Test printSomething " << std::endl;
	}

    void printResource() {
		std::cout << "Test printResource " << a << std::endl;
	}

    int getResource() {
        return a;
    }

private:
    int a = 10;
};

// ʹ��UniquePtr����
class PUser {
public:
	PUser() {
        //��ʼ��pTest
        pTest.reset(new Test());
		std::cout << "PUser construct " << std::endl;
	}
	~PUser() {
		std::cout << "PUser destruct" << std::endl;
	}

    //��������ĸ��ֺ�����ʹ��pTest��
	void userTest() {
		std::cout << "userTest " << pTest->getResource() << std::endl;
	}

private:
    //�����÷�����һ�����У���Ϊһ�����Ա����
    UniquePtr<Test> pTest;
};

// ���������
int main(int argc, char* argv[]) {
    UniquePtr<Test> tPtr1(new Test());
    // ���������仰������Ͳ�ͨ������Ϊ�Ѿ����� UniquePtr& operator=(const UniquePtr&) noexcept = delete;
    // UniquePtr<Test> tPtr2 = tPtr1;
    // UniquePtr<Test> tPtr3(tPtr1);
    
    // �������仰��������ΪpPtr1���˿���Ȩת��
    UniquePtr<Test> tPtr2(std::move(tPtr1));
    UniquePtr<Test> tPtr3 = std::move(tPtr2);

    // tPtr1->printResource();//��һ��ͱ�������ΪtPtr1�ǿգ�ֻ������Դ��ȫ��������
    tPtr1->printSomething(); //��һ�䲻������tPtr1��Ȼ��Դ�����ã����Ǵ���ο��Ե��ã�ֻҪ�����û��ʹ�õ���Դ


    PUser* pUser = new PUser();
    pUser->userTest();

    return 0;
}
