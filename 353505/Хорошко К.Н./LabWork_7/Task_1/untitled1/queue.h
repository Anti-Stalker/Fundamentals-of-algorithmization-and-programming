#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class queue
{

private:

    size_t size;
    T* array;

public:
    queue(){
        size = 0;
        array = new T[0];
    }

    ~queue(){
        delete[] array;
        array = nullptr;
    }

    bool isEmpty(){
        return size == 0;
    }

    size_t Size(){
        return size;
    }

    void push(T data){
        size++;
        T* new_array = new T[size];
        for (int i = 0; i < size-1; i++){
            new_array[i] = array[i];
        }
        delete[] array;
        array = new_array;
        new_array = nullptr;
        array[size-1] = data;
    }

    T front(){
        if (!isEmpty()){
            return array[0];
        }
    }

    T back(){
        if (!isEmpty()){
            return array[size-1];
        }
    }

    void pop(){
        if (!isEmpty()){
            size--;
            T* new_array = new T[size];
            for (int i = 0; i < size; i++){
                new_array[i] = array[i+1];
            }
            delete[] array;
            array = new_array;
            new_array = nullptr;
        }
    }

    T& operator[](size_t index){
        return array[index];
    }

    void task(queue<T>& a, queue<T>& b){
        long long max = -999999999999;
        int index = 0;
        for (int i = 0; i < a.Size(); i++){
            if (a[i] > max){
                max = a[i];
                index = i;
            }
        }

        queue<T> c;

        index++;

        for (int i = 0; i < b.Size(); i++){
            if (index + i < a.Size()){
                c.push(a[i + index]);
                a[index+i] = b[i];
            }
            else
            {
                a.push(b[i]);
            }
        }

        for (int i = 0; i < c.Size(); i++){
            a.push(c[i]);
        }
    }
};

#endif // QUEUE_H
