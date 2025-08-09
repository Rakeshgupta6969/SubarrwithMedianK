class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {

    // using the brute force solution.

    // sort(nums.begin(),nums.end());


    // int n  = nums.size();

    // int count  = 0;

    // for(int i  = 0; i<n; i++){
    //     vector<int> temp = {nums[i]};
    //     if(temp[0] == k)count++;


    //     for(int j  = i+1; j<n; j++){

    //     temp.push_back(nums[j]);
    //     int n1 =temp.size();
    //     if(n1%2 == 0){
    //         int index = n1/2;
    //         if(temp[index] == k) count++;
    //     }
    //     else{
    //         if(temp[n1/2] == k) count++;
    //     }

    //     }
    // }
    
    // return count-1;


      // using the optimal solution.


      // with the help of the hashmap;
    
    int n = nums.size();
     
     int count  = 0;

     int index = -1;

     for(int i = 0; i<n; i++){
        if(nums[i]== k){
            index = i;
            break;
        }
     }
    
    if(index == -1) return 0;

    unordered_map<int,int>mp;
    mp[0]  = 1;

    int diff = 0;
    for(int i = index+1; i<n; i++){
    
    if(nums[i]>k){
        diff++;
    }
    else{
        diff--;
    }

    mp[diff]++;

    }

  

    int diff1 = 0;
   for(int i = index; i>=0; i--){

        if(i != index){
        if(nums[i]>k){
        diff1++;
      }
      else{
        diff1--;
      }

        }
      count += mp[0-diff1];
      count += mp[1-diff1];


   }
    

     return count;

    }
};