class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        HashMap<String, ArrayList<String>> hashtable = new HashMap<>();
        for(String path: paths){
            String[] s = path.split(" ");
            for(int i=1; i<s.length; i++){
                String[] f = s[i].split("\\(");
                if(!hashtable.containsKey(f[1])){
                    hashtable.put(f[1], new ArrayList<String>());
                }
                hashtable.get(f[1]).add(s[0]+"/"+f[0]);
            }
        }
        ArrayList<List<String>> ans = new ArrayList<>();
        for(String key: hashtable.keySet()){
            if(hashtable.get(key).size() >= 2){
                ans.add(hashtable.get(key));
            }
        }
        return ans;
    }
}