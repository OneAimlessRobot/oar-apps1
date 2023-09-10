

typedef struct Node
{

    Node*prev,*next;
    Matrix state;


} Node;


Node* getPrev(Node*target);
Node* getNext(Node*target);

Matrix* printState()
