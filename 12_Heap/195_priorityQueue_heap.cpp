// #include <iostream>
// using namespace std;

// class PriorityQueue {
//     int arr[100];  // fixed-size array for simplicity
//     int size;

// public:
//     PriorityQueue() {
//         size = 0;
//     }

//     // Return parent index
//     int parent(int i) { return (i - 1) / 2; }

//     // Return left child index
//     int leftChild(int i) { return (2 * i + 1); }

//     // Return right child index
//     int rightChild(int i) { return (2 * i + 2); }

//     // Insert (enqueue) an element
//     void push(int val) {
//         arr[size] = val;
//         int i = size;
//         size++;

//         // Fix the max heap property if violated
//         while (i != 0 && arr[parent(i)] < arr[i]) {
//             swap(arr[i], arr[parent(i)]);
//             i = parent(i);
//         }
//     }

//     // Return the highest priority element
//     int top() {
//         if (size == 0) {
//             cout << "Priority Queue is empty!" << endl;
//             return -1;
//         }
//         return arr[0];
//     }

//     // Remove (dequeue) the highest priority element
//     void pop() {
//         if (size == 0) {
//             cout << "Priority Queue is empty!" << endl;
//             return;
//         }
//         arr[0] = arr[size - 1];
//         size--;
//         heapify(0);
//     }

//     // Heapify (maintain max-heap property)
//     void heapify(int i) {
//         int largest = i;
//         int l = leftChild(i);
//         int r = rightChild(i);

//         if (l < size && arr[l] > arr[largest])
//             largest = l;

//         if (r < size && arr[r] > arr[largest])
//             largest = r;

//         if (largest != i) {
//             swap(arr[i], arr[largest]);
//             heapify(largest);
//         }
//     }

//     // Check if empty
//     bool empty() {
//         return size == 0;
//     }

//     // Display queue elements (not in sorted order, heap order)
//     void display() {
//         cout << "Priority Queue (Heap): ";
//         for (int i = 0; i < size; i++) {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }
// };

// int main() {
//     PriorityQueue pq;

//     pq.push(10);
//     pq.push(30);
//     pq.push(20);
//     pq.push(5);

//     pq.display();

//     cout << "Top element: " << pq.top() << endl;

//     pq.pop();
//     pq.display();

//     cout << "Top after pop: " << pq.top() << endl;

//     return 0;
// }



#include<iostream>
#include<queue>
using namespace std;


int main(){

     int arr[5] = {54,53,55,52,50};


     // max Heap;
     priority_queue<int> pq;
     pq.push(10);
     pq.push(15);
     pq.push(5);
     pq.push(90);
     pq.push(25);

    cout<<"Max Heap->>>"<<endl;
     cout<<"Top:"<<pq.top()<<endl;
     pq.pop();
    cout<<"Top:"<<pq.top()<<endl;


    // priority queue min heap
    priority_queue<int,vector<int>,greater<int>> minheap;

    minheap.push(4);
    minheap.push(10);
    minheap.push(5);
    minheap.push(15);
    minheap.push(20);
    minheap.push(7);

    cout<<"Min Heap->>>"<<endl;
    cout<<"Top:"<<minheap.top()<<endl;
    minheap.pop();
    cout<<"Top:"<<minheap.top()<<endl;

    

}