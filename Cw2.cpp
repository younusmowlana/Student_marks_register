#include<iostream>
#include <algorithm>
#include <iomanip>




using namespace std;

/*
* Node Declaration
*/
struct avl_node
{
	int data;
	string subject;
	string name;
	struct avl_node *left;
	struct avl_node *right;
}*root;

/*
* Class Declaration
*/
class avlTree
{
public:
	int height(avl_node *);
	int diff(avl_node *);
	avl_node *rr_rotation(avl_node *);
	avl_node *ll_rotation(avl_node *);
	avl_node *lr_rotation(avl_node *);
	avl_node *rl_rotation(avl_node *);
	avl_node* balance(avl_node *);
	avl_node* insertinto(avl_node *, int num,string sub,string name);
	void display(avl_node *);
	void inorder(avl_node *);
	void preorder(avl_node *);
	void postorder(avl_node *);
	avl_node* removesub(avl_node* t, int x,string sub,string name);
	avl_node* findMin(avl_node*);
	avl_node* findMax(avl_node*);
	void displaytree(avl_node *, int);
	avlTree()
	{
		root = NULL;
	}
};
/*
* Height of AVL Tree
*/
void avlTree::displaytree(avl_node *ptr, int level)
{
	int i;
	if (ptr != NULL)
	{
		displaytree(ptr->right, level + 1);

		printf("\n");

		if (ptr == root){
                                       cout << "Root -> ";
		}

		for (i = 0; i < level && ptr != root; i++)
			cout << "        ";
		cout << ptr->data;
		displaytree(ptr->left, level + 1);
	}
}




int avlTree::height(avl_node *temp)
{
	int h = 0;
	if (temp != NULL)
	{
		int l_height = height(temp->left);
		int r_height = height(temp->right);
		int max_height = max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

/*
* Height Difference
*/


int avlTree::diff(avl_node *temp)
{
	int l_height = height(temp->left);
	int r_height = height(temp->right);
	int b_factor = l_height - r_height;
	return b_factor;
}

/*
* Right- Right Rotation
*/
avl_node *avlTree::rr_rotation(avl_node *parent)
{
	avl_node *temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}
/*
* Left- Left Rotation
*/
avl_node *avlTree::ll_rotation(avl_node *parent)
{
	avl_node *temp;

	temp = parent->left;

	parent->left = temp->right;

	temp->right = parent;

	return temp;
}

/*
* Left - Right Rotation
*/
avl_node *avlTree::lr_rotation(avl_node *parent)
{
	avl_node *temp;

	temp = parent->left;

	parent->left = rr_rotation(temp);

	return ll_rotation(parent);
}

/*
* Right- Left Rotation
*/
avl_node *avlTree::rl_rotation(avl_node *parent)
{
	avl_node *temp;

	temp = parent->right;

	parent->right = ll_rotation(temp);

	return rr_rotation(parent);
}

/*
* Balancing AVL Tree
*/
avl_node *avlTree::balance(avl_node *temp)
{
	int bal_factor = diff(temp);

	if (bal_factor > 1)
	{
		if (diff(temp->left) > 0)

			temp = ll_rotation(temp);
		else
			temp = lr_rotation(temp);
	}
	else if (bal_factor < -1)
	{
		if (diff(temp->right) > 0)

			temp = rl_rotation(temp);
		else
			temp = rr_rotation(temp);
	}
	return temp;
}

/*
* Insert Element into the tree
*/
avl_node *avlTree::insertinto(avl_node *root, int value,string sub,string nme)
{
	if (root == NULL)
	{
		root = new avl_node;

		root->data = value;

		root->subject=sub;

		root->name=nme;

		root->left = NULL;

		root->right = NULL;

		return root;
	}
	else if (value < root->data)
	{
		root->left = insertinto(root->left, value,sub,nme);

		root = balance(root);
	}
	else if (value >= root->data)
	{
		root->right = insertinto(root->right, value,sub,nme);

		root = balance(root);
	}
	return root;



}

/*
* Display AVL Tree
*/
void avlTree::display(avl_node *ptr)
{




               const char separator    = ' ';
    const int nameWidth     = 12;
    const int numWidth      =12;
             char result;





           if (ptr == NULL)

		return;
	display(ptr->right);


	 if(ptr->data>=75){
                          result='A';
             }
             else if(ptr->data>=65){
                           result='B';

             }
             else if(ptr->data>=50){
                           result='C';

             }
             else if(ptr->data>=35){
                           result='S';

             }
             else{
                          result='D';
             }


               cout<<endl;



     cout << setw(nameWidth) << setfill(separator) << ptr->name;
    cout << setw(nameWidth) << setfill(separator) << ptr->subject;
    cout << setw(numWidth) << setfill(separator) <<ptr->data<<"%";
  cout << setw(nameWidth) << setfill(separator) << result;


    cout << endl;


	display(ptr->left);

    }

/*
* Inorder Traversal of AVL Tree
*/
void avlTree::inorder(avl_node *tree)
{

          //      cout<<"\t\t---------- Inorder Traversal ----------"<<endl;

	if (tree == NULL)

		return;
	inorder(tree->left);

                  cout <<"student name :"<<tree->name<<" | "<< "subject :  "<<tree->subject<<" | "<<"marks : "<<tree->data<<"%"<<endl;


	inorder(tree->right);




}
/*
* Preorder Traversal of AVL Tree
*/
void avlTree::preorder(avl_node *tree)
{
	if (tree == NULL)
		return;
            cout <<"student name :"<<tree->name<<" | "<< "subject :  "<<tree->subject<<" | "<<"marks : "<<tree->data<<"%"<<endl;



	preorder(tree->left);

	preorder(tree->right);


}
avl_node* avlTree::findMin(avl_node* t) {

	if (t == NULL)
                          return NULL;

	else if (t->left == NULL)
                          return t; // if element traverse on max left then return

	else
                          return findMin(t->left); // or recursively traverse max left

}
avl_node* avlTree:: findMax(avl_node* t) {

	if (t == NULL)
                          return NULL;

	else if (t->right == NULL)
                          return t;

	else
                          return findMax(t->right);
}
/*
* Postorder Traversal of AVL Tree
*/
void avlTree::postorder(avl_node *tree)
{
	if (tree == NULL)

		return;
	postorder(tree->left);

	postorder(tree->right);

	    cout <<"student name :"<<tree->name<<" | "<< "subject :  "<<tree->subject<<" | "<<"marks : "<<tree->data<<"%"<<endl;


}
avl_node* avlTree:: removesub(avl_node* t, int x ,string sub,string nme) {

	avl_node* temp;
	// element not found
	if (t == NULL)
                          return NULL;
	// searching element
	else if (x < t->data)
	t->left = removesub(t->left, x,sub,nme);

	else if (x >t->data)
                          t->right = removesub(t->right, x,sub,nme);

	// element found
	// element has 2 children
	else if (t->left && t->right) {

		temp = findMin(t->right);

		t->data = temp->data;
		t->name=temp->name;
		t->subject=temp->subject;

		t->right = removesub(t->right, t->data,t->subject,t->name);
	}
	// if element has 1 or 0 child
	else {
		temp = t;
		if (t->left == NULL) {
                                       t = t->right;
		}

		else if (t->right == NULL){
                                       t = t->left;
		}

		delete temp;
	}
	if (t == NULL)
                          return t;
	// check balanced)
	return t = balance(t);






}
///testing
avlTree avl;
///function declaration
void insertitems();
void deleteitem();
void switchtomenu();
void init();
void itemdisplay();
void displaytree();
void inorder1();
void preorder1();
void post();
//void displaytree();


int main()
{
	init();
	return 0;
}

void init(){
int choice, item;

              system("cls");

	while (1)
	{
		 cout<<"\n\t\t------- Student marks register -------\n"<<endl;

    cout<<"\t1. press 1 for insert student details"<<endl;
    cout<<"\t2. Press 2 Delete student details from the tree"<<endl;
    cout<<"\t3. press 3 Display records"<<endl;
    cout<<"\t4. press 4 InOrder traversal"<<endl;
    cout<<"\t5. press 5 PreOrder traversal"<<endl;
    cout<<"\t6. press 6 PostOrder traversal"<<endl;
    cout<<"\t7. press 7 to display the marks inside the tree"<<endl;
    cout<<"\t8. press 8 Exit"<<endl;


    cout<<"\nPlease select any option - ";
		cin >> choice;

		system("cls");
		switch (choice)
		{
		case 1:
			insertitems();
			break;
		case 2:
		             if (root == NULL)
			{
				cout << "There No Records To Delete" << endl;
				continue;
			}
			deleteitem();
			break;
		case 3:
			if (root == NULL)
			{
				cout << "There No Records " << endl;
				continue;
			}
			itemdisplay();
			break;
		case 4:
			inorder1();
			break;
		case 5:
			preorder1();
			break;
		case 6:
			post();
			break;
		case 7:
                                       if (root == NULL)
			{
				cout << "Tree is Empty" << endl;
				continue;
			}
			displaytree();
			break;
                          case 8:
                                       exit(1);
                                       break;

		default:
			cout << "Wrong Choice" << endl;
			 system("cls");
                                         init();

		}
	}

}
void insertitems(){
              system("cls");

 cout<<"\t\t---------- New item add ----------"<<endl;


    string subject,nme;
    int marks;
    char status;

    cin.ignore();

      while(true){

           cout<<"enter your name -"<<endl;
         getline(cin, nme);

        cout<<"enter new subject - "<<endl;
             cin>>subject;


        cout<<"enter marks - "<<endl;
        cin>>marks;

  //cout<<marks <<endl;

        root=avl.insertinto(root,marks,subject,nme);


 cout<<"inserted" <<endl;

        cout<<"press any key add a new item or press 'n/N' to stop "<<endl;
 //cout<<root <<endl;
        cin>>status;

        if(status == 'n' || status == 'N'){
            main();
            break;
      }



        cin.ignore();

        system("cls");
    }

}

void deleteitem(){
             system("cls");
    cout<<"\t\t---------- Delete record ----------"<<endl;

    cout<<"Enter the name that to be deleted:"<<endl;

    string name,sub;
    int marks;

    cin>>name;
    cout<<"enter the subject to be deleted"<<endl;
    cin>>sub;

     cout<<"Enter marks to be deleted:"<<endl;
     cin>>marks;
             if(name == root->name && sub==root->subject && marks==root->data)
             {
             root=avl.removesub(root, marks,sub,name);
            cout<<name<<"  "<< "item deleted "<<endl;
             }

    else{

        cout<<"Theres no records for given item "<<name<<endl;
    }

    switchtomenu();

}
void inorder1(){
              system("cls");
cout<<"\t\t---------- Inorder Traversal ----------"<<endl;
cout<<endl;
avl.inorder(root);


 switchtomenu();

}


void preorder1(){
    cout<<"\t\t---------- preorder Traversal ----------"<<endl;
cout<<endl;
avl.preorder(root);


 switchtomenu();




}
void post(){
              system("cls");

cout<<"\t\t---------- postrder Traversal ----------"<<endl;
cout<<endl;
avl.postorder(root);



switchtomenu();

}


void switchtomenu(){

    char status;

    cout<<"Back to main menu (Y) ";
    cin>>status;
    if(status=='Y' || status=='y'){
         main();
        return;
    }


}
void itemdisplay(){

    system("cls");

    cout<<"\t\t---------- Display items ----------"<<endl;

    cout<<endl;

    avl.display(root);

    switchtomenu();

    //cin.ignore();
}
void displaytree(){
               system("cls");

    cout<<"\t\t---------- Display items ----------"<<endl;

    cout<<endl;

    avl.displaytree(root, 1);
     cout<<endl;
      cout<<endl;
      cout<<endl;
      cout<<endl;
      cout<<endl;
    switchtomenu();



}





