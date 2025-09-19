#include<iostream> 
using namespace  std;


class Heap{

    public:
        int size;
        int arr[100];

        Heap(){
            size = 0;
            arr[0] = -1;
        }


        void insert(int val){
            size = size + 1;
            int indx = size;
            arr[indx] = val;


            while(indx>1){
            int parent = indx/2;
            
            if(arr[parent] < arr[indx] ){
                swap(arr[parent],arr[indx]);
                 indx = parent; 
            }else{
                return;
            }
            
            }

            // TC - O(log(n));
        }

        void deletefromHeap(){
            
            if(size==0){
                cout<<"Empty!";
                return;
            }

            arr[1] = arr[size];
            size--;

            int i = 1;

            while(i<size){
                int leftIndx = 2*i;
                int rightIndx = 2*i + 1;


                 if(leftIndx < size && arr[i] < arr[leftIndx]){

                    swap(arr[i],arr[leftIndx]);
                    i = leftIndx;
                
                }else if(rightIndx < size && arr[i] < arr[rightIndx]){
                    swap(arr[i],arr[rightIndx]);
                    i = rightIndx;
                }else{
                    return;
                }

            }

            
            // TC - O(log(n));
           
        }

        void print(){
            for(int i = 1; i<=size; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }


};


int main(){

    Heap h;
    h.insert(50);
    h.insert(60);
    h.insert(70);
    h.insert(55);
    h.insert(65);

    h.print();

    h.deletefromHeap();
    h.print();
    


}