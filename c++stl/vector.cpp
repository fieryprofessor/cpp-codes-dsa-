//vector
#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int> v;
   v.push_back(1);
   v.emplace_back(2);
   
   vector<pair<int,int>> vec;
   vec.push_back({1,2}); //with push_back we need to give the created object.
   vec.emplace_back(3,4);// with emplace_back , it creates the object automatically.

   vector<int> myvec(5,20); // vector of size 5 and all default values set to 20.
   vector<int> myvec2(5); // vector of size 5.
   vector<int> myvec3(myvec);// vector that is the copy of myvec.

    //Iterator
    vector<int>::iterator it = v.begin(); //points to the address of first element.
    vector<int>::reverse_iterator it2 = v.rbegin(); //points to the address of last element.
    vector<int>::iterator it3 = v.end(); //points to the address after last element.
    vector<int>::reverse_iterator it4= v.rend(); //points to the address before first element.

    cout<<*(it)<<endl;
    it++;
    cout<<*(it)<<endl;
    cout<<v[0]<< " "<<v.at(1)<<endl;

    for(it = v.begin();it!=v.end();it++){
        cout<<*(it)<<" ";
    }

    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    //v becomes {1,2,3,4,5}
    v.erase(v.begin()+1); //{1,3,4,5}
    v.erase(v.begin()+1,v.begin()+3);//{1,5}
    v.insert(v.begin()+1,6);//{1,6,5}
    v.insert(v.begin()+2,2,7);//{1,6,7,7,5}

    vector<int> newv(2,8);
    v.insert(v.begin(),newv.begin(),newv.end());//{8,8,1,6,7,7,5}

    cout<<endl;
    for(it = v.begin();it!=v.end();it++){
        cout<<*(it)<<" ";
    }
    cout<<endl;
    cout<<v.size();//7
    v.pop_back();//{8,8,1,6,7,7}
    v.swap(newv); //v now has {8,8}
    v.clear();//{}
    cout<<endl;
    cout<<v.empty()<<endl; // returns 1 as v is empty
    return 0;
}