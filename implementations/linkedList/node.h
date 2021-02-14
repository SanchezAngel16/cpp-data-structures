class Node{
    public:
        int data;
        Node* next;
        Node();
        Node(int d);
};

Node::Node(){
    data = NULL;
    next = NULL;
}

Node::Node(int d){
    data = d;
    next = NULL;
}
