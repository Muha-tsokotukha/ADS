#include <bits/stdc++.h>
class Solution {
public:
    struct myComp{
        bool operator()(const pair<int,int> &a,const pair<int,int>  &b){
            if(a.second==b.second) return a.first > b.first;
            return a.second > b.second;
        }
    };
    int bsearch(vector<int> arr,int t){
        int l=0,r=arr.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(arr[mid]==t){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return l;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,myComp> pq;
        vector<int> output;
        for(int i=0;i<mat.size();i++){
            int count = bsearch(mat[i],1);
            pq.push({i,count});
        }
        while(k-- && !pq.empty()){
            output.push_back(pq.top().first);
            pq.pop();
        }
        return output;
    }
};