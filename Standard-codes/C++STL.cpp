#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(){

    cout<<endl<<"Implementing STL Array : "<<endl;

    array<int,5> a = { 1, 2, 3 ,4 ,5} ;
    a[0] = 5454;
    a[2] = 45;
    a[1] = 599;
    a[3] = 796;
    a[4] = 249;
    int size = a.size();   // a.front() , a.empty() , a.back() 
    cout<<endl<<"Printing all the elements of STL array !!!"<<endl;

    for(int i = 0 ; i<size ; i++){
        cout<<a[i]<<" ";
    }    


    cout<<endl<<"----------------------------------------------------------"<<endl;

    cout<<endl<<"Implementing Vector : "<<endl;

    vector<int> v;

    v.push_back(353);
    v.push_back(6544);
    v.push_back(567);

    for( int i : v){
        cout<<i<<" ";
    }
    cout<<endl<<" Capacity : "<<v.capacity()<<" size : "<<v.size()<<endl;

    v.pop_back();
    
    cout<<"After popping out 1 element : "<<endl<<" Capacity : "<<v.capacity()<<" size : "<<v.size()<<endl;
    
    cout<<endl<<"Clearing the vector :"<<endl;

    cout<<"before : "<<endl<<" Capacity : "<<v.capacity()<<" size : "<<v.size()<<endl;
    v.clear();
    cout<<"before : "<<endl<<" Capacity : "<<v.capacity()<<" size : "<<v.size()<<endl;
    
    cout<<endl<<"Another way to initialize a vector :"<<endl;

    vector<int> another(10,2);
    cout<<"Checking that the another way is working or not and also the initialization is done properly or not : "<<endl;
    for( int i : v){
        cout<<i<<" ";
    }
    
    cout<<endl<<"Copying the Elements of vector 'another' into the vector 'copy' :"<<endl;
    vector<int> copy(another);
    cout<<"Checking that the Elements are copied properly or not : "<<endl;
    cout<<"Capacity : "<<copy.capacity()<<" Size : "<<copy.size()<<endl;
    cout<<"Elements of the vector : ";
    for( int i : v){
        cout<<i<<" ";
    }

    cout<<endl<<"----------------------------------------------------------"<<endl;

    cout<<endl<<"Implementing DEQueue :"<<endl;

    deque<int> q ;

    q.push_back(565);
    q.push_back(746);
    q.push_front(878);
    q.push_front(646);
    q.push_back(546);
    q.push_front(66);

    cout<<endl<<"Printing the elements of DEQueue : ";
    for(int i:q){
        cout<<i<<" ";
    }
    cout<<endl<<"Size : "<<q.size()<<endl;

    q.pop_front();
    cout<<endl<<"Popped a element from front : "<<endl;
    cout<<"Printing the elements of DEQueue : ";
    for(int i:q){
        cout<<i<<" ";
    }
    cout<<endl<<"Size : "<<q.size()<<endl;

    q.pop_back();
        cout<<endl<<"Popped a element from back : "<<endl;
        cout<<"Printing the elements of DEQueue : ";
    for(int i:q){
        cout<<i<<" ";
    }
    cout<<endl<<"Size : "<<q.size()<<endl;

    q.erase(q.begin(),q.begin()+2);
    cout<<"Printing the elements of DEQueue : ";
    for(int i:q){
        cout<<i<<" ";
    }
    cout<<endl<<"Size : "<<q.size()<<endl;

    cout<<endl<<"----------------------------------------------------------"<<endl;

    cout<<endl<<"Implementing List :"<<endl;

    list<int> l ;

    l.push_back(565);
    l.push_back(746);
    l.push_front(878);
    l.push_front(646);
    l.push_back(546);
    l.push_front(66);

    cout<<endl<<"Printing the elements of list : ";
    for(int i:l){
        cout<<i<<" ";
    }
    cout<<endl<<"Size : "<<l.size()<<endl;

    l.pop_front();
    cout<<endl<<"Popped a element from front : "<<endl;
    cout<<"Printing the elements of list : ";
    for(int i:l){
        cout<<i<<" ";
    }
    cout<<endl<<"Size : "<<l.size()<<endl;

    l.pop_back();
        cout<<endl<<"Popped a element from back : "<<endl;
        cout<<"Printing the elements of list : ";
    for(int i:l){
        cout<<i<<" ";
    }
    cout<<endl<<"Size : "<<l.size()<<endl;

     cout<<endl<<"Another way to initialize a list :"<<endl;

    list<int> anotherlist(10,2);
    cout<<endl<<"Checking that the another way is working or not and also the initialization is done properly or not : "<<endl;
    for( int i : anotherlist){
        cout<<i<<" ";
    }
    
    cout<<endl<<endl<<"Copying the Elements of list 'l' into the list 'copy' :"<<endl;
    list<int> anothercopy(l);
    cout<<"Checking that the Elements are copied properly or not : "<<endl;
    cout<<" Size : "<<anothercopy.size()<<endl;
    cout<<"Printing the elements of list : ";
    for( int i : anothercopy){
        cout<<i<<" ";
    }

    cout<<endl<<"----------------------------------------------------------"<<endl;

    cout<<endl<<"Implementing Stack :"<<endl;

    stack<int> s ;

    s.push(453);
    s.push(3);
    s.push(4);
    s.push(3);
    s.push(45);
    s.push(53);
    s.push(43);

    cout<<"Printing the top element of the stack : "<<s.top()<<endl;
    cout<<endl<<"Size : "<<s.size()<<endl;

    s.pop();
    cout<<endl<<"Popped a element  : "<<endl;
    cout<<endl<<"Size : "<<s.size()<<endl;
    cout<<"Printing the top element of the stack : "<<s.top()<<endl;

    cout<<endl<<"----------------------------------------------------------"<<endl;

    cout<<endl<<"Implementing Queue :"<<endl;

    queue<int> Queue ;

    Queue.push(565);
    Queue.push(746);
    Queue.push(878);
    Queue.push(646);
    Queue.push(546);
    Queue.push(66);

    
    cout<<endl<<"Front element of the Queue : "<<Queue.front();
    cout<<endl<<"Size : "<<Queue.size()<<endl;

    Queue.pop();
    cout<<endl<<"Popped a element from front : ";
    cout<<endl<<"Front element of the Queue : "<<Queue.front();
    cout<<endl<<"Size : "<<Queue.size()<<endl;

    cout<<endl<<"----------------------------------------------------------"<<endl;

    cout<<endl<<"Implementing Priority Queue :"<<endl<<endl;

    cout<<"Implementing MAX heap : "<<endl;
    priority_queue<int> PQ ;

    PQ.push(546);
    PQ.push(2);
    PQ.push(3);
    PQ.push(33);
    PQ.push(4);
    PQ.push(6);
    PQ.push(87);

    cout<<"Size : "<<PQ.size()<<endl;
    cout<<"Top element of the heap : "<<PQ.top()<<endl;
    cout<<"Popped out the element : "<<PQ.top()<<endl;
    PQ.pop();
    cout<<"Top element after popping out one element : "<<PQ.top()<<endl;
    


    cout<<endl<<"Implementing MIN heap : "<<endl;
    priority_queue<int , vector<int>, greater<int>> PQM ;

    PQM.push(546);
    PQM.push(2);
    PQM.push(3);
    PQM.push(33);
    PQM.push(4);
    PQM.push(6);
    PQM.push(87);

    cout<<"Size : "<<PQM.size()<<endl;
    cout<<"Top element of the heap : "<<PQM.top()<<endl;
    cout<<"Popped out the element : "<<PQM.top()<<endl;
    PQM.pop();
    cout<<"Top element after popping out one element : "<<PQM.top()<<endl;

    cout<<endl<<"----------------------------------------------------------"<<endl;

    cout<<endl<<"Implementing Ordered set :"<<endl<<endl;
    

    set<int> ST ;

    ST.insert(345);
    ST.insert(3);
    ST.insert(4);
    ST.insert(5);
    ST.insert(34);
    ST.insert(45);
    ST.insert(35);

    cout<<endl<<"Printing elements of sets : ";
    for(int i : ST){
        cout<<i<<" ";
    }
    ST.erase(ST.begin());
    cout<<endl<<"Printing elements of sets after erasing one element : ";
    for(int i : ST){
        cout<<i<<" ";
    }

    cout<<endl<<"Is '34' present or not : "<<ST.count(34)<<endl;

    cout<<endl<<"----------------------------------------------------------"<<endl;

    cout<<endl<<"Implementing Map :"<<endl<<endl;

    map<string,string> m;

    m["name"] = "Dishant" ;
    m["surname"] = "Radadiya" ;
    m["father"] = "Bharatbhai" ;
    m["mother"] = "Geeta" ;
    m.insert( { "collage" , "IIIT SURAT" } ) ;
    m.insert( { "institute" , "IIIT SURAT" } ) ;
    m.insert( { "branch" , "CSE" } ) ;
  
    cout<<"Printing all elements of the Map ( Key -> Value ) : "<<endl;
    for( auto i : m){
        cout<< i.first << " -> " << i.second << endl ;
    }
    cout<<"Size of the map : "<<m.size()<<endl;

    cout<<endl<<"Is element 'collage' present ? : "<<m.count("father")<<endl;

    m.erase("institute");
    cout<<endl<<"After erasing the element 'institute' : "<<endl;
    cout<<"Printing all elements of the Map ( Key -> Value ) : "<<endl;
    for( auto i : m){
        cout<< i.first << " -> " << i.second << endl ;
    }
    cout<<"Size of the map : "<<m.size()<<endl<<endl;

    cout<<endl<<"----------------------------------------------------------"<<endl;

    cout<<endl<<"Implementing Algorithms : "<<endl<<endl;

    cout<<endl<<"Implementing Binary Search : "<<endl;

    int  array[10] = {1,42,43,74,564,670,680,710,1000,1200};
  
    cout<<endl<<"Printing the elements of the array : ";
    for(int i:array){
        cout<<i<<" ";
    }

    cout<<endl<<"Is element '43' Present ? :  "<<binary_search(&array[0],&array[9],680);
    cout<<endl<<"Upper bound of the element '75' ? (index) : "<<upper_bound(&array[0],&array[9],100) - &array[0];
    cout<<endl<<"Lower bound of the element '100'? (index) : "<<lower_bound(&array[0],&array[9],700) - &array[0];

    int x = 28423 , y = 38439;
    cout<<endl<<endl<<"Determining the max value from 2 variables using 'max' function -> ";
    cout<<max(x,y)<<" is max value among both variables 'x' and 'y'";

    cout<<endl<<endl<<"Determining the min value from 2 variables using 'min' function -> ";
    cout<<min(x,y)<<" is min value among both variables 'x' and 'y'"<<endl;
    
    cout<<endl<<"Implementing swap function : "<<endl;
    cout<<"Before swapping : "<<endl<<"x = "<<x<<" , y = "<<y<<endl;
    swap(x,y);
    cout<<"After swapping : "<<endl<<"x = "<<x<<" , y = "<<y<<endl;

    cout<<endl<<"Implementing reverse function : "<<endl;

    vector<int> i = {1,2,3,4,5,6,7,8,9};

    cout<<endl<<"Using integer vector for reversing : "<<endl;
    cout<<"Original vector : ";
    for ( int j : i){
        cout<<j<<" ";
    }
    reverse(i.begin(),i.end());
    cout<<endl<<"Reversed integer vector : ";
    for ( int j : i){
        cout<<j<<" ";
    }

    string ab = "abcdef";

    cout<<endl<<endl<<"Using string for reversing : "<<endl;
    cout<<"Original string : "<<ab<<endl;
    reverse(ab.begin(),ab.end());
    cout<<"Reversed integer vector : "<<ab<<endl;

    cout<<endl<<"Implementing rotate function : "<<endl;

    cout<<endl<<"Before rotation : ";
    for(int i : array){
        cout<<i<<" ";
    }
    rotate(&array[2],&array[7],&array[10]);
    cout<<endl<<"After rotation : ";
    for(int i : array){
        cout<<i<<" ";
    }


    cout<<endl<<endl<<"Implementing sort function : "<<endl;

    int Array[10] = {1,1465,44,4,84,8987,132164,121,98,464};

    cout<<endl<<"Before sorting : ";
    for(int i : Array){
        cout<<i<<" ";
    }

    sort(&Array[0],&Array[9]);

    cout<<endl<<"After sorting : ";
    for(int i : Array){
        cout<<i<<" ";
    }


cout<<endl<<endl<<"Tanks for watching 👌🦤"<<endl;
    return 0 ;
}