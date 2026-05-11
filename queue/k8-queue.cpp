#include <iostream>
#include <stack>
#include <string>

using namespace std;

class MyQueue {
public:
    stack<int>stin,stout;

    MyQueue(){
    }
    
    void push(int x){
        stin.push(x);
    }
    
    void geser(){
        if(stout.empty()){
            while(!stin.empty()){
                stout.push(stin.top());
                stin.pop();
            }
        }
    }
    
    int pop(){
        geser();
        int val=stout.top();
        stout.pop();
        return val;
    }
    
    int peek(){
        geser();
        return stout.top();
    }
    
    bool empty(){
        return stin.empty()&&stout.empty();
    }
};

int main(){
    MyQueue q;
    string perintah;
    int nilai;

    cout<<"---Simulasi Queue dengan 2 Stack---"<<endl;
    cout<<"COMMAND: push [angka], pop, peek, empty, exit"<<endl;

    while(true){
        cout<<"> ";
        cin>>perintah;

        if(perintah=="push"){
            cin>>nilai;
            q.push(nilai);
            cout<<"Berhasil push "<<nilai<<endl;
        }
        else if(perintah=="pop"){
            if(q.empty()){
                cout<<"Error: Queue kosong!"<<endl;
            }
            else{
                cout<<"Hasil pop: "<<q.pop()<<endl;
            }
        }else if(perintah=="peek"){
            if(q.empty()){
                cout<<"Error: Queue kosong!"<<endl;
            }
            else{
                cout<<"Hasil peek: "<<q.peek()<<endl;
            }
        }
        else if(perintah=="empty"){
            cout<<"Status empty: "<<(q.empty()?"Ya":"Tidak")<<endl;
        }else if(perintah=="exit"){
            break;
        }else{
            cout<<"Perintah tidak dikenal!"<<endl;
        }
    }

    return 0;
}