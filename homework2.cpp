#include <iostream>

#define N 128

struct node{
	int val;
	struct node *left;
	struct node *right;
};

/* Bonus 1 search value in the binary search tree.
struct node *
search_value_in_bst(struct node *root, int value)
{

}*/

/*Bonus 2 delete value in the binary search tree.
struct node *delete_value_in_bst(struct node *root, int value)
{

}*/

void
print_bst_queue(struct node **queue, struct node **queue_parent, int queue_size)
{
	for(int i = 0; i < queue_size; i ++)
	{
		printf("%d(%d), ", queue[i]->val, queue_parent[i]->val);
	}

	printf("\n");
}

void
print_bst_by_level(struct node *root)
{
	if (root == NULL) {
		printf("This tree is empty\n");
		return;
	}

	struct node **current_queue = new struct node*[N];
	struct node **current_queue_parent = new struct node*[N];
	struct node **next_queue = new struct node*[N];
	struct node **next_queue_parent = new struct node*[N];

	for(int i = 0; i < N; i ++)
	{
		current_queue[i] = new struct node;
		current_queue_parent[i] = new struct node;
		next_queue[i] = new struct node;
		next_queue_parent[i] = new struct node;
	}
	
	int current_queue_size = 0;
	int next_queue_size = 0;
	
	current_queue[0] = root;
	current_queue_parent[0] = root;

	current_queue_size = 1;
	
	while(current_queue_size != 0)
	{
		print_bst_queue(current_queue, current_queue_parent, current_queue_size);

		
		// Traverse current queue to generate next_queue;
		next_queue_size = 0;
		for(int i = 0; i < current_queue_size; i ++)
		{
			struct node *tmp = current_queue[i];

			if(tmp->left != NULL)
			{
				next_queue[next_queue_size] = tmp->left;
				next_queue_parent[next_queue_size++] = tmp;
			}

			if(tmp->right != NULL)
			{
				next_queue[next_queue_size] = tmp->right;
				next_queue_parent[next_queue_size++] = tmp;
			}

		}

		// Swap the current and next for the coming iteration
		struct node **tmp_ptr = current_queue;
		current_queue = next_queue;
		next_queue = tmp_ptr;

		tmp_ptr = current_queue_parent;
		current_queue_parent = next_queue_parent;
		next_queue_parent = tmp_ptr;

		current_queue_size = next_queue_size;

		// printf("Next count: %d\n", next_queue_size);
	}

}

struct node *build_binary_search_tree(int *array, int array_size)
{
	//Scan through the array and allocate "struct node" to contain each 
	//- element from this *array

	struct node *root = new struct node;
	root->val = array[0];
	root->left = NULL;
	root->right = NULL;

	for(int i = 1; i < array_size; i ++)
	{
		// - 30 points
		// allocate a struct node variable
		// store array[i] into this variable
		
		/* 
		 *  Section 1 for the Initialize the stucture for the node in the binary search tree.
		 *
		 *  */
		 
		struct node *newArrival = new struct node;
		newArrival->val = array[i];  // Change this value;
		newArrival->left = NULL;
		newArrival->right = NULL;
		

		/*
		 * End of the section 1:
		 * 
		 *
		 * */

		/*
		 * Start of the section 2:
		 *
		 * */
		// - 30 points
		// descend the tree from root by 
		//	- going left if this array[i] is smaller than the node
		//	- going right if this array[i] is larger than the node
		// Continue descending until you cannot, and that's the spot for you to store array[i]
		//	
		
		struct node *tmp = root;

		while(true){
		    if(array[i] < tmp->val && tmp->left == NULL){
		        tmp->left = newArrival;
		        break;
		    } 
		    else if(array[i] > tmp->val && tmp->right == NULL){
		            tmp->right = newArrival;
		            break;
		        }
		        else if(array[i] < tmp->val){
		            tmp = tmp->left;
		        }
		        else if(array[i] > tmp->val){
		            tmp = tmp->right;
		        }
		    }
		
		/*
		 *
		 *  End of the section 2.
		 *
		 * */

		/*
		 * End of the section 2:
		 * 
		 * */
		//- if the entire program builds a correct BST, - 40 points
	}
	return root;
}	

int main(int args, char **argv){

	std::cout << "Input the  array_size -> \n";	

	int array_size;
	scanf("%d", &array_size);

	int *array = new int[array_size];

	//This array should contain no duplicates elements
	for(int i = 0; i < array_size; i ++)
	{
		int num = rand()%100;
		array[i] = num;
		
		for(int j = 0; j < i; j ++)
			if(num == array[j])
			{
				i--;
				break;
			}
	}

	//Generate the binary search tree
	struct node *root = build_binary_search_tree(array, array_size);	

	print_bst_by_level(root);
}





