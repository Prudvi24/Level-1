#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

class DynamicArray{
private:
	int *data;
	int nextIndex;
	int capacity;

public:
	DynamicArray(){
		data = new int[5];
		nextIndex = 0;
		capacity = 5;
	}

	DynamicArray(const DynamicArray &d){
		// this->data = d.data;    (default)       // shallow copy

		// Deep copy
		this->data = new int[d.capacity];
		for(int i=0;i<d.nextIndex;i++){
			this->data[i] = d.data[i];
		}
		this->nextIndex = d.nextIndex;
		this->capacity = d.capacity;
	}

	DynamicArray operator=(const DynamicArray &d){
		// this->data = d.data;   (default)        // shallow copy

		// Deep copy
		this->data = new int[d.capacity];
		for(int i=0;i<d.nextIndex;i++){
			this->data[i] = d.data[i];
		}
		this->nextIndex = d.nextIndex;
		this->capacity = d.capacity;	
	}

	void add(int element){
		if(nextIndex==capacity){
			int *newData = new int[2*capacity];
			for(int i=0;i<capacity;i++){
				newData[i] = data[i];
			}
			delete []data;
			data = newData;
			capacity *= 2;
		}
		else{
			data[nextIndex] = element;
			nextIndex++;
		}
	}

	int get(int i){
		if(i>=nextIndex){
			return -1;
		}
		else{
			return data[i];
		}
	}

	void add(int i, int element){
		if(i<nextIndex){
			data[i]=element;
		}
		else if(i==nextIndex){
			add(element);
		}
		else{
			return ;
		}
	}

	void display(){
		for(int i=0;i<nextIndex;i++){
			cout<<data[i]<<" ";
		}
		cout<<endl;
	}
};

int main(){
	DynamicArray d1;
	d1.add(10);
	d1.add(20);
	d1.add(30);
	d1.add(40);
	d1.add(50);
	d1.add(5,60);
	d1.add(2,70);
	DynamicArray d2(d1);
	d1.add(80);
	cout<<"Dynamic array of d1"<<endl;
	d1.display();

	cout<<"\nDynamic array of d2"<<endl;
	d2.display();
	return 0;
}

/*

Dynamic array of d1
10 20 70 40 50 80 

Dynamic array of d2
10 20 70 40 50 

*/