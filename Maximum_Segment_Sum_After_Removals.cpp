//Link->https://leetcode.com/contest/biweekly-contest-85/problems/maximum-segment-sum-after-removals/
//same concept like this ->https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/A
//Author: Rohit Kumar
//Status: Accepted
//Time_complexity: O(nlongn)
//Space_complexity: O(n)
//Submission_date: 20/08/2022
//idea-> used segment tree to find the maximum subsegmet sum of a segment of the array
//whenver we remove an element from the array we update the segment tree
//we have to find maxium seb_segement sum of the array after removing an element which will lead
//us to divide the array into two parts ..... removedelement ......
//so how to handle this situation using segement tree
//so we no how to find subsegment sum of the array 
// if we have to part  exampale [1,2,3,-4] [2,3,4,-5];
// so if we add this segement so the we have many senario like the max_sum is sum of both array
//or maxvalue is sum of first_arrray and max_prefix of second array
//or max_suffix of first array and sum of second array
//so we have to comsider all these senario and find the max value
//also we have to update the prefix and suffix of the array

    #define ll long long int
struct node{
        ll maxvalue;
        ll prefix,suffix,sum;
};
    
    
    
vector<node> seg_tree;
void assign(int index){
    seg_tree[index].maxvalue=max(seg_tree[2*index+1].maxvalue,seg_tree[2*index+2].maxvalue);
        seg_tree[index].maxvalue=max(seg_tree[index].maxvalue,seg_tree[2*index+1].suffix+seg_tree[2*index+2].prefix);
        seg_tree[index].maxvalue=max(seg_tree[index].maxvalue,seg_tree[2*index+1].sum+seg_tree[2*index+2].prefix);
        seg_tree[index].maxvalue=max(seg_tree[index].maxvalue,seg_tree[2*index+1].suffix+seg_tree[2*index+2].sum);
         seg_tree[index].maxvalue=max(seg_tree[index].maxvalue,seg_tree[2*index+1].sum+seg_tree[2*index+2].sum);
        seg_tree[index].prefix=max(seg_tree[2*index+1].prefix,seg_tree[2*index+1].sum+seg_tree[2*index+2].prefix);
        seg_tree[index].prefix=max(seg_tree[index].prefix,seg_tree[2*index+1].sum+seg_tree[2*index+2].sum);
        seg_tree[index].suffix=max(seg_tree[2*index+2].suffix,seg_tree[2*index+2].sum+seg_tree[2*index+1].suffix);
        seg_tree[index].suffix=max(seg_tree[index].suffix,seg_tree[2*index+1].sum+seg_tree[2*index+2].sum);
        ll sm=-1e14;
        seg_tree[index].sum=max(sm,seg_tree[2*index+1].sum+seg_tree[2*index+2].sum);
}

    void build_tree(vector<int>&nums,int left,int right,int index){
        if(left>right){
            return;
        }
        if(left==right){
            seg_tree[index].maxvalue=nums[left];
            seg_tree[index].prefix=nums[left];
            seg_tree[index].suffix=nums[left];
            seg_tree[index].sum=nums[left];
            return;
        }
        int mid=(left+right)/2;
        build_tree(nums,left,mid,2*index+1);
        build_tree(nums,mid+1,right,2*index+2);
        assign(index);
       
    }
    void update(int pos,int left,int right,int index){
        if(left>pos||right<pos){
            return;
        }
        if(left==right&&left==pos){
            seg_tree[index].maxvalue=-1e14;
            seg_tree[index].prefix=-1e14;
            seg_tree[index].suffix=-1e14;
            seg_tree[index].sum=-1e14;
            return;
        }
        int mid=(left+right)/2;
        update(pos,left,mid,2*index+1);
        update(pos,mid+1,right,2*index+2);
        assign(index);
        
    }
    
    
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
       int n=nums.size();
        seg_tree.resize(4*n);
        build_tree(nums,0,n-1,0);
        vector<ll> ans;
        for(int i=0;i<n-1;i++){
            update(removeQueries[i],0,n-1,0);
            ans.push_back(seg_tree[0].maxvalue);
        }
        ans.push_back(0);
        return ans;
    }