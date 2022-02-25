#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
// 定义一个类似与vector的类Re_Vector，并且实现push_back(),pop_back(),size(),insert(),capacity()
// 当达到一定容量时，类会自动增大容量
template <class T>
class Re_Vector
{
private:
    /* 定义成员变量 */
    T *p;
    int capacity;
    int size;
public:
    // 无参构造函数初始化
    Re_Vector(){
        this->capacity = 1;
        this->size = 0;
        this->p = new T[this->capacity];
    }
    // 有参构造函数
    Re_Vector(const int size, const T data){
        this->size =  size;
        this->capacity = size*5;
        this->p = new T[capacity];
        for(int i=0; i<size; i++){
            this->p[i] = data;
        }   
    }
    // 复制另一个vector的函数
    Re_Vector(const Re_Vector& rv){
        this->capacity = rv->capacity;
        this->size = rv->size;
        this->p = new T[this->capacity];
        memcpy(this->p, rv->p, this->size*sizeof(T));
    }
    // 声明析构函数，释放掉占用的存储空间
    ~Re_Vector(){
        if(this->p!=NULL){
        // 如果是new的空间使用delete，如果是
        delete[] this->p;
        }
    }
     // 打印vector存储的内容
    void print(){
        cout<<"打印所有数据"<<endl;
        for(int i=0; i<this->size; i++){
            cout<<this->p[i]<<" ";
        }
        cout<<endl;
    }
     // 打印该vector的capacity
    int pcapacity(){
        return this->capacity;
    }
     // 打印该vector的size
    int psize(){
        return this->size;
    }
     // 重载运算符[]
    T& operator [](const int index){
        if(index>0 && index<this->size){
            return this->p[index];
        }
        else{
            cout<<"出错"<<endl;
        }
    }
    // 实现原vector中的push_back函数
    void push_back(const T data){
        // 判断是否溢出
        if(this->size+1 == this->capacity){
            // 扩大存储空间
            this->capacity = this->capacity *5;
            T* new_p = new T[this->capacity];
            for(int i=0; i<this->size; i++){
                new_p[i] = this->p[i];
            }
            delete[] p;
            this->p = new_p;
        }
        this->p[this->size] = data;  // 将数据加到末尾
        this->size += 1;
    }
    // 删除并返回尾部元素
    T pop_back(){
        if(this->size >= 1){
            T data = this->p[this->size-1];
            this->p[this->size-1] = 0;
            this->size -= 1;
            return data;
        }
        else{
            cout<<"出错"<<endl;
        }
    }
     // 在指定位置插入元素
    void insert(const int index, const T data){
        if(index>=0 && index<=this->size){
            if(this->size+1 == this->capacity){
                // 扩大存储空间
                this->capacity = this->capacity *5;
                T* new_p = new T[this->capacity];
                for(int i=0; i<this->size; i++){
                    new_p[i] = this->p[i];
                }
                delete[] p;
                this->p = new_p;
            }
            for(int i=this->size; i>index; i--){
                this->p[i] = this->p[i-1];
            }
            this->p[index] = data;
            this->size++;
        }
    }
};
 


int main(){
    // 测试
    Re_Vector<int> rv1;
    cout<<"size: "<<rv1.psize()<<" capacity: "<<rv1.pcapacity()<<endl;
    rv1.push_back(3);
    rv1.push_back(4);
    rv1.push_back(1);
    rv1.print();
    cout<<"size: "<<rv1.psize()<<" capacity: "<<rv1.pcapacity()<<endl;
    cout<<"删除并返回数据："<<rv1.pop_back()<<endl;
    // 插入数据
    cout<<"在下标为1的地方，插入10"<<endl;
    rv1.insert(1, 10);
    rv1.print();
    return 0;
}