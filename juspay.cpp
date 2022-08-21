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