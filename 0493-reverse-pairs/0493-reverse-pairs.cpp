
class Solution {
    int cnt=0;
public:
void merge(vector<int>& arr, int left, 
                     int mid, int right){
                         
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void countpair(vector<int>& arr, int low, int mid, int high) {
    int right = mid + 1;

    for (int i = low; i <= mid; i++) {
        while (right <= high && arr[i] > 2LL * arr[right]) {
            right++;
        }
        cnt += right - (mid + 1);
    }
}
void mergeSort(vector<int>& arr, int left, int right){
    
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    countpair(arr,left,mid,right);
    merge(arr, left, mid, right);
}

    int reversePairs(vector<int>& nums) {

        // int n=nums.size();
        // int cnt=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]>2*nums[j]){
        //             cnt++;
        //         }
                
        //     }
        // }

        // return cnt;
      
        mergeSort(nums,0,nums.size()-1);
        return cnt;
    }
};