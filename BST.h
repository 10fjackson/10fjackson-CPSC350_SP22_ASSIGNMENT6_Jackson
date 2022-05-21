#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;
template <class T>
class TreeNode{
    public:
        TreeNode();
        TreeNode(T key);
        virtual ~TreeNode();
        T key; //key = data
        TreeNode<T> *left;
        TreeNode<T> *right;
};
template <class T>
TreeNode<T>::TreeNode(){
    left = NULL;
    right = NULL;
    key = NULL;
}
template <class T>
TreeNode<T>::TreeNode(T k){
    left = NULL;
    right = NULL;
    key = k;
}
template <class T>
TreeNode<T>::~TreeNode(){
    left = NULL;
    right = NULL;
}
template <class T>
class BST{
    public:
        BST();
        virtual ~BST();
        void insert(T value);
        bool contains(T value);//search
        bool deleteNode(T k);
        bool isEmpty();
        T* getMin();
        T* getMax();
        int getSize();
        TreeNode<T> *getSuccessor(TreeNode<T> *d); //d represents the node we are going to delete
        TreeNode<T> *getPerson(int id);
        void printNodes();
        void printInfo();
        void printPerson(int id);
        void recPrint(TreeNode<T> *node);
        T calcSum(TreeNode<T> *node);
        TreeNode<T>* getRoot();
    private:
        TreeNode<T> *root;
        int size;
};
template <class T>
BST<T>::BST(){
    root = NULL;
    size = 0;
}
template <class T>
BST<T>::~BST(){
    //build some character
    //and do a little research
}
template <class T>
TreeNode<T>* BST<T>::getRoot(){
    return root;
}
template <class T>
void BST<T>::recPrint(TreeNode<T> *node){
    if(node == NULL)
        return;
    cout << node->key << endl;
    recPrint(node->left);
    recPrint(node->right);
}
template <class T>
T BST<T>::calcSum(TreeNode<T> *node){
    if(node == NULL)
        return 0;
    
    return (node->key + calcSum(node->left) + calcSum(node->right));
}
template <class T>
/*this function prints the entire tree*/
void BST<T>::printNodes(){
    recPrint(root);
}
template <class T>
bool BST<T>::isEmpty(){
    return (root == NULL);
}
template <class T>
T* BST<T>::getMin(){
    if(isEmpty())
        return NULL;
    TreeNode<T> *current = root;
    while(current->left != NULL){
        current = current->left;
    }
    return &(current->key);
}
template <class T>
T* BST<T>::getMax(){
    if(isEmpty())
        return NULL;
    TreeNode<T> *current = root;
    while(current->right != NULL){
        current = current->right;
    }
    return &(current->key);
}
template <class T>
void BST<T>::insert(T value){
    TreeNode<T> *node = new TreeNode<T>(value);
    size++;
    if(isEmpty())
        root = node;
    else{
        //the tree is not empty
        TreeNode<T> *current = root;
        TreeNode<T> *parent = NULL;
        while(true){
            parent = current;
            
            if(value < current->key){
                //we go left
                current = current->left;
                if(current == NULL){
                    //we found the insertion point
                    parent->left = node;
                    break;
                }
            }
            else{
                //we go right
                current = current->right;
                if(current == NULL){
                    //we found the insertion point
                    parent->right = node;
                    break;
                }
            }
        }
    }
    
}
template <class T>
bool BST<T>::contains(T value){
    if(isEmpty())
        return false;
    TreeNode<T> *current = root;
    while(current->key != value){
        if(value < current->key)
            current = current->left;
        else
            current = current->right;
        if(current == NULL)
            return false;
    }
    return true;
}
template <class T>
bool BST<T>::deleteNode(T k){
    //check if leaf
    //check which child exists(left or right or both)
    size--;
    if(isEmpty()){
        return false;
    }

    TreeNode<T> *current = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;

    //lets search for node to be deleted
    while(current->key != k){
        parent = current;

        if(k < current->key){
            isLeft = true;
            current = current->left;
        }
        else{
            isLeft = false;
            current = current->right;
        }

        if(current == NULL){
            return false;
        }
    }
        //found node to be deleted, now we proceed

        //checking if node is a leaf node
    if(current->left == NULL && current->right == NULL){
        //its a leaf, node to deleted has not children
        if(current == root){
            root = NULL;
        }
        else if(isLeft){
            parent->left = NULL;
        }
        else{
            parent->right = NULL;
        }
    }

    //if node has no right child, only a left child
    else if(current->right == NULL){
        //node to be deleted, has a left child (no right)
        if(current == root){
            root = current->left;
        }
        else if(isLeft){
            parent->left = current->left;
        }
        else{
            parent->right = current->left;
        }
    }

    //if node has no left child, only a right child
    else if(current->left == NULL){
        //node to be deleted, has a right child (no right)
        if(current == root){
            root = current->right;
        }
        else if(isLeft){
            parent->left = current->right;
        }
        else{
            parent->right = current->right;
        }
    }

    //node to delete has 2 children
    else{
        TreeNode<T> *successor = getSuccessor(current);

        if(current == root){
            root = successor;
        }
        else if(isLeft){
            parent->left = successor;
        }
        else{
            parent->right = successor;
        }
        successor->left = current->left;
        current->left = NULL;
        current->right = NULL;
    }
    current->left = NULL;
    current->right = NULL;
    delete current;
    return true;
}
template<class T>
TreeNode<T>* BST<T>::getPerson(int id){
  bool isTrue = false;
  if(isEmpty()){
    return NULL;
  }
  TreeNode<T> *current = root;
  while(isTrue == false){
    if(current->key.getID() == id){
      isTrue = true;
      return current;
    }
    else{
      current = getSuccessor(current);
    }
  }
}
template<class T>
int BST<T>::getSize(){
    return size;
}
template<class T>
void BST<T>::printInfo(){
  if(isEmpty()){
    return;
  }
  TreeNode<T> *current = root;
  for (int i = 0; i<getSize();++i){
    cout<<current->key.toString()<<endl;
    current = getSuccessor(current);
  }
}

template<class T>
void BST<T>::printPerson(int id){
  bool isTrue = false;
  if(isEmpty()){
    return;
  }
  TreeNode<T> *current = root;
  while(isTrue == false){
    if(current->key.getID() == id){
      cout<<current->key.toString()<<endl;
      isTrue = true;
    }
    else{
      current = getSuccessor(current);
    }
  }
}

template <class T>
/* d represents the node to be delete */
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){
    TreeNode<T> *sp = d; //sp = successors parent
    TreeNode<T> *successor = d;
    TreeNode<T> *current = d->right;

    while(current != NULL){
        sp = successor;
        successor = current;
        current = current->left;
    }
    //we found successor but we need to check
    //we need to check if the successor is a descendant of the right child(d->right)

    if(successor != d->right){
        sp->left = successor->right;
        successor->right = d->right;
    }
    return successor;

}
#endif