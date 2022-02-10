#include <iostream>
#include <vector>

using namespace std;


struct arr{
    int array[5];
    int top;
};

class hash_table{
    public:
		int n;
		arr table[];
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
        
        int hash_func(int x) 
		{
        	return (x % n);
    	}
    	
    	void add(int x)
    	{
    		int hash_value = hash_func(x);
    		table[hash_value].array[table[hash_value].top] = x;
    		table[hash_value].top++;
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
    	ht.add(input);
	}
	cout<<"\n\nThe table:\n";
	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j< ht.table[i].top; j++)
		{
			cout<<ht.table[i].array[j]<<" ";
		}
		cout<<"\n";
	}
}
