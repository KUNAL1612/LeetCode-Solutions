/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> answer = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();
        if(root==null){
            return answer;
        }
        
        Queue<TreeNode> q1 =new LinkedList<>();
        q1.offer(root);
        int i = 1;
        while(!q1.isEmpty()){
            int curr_q_size = q1.size();
            for(int j=0;j<curr_q_size;j++){
                TreeNode temp = q1.poll();
                if(temp.left!=null){
                    q1.offer(temp.left);
                }
                if(temp.right!=null){
                    q1.offer(temp.right);
                }
                curr.add(temp.val);
            }
            //level done
            if(i==-1){
                Collections.reverse(curr);
            }
            answer.add(new ArrayList<>(curr));
            curr.clear();
            i *= -1;
        }
        
        
        return answer;
        
    }
}