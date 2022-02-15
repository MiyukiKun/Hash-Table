#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct arr{
    int array[5];
    string names[5];
    int top;
};

class hash_table{
    public:
		int n;
		arr table[100];
        hash_table(int size)
        {
        	n = size;
            
            for(int i = 0; i < n; i++)
            {
                arr a;
                a.top = 0;
                table[i] = a;
            }
        }
        
        int hash_func_modulo(int x) 
		{
        	return (x % n);
    	}

		int hash_func_digit_extraction(int x)
		{
			return (x % 100);
		}
    	
    	void add(int x, string nam)
    	{
    		int hash_value = hash_func_modulo(x);
    		table[hash_value].array[table[hash_value].top] = x;
			table[hash_value].names[table[hash_value].top] = nam;
    		table[hash_value].top++;
		}

		int search(int x)
		{
			int hash_value = hash_func_modulo(x);
			int res = -1;
			int t = table[hash_value].top;
			for(int i = 0; i <= t; i++){
				cout<<i<<endl;
				if (table[hash_value].array[i] == x){
					res = i;
				}
			}
			return res;
		}
};



int main()
{
    int n;
    cout<<"Length of array: ";
    cin>>n;
    hash_table ht(n);
    for(int i = 0; i < n; i++)
    {
    	int input;
    	cout<<"Element no "<<i+1<<": ";
    	cin>>input;
		string name;
		cout<<"Name: ";
		cin>>name;
    	ht.add(input, name);
	}
	cout<<"\n\nThe table:\n";
	for(int i = 0; i < n; i++)
	{
		cout<<i+1<<". ";
		for (int j = 0; j< ht.table[i].top; j++)
		{
			cout<<ht.table[i].array[j]<<","<<ht.table[i].names[j]<<"  ";
		}
		cout<<"\n";
	}

	int no;
	cout<<"Enter number to search: ";
	cin>>no;
	int res = ht.search(no);
	cout<<no<<" is located in hashtable at position: "<<ht.hash_func_modulo(no)+1<<","<<res;
	
	return 0;
}
