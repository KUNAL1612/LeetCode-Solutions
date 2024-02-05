/*
// Definition for a Node.
class Node {
    public int val;
    public Node next;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
  public Node insert(Node head, int insertVal) {
    if (head == null) {
        // return with just the single loop
      Node newNode = new Node(insertVal, null);
      newNode.next = newNode;
      return newNode;
    }

    Node prev = head;
    Node curr = head.next;
    boolean toInsert = false;

    do {
      if (prev.val <= insertVal && insertVal <= curr.val) {
        // Case 1).
        toInsert = true;
      } else if (prev.val > curr.val) {
        // Case 2). // we've reached the tail/head of the cycle
        if (insertVal >= prev.val || insertVal <= curr.val)
          toInsert = true;
      }
      // okay we now know that we need to insert this here. If not
      if (toInsert) {
        prev.next = new Node(insertVal, curr);
        return head;
      }

      prev = curr;
      curr = curr.next;
    } while (prev != head);

    // Case 3).
    prev.next = new Node(insertVal, curr);
    return head;
  }
}