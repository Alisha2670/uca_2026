import java.util.*;

class Reverse{

    static class Node{
        int data;
        Node next;
        Node(int data){
            this.data=data;
            this.next=null;
        }    
    }

    static Node reverselist(Node head) {
        if (head==null || head.next==null) {
            return head;
        }
        Node newHead=reverselist(head.next);
        head.next.next=head;
        head.next=null;
        return newHead;
    }

    static void printList(Node head) {
        while (head!=null) {
            System.out.print(head.data);
            if (head.next!=null) {
                System.out.print(" -> ");
            }
            head = head.next;
        }
    }
    public static void main(String[] args){
        Node head=new Node(1);
        head.next=new Node(2);
        head.next.next=new Node(3);
        head.next.next.next=new Node(4);
        head.next.next.next.next=new Node(5);
        System.out.println("Original list:");
        printList(head);
        head=reverselist(head);
        System.out.println("\nReversed list:");
        printList(head);
    }
    
}