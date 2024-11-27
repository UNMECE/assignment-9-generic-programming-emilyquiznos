#include <iostream>

template <typename T>
class GenericArray{
private:
    T* data;
    int size_;

public:
    // construcor and destructor
    GenericArray() : data(nullptr), size_(0){}

    ~GenericArray(){
        delete[] data;
    }

    void addElement(const T& element){
        T* new_data = new T[size_ + 1];
        for (int i = 0; i < size_; ++i){
            new_data[i] = data[i];
        }
        new_data[size_] = element; 
        delete[] data;  
        data = new_data;
        ++size_;
    }

    T at(int index) const{
        if (index < 0 || index >= size_){
             std::cerr<<"Error: Index is out of bounds.\n";
             return T();
        }
        return data[index];
    }

    int size() const{
        return size_;
    }

    T sum() const{
        T total = 0;
        for (int i = 0; i < size_; ++i){
            total += data[i];
        }
        return total;
    }

    T max() const{
        if (size_==0){
            std::cerr<<"Error: Array is empty\n";
            return T();
        }
        T max_val=data[0];
        for (int i=0; i<size_; ++i){
            if (data[i]>max_val){
                max_val=data[i];
            }
        }
        return max_val;
    }

    T min() const{
        if (size_==0){
            std::cerr<<"Error: Array is empty\n";
            return T();
        }
        T min_val=data[0];
        for (int i=0; i<size_; ++i){
            if (data[i]<min_val){
                min_val=data[i];
            }
        }
        return min_val;
    }

    T* slice(int begin, int end) const{
        if (begin<0 || end >= size_ || begin>end) {
            std::cerr<<"Error: Slice bounds are invalid\n";
            return nullptr;
        }
        int new_size=end-begin+1;
        T* sliced_array=new T[new_size];
        for (int i=0; i<new_size; ++i) {
            sliced_array[i]=data[begin+i];
        }
        return sliced_array;
    }
};

int main() {
    GenericArray<int> int_array;

    int_array.addElement(0);
    int_array.addElement(2);
    int_array.addElement(4);
    int_array.addElement(6);
    int_array.addElement(8);

    std::cout << "size of array is " << int_array.size() << std::endl;
    std::cout << "sum of the array is " << int_array.sum() << std::endl;
    std::cout << "maximum of array is " << int_array.max() << std::endl;
    std::cout << "minimum of array is " << int_array.min() << std::endl;
// test
    int* sliced_array = int_array.slice(2,4);
    if (sliced_array != nullptr){
        std::cout << "sliced array: ";
        for (int i = 0; i <= 4 - 2; ++i){
            std::cout << sliced_array[i]<<" ";
    }
    std::cout<<std::endl;

    delete[] sliced_array; 
    }
    return 0;
}
