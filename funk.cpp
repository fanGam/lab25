#include <iostream>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;

struct Node {
	int ID;
	int x;
	Node* Next, * Prev;
};

typedef Node* Pnode;

void AddEnd(int ids, int data, Pnode& Head, Pnode& LastNode) {
	Pnode MyNode;
	if (Head == NULL) {
		Head = new Node;
		LastNode = Head;
		Head->Next = NULL;
		Head->Prev = NULL;
	}
	else {
		MyNode = new Node;
		LastNode->Next = MyNode;
		MyNode->Prev = LastNode;
		MyNode->Next = NULL;
		LastNode = MyNode;
	}
	LastNode->x = data;
	LastNode->ID = ids;
}

void AddAfter(Pnode& PrevNode, Pnode& NextNode, Pnode& NewNode) {
	NewNode->Next = NextNode;
	PrevNode->Next = NewNode;
	NextNode->Prev = NewNode;
	NewNode->Prev = PrevNode;
}

void ShowAndDestroy(Pnode& Head) {
	Pnode MyNode;
	//Head->Prev->Next = NULL;
	while (Head != NULL) {
		MyNode = Head;
		cout << Head->ID << " " << Head->x << " " << Head->Next << endl;
		Head = Head->Next;
		delete MyNode;
	}
}

void ShowOnly(Pnode Head) {
	Pnode MyNode = Head;
	while (MyNode != NULL) {
		cout << MyNode->ID << " " << MyNode->x  << " " << MyNode->Next << endl;
		MyNode = MyNode->Next;
	}
}

void Destroyer(Pnode& Head) {
	Pnode MyNode;
	while (Head != NULL) {
		MyNode = Head;
		Head = Head->Next;
		delete MyNode;
	}
}

void MakeCycle(Pnode& Head, Pnode& LastNode) {
	LastNode->Next = Head;
	Head->Prev = LastNode;
}

void DeleteAfter(Pnode& MyNode) {
	MyNode->Next = MyNode->Next->Next;
	MyNode->Next->Next->Prev = MyNode;
	delete MyNode->Next;
}

void ListWorker1(Pnode Head, Pnode LastNode) {
	bool Done = true;
	Pnode Worker = Head;
	Pnode Buff;
	while (Worker) {
		if (Worker->Next == Head) {
			if (Done == false) {
				break;
			}
			Done = false;
		}
		if ((Worker->Prev->x) == (Worker->Next->x)) {
			Buff = Worker;
			Buff = Buff->Prev;
			Buff->Next = Worker->Next;
			Buff = Worker;
			Buff = Buff->Next;
			Buff->Prev = Worker->Prev;
			delete Worker;
			Worker = Buff;
			Done = true;
		}
		Worker = Worker->Next;
	}
}

void ListWork42() {
	int N;
	Pnode Head = NULL, LastNode = NULL;
	cout << "How many numbers do you want?" << endl;
	cout << "-> ";
	cin >> N;
	for (int i = 0; i < N; i++) {
		AddEnd(i, rand() % 10, Head, LastNode);
	}
	ShowOnly(Head);
	cout << "-------------------" << endl;
	MakeCycle(Head, LastNode);
	ListWorker1(Head, LastNode);
	ShowAndDestroy(Head);
}

void DoubleSwap(Pnode& Worker) {
	Pnode WorkerBef = Worker->Prev;
	Pnode WorkerBefBef = Worker->Prev->Prev;
	Pnode WorkerAft = Worker->Next;

	Worker->Prev = WorkerBefBef;
	WorkerBefBef->Next = Worker;
	Worker->Next = WorkerBef;
	WorkerBef->Prev = Worker;

	WorkerBef->Next = WorkerAft;
	WorkerAft->Prev = WorkerBef;
	WorkerBef->Prev = Worker;
}

void ListWorker2(Pnode Head) {
	Pnode Worker = Head;
	while (Worker != NULL) {
		if ((Worker->ID > 1) && ((Worker->ID % 2) == 1)) {
			while (Worker->Prev->ID % 2 == 0) {
				DoubleSwap(Worker);
				/*Worker->Next->Prev = Worker->Prev;
				Worker->Prev->Next = Worker->Next;
				Worker->Prev->Prev->Next = Worker;
				Worker->Prev = Worker->Prev->Prev;
				Worker->Next = Worker->Next->Prev;
				Worker->Next->Prev->Prev = Worker;*/
			}
		}
		Worker = Worker->Next;
	}
}

void ListWork43() {
	Pnode Head = NULL, LastNode;
	int N;
	cout << "How many numbers do you want?" << endl;
	cout << "-> ";
	cin >> N;
	for (int i = 0; i < N; i++) {
		AddEnd(i, rand() % 10, Head, LastNode);
	}
	ShowOnly(Head);
	cout << "--------------" << endl;
	ListWorker2(Head);
	ShowAndDestroy(Head);
}

void FileBackDouble(Pnode& Head) {
	Pnode MyNode;
	ofstream f1;
	f1.open("numbers.txt");
	while (Head->Next != NULL) {
		Head = Head->Next;
	}
	while (Head != NULL) {
		f1 << " " << Head->x;
		MyNode = Head;
		Head = Head->Prev;
		delete MyNode;
	}
}

void ListWork63() {
	Pnode Head = NULL, LastNode = NULL;
	int N;
	cout << "How many numbers do you need?" << endl;
	cout << "-> ";
	cin >> N;
	for (int i = 0; i < N; i++) {
		AddEnd(i, rand() % 10, Head, LastNode);
	}
	ShowOnly(Head);
	cout << "--------------" << endl;
	FileBackDouble(Head);
}