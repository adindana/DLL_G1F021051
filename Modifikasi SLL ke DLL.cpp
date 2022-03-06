#include<iostream>
using namespace std;

struct Sepatu{
	string merek, ukuran;
	int warna;
	Sepatu *prev;
	Sepatu *next;
	
};

	Sepatu *head, *tail, *cur, *newNode, *del, *before;
	
	//create Double Linked List
	void createDoubleLinkedList(string merek, string ukuran, int warna) {
		head = new Sepatu();
		head->merek = merek;
		head->ukuran = ukuran;
		head->warna = warna;
		head->prev=NULL;
		head->next=NULL;
		tail = head;
	}
	
		//count Double Linked List
	int countDoubleLinkedList() {
			if (head == NULL) {
				cout<<"Double Linked List Belum Dibuat";
			} else {
				cur = head;
				int jumlah = 0;
				while (cur != NULL) {
					jumlah++;
				cur= cur->next;
			}
			return jumlah;
		}
	}
	
	//add first Double Linked List
	void addfirst(string merek, string jenis, string tipe, int harga) {
		if (head == NULL) {
				cout<<"Double Linked List Belum Dibuat";
		} else {
		newNode = new Sepatu();
		newNode->merek = merek;
		newNode->ukuran = ukuran;
		newNode->warna = warna;
		newNode->prev=NULL;
		newNode->next=head;
		head->prev=newNode;
		head=newNode;
		}
	}
	
	//add last Double Linked List
	void addlast(string merek, string jenis, string tipe, int harga) {
		if (head == NULL) {
				cout<<"Double Linked List Belum Dibuat";
		} else {
		newNode = new Sepatu();
		newNode->merek = merek;
		newNode->ukuran = ukuran;
		newNode->warna = warna;
		newNode->prev=tail;
		newNode->next=NULL;
		tail->next=newNode;
		tail=newNode;
		}
	}
	
	//add middle Double Linked List
	void addmiddle(string merek, string jenis, string tipe, int harga, int posisi) {
			if (head == NULL) {
				cout<<"Double Linked List Belum Dibuat";
		} else {
			if (posisi == 1) {
				cout<<"Posisi 1 itu bukan posisi tengah"<<endl;
			} else if (posisi < 1 || posisi > countDoubleLinkedList() ) {
				cout<<"Posisi diluar jangkauan"<<endl;
			} else {
				newNode = new Sepatu();
				newNode->merek = merek;
				newNode->ukuran = ukuran;
				newNode->warna = warna;
				newNode->prev=tail;
				newNode->next=NULL;
				
				//tranversing
				cur = head;
				int nomor = 1;
				while (nomor < posisi - 1) {
					cur = cur->next;
					nomor++;
					}
					afterNode = cur->next;
					newNode->prev=cur;
					newNode->next=afterNode;
					cur->next=newNode;
					afterNode->prev=newNode;
			}
		}
	}

		//delete first
	void deletefirst() {
		if (head == NULL) {
				cout<<"Double Linked List Belum Dibuat";
		} else {
		del=head;
		head=head->next;
		head->prev=NULL;
		delete del;
		}	
	}
	
	//delete last
	void deletelast() {
		if (head == NULL) {
				cout<<"Double Linked List Belum Dibuat";
		} else {
		del=tail;
		tail=tail->prev;
		tail->next=NULL;
		delete del;
		}	
	}
	
	//delete middle
	void deletemiddle(int posisi) {
		if (head == NULL) {
				cout<<"Double Linked List Belum Dibuat";
		} else {
			if (posisi ==1 || posisi == countDoubleLinkedList() ) {
				cout<<"Posisi  bukan posisi tengah"<<endl;
			} else if (posisi < 1 || posisi > countDoubleLinkedList() ) {
				cout<<"Posisi diluar jangkauan"<<endl;
			} else {
				int nomor =1;
				cur = head;
				while (nomor < posisi - 1) {
					cur = cur->next;
					nomor++;
				}
				del = cur->next;
				afterNode=del->next;
				cur->next = afterNode;
				afterNode->prev = cur;
				delete del;
			}
		}
	}
	
	//print Double Linked List
	void printDoubleLinkedList() {
			if (head == NULL) {
				cout<<"Double Linked List Belum Dibuat";
			} else {
				cout<<"Jumlah Data : "<<countDoubleLinkedList()<<endl;
				cout<<"Isi Data : "<<endl;
				cur = head;
				while (cur != NULL) {
				cout << "Merek Sepatu   : "<< cur->merek<<endl;
				cout << "ukuran Sepatu    : "<< cur->ukuran<<endl;
				cout << "warna Sepatu : "<< cur->warna<<endl;
				
				cur= cur->next;
			}
		}
	}

	int main() {
	
	createDoubleLinkedList("Adidas", "Rudolf Dassler", 1920);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	addfirst(Nike", "Philip knight", 1964);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	addlast("Acisc", "Kihachiro", 1949);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	addmiddle("Reebook", "J.W.Foster", 1895, 2); //menambahakan data baru di posisi ke-2
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	/*deletefirst();
	printDoubleLinkedList();
	
	deletelast();
	printDoubleLinkedList();
	
	deletemiddle(3); //menghapus data pada posisi ke-3
	printDoubleLinkedList(); */
	
}
