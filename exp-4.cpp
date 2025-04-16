// Problem 1: Sort Colors
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Dutch National Flag Algorithm
        int low = 0, mid = 0, high = nums.size() - 1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low++], nums[mid++]);
            } else if(nums[mid] == 1){
                mid++;
            } else{
                swap(nums[high--], nums[mid]);
            }
        }
        return;
    }
};

// Problem 2: Merge Sort
void merge(vector<int>&arr,int l,int mid,int r){
        vector<int>temp;
        int i=l,j=mid+1;
        while(i<=mid && j<=r){
            if(arr[i]<arr[j]) temp.push_back(arr[i++]);
            else temp.push_back(arr[j++]);
        }
        while(i<=mid) temp.push_back(arr[i++]);
        while(j<=r) temp.push_back(arr[j++]);
        for(int i=l;i<=r;i++){
            arr[i]=temp[i-l];
        }
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        if(r-l+1<=2){
            if(arr[l]>arr[r]) swap(arr[l],arr[r]);
            return ;
        }
        int mid=l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }

// Problem 3: Binary Search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1, mid;

        while (st <= end) {
            mid = st + (end - st) / 2;

            if (target < nums[mid]) {
                end = mid - 1;
            } else if (target > nums[mid]) {
                st = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
