#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// 定义类RealiseVector，模拟vector实现push_back(),size(),capacity()三个函数
template <class T>
class RealiseVector
{
public:
    // 无参构造函数初始化
    RealiseVector(){
        this->capacity_ = 1;
        this->size_ = 0;
        this->data_list_ = new T[this->capacity_];
    }

    // 有参构造函数
    RealiseVector(const int size, const T data){
        this->size_ =  size;
        this->capacity_ = size*5;
        this->data_list_ = new T[this->capacity_];
        for(int i=0; i<size; i++){
            this->data_list_[i] = data;
        }   
    }

    // 声明析构函数，释放掉占用的存储空间
    ~RealiseVector(){
        if(this->data_list_!=NULL){
        delete[] this->data_list_;
        }
    }

    // 打印vector存储的内容
    void Print(){
        cout<<"打印所有数据"<<endl;
        for(int i=0; i<this->size_; i++){
            cout<<this->data_list_[i]<<" ";
        }
        cout<<endl;
    }
    // 返回该vector的capacity
    int PrintCapacity(){
        return this->capacity_;
    }

    // 返回该vector的size
    int PrintSize(){
        return this->size_;
    }
    
    // 重载运算符[]
    T& operator [](const int index){
        if(index>0 && index<this->size_){
            return this->data_list_[index];
        }
        else{
            cout<<"出错"<<endl;
        }
    }

    // 实现原vector中的push_back函数
    void push_back(const T data){
        // 判断是否溢出
        if(this->size_+1 == this->capacity_){
            // 扩大存储空间
            this->capacity_ = this->capacity_ *5;
            T* new_data_list_ = new T[this->capacity_];
            for(int i=0; i<this->size_; i++){
                new_data_list_[i] = this->data_list_[i];
            }
            delete[] this->data_list_;
            this->data_list_ = new_data_list_;
        }
        this->data_list_[this->size_] = data;  // 将数据加到末尾
        this->size_ += 1;
    }

private:
    /* 定义成员变量 */
    T *data_list_;
    int capacity_;
    int size_;
};

int main(){
    // 测试
    RealiseVector<int> rv1;
    cout<<"size: "<<rv1.PrintSize()<<" capacity: "<<rv1.PrintCapacity()<<endl;
    rv1.push_back(3);
    rv1.Print();
    cout<<"size: "<<rv1.PrintSize()<<" capacity: "<<rv1.PrintCapacity()<<endl;
    return 0;
}