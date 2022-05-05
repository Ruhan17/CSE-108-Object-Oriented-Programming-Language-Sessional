#include<iostream>
#include<cstdlib>
using namespace std;

class stack
{
    int i;
    int *p;
    int size;
public:
    stack();
    stack(int n);
    stack(const stack &o);
    void push(int n);
    void push(int sz,int *n);
    void push(stack &o);
    int pop();
    int top();
    int Size();
    float similiarity(stack ob1);
    ~stack();
};

stack::stack()
{
    i=0;
    size=0;
    p=(int *)malloc(sizeof(int)*size);
    if(!p){
        cout<<"Allocation error\n";
        exit(1);
    }
    else{
        cout<<"Using default constructor\n";
    }
}

stack::stack(int n)
{
    i=0;
    size=0;
    p=(int *)malloc(sizeof(int)*size);
    if(!p){
        cout<<"Allocation error\n";
        exit(1);
    }
    else{
        cout<<"Using parameterized constructor\n";
    }
}

stack::stack(const stack &o)
{
    i=0;
    size=o.size;
    p=new int[size];
    if(!p){
        cout<<"Allocation error\n";
        exit(1);
    }
    else{
        cout<<"Using copy constructor\n";
    }
    for(i=0;i<size;i++){
        p[i]=o.p[i];
    }
}

stack::~stack()
{
    cout<<"Destructing\n";

    free(p);
}

void stack::push(int n)
{
    ++size;
    p=(int *)realloc(p,sizeof(int)*size);
    *(p+i)=n;
    i++;
}

void stack::push(int sz,int *n)
{
    int j;
    for(j=0;j<sz;j++){
        size++;
        p=(int *)realloc(p,sizeof(int)*size);
        *(p+i)=n[j];
        i++;
    }
}

void stack::push(stack &o)
{
    int j;

    //cout<<o.size<<"\n";
    for(j=0;j<=o.size+1;j++){
        size++;
        p=(int *)realloc(p,sizeof(int)*size);
        *(p+i)=o.pop();
        i++;
    }
}

int stack::pop()
{
    int k;

    if(size==0){
        cout<<"Stack is empty\n";
        return -1;
    }
    i--;
    k=p[i];
    p=(int *)realloc(p,sizeof(int)*(size--));
    return k;
}

float stack::similiarity(stack ob1)
{
    int i,j,a,b;
    float s,count=0,result;

    a=size;
    b=ob1.size;

    s=(a+b)/2.0;

    if(a<b){
        j=b-1;
        for(i=a-1;i>=0;i--){
            if(p[i]==ob1.p[j]){
                count++;
                j--;
            }
            else j--;
        }
    }

    else{
        j=a-1;
        for(i=b-1;i>=0;i--){
            if(ob1.p[i]==p[j]){
                count++;
                j--;
            }
            else j--;
        }
    }

    result=count/s;

    return result;
}

int stack::top()
{
    if(size==0){
        cout<<"No top element found\nstack is empty\n";
        return -1;
    }
    return p[size-1];
}

int stack::Size()
{
    return size;
}

int main()
{
    stack s;
    int n,a,i,a_size,b,c;
    int *ara;

    while(1){
        cout<<"PRESS A BUTTON: \n";
        cout<<"1:Push an element\t5:Top\n";
        cout<<"2:Push an array         6:Size\n";
        cout<<"3:Push a stack          7:Similiarity\n";
        cout<<"4:Pop                   8:Exit\n";

        cin>>n;

        if(n==1){
            cout<<"Enter an element: \n";
            cin>>a;
            s.push(a);
        }

        if(n==2){
            cout<<"Enter the size of array: \n";
            cin>>a_size;
            ara=new int[a_size];
            for(i=0;i<a_size;i++){
                cout<<"Enter the "<<i+1<<" No. element of array:\n";
                cin>>a;
                s.push(a);
            }
        }

        if(n==3){
            cout<<"Enter the size of stack: \n";
            cin>>a;
            stack s1(a);
            for(i=0;i<a;i++){
                cout<<"Enter the "<<i+1<<" No. element of stack:\n";
                cin>>b;
                s1.push(b);
            }
            s.push(s1);
        }

        if(n==4){
            cout<<"Popped element is: ";
            cout<<s.pop()<<endl;
        }

        if(n==5){
            cout<<"Element at the top: ";
            cout<<s.top()<<endl;
        }

        if(n==6){
            cout<<"Current size of stack: ";
            cout<<s.Size()<<endl;
        }

        if(n==7){
            stack s2;
            cout<<"Enter the size of stack: \n";
            cin>>a;
            for(i=0;i<a;i++){
                cout<<"Enter the "<<i+1<<" No. element of stack:\n";
                cin>>b;
                s2.push(b);
            }
            cout<<"Value of similiarity: "<<s.similiarity(s2)<<endl;
        }

        if(n==8){
            int k;
            k=s.Size();
            cout<<"Elements of the stack:\n";
            for(i=0;i<k;i++){
                cout<<s.pop()<<"\n";
            }
            return 0;
        }
    }
}
