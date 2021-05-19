package Trees;

import java.util.ArrayList;
public class BSToperations
{
    Node root;
    public class Node
    {
        Node left;
        Node right;
        int val;
        public Node(int val)
        {
            this.val = val;
            left = null;
            right = null;
        }
    }


    public Node insert(int val)
    {
        Node newNode = new Node(val);

        if(root == null)
        {
            root = newNode;
            return root;
        }

        Node current = root;
        while(true)
        {
            if(current.val < newNode.val)
            {
                if(current.right == null)
                {
                    current.right = newNode;
                    return root;
                }
                else
                    current = current.right;
            }
            else if(current.val > newNode.val)
            {
                if(current.left == null)
                {
                    current.left = newNode;
                    return root;
                }
                else
                    current = current.left;
            }
        }
    }


    public ArrayList<Integer> DFSinorder(Node root, ArrayList<Integer> result)
    {
        if(root.left != null)
        {
            DFSinorder(root.left, result);
        }
        result.add(root.val);
        if(root.right != null)
        {
            DFSinorder(root.right, result);
        }
        return result;
    }

    public static void main(String[] main)
    {
        BSToperations obj = new BSToperations();
        obj.insert(9);
        obj.insert(6);
        obj.insert(3);
        obj.insert(7);
        obj.insert(14);
        obj.insert(11);
        obj.insert(20);
        
        
        ArrayList<Integer> list = new ArrayList<>();
        list = obj.DFSinorder(obj.root, list);

        for(int i : list)
        {
            System.out.print(i + " , ");
        }


    }
    
}