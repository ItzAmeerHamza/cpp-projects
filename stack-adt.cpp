#include<iostream>
using namespace std;
template<typename Type>
struct Node
{
	// structure for creating nodes of link list
	Type data; // data element of node
	Node* link; //for storing next address
};
// class for link list
template<typename Type>
class List {
protected:
	int length; // for holding length of the link list
	Node<Type> *head; // for storing the head address of the link list 
private:
	// Helper Function
	bool is_Full(); // function for checking whether the list is full or not 
public:
	List(); // constructor
	bool is_Empty(); // function for checking whether the list is empty or not
	int get_Length(); // function for returning the lenght of the list
	void insert_Node(Type val); // insert a new node at the start of the list
	Type delete_node(); // delete node from the start of the list.
	Type return_Middle(); // will retun the middle element of the list.
	void traverse_List(); // traverse the whole list and print the values
	int top(); // for returning top element of the stack
	void DestroyList(); // for clearing all node of the link list
};
template<typename Type>
List<Type>::List() 
{
	// constructor for initializing default value
	length = 0;
	head = nullptr;
}
///////////////////////////////////////////////////////////
template<typename Type>
bool List<Type>::is_Empty()
{
	if (head == nullptr || length == 0) // whether the stack is empty or not
	{
		return true;
	}
	else
	{
		return false;
	}
}
//////////////////////////////////////////////////////////////////
template<typename Type>
bool List<Type>::is_Full()
{
	Node<Type>* temp;
	try
	{
		// try block for checking the exception of bad_alloc
		temp = new Node<Type>;
		delete temp;
		return false;
	}
	catch (bad_alloc exception)
	{
		return true;
	}
}
//////////////////////////////////////////////////////////////////
template<typename Type>
int List<Type>::get_Length()
{
	// return the number of nodes of the list
	return this->length;
}
///////////////////////////////////////////////////////////////////
template<typename Type>
void List<Type>::traverse_List()
{
	// the function will traverse the whole list and print the data
	Node<Type>* temp;
	temp = this->head;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->link;
	}
}
////////////////////////////////////////////////////////////////////////
template<typename Type>
void List<Type>::insert_Node(Type val)
{
	if (!is_Full())
	{
		this->length++;
		Node<Type>* temp;
		temp = new Node<Type>; // creating new node
		temp->data = val;
		temp->link = head;
		head = temp; //changing the head position
	}
	else
	{
		cout << "Over flow can`t push new item onto the stack" << endl;
	}
}
//////////////////////////////////////////////////////////////////////////
template<typename Type>
Type List<Type>::delete_node() // the function will delete the node and returns the data of deleting node
{
	Node<Type>* temp = head;
	Node<Type>* deletingNode;
	if (temp != nullptr) 
	{
		Type val;
		this->length--;
		head = temp->link; 
		deletingNode = temp;
		val = deletingNode->data;
		delete temp; // deletion of the node 
		return val;// returning the data of the deleting node 
	}
	else
	{
		cout << "Under Flow can`t delete node" << endl;
		exit(1);
	}
}
/////////////////////////////////////////////////////////////////////
template<typename Type>
Type List<Type>::return_Middle() // this function will return the middle element of the stack
{
	Node<Type>* temp = this->head;
	int Middle = (length)/2;
	for (int  i = 0; i < Middle; i++)
	{
		temp = temp->link;
	}
	return temp->data;
}
template<typename Type>
int List<Type>::top() // will return the top element of the stack
{
	Node<Type>* temp = head;
	return temp->data;
}
template<class Type>
void List<Type>::DestroyList()
{
	head = nullptr;
	this->length = 0;

}
// class for stack . Instances of link list will be used in stack class to access functionalities.
template<typename Type>
class stack {
private:
	List<Type> L; // instance of link list
	Type top;
public:
	stack(); // constructor 
	bool IsEmpty(); // check whether the string is empty
	void Push(int val); // push element onto the stack
	Type Pop(); // pop element from the stack
	void Display(); // display all element of the stack
	Type Return_Middle(); // return the middle element of the stack
	void ClearStack();
};
template<class Type>
stack<Type>::stack()
{
	top = 0;
}
////////////////////////////////////////////////////////////////
template<class Type>
bool stack<Type>::IsEmpty()
{
	return L.is_Empty();
}
/////////////////////////////////////////////////////////////////
template<class Type>
void stack<Type>::Push(int val)
{
	L.insert_Node(val);
}
////////////////////////////////////////////////////////////////
template<class Type>
Type stack<Type>::Pop()
{
	return L.delete_node();
}
////////////////////////////////////////////////////////////////
template<class Type>
void stack<Type>::Display()
{
	L.traverse_List();
}
///////////////////////////////////////////////////////////////
template<class Type>
Type stack<Type>::Return_Middle()
{
	return L.return_Middle();
}
///////////////////////////////////////////////////////////////////
template<class Type>
void stack<Type>::ClearStack()
{
	L.DestroyList();
}
int main(void)
{
	string choice = ""; 
	stack<int> obj;
	while (true)
	{
		cout << "Press 1 to check whether the stack is empty?" << endl
			<< "Press 2 to push items into stack" << endl
			<< "Press 3 to pop item from stack" << endl
			<< "Press 4 to display all data in the stack" << endl
			<< "Press 5 to return middle item of stack" << endl
			<< "Press 6 to clear the stack" << endl
			<< "Press c to clear the screen" << endl;
		cin >> choice;
		if (choice == "1")
		{
			if (obj.IsEmpty())
			{
				cout << "Stack is Empty" << endl;

			}
			else
			{
				cout << "Stack is not Empty" << endl;
			}
			cout << "\t\t\t\t\t~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
		}
		else if (choice == "2")
		{
			int val;
			cout << "Enter Value to push into the stack" << endl;
			cin >> val;
			while (val != -111)
			{
				obj.Push(val);
				cout << "Enter next value -111 to terminate" << endl;
				cin >> val;
				cout << endl;
			}
			cout << "\t\t\t\t\t~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
		}
		else if (choice == "3")
		{
			cout << obj.Pop() << " is poped from stack " << endl;
			cout << "\t\t\t\t\t~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
		}
		else if (choice == "4")
		{
			
			cout << "Stack contains : " << endl; obj.Display(); cout << endl;
			cout << "\t\t\t\t\t~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
		}
		else if (choice == "5")
		{
			cout << "Middle item of the stack is : " << obj.Return_Middle() << endl;
			cout << "\t\t\t\t\t~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
		}
		else if (choice == "6")
		{
			obj.ClearStack();
			cout << "\t\t\t\t\t~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
		}
		else
		{
			cout << "\aWrong input" << endl;
			cout << "\t\t\t\t\t~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
			system("cls"); // will clear all the screen
		}
	}
	system("pause");
	return 0;
}
