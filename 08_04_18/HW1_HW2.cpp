#include <iostream>
#include <cstdlib>
#include <ctime>

/*
Задача 1. Реализовать структуру данных Бинарная Куча на Бинарном Дереве
Реализованы следующие методы класса THeap:
	swapNodes - поменять местами два node;
	getSize - возвращает количество элементов;
	getMax - возвращает максимальный ключ;
	add - добавить элемент в кучу;
	heapify - упорядочить кучу вниз, начиная с node t;
	extractMax - удалить максимальный элемент;
	changeKey - изменить значение ключа на заданном элементе;
	merge - объединить кучи;
	show - вывести первые N элементов на экран;
Задача. Реализовать Пирамидальную Сортировку на определенной в задаче первой куче.
Сортировка реализована в процедуре testSort:
    - сначала формируется куча из заданного массива путем добавления
      каждого элемента методом класса add.
    - затем в цикле методом класса extractMax из кучи
      забирается (с удалением) максимальный элемент. 
      Куча каждый раз упорядочивается.
      Фиксируется время на создание и сортировку кучи.
*/

// Класс бинарная куча на бинарном дереве
struct TNode{
  long key;
  TNode *left; 
  TNode *right;
  TNode *parent;
  TNode *next;   // следущий в списке
  TNode *prev;   // предыдущий в списке
};

class THeap{
   public:	
    TNode *tree;  //дерево в массиве
    TNode * last; // указатель на последний элемент
    long cnt; // число элементов
	THeap();  // конструктор
	~THeap();      // деструктор
	void swapNodes(TNode *p1, TNode *p2); // поменять местами
	long getSize(){ return cnt;};  // return cnt
	long getMax(){ return tree->key;}; // return max
	void add(long t); // добавить элемент в кучу
	void heapify(TNode *t); // упорядочить кучу вниз, начиная с node t
	long extractMax(); // удалить максимальный элемент
	void changeKey(long ind, long key); // изменить значение ключа 
	void merge(THeap &heap);  // объединить кучи
	void show(long N);  //вывести первые N элементов
};

// конструктор
THeap::THeap(){
	tree = NULL;  
	cnt = 0;
	last = NULL;
}
// деструктор
THeap::~THeap(){
	while( tree){
      	TNode *p = tree;
      	tree = tree->next;
        delete p; // 
    }
}

// поменять местами 
void THeap::swapNodes(TNode *p1, TNode *p2){
	long t = p1->key;
	p1->key = p2->key;
	p2->key = t;
}

// добавить элемент в кучу
void THeap::add(long t){
    TNode *p;
    p = new TNode;
    p->parent = p->left = p->right = p->next = p->prev = NULL;
    p->key = t;
    cnt++;
    if( cnt == 1 ){ // самый первый элемент
       tree = p;
       last = p;
       return;
    }
    if( cnt == 2 ){ // второй элемент
       tree->left = p;
       tree->next = p;
       p->prev = tree;
       last = p;
       p->parent = tree;
       if( tree->key < p->key) swapNodes(tree, p);
       return;
    }
    //ищем родителя для нового элемента
    p->prev = last;
    TNode *pp = last->parent; //родитель последнего элемента
    last->next = p;
    last = p;
    if( cnt % 2 != 0 ){  // родитель тот же как и у элемента last
    	pp->right = p;
    }else{
    	pp = pp->next;   // родитель будет следующий элемент за parent'ом
    	pp->left = p;
    }    
	p->parent = pp;
	// двигаем элемент, вверх если надо
	while( pp != NULL && pp->key < p->key){
		swapNodes(p, pp);
		p = pp;
		pp = pp->parent;
	}
}

// Упорядочиваем heap вверх, начиная с  элемента pp
void THeap::heapify(TNode *pp){
	// i - родитель
	TNode *l = pp->left;  // левый потомок
	TNode *r = pp->right;  // правый потомок
	TNode *largest;
	// Выбираем наибольшего потомка
	if( l != NULL && l->key > pp->key ) largest = l;
	else largest = pp;
	if( r != NULL && r->key > largest->key ) largest = r;
//std::cout << pp->key << " === " << largest->key << std::endl;
	// Меняем местами ключи родителя и наибольшего потомка
	if( largest != pp ){
				//std::cout << pp->key << " === " << largest->key << std::endl;
		swapNodes(largest, pp);
		heapify(largest);  // повторяем процедуру
	}
}

// Удаляем максимальный элемент 
long THeap::extractMax(){
	long tmp = tree->key; // max element всегда первый в массиве
	cnt--;
	if(cnt == 0){
	  delete tree;
	  tree = NULL;
	  return tmp;
	}	
	tree->key = last->key;  // заменили ключ в корне
	TNode *p = last->parent; // parent
	TNode *pp = last->prev;  // предыдущий
	pp->next = NULL;  //  последний в списке
	delete last;
	last = pp;  //
// извлечь максимальный элемент
	if( p->right != NULL){ //удалили правый элемент 
	   p->right = NULL;
	}else{
	   p->left = NULL;
	}
	if( cnt > 1) heapify(tree);  // упорядочиваем
	return tmp;
}

// изменить значение ключа
void THeap::changeKey(long ind, long key){
	if( ind >= cnt) return;
	TNode *p = tree;
	for( long i = 0; i < ind-1; i++){
		p = p->next;
	}
	if( p->key == key ) return;
	if(p->key > key ){
		p->key = key;
		heapify(p); // упорядочиваем вниз дерева
	} else{
		p->key = key;
		TNode *pp = p->parent;
		while( pp != NULL && pp->key < p->key){
			swapNodes(p, pp);
			p = pp;
			pp = pp->parent;  // тянем большее вверх 
		}
	}
}

void THeap::merge(THeap &heap){  // объединить кучи
	TNode *p = heap.tree;
	while(p != NULL){
		add(p->key);
		p = p->next;
	}
}

// вывести первые N элементов
void  THeap::show(long N){
	long pw2 = 2;
	TNode *p = tree;
	int i = 0;
	while( p != NULL){
		if( i+1 == pw2){
		  std::cout << std::endl;
		  pw2 *= 2;  // следующий раз для endl
		}
		std::cout << p->key << " ";
		p = p->next;
		i++;
	}
	std::cout << std::endl;
}

///////////////////////////////////////////////////////////////////////////

//Тест процедуры Add новый элемент
void testAdd(long N){
	std::cout << "////// Test Add ///////" << std::endl;

	THeap tree = THeap();
	unsigned long start_time =  clock(); // начальное время
	for( long i = 0; i < N; i++){
		tree.add(i);
		//std::cout << "====" << std::endl;
	}
	unsigned long end_time = clock(); // конечное время
	unsigned long time = end_time - start_time;
	if(N < 32) tree.show(N);
	std::cout << "time=" << ' ' << time <<std::endl;
}

// Тест Extract Max element
void testExtractMax(long N){
	std::cout << "////// Test Extract Max ///////" << std::endl;

	// make heap
	THeap tree = THeap();
	for( long i = 0; i < N; i++){
		tree.add(i);
		//std::cout << "====" << std::endl;
	}
	if(N < 32) tree.show(N);
	tree.extractMax();	
	if(N < 32) tree.show(N);
	//tree.extractMax();	
	//if(N < 32) tree.show(N);
}

// Тест changeKey
void testChange(long N, long ind, long key){
	std::cout << "////// Test Change Key " << ind << ' ' << key << std::endl;

	THeap tree = THeap();
	for( long i = 0; i < N; i++){
		tree.add(i);
	}
	if(N < 32) tree.show(N);
	tree.changeKey(ind, key);
	if(N < 32) tree.show(N);
}

// Тест сортировки
void testSort(long *a, long N){
	std::cout << "////// Test Sort ///////" << std::endl;

	// heap
	THeap tree = THeap();
	unsigned long start_time =  clock(); // начальное время
	for(long i = 0; i < N; i++){
		tree.add( a[i] );
		//std::cout << a[i] <<std::endl;
	}
	for( long i = 0; i < N; i++){
		a[N-i-1] = tree.extractMax();
		//std::cout << a[N-i-1] <<std::endl;
	}	
	unsigned long end_time = clock(); // конечное время
	long time = end_time - start_time;
	//for( long i=0; i< N; i++){
		//std::cout << a[i] <<std::endl;
	//}
	std::cout << "time=" << ' ' << time <<std::endl;

}

//////////////////////////////////
int main(int argc, char** argv) {
	long N = 500000;
	long a[N];
/*
	testAdd(N);
	testExtractMax(N);
    testChange(25,12,5);
*/	
	for( long i = 0; i < N; i++){
		a[i] = rand() % 1000;
	}
	testSort(a, N);
	
		
	system("pause");
	return 0;
}
