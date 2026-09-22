class Intersection {

    static class Node{
        int data;
        Node next;
        Node(int data){
            this.data=data;
            this.next=null;
        }
    }

    static Node intersection(Node head1, Node head2){
        Node resultHead=null;
        Node resultTail=null;
        while(head1!=null && head2!=null){
            if(head1.data == head2.data){
                Node newNode=new Node(head1.data);
                if (resultHead == null){
                    resultHead=newNode;
                    resultTail=newNode;
                } else{
                    resultTail.next=newNode;
                    resultTail=newNode;
                }
                head1=head1.next;
                head2=head2.next;
            }
            else if(head1.data < head2.data){
                head1=head1.next;
            }
            else{
                head2=head2.next;
            }
        }
        return resultHead;
    }

    static void printList(Node head){
        while (head != null) {
            System.out.print(head.data);
            if(head.next != null){
                System.out.print(" -> ");
            }
            head=head.next;
        }
    }

    public static void main(String[] args){
        Node head1 = new Node(1);
        head1.next = new Node(2);
        head1.next.next = new Node(2);
        head1.next.next.next = new Node(3);
        head1.next.next.next.next = new Node(4);
        Node head2 = new Node(2);
        head2.next = new Node(2);
        head2.next.next = new Node(2);
        head2.next.next.next = new Node(4);
        Node result = intersection(head1, head2);
        System.out.println("Intersection:");
        printList(result);
    }
}