#include <bits/stdc++.h>
using namespace std;


class MinMaxHeap
{

	public:
		
		int size = 0;
		int lev = -1;
		int cur_level = 1;
		
		// 0 for min level
		// 1 for max level

		vector<int> heap_array;

		void insert(int x)
		{
			heap_array.push_back(x);
			size++;

			if(size == pow(2 , lev+1))
			{
				lev++;
				cur_level ^= 1;
			}

			int curnode = size - 1;
			int curlev  = cur_level;

			while(curnode > 0)
			{
				// repeat swapping until current node reached the root of tree
				int parent = (curnode - 1)/2;
				int grand_parent = (parent - 1)/2;

				if(curlev == 0)
				{
					// current node at min level
					if(heap_array[parent] < heap_array[curnode])
					{
						swap(heap_array[parent] , heap_array[curnode]);
						curnode = parent;
						curlev ^= 1;
						continue;
					}

					if(parent != 0 && heap_array[grand_parent] > heap_array[curnode])
					{
						swap(heap_array[grand_parent] , heap_array[curnode]);
						curnode = grand_parent;
						continue;
					}
					break;
				}
				else
				{
					// current node at max level
					
					if(heap_array[parent] > heap_array[curnode])
					{
						swap(heap_array[parent] , heap_array[curnode]);
						curnode = parent;
						curlev ^= 1;
						continue;
					}

					if(parent != 0 && heap_array[grand_parent] < heap_array[curnode])
					{
						swap(heap_array[grand_parent] , heap_array[curnode]);
						curnode = grand_parent;
						continue;
					}
					break;
				}

			}
		}

		void print()
		{
			// print heap level wise
			// level order traversal

			int pos = 0;
			for(int level = 0 ; level <= lev ; level++)
			{
				while(pos < pow(2 , level+1)-1)
				{
					cout << heap_array[pos] <<" ";
					pos++;
					if(pos == size) break;
				}
				cout << endl;
				if(pos == size) break;
			}
		}

};


int main()
{

	MinMaxHeap Mheap;

	Mheap.insert(1);
	Mheap.insert(4);
	Mheap.insert(-5);
	Mheap.insert(6);
	Mheap.insert(7);
	Mheap.insert(9);
	Mheap.insert(3);
	Mheap.insert(40);
	Mheap.insert(20);
	Mheap.insert(2);
	Mheap.insert(70);
	Mheap.insert(100);

	Mheap.print();

	
	return 0;
}