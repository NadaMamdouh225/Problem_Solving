class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats=0;
        int n = people.size();
        int l=0,r=n-1;
        sort(people.begin(),people.end());
        while(l<=r)
        {
            if(people[r]+people[l]<=limit)
            {
                boats++;
                l++;
                r--;
            }
            else if(people[r]+people[l]>limit)
            {
                boats++;
                r--;   
            }
        }
        return boats;
    }
};
