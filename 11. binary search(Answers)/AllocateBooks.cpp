//You are given n books, numbered from 0 to n-1, and an array pages[] 
//where pages[i] is the number of pages in the i-th book. 
//There are m students, and you have to allocate books such that:
//Each student gets contiguous books.
//Each book is allocated to exactly one student.
//Every student must get at least one book.
//The maximum number of pages assigned to a student is minimized.
#include<bits/stdc++.h>
using namespace std;

int check(vector<int>v, int pages){
    int stu=1, pagesStudent=0;
    int n = v.size();

    for(int i=0;i<n;i++){
        if(pagesStudent+v[i]<=pages){
            pagesStudent+=v[i];
        }
        else{
            stu++;
            pagesStudent=v[i];
        }
    }
    return stu;
}

int bookAllocation(vector<int>v,int s){
    int low = *max_element(v.begin(),v.end());
    int high = accumulate(v.begin(),v.end(),0);
    int n = v.size();
    int res = -1;
    while(low<=high){
        int mid = (high+low)/2;
        int noStud = check(v,mid);
        if(noStud>s)
        low = mid+1;
        else{
             res = mid;
            high = mid-1;
        }
    }
    return res;
}

int main(){
    vector<int>books = {25,46,28,49,24};
    int students = 4;
    int maxPages = bookAllocation(books,students);
    cout<<maxPages<<endl;
    return 0;
}

//time:O(nlog(sum-maxEle))
//space:O(1)