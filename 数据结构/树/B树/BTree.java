import java.util.Arrays;

public class BTree {

    static class Node {
        int[] keys;          // 关键字
        Node[] children;    //孩子
        int keyNumber;      // 有效关键字树
        boolean leaf = true;// 是否叶子节点
        int t;              //最小度数

        public Node(int t) {
            // t >= 2
            this.t = t;
            this.keys = new int[2 * t - 1]; // 关键字比孩子少一个
            this.children = new Node[2 * t];
            this.keyNumber = 0;
        }

        public String toString() {
            // 拷贝
            return "key: " + Arrays.toString(Arrays.copyOfRange(keys, 0, keyNumber)) + " keyNumber: " + keyNumber;
        }

        // 多路查找
        Node get(int target_key){
            int i = 0;
            while (i < this.keyNumber )
            {
                if(this.keys[i] == target_key)
                {
                    return this;
                }
                else if(this.keys[i] > target_key)
                {
                    // 当前节点没有
                    break;
                }
                else
                {
                    i++;
                }
            }
            if(this.leaf)
            {
                // 叶子节点 查找不到
                return null;
            }
            // 非叶子节点
            return this.children[i].get(target_key);
        }
        // 向指定索引插入key
        void insertKey(int index, int key)
        {
            System.arraycopy(this.keys, index, this.keys, index+1, this.keyNumber-index);
//            for(int i = this.keyNumber; i > index; i--)
//            {
//                this.keys[i] = this.keys[i-1];
//            }
            this.keys[index] = key;
            this.keyNumber++;
        }
        // 向指定索引插入child
        void insertChild(int index, Node node)
        {
            System.arraycopy(this.children, index, this.children, index+1, this.keyNumber-index);
//            for(int i = this.keyNumber; i >= index; i--)
//            {
//                this.children[i+1] = this.children[i];
//            }
            this.children[index] = node;
        }
    }

    Node root;  // 根节点
    int t;      // 最小度数
    final int MIN_KEY_NUMBER;
    final int MAX_KEY_NUMBER;
    public BTree() {
        this(2);
    }
    public BTree(int t) {
        this.t = t;
        this.root = new Node(t);
        this.MIN_KEY_NUMBER = t - 1;
        this.MAX_KEY_NUMBER = 2 * t - 1;
    }

    // 是否存在
    public boolean contains(int target_key)
    {
        return root.get(target_key) != null;
    }

    // 叶子节点，直接插入，叶子节点超过，分裂
    // 非叶子节点找孩子

    /**
     * 首先查找本节点中的插入位置i，如果没有空位(key 被找到)，应该走更新的逻辑，目前什么没做C接下来分两种情况e
     *  如果节点是叶子节点，可以直接插入了
     *  如果节点是非叶子节点，需安继续在 children[i]处继续递归插入
     * 无论哪种情况，插入完成后都可能超过节点keys 数目限制，此时应当执行节点分裂
     */
    public void put(int target_key)
    {
        doPut(root, target_key);
    }

    public void doPut(Node node, int target_key)
    {
        int i = 0;
        while (i < node.keyNumber)
        {
            if(node.keys[i] == target_key)
            {
                // 更新
                return;
            }
            else if(node.keys[i] > target_key)
            {
                // 插入
                break;
            }
            else
            {
                i++;
            }
        }
        if(node.leaf)
        {
            node.insertKey(i, target_key);
        }
        else
        {
            doPut(node.children[i], target_key);
        }
    }
    // 分裂
    private void split(Node left, Node parent, int index)
    {
        if(parent==null)
        {
            Node newRoot = new Node(t);
            newRoot.leaf = false;
            newRoot.insertChild(0, left);
            this.root = newRoot;
            parent = newRoot;
        }
        // 创建right节点，将left t 之后的key child 全部拷贝到right
        Node right = new Node(parent.t);
        right.leaf = left.leaf;
        System.arraycopy(left.keys, left.t, right.keys, 0, t-1);
        right.keyNumber = t-1;
        left.keyNumber = t-1;

        // 非叶子节点拷贝孩子
        if(!left.leaf)
        {
            System.arraycopy(left.children, left.t, right.children, 0, t);
        }

        // 中间的key 作为 parent的key
        int mid = left.keys[t-1];
        parent.insertKey(index, mid);

        // right 作为parent的右节点
        parent.insertChild(index, right);


    }
    public static void main(String[] args) {
        System.out.println("Hello World");
    }
}
