class Solution {
    
    void permuteUtil(int[] nums,
                     List<Integer> perm,
                     List<Boolean> visited,
                     Set<List<Integer>> perms,
                     int n) {
        
        if(perm.size() == n) {
            perms.add(new ArrayList<>(perm));
            return;
        } 
        for(int i = 0; i < n; ++i) {
            if(visited.get(i) == true)  continue;
            perm.add(nums[i]);
            visited.set(i, true);
            permuteUtil(nums, perm, visited, perms, n);
            perm.remove(perm.size()-1);
            visited.set(i, false);
        }
    }
    
    public List<List<Integer>> permuteUnique(int[] nums) {
        int n = nums.length;
        Set<List<Integer>> ansSet = new HashSet<>();
        List<Integer> perm = new ArrayList<>();
        List<Boolean> visited = new ArrayList<>();
        for(int i = 0; i < n; ++i)  visited.add(false);
        permuteUtil(nums, perm, visited, ansSet, n);
        List<List<Integer>> ans = new ArrayList<>();
        for(List<Integer> an : ansSet) {
            ans.add(an);
        }
        return ans;
    }
}
