#include <iostream>
using namespace std;
#include <queue>
#define n 20

// class queue {
//     int* arr;
//     int front ;
//     int back ;

//     public:
//     queue(){
//         arr=new int[n] ;
//         front = -1;
//         back=-1;

//     }
//     void push(int x){
//         if (back ==n-1){
//             cout<<"queue overflow"<<endl;
//             return;
//         }
//         back++;
//         arr[back]=x;
//         if (front==-1){
//             front++;
//         }

//     }
//     void pop(){
//         if (front==-1 || front >back){
//             cout <<"queue is empty";
//             return;
//         }

//         front++;

//     }
//     int peek(){
//         if (front==-1 || front >back){
//             cout<<"queue is empty";
//             return -1 ;
//         }
//         return arr[front];
//     }
//     bool empty(){
//         if (front==-1 || front >back){
//             cout<<"queue is empty";
//             return true;
//         }
//     }
// };

int main() {
  //     queue q;
  //     q.push(30);
  //     q.push(30);
  //     q.push(30);
  //     q.pop();
  //     cout<<q.peek()<<endl;
  //     q.pop();

  //     cout<<q.peek()<<endl;
  //     q.pop();
  //     cout<<q.peek()<<endl;
  //     q.pop();

  queue<int> q;
  q.push(44);
  q.push(12);
  while (!q.empty()) {
    cout << q.front();
    q.pop();
  }

  return 0;
}