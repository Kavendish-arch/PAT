import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;

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
class TreeNode{
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(){}    
    TreeNode(int vale){this.val = vale;}    
    TreeNode(int val, TreeNode left, TreeNode right){
        this.val = val;
        this.left = left;
        this.right = right;
    }    
}
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        ArrayList<Integer> list = new ArrayList<>();
        inOrder(root, list);
        return list;
    }
    public void inOrder(TreeNode root, List<Integer> res) {
        if(root == null){
            return;
        }
        inorderTraversal(root.left);
        res.add(root.val);
        inorderTraversal(root.right);
    }
}
public class InOrder {
    public static void main(String[] args) {
        TreeNode A = new TreeNode(1);
        TreeNode B = new TreeNode(2);
        TreeNode C = new TreeNode(3);
        A.right = B;
        B.left = C;
        
        Solution solution = new Solution();
        List<Integer> list = solution.inorderTraversal(A);
        for(Integer i : list){
            System.out.println(i);
        }
        
    }
}
