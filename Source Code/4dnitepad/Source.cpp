#include<iostream>
#include<string>
#include<conio.h>
#include<windows.h>
//constexpr auto MAXsize = 10;
using namespace std;

class node {
public:
	int key;
	string data;
	node* next;
	node* prev;
	node* up;
	node* down;
	node(string d) {
		int k = 0;
		key = k;
		data = d;
		next = NULL;
		prev = NULL;
		up = NULL;
		down = NULL;
	}
	node() {
		int k = 0;
		data = " ";
		next = NULL;
		prev = NULL;
		up = NULL;
		down = NULL;
	}
};

class Queue {
public:
	string* queue_arr;
	int front, rear;
	int size;
	
	Queue() {
		size = 0;
		front = -1;
		rear = -1;
	}

	void setSize(int n) {
		size = n;
		queue_arr = new string[size];
	}

	bool isFull() {
		if (front == 0 && rear == size - 1) {
			return true;
		}
		return false;
	}

	bool isEmpty() {
		if (front == -1) return true;
		else return false;
	}
	void enqueue_copy_txt3(int x);
	string dequeue_paste_txt4() {
		string value;
		if (isEmpty()) {
			return("");
		}
		else {
			value = queue_arr[front];
			if (front >= rear) {
				front = -1;
				rear = -1;
			}
			else {
				front++;
			}
			return (value);
		}
	}

	void displayQueue()
	{
		int i=0;
		if (isEmpty()) {
			cout << endl << endl << "No Elements Copied" << endl;
		}
		else {
			for (i = front; i <= rear; i++)
				cout << queue_arr[i] << " ";
		}
	}
};
node* head;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
int count_total_Words_8() {
	int i = 0;
	node* temp = head;
	while (temp != NULL) {
		temp = temp->next;
		i++;
	}
	return i;
}
void open_insert_txt_1(string d) 
{
	node* n1 = new node(d);
	node* temp = head;
	node* ptr = head;
	int count1 = 0;
	if (head == NULL) 
	{
		head = n1;
	}
	else 
	{
		while (temp->next != NULL) 
		{
			temp = temp->next;
		}
		temp->next = n1;
		n1->prev = temp;
	}
	if (count_total_Words_8() > 5) 
	{
		node* temp2 = head;
		node* ptr2 = head;
		for (int i = 0; i < 5; i++)
		{
			temp2 = temp2->next;
		}
		while (temp2 != NULL)
		{
			ptr2->down = temp2;
			temp2->up = ptr2;
			temp2 = temp2->next;
			ptr2 = ptr2->next;
		}
	}
}

void delete_txt_2(int pos) {
	node* temp = head;
	node* tempDel = head;
	if (pos == 1) {
		head = head->next;
		head->prev = NULL;
	}
	else {
		if (pos > count_total_Words_8()) {
			cout << "Deletion out of bounds\n";
		}
		else {
			for (int i = 1; i < pos; i++)
			{
				tempDel = tempDel->next;
			}

			node* ptr = tempDel->prev;
			ptr->next = tempDel->next;
		}
	}
}

void Queue::enqueue_copy_txt3(int x) {
	if (isFull()) {
		cout << endl << "Queue is full!!";
	}
	else {
		if (front == -1) {
			front = 0;
		}
		rear++;
		node* temp = head;
		for (int i = 1; i < x; i++) {
			temp = temp->next;
		}
		queue_arr[rear] = temp->data;
	}
}


void split(string sentence) {
		string word = "";
		for (auto x : sentence) {
			if (x == ' ') {
				if(word!="~")
				open_insert_txt_1(word);
				word = "";
			}
			else {
				word = word + x;
			}
		}
		if (word != "~")
		open_insert_txt_1(word);
}

void view_print_txt_9() {
	node* temp = head;
	int i=0;
	while (temp != NULL) {
		if (i % 10 == 0) {
			cout << endl << endl;
		}
			i++;
			temp->key = i;
			cout << temp->data;
			SetConsoleTextAttribute(console, 02);
			cout << "(" << temp->key << ")" << " ";
			SetConsoleTextAttribute(console, 07);
			temp = temp->next;
		}
}

void print_Heading() { //Prints large 4D note pad text
	SetConsoleTextAttribute(console, 06);
	cout << "\t\t\b*************************************************************************************************\n";
	cout << "\t\t\b4    4   DDDDDD         NN     N    OOOO   TTTTTTT  EEEEEEE    PPPPPPP     AAAA    DDDDDD\n";
	cout << "\t\t\b4    4   D     D        N N    N   O    O     T     E         P       P   A    A   D     D\n";
	cout << "\t\t\b4    4   D      D       N  N   N   O    O     T     E         P       P   A    A   D      D\n";
	cout << "\t\t\b444444   D       D      N   N  N   O    O     T     EEEEEEE   PPPPPPPP    AAAAAA   D       D\n";
	cout << "\t\t\b     4   D      D       N    N N   O    O     T     E         P           A    A   D      D\n";
	cout << "\t\t\b     4   D     D        N     NN   O    O     T     E         P           A    A   D     D\n";
	cout << "\t\t\b     4   DDDDDD         N      N    OOOO      T     EEEEEEE   P           A    A   DDDDDD\n";
	cout << "\t\t\b*************************************************************************************************\n";
	cout << endl << endl;
	SetConsoleTextAttribute(console, 07);
}
int main() {
	Queue obj;
	int choice;
	string d;
	do {
		system("cls");
		print_Heading();
		cout << "\n\t\t\t\t\t-----------------------------------\n";
		cout << "\t\t\t\t\t|                                 |\n";
		cout << "\t\t\t\t\t|        Main Menu                |\n";
		cout << "\t\t\t\t\t|                                 |\n";
		cout << "\t\t\t\t\t| 0. Exit notepad                 |\n";
		cout << "\t\t\t\t\t| 1. Open notepad                 |\n";
		cout << "\t\t\t\t\t| 2. Delete text in notepad       |\n";
		cout << "\t\t\t\t\t| 3. Copy text in notepad         |\n";
		cout << "\t\t\t\t\t| 4. Paste text in notepad        |\n";
		cout << "\t\t\t\t\t| 5. Find text in notepad         |\n";
		cout << "\t\t\t\t\t| 6. Replace text in notepad      |\n";
		cout << "\t\t\t\t\t| 7. Undo text in notepad         |\n";
		cout << "\t\t\t\t\t| 8. Count total words in notepad |\n";
		cout << "\t\t\t\t\t| 9. View notepad                 |\n";
		cout << "\t\t\t\t\t|                                 |\n";
		cout << "\t\t\t\t\t-----------------------------------\n";
		cout << "\n Enter any option to proceed: ";
		cin >> choice;
		int count = 0;
		switch (choice) {
		case 0:
			SetConsoleTextAttribute(console, 04);
			cout << "\n\n   Entered '0', Exiting Program...\n\n";
			Sleep(1200);
			SetConsoleTextAttribute(console, 07);
			break;
		case 1:
			system("cls");
			SetConsoleTextAttribute(console, 02);
			cout << "\t\t*******************************************************************************\n";
			cout << "\t\tIII   NN     N   SSSSSS   EEEEEE   RRRRRR    TTTTTTT   III    OOOOO    NN     N\n";
			cout << "\t\t I    N N    N   S        E        R     R      T       I    O     O   N N    N\n";
			cout << "\t\t I    N  N   N   S        E        R     R      T       I    O     O   N  N   N\n";
			cout << "\t\t I    N   N  N   SSSSSS   EEEEEE   RRRRRR       T       I    O     O   N   N  N\n";
			cout << "\t\t I    N    N N        S   E        RR           T       I    O     O   N    N N\n";
			cout << "\t\t I    N     NN        S   E        R RR         T       I    O     O   N     NN\n";
			cout << "\t\tIII   N      N   SSSSSS   EEEEEE   R   RR       T      III    OOOOO    N      N\n";
			cout << "\t\t*******************************************************************************\n";
			cout << endl << endl;
			SetConsoleTextAttribute(console, 07);
			cout << " Enter '~' key on the next line to return to menu page...\n\n";
			cout << "Enter data in notepad:\n";
			cin.ignore();
			while (d != "~") {
				getline(cin, d);
				split(d);
			}
			system("cls");
			break;
		case 2:
			system("cls");
			SetConsoleTextAttribute(console, 04);
			cout << "\t\t*****************************************************************************\n";
			cout << "\t\tDDDDDD      EEEEEEE   L		EEEEEEE   TTTTTTT   III    OOOOO    NN     N\n";
			cout << "\t\tD     D     E         L         E            T       I    O     O   N N    N\n";
			cout << "\t\tD      D    E         L         E            T       I    O     O   N  N   N\n";
			cout << "\t\tD       D   EEEEEEE   L		EEEEEEE      T       I    O     O   N   N  N\n";
			cout << "\t\tD      D    E         L         E            T       I    O     O   N    N N\n";
			cout << "\t\tD     D     E         L         E            T       I    O     O   N     NN\n";
			cout << "\t\tDDDDDD      EEEEEEE   LLLLLLL   EEEEEEE      T      III    OOOOO    N      N\n";
			cout << "\t\t*****************************************************************************\n";
			cout << endl << endl;
			SetConsoleTextAttribute(console, 07);
			int pos;
			cout << endl;
			view_print_txt_9();
			cout << "Enter which position of element u want to delete: ";
			cin >> pos;
			if (count_total_Words_8()<1) {
				cout << "\n\nThere is no element in notepad remaining!\n";
				break;
			}
			delete_txt_2(pos);
			view_print_txt_9();
			cout << endl;
			cout << endl;
			system("pause");
			break;
		case 3:
			system("cls");
			SetConsoleTextAttribute(console, 06);
			cout << "\t\t********************************************************************************\n";
			cout << "\t\t CCCCCC    OOOO    PPPPPPPP    Y     Y    TTTTTTT   EEEEEEE   X     X   TTTTTTT \n";
			cout << "\t\tC         O    O   P       P   Y     Y       T      E         X     X      T    \n";
			cout << "\t\tC         O    O   P       P   Y     Y       T      E          X   X       T    \n";
			cout << "\t\tC         O    O   PPPPPPPP     YYYYY        T      EEEEEEE      X         T    \n";
			cout << "\t\tC         O    O   P              Y          T      E          X   X       T    \n";
			cout << "\t\tC         O    O   P              Y          T      E         X     X      T    \n";
			cout << "\t\t CCCCCC    OOOO    P              Y          T      EEEEEEE   X     X      T    \n";
			cout << "\t\t********************************************************************************\n";
			cout << endl << endl;
			SetConsoleTextAttribute(console, 07);
			cout << endl;
			view_print_txt_9();
			cout << endl;
			while (!obj.isEmpty()) {
				obj.dequeue_paste_txt4();
			}
			int tot, x;
			cout << "\nEnter total words you want to copy: ";
			cin >> tot;
			obj.setSize(tot);
			count = count_total_Words_8();
			//cout << "total words" << count;
			if (tot <= count && tot != 0) {
				cout << endl;
				for (int i = 0; i < tot; i++) {
					cout << "Enter key value to copy a certain word: "; //Enter here the green integer value which you see in the notepad to copy
					cin >> x;
					obj.enqueue_copy_txt3(x);
					SetConsoleTextAttribute(console, 03);
					cout << i + 1 << "th word copied SUCCESSFULLY!\n\n";
					SetConsoleTextAttribute(console, 07);
				}
			}
			else {
				SetConsoleTextAttribute(console, 04);
					cout << "\nThe word you want to copy does not EXIST!\n\n";
					cout << "Program returning back to main menu...\n\n";
					SetConsoleTextAttribute(console, 07);
				Sleep(4000);
				break;
			}
			SetConsoleTextAttribute(console, 06);
			cout << "The Copied Words are ==> ";
			obj.displayQueue();
			SetConsoleTextAttribute(console, 07);
			cout << endl << endl;
			system("pause");
			break;
		case 4:
			system("cls");
			SetConsoleTextAttribute(console, 01);
			cout << "\t\t*******************************************************************************************\n";
			cout << "\t\tPPPPPPPP     AAAA    SSSSSS   TTTTTTT   EEEEEEE      TTTTTTT   EEEEEEE   X     X   TTTTTTT \n";
			cout << "\t\tP       P   A    A   S           T      E               T      E         X     X      T    \n";
			cout << "\t\tP       P   A    A   S           T      E               T      E          X   X       T    \n";
			cout << "\t\tPPPPPPPP    AAAAAA   SSSSSS      T      EEEEEEE         T      EEEEEEE      X         T    \n";
			cout << "\t\tP           A    A        S      T      E               T      E          X   X       T    \n";
			cout << "\t\tP           A    A        S      T      E               T      E         X     X      T    \n";
			cout << "\t\tP           A    A   SSSSSS      T      EEEEEEE         T      EEEEEEE   X     X      T    \n";
			cout << "\t\t*******************************************************************************************\n";
			cout << endl << endl;
			SetConsoleTextAttribute(console, 07);
			int x1, x2;
			SetConsoleTextAttribute(console, 06);
			cout << "The Copied Words are ==> ";
			obj.displayQueue();
			SetConsoleTextAttribute(console, 07);
			if (obj.isEmpty()) {
				SetConsoleTextAttribute(console, 04);
				cout << "\nNO ELEMENTS FOUND TO PASTE!\n\n";
				cout << "Program returning back to main menu...\n\n";
				SetConsoleTextAttribute(console, 07);
				Sleep(4000);
				break;
			}
			view_print_txt_9();
			cout << "\n\nEnter 2 Adjacent Key values(Greater than 0) in between which you want to paste the Copied Words(in Ascending Order): \n";
			cin >> x1 >> x2;
			while ((x1 <= 0) || (x2 <= 0)) {
				cout << "\nEnter 2 Adjacent Key values(Greater than 0) in between which you want to paste the Copied Words(in Ascending Order): \n";
				cin >> x1 >> x2;
			}
			while (x1 > x2) {
				cout << "\nEnter 2 Adjacent Key values(Greater than 0) in between which you want to paste the Copied Words(in Ascending Order): \n";
				cin >> x1 >> x2;
			}
			if (((x1 < 1) || (x1 > count_total_Words_8())) && ((x2 < 1) || (x2 > count_total_Words_8()))) {
				SetConsoleTextAttribute(console, 04);
				cout << "\nThe key values OUT OF BOUND!\n\n";
				cout << "Program returning back to main menu...\n\n";
				SetConsoleTextAttribute(console, 07);
				Sleep(4000);
				break;
			}
			else if (x2 != x1 + 1) {
				while (x2 != x1 + 1) {
					cout << "\nEnter 2 Adjacent Key values(Greater than 0) in between which you want to paste the Copied Words(in Ascending Order): \n";
					cin >> x1 >> x2;
				}
			}
			else {
				/*if(count_total_Words_8())*/
			}
			cout << endl;
			cout << endl;
			system("pause");
			break;
		case 5:
			cout << "find text notepad\n\n";
			break;
		case 6:
			cout << "replace text notepad\n\n";
			break;
		case 7:
			cout << "undo text notepad\n\n";
			break;
		case 8:
			system("cls");
			SetConsoleTextAttribute(console, 02);
			cout << "\t\t*******************************************************************************\n";
			cout << "\t\tTTTTTTT    OOOOO    TTTTTTT    AAAAA    L         W         W    OOOOO    RRRRRR    DDDDDD                \n";
			cout << "\t\t   T      O     O      T      A     A   L         W         W   O     O   R     R   D     D              \n";
			cout << "\t\t   T      O     O      T      A     A   L         W         W   O     O   R     R   D      D               \n";
			cout << "\t\t   T      O     O      T      AAAAAAA   L         W    W    W   O     O   RRRRRR    D       D              \n";
			cout << "\t\t   T      O     O      T      A     A   L         W   W W   W   O     O   RR        D      D                \n";
			cout << "\t\t   T      O     O      T      A     A   L         W   W W   W   O     O   R RR      D     D                  \n";
			cout << "\t\t   T       OOOOO       T      A     A   LLLLLLL    WWW   WWW     OOOOO    R   RR    DDDDdD                   \n";
			cout << "\t\t*******************************************************************************\n";
			cout << endl << endl;
			SetConsoleTextAttribute(console, 07);
			cout << count_total_Words_8();
			cout << endl;
			system("pause");
			break;
		case 9:
			system("cls");
			print_Heading();
			cout << endl;
			view_print_txt_9();
			cout << endl << endl;
			system("pause");
			break;
		default:
			cout << "Invalid Entry!\n";
		}
	} while (choice != 0);
	return 0;
}