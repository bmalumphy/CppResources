class Solution {
public:
    float getMedian(vector<int>& arr) {
        int n = arr.size();
        int isOdd = (n & 0x1) == 1;
        if (isOdd) return arr[n/2];
        return (arr[n/2 - 1] + arr[n/2])/2.0;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        if (!sz1) return getMedian(nums2);
        if (!sz2) return getMedian(nums1);
        int tot = (sz1 + sz2);
        int isOdd = (tot & 0x1) > 0;
        int med = (tot + isOdd)/2;
        int pos1 = -1;
        int pos2 = -1;
        int count = 0;
        int val = 0;
        while (med) {
            int incr = (med == 1)?med:med/2;
            int p1 = pos1 + incr;
            if ( p1 >= sz1) {
                p1 = sz1-1;  
            } 
            int p2 = pos2 + incr;
            if ( p2 >= sz2) {
                p2 = sz2-1;  
            } 
            if (nums1[p1] < nums2[p2]) {
                med -= (p1 - pos1);
                if (!med) {
                    val += nums1[p1];
                    count++;
                }
                pos1 = p1;
            } else {
                med -= (p2 -pos2);
                if (!med) {
                    val += nums2[p2];
                    count++;
                }
                pos2 = p2;
            }
			//Found the first median, look for the second one in the same loop
            if (!med && !isOdd && count == 1) med = 1; 
            if ((pos1 == (sz1-1)) || (pos2 == (sz2-1))) break;
        }
		// One of the arrays have been fully covered. Just lookup the rest from the other one.
        if (med) {
            if (pos1 == (sz1-1)) {
                val += nums2[pos2+med];
                count++;
                if (!isOdd && count == 1) {
                    val += nums2[pos2+med+1];
                    count++;
                }
            } else {
                val += nums1[pos1+med];
                count++;
                if (!isOdd && count == 1) {
                    val += nums1[pos1+med+1];
                    count++;
                }
                
            }
        } 
        return (val * 1.0)/count;
          
    }
};