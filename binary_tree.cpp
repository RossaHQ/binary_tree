#include "binary_tree.h"

// Creates an empty binary tree
binary_tree::binary_tree()
{
}

// Creates a binary tree with an initial value to store
binary_tree::binary_tree(int value)
{
	// Create first node of tree
	tree = new node;

    // Add value to tree
	tree->data = value;

    // Set left and right branches to nullptr
	tree->left = nullptr;
	tree->right = nullptr;
}

// Creates a binary tree from a collection of existing values
binary_tree::binary_tree(const std::vector<int> &values)
{
	//loop for values
	for(int x : values){
        insert(x);
    }
}

// Creates a binary tree by copying an existing tree
binary_tree::binary_tree(const binary_tree &rhs)
{
	
}

void dele_tree(node *tree)
{
	if((tree)==nullptr)
		return;
	//recursively delete each node of the tree
	dele_tree((tree)->left);
	dele_tree((tree)->right);
	//if there are no more branches in the tree, delete it
		delete tree;
}


// Destroys (cleans up) the tree
binary_tree::~binary_tree()
{
	dele_tree(tree);
	
}
void insert_to(node **tree,int value)
{
	if (*tree == nullptr)
		{	
		*tree = new node;
		(*tree)->data = value;
		(*tree)->left = nullptr;
		(*tree)->right = nullptr;
		
		}else{
			
			if (value < (*tree)->data){
		
			insert_to(&((*tree)->left), value);	
			}
		else{
		
		if (value > (*tree)->data)
	
			insert_to(&((*tree)->right), value);
			
			else 
				return;
			
			}
		}
}

// Adds a value to the tree

void binary_tree::insert(int value)
{
	insert_to(&tree, value);
}



// Removes a value from the tree
void binary_tree::remove(int value)
{
		return;
}

// Checks if a value is in the tree
bool binary_tree::exists(int value) const
{
    return true;
}

// Prints the tree out in order
std::string inorder_func(node *tree){
   if (tree != nullptr){
	   //orders the values in the tree, converts them to strings and the returns them to main function
        return inorder_func(tree -> left) + " " + std::to_string(tree -> data) + inorder_func(tree -> right);
    }else{
		
        return std::string("");
    } 
}

std::string binary_tree::inorder() const
{
    std::string values = inorder_func(tree);
    values.erase(0,1);
	//returns the ordered values from the tree
    return values;
}

std::string preord_func(node *tree){
    if (tree != nullptr){
        return " " + std::to_string(tree -> data) + preord_func(tree -> left) + preord_func(tree -> right);
    }else{
        return std::string("");
    }
}

// Prints the tree in pre-order
std::string binary_tree::preorder() const
{
    std::string values = preord_func(tree);
    values.erase(0,1);
	//returns the pre-ordered values from the tree
    return values;
}

std::string postord_func(node *tree){
    if (tree != nullptr){
        return postord_func(tree -> left) + postord_func(tree -> right) + " " + std::to_string(tree -> data);
    }else{
        return std::string("");
    }
}

// Prints the tree in post-order
std::string binary_tree::postorder() const
{
    std::string values = postord_func(tree);
    values.erase(0,1);
    return values;
}

// Copy assignment operator
binary_tree& binary_tree::operator=(const binary_tree &other){

  return *this;
  
}

// Checks if two trees are equal
bool binary_tree::operator==(const binary_tree &other) const
{
	//order the tree and then check if they are equal
	if (this->inorder() == other.inorder()){
		
		return true;
		
	}else{
		
    return false;
   }
}
// Checks if two trees are not equal
bool binary_tree::operator!=(const binary_tree &other) const
{
	//order the trees and then check if they are equal
	if (this->inorder() == other.inorder()){
		
		return false;
		
	}else{
		
    return true;
	
	}
}

// Inserts a new value into the binary tree
binary_tree& binary_tree::operator+(int value)
{
	//call insert
	insert(value);
	//return instance of this class
    return *this;
}

// Removes a value from the binary tree
binary_tree& binary_tree::operator-(int value){

    return *this;
}

// Reads in values from an input stream into the tree
std::istream& operator>>(std::istream &in, binary_tree &value)
{
    return in;
}

// Writes the values, in-order, to an output stream
std::ostream& operator<<(std::ostream &out, const binary_tree &value)
{
    return out;
}
