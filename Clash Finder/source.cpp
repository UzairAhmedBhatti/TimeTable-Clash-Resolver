#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

//template <class T>
//class List
//{
//private:
//	T* ptr;
//	int size{};
//	int count{};
//public:
//	List()
//	{
//		
//	}
//
//	List(int s)
//	{
//		size = s;
//		ptr = new T[size];
//		for (int i = 0; i < size; i++)
//		{
//			ptr[i] = NULL;
//		}
//		count = 0;
//	}
//	~List()
//	{
//		if (ptr != NULL)
//		{
//			delete[] ptr;
//		}
//	}
//	void insert(T num)
//	{
//		if (size > count)
//		{
//			if (ptr[count] == NULL)
//			{
//				ptr[count] = num;
//				count++;
//			}
//		}
//		else
//		{
//			if (size == count)
//			{
//				size = size * 2;
//				T* ptr1 = new T[size];
//				for (int i = 0; i < size; i++)
//				{
//					if (count > i)//Condition to put the previous values in new Array
//					{
//						ptr1[i] = ptr[i];
//					}
//					else//Otherwise put the NULL
//					{
//						ptr1[i] = NULL;
//					}
//				}
//				for (int i = 0; i < size; i++)//This loop used to insert the new element in the list
//				{
//					if (ptr1[i] == NULL)
//					{
//						ptr1[i] = num;
//						count = i;
//						count++;
//						break;
//					}
//				}
//				delete[]ptr;//Delete previous Array
//				ptr = ptr1;//New array point the previous
//			}
//		}
//	}
//	void remove(T num)
//	{
//		for (int i = 0; i < size; i++)
//		{
//			if (ptr[i] == num)//If Num find in list and put Null
//			{
//				ptr[i] = NULL;
//				break;
//			}
//		}
//
//		//Sort the Array in decending order
//		int temp;
//		for (int i = 0; i < size; i++)
//		{
//			for (int j = i + 1; j < size; j++)
//			{
//				if (ptr[i] < ptr[j])
//				{
//					swap(ptr[i], ptr[j]);
//				}
//			}
//		}
//
//		size--;
//		T* ptr1 = new T[size];
//		int k = 0;
//		for (int i = 0; i < size; i++)
//		{
//			ptr1[k] = ptr[i];
//			k++;
//		}
//
//		delete[]ptr;
//		ptr = ptr1;
//		sort();//Call sort function of Accending order
//	}
//
//	T& operator[](int _index)
//	{
//		return ptr[_index];
//	}
//
//	int what_size() const
//	{
//		return count;
//	}
//
//	bool is_empty() const
//	{
//		if(count==0)
//		{
//			return true;
//		}
//		return false;
//	}
//
//	void make_empty()
//	{
//		count = 0;
//	}
//
//	void search(T num)
//	{
//		bool check = true;
//		int index;
//		for (int i = 0; i < size; i++)
//		{
//			if (ptr[i] == num)
//			{
//				check = true;
//				index = i;
//				break;
//			}
//			else
//			{
//				check = false;
//			}
//		}
//		if (check == true)
//		{
//			cout << num << " present in the list\n ";
//		}
//		else
//		{
//			cout << num << " is not present in the List\n";
//		}
//	}
//	void sort()
//	{
//		for (int i = 0; i < size; i++)
//		{
//			for (int j = i + 1; j < size; j++)
//			{
//				if (ptr[i] > ptr[j])
//				{
//					swap(ptr[i], ptr[j]);
//				}
//			}
//		}
//	}
//	void print()
//	{
//		for (int i = 0; i < size; i++)
//		{
//			if (ptr[i] != NULL)
//			{
//				cout << ptr[i] << endl;
//			}
//		}
//	}
//};


template<class T>
class List
{
private:
	T* ptr;
	int size;
	int count;

public:

	List()   // Default Constructor
	{
		size = 10;
		ptr = new T[size];
		count = 0;
	}
	List(List<T> &obj)
	{
		size = obj.getsize();
		T* tptr = obj.getptr();
		ptr = new T[size];
		for(int i=0;i<size;i++)
		{
			ptr[i] = tptr[i];
		}
		count = obj.getcount();
	}
	List<T> operator=( List<T> &obj)
	{
		
		size = obj.getsize();
		T* tptr = obj.getptr();
		ptr = new T[size];
		for (int i = 0; i < size; i++)
		{
			ptr[i] = tptr[i];
		}
		count = obj.getcount();
		return *this;
	}
	int getcount()
	{
		return count;
	}
	int getsize()
	{
		return size;
	}
	T* getptr()
	{
		return ptr;
	}
	void insert(T num)
	{
		if (count < size)      // if list has some space left in it
		{
			ptr[count] = num;
			count++;
		}
		else                        // else make new array of twice size
		{
			int i = 0;
			size = 2 * size;   // new size
			T* new_ptr = new T[size];

			for (; i < size / 2; i++)  // copying old data to new array
			{
				new_ptr[i] = ptr[i];
			}
			//delete[] ptr;     // delete old array ( de allocate memory on heap)

			new_ptr[i] = num;  // store the new number
			count++;
			ptr = new_ptr; // address of new array being given to our pointer variable
		}
	}

	void remove(T& param)
	{
		int index = 0;    // index at where to remove from
		if (search(param))  // if number in the list
		{
			index = search_index(param);  // index at where to remove from
			param = ptr[index];
			if (index == count - 1)       // if at the last than no need to shift/copy up
			{
				count--;
			}
			else          // if at the start or anywhere in the middle
			{
				int x = count - 1;  // terminating value 
				for (int i = index; i < x; i++)
				{
					ptr[index] = ptr[index + 1];   // shifting up
					index++;
				}
				count--;   // dec count 
			}
		}
	}

	T& operator[](int _index)
	{
		return ptr[_index];
	}

	int what_size() const
	{
		return count;
	}

	bool is_empty() const
	{
		if (count == 0)
		{
			return true;
		}
		return false;
	}

	void make_empty()
	{
		count = 0;
	}

	int search_index(T num)     // same as the search function except that it returns the index at which data is found
	{
		int index = 0;
		int flag = 0;
		for (int i = 0; i <= count && flag == 0; i++)
		{
			if (ptr[i] == num)
			{
				flag = 1;
				index = i;
				break;
			}
		}
		if (flag == 1)
		{
			return index;
		}
		else
		{
			return -1;
		}
	}

	bool search(T num)
	{
		int flag = 0;   // flag
		for (int i = 0; i <= count && flag == 0; i++)
		{
			if (ptr[i] == num)   // if found
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			return true;
		}
		return false;
	}

	void sort()      // Bubble Sorting 
	{
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < count - 1; j++)
			{
				if (ptr[j + 1] < ptr[j])
				{
					swap(ptr[j + 1], ptr[j]);
				}
			}
		}
	}

	void print()    // simple print function
	{
		for (int i = 0; i < count; i++)
		{
			cout << ptr[i] << endl;
		}
	}

	~List()     // Destructor 
	{
		if (ptr != nullptr) {
			delete[] ptr;
			size = 0;
			count = 0;
		}
	}
};




class time_
{
public:
	int hour_ = 0;
	int minute_ = 0;
};

//classlist is a struct that contains :

struct classlist
{
	int count;
	char names[60][15]; //60 students in class, first name only.
	char rollNo[60][10];
};

class slots
{
public:
	slots()
	{
		
	}
	slots(slots &obj)
	{
		name = obj.name;
		time = obj.time;
		students = obj.students;
	}
	string name;
	time_ time;
	classlist* students=nullptr;
};

class classes
{
public:
	classes() = default;
	classes(classes &obj)
	{
		name = obj.name;
		slot = obj.slot;
	}
	string name;
	List<slots> slot;
};

class day
{
public:
	day()
	{
		name = "";
	}
	day(day &obj)
	{
		name = obj.name;
		room = obj.room;
	}
	string name;
	List<classes> room;
};


class TTADT
{
	List<day> days;
	//you data structure here...
public:
	void load(const char filename[])
	{
		int hour = 8;
		int minute = 0;

		ifstream fin;
		fin.open(filename);
		if (!fin.is_open())
		{
			return;
		}

		string buffer;
		char* pch;

		day day_obj;

		while (!fin.eof())
		{
			getline(fin, buffer);
			if (strcmp(buffer.c_str(), "Monday") == 0 || strcmp(buffer.c_str(), "Tuesday") == 0 || strcmp(buffer.c_str(), "Wednesday") == 0 || strcmp(buffer.c_str(), "Thursday") == 0 || strcmp(buffer.c_str(), "Friday") == 0)
			{
				day_obj.name = buffer;
				List<string> tokens;
				for (int x = 0 ; x < 25; x++)
				{
					getline(fin, buffer);
					pch = strtok(const_cast<char*>(buffer.c_str()), ",");
					while (pch)
					{
						if (pch != NULL)
						{
							tokens.insert(string(pch));
						}
						pch = strtok(NULL, ",");
					}

					classes room_obj;
					room_obj.name = tokens[0];
					for (int i = 1; i < tokens.what_size();i++)
					{
						time_ time_temp;
						time_temp.hour_ = hour;
						time_temp.minute_ = minute;

						slots slot_obj;
						slot_obj.name = tokens[i];
						slot_obj.time = time_temp;
						//Woking for studentInfo pointer and time object
						room_obj.slot.insert(slot_obj);

						string temp = tokens[i];
						if (temp[0] == '"')
						{
							hour += 3;
						}
						else
						{
							hour += 1;
							minute += 30;
							if (minute == 60)
							{
								hour++;
								minute = 0;
							}
						}
					}

					day_obj.room.insert(room_obj);
					//tokens.make_empty();
				}
				hour = 8;
				minute = 0;
			}
			days.insert(day_obj);
		}
	}

};




int main()
{
	TTADT timetable;
	timetable.load("data.txt");

	return 0;
}

