#include <iostream>
#include <stdexcept>

using namespace std;

class Queue
{
public:
    // 构造函数，传入队列的最大大小
    Queue(int max_queue_size) : maxSize(max_queue_size), front(0), rear(0), size(0)
    {
        queue = new int[max_queue_size]; // 分配队列空间
    }

    // 析构函数
    ~Queue()
    {
        delete[] queue; // 释放队列空间
    }

    // 判断队列是否为空
    bool IsEmpty()
    {
        return size == 0;
    }

    // 判断队列是否已满
    bool IsFull()
    {
        return size == maxSize;
    }

    // 获取队头元素
    void GetFront(int &result)
    {
        if (IsEmpty())
        {
            throw runtime_error("队列为空。");
        }
        result = queue[front];
    }

    // 获取队尾元素
    void GetRear(int &result)
    {
        if (IsEmpty())
        {
            throw runtime_error("队列为空。");
        }
        result = queue[rear == 0 ? maxSize - 1 : rear - 1];
    }

    // 入队操作
    void EnQueue(int new_value)
    {
        if (IsFull())
        {
            throw runtime_error("队列已满。");
        }
        queue[rear] = new_value;
        rear = (rear + 1) % maxSize;
        size++;
    }

    // 出队操作
    void DeQueue(int &result)
    {
        if (IsEmpty())
        {
            throw runtime_error("队列为空。");
        }
        result = queue[front];
        front = (front + 1) % maxSize;
        size--;
    }

private:
    int *queue;  // 队列数组
    int maxSize; // 队列最大大小
    int front;   // 队头指针
    int rear;    // 队尾指针
    int size;    // 队列当前大小
};

int main()
{
    Queue q(5);
    int value;

    q.EnQueue(10);
    q.EnQueue(20);
    q.EnQueue(30);
    q.EnQueue(40);
    q.EnQueue(50);

    if (q.IsFull())
    {
        cout << "队列已满。" << endl;
    }

    q.GetFront(value);
    cout << "队头元素： " << value << endl;

    q.GetRear(value);
    cout << "队尾元素： " << value << endl;

    q.DeQueue(value);
    cout << "出队元素： " << value << endl;

    q.GetFront(value);
    cout << "出队后的队头元素： " << value << endl;

    q.GetRear(value);
    cout << "出队后的队尾元素： " << value << endl;

    return 0;
}
