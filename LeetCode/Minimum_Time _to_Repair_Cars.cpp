class Solution {
public:
    bool ok(long long t, vector<int>& ranks, int cars)
    {
        int n = ranks.size();
        for(int rank : ranks)
        {
            cars-=int(sqrt(t/rank));
            if(cars <=0) return true;
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long st =0, ed= 1e14 ;
        long long curr=-1, mid;
        while(st <= ed)
        {
            mid = (st+ed)/2;
            if(ok(mid, ranks, cars))
            {
                curr = mid;
                ed = mid-1;
            }else st = mid+1;

        }
        return curr;
    }
};
