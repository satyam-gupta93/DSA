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

  
    


}