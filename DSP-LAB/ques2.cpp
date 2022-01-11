# include<iostream>
using namespace std;

class Stack
{
    int top;
    
    public:
    int array[100];  
    //Maximum size of Stack is 100
    
    //construtor
    Stack(){top = -1;}
    
    void push(int x);
    int pop();
    void isEmpty();
    void Display();
};


void Stack::push(int x)
{
    if(top >= 100)
    {
        cout << "Stack Overflow \n";
    }
    else
    {
        array[++top] = x;
        cout << "Pushed "<<x<<"\n";
    }
}

int Stack::pop()
{
    if(top < 0)
    {
        cout << "Stack Underflow \n";
        return 0;
    }
    else
    {
        int d = array[top--];
        return d;
    }
}

void Stack::isEmpty()
{
    if(top < 0)
    {
        cout << "Stack empty \n";
    }
    else
    {
        cout << "Stack not empty \n";
    }
}

void Stack::Display()
{
    for(int i=0;i<=top;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main() {

    Stack st;
    
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    
    st.Display();
    
    cout<<"Popped "<<st.pop()<<endl;
    cout<<"Popped "<<st.pop()<<endl;
    
    st.Display();
}

