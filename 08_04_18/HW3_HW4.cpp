#include <iostream>
#include <cstdlib>
#include <ctime>

/*
Задача 3. Реализовать структуру данных Бинарная Куча на массиве
Попыталась использовать templates: для типа long все работает.
Реализованы следующие методы класса THeap:
	getSize - возвращает количество элементов;
	getMax - возвращает максимальный ключ;
	add - добавить элемент в кучу;
	heapify - упорядочить кучу вниз, начиная с node t;
	extractMax - удалить максимальный элемент;
	changeKey - изменить значение ключа на заданном элементе;
	merge - объединить кучи;
	show - вывести первые N элементов на экран;
Задача 4. Реализовать Пирамидальную Сортировку на определенной в задаче 3 куче.
Сортировка реализована в процедуре testSort:
    - сначала формируется куча из заданного массива путем добавления
      каждого элемента методом класса add.
    - Затем в цикле методом класса extractMax из кучи
      забирается (с удалением) максимальный элемент. 
      Куча каждый раз упорядочивается.
      Фиксируется время на создание и сортировку кучи.
*/


// Класс бинарная куча на массиве
template <typename T> 
class THeap{
   public:	
    T *tree;  //дерево в массиве
    bool isNew;  // выделяли ли массив 
    long len; // размер массива
    long cnt; // число элементов
	THeap(long N);  // конструктор. N - размер массива
	THeap(T *a, long N);  // конструктор. a - готовый массив, N - размер массива
	~THeap();      // деструктор
	T getSize();  // return cnt
	void add(T t); // добавить элемент в кучу
	T extractMax(); // удалить максимальный элемент
	T getMax(); // return max
	void merge(THeap &heap);  // объединить кучи
	void changeKey(long ind, T key); // изменить значение ключа 
	void heapify(long i); // Упорядочить кучу вниз, начиная с i-го элемента
	void show(long N);  //вывести первые N элементов
};

// конструктор
template <typename T>
THeap <T> ::THeap(long N){
	tree = new T [N];  //Выделяяем память для N элементов типа Т
	len = N;
	cnt = 0;
	isNew = true;  // cами выделили память
}
// конструктор. a - готовый массив, N - размер массива
template <typename T>
THeap <T> ::THeap(T *a, long N){
	isNew = false;  // не надо освобождать память
	cnt = N;
	len = N;
	tree = a;
	// упорядочиваем, начиная с родителя последнего элемента
	for( long i = cnt/2; i >= 0; i--){
		heapify(i);
	}
}
// деструктор
template <typename T>
THeap <T>::~THeap(){
	if( isNew ) delete [] tree; // если выделяли память
}

// возвращает число элементов
template <typename T>
T THeap <T>::getSize(){
	return cnt;
}

// Упорядочиваем массив, начиная с i-го элемента
template <typename T>
void THeap <T>::heapify(long i){
	// i - родитель
	long l = 2*i + 1;  // левый потомок
	long r = 2*i + 2;  // правый потомок
	long largest;

	// Выбираем наибольшего потомка
	if( l < cnt && tree[l] > tree[i] ) largest = l;
	else largest = i;
	if( r < cnt && tree[r] > tree[largest] ) largest = r;
	// Меняем местами родителя и наибольшего потомка
	if( largest != i ){
		T tmp = tree[i];
		tree[i] = tree[largest];
		tree[largest] = tmp;
		heapify(largest);  // повторяем процедуру
	}
}

// добавить элемент в кучу
template <typename T>
void THeap <T>::add(T t){
	tree[cnt] = t;   // t- в конец массива
	long i = cnt;    
	long parent = (i-1)/2;  //индекс родителя
	cnt++;
	// двигаем эл-т вверх
	while( i > 0 && tree[parent] < tree[i]){
		T tmp = tree[i];
		tree[i] = tree[parent];
		tree[parent] = tmp;
		i = parent;
		parent = (i - 1) >> 1; // /2;
	}
}
// Удаляем максимальный элемент 
template <typename T>
T THeap <T>::extractMax(){
	T tmp = tree[0]; // max элемент всегда первый в массиве
// извлечь максимальный элемент
	tree[0] = tree[cnt-1];  // вместо первого ставим последний
	cnt--;  // число элементов -1
	heapify(0);  // упорядочиваем
	return tmp;
}

// return максимальный элемент
template <typename T>
T THeap <T>::getMax(){
	return tree[0];
}
// изменить значение ключа 
template <typename T>
void THeap <T>::changeKey(long ind, T key){
	if( tree[ind] == key ) return;
	if(tree[ind] > key ){
		tree[ind] = key;
		heapify(ind); // упорядочиваем вниз дерева
	} else{
		tree[ind] = key;
		while( ind > 0 && tree[(ind-1) >> 1]  < key ){
			//std::cout << ind << ' ' << tree[ind] << std::endl;
			tree[ind] = tree[(ind-1) >> 1]; // Сдвигаем родителя вниз
			tree[(ind-1) >> 1] = key;
			ind = (ind-1) >> 1;
		}
	}
}
// объединить кучи
template <typename T>
void THeap <T>::merge(THeap &heap){
	long N = heap.getSize();
	if( N == 0) return;
	//Заводим новый массив и переписываем все элементы
	T *h = new T [cnt+N];
	for( long i = 0; i < cnt; i++) h[i] = tree[i];
	delete [] tree;
	// добавляем по очереди элементы из heap
	cnt += N;
	tree = h;
	for( long i = 0; i < N; i++){
		add( heap.extractMax() );
	}
}
// вывести первые N элементов
template <typename T>
void  THeap <T>::show(long N){
	long pw2 = 2;
	for( long i = 0; i < N; i++){
		if( i+1 == pw2){
		  std::cout << std::endl;
		  pw2 *= 2;  // следующий раз для endl
		}
		std::cout << tree[i] << " ";
	}
	std::cout << std::endl;
}

///////////////////////////////////////////////////////////////////////////

//Тест процедуры Add новый элемент
void testAdd(long N){
	std::cout << "////// Test Add ///////" << std::endl;

	THeap <long> tree = THeap <long> (N);
	unsigned long start_time =  clock(); // начальное время
	for( long i = 0; i < N; i++){
		tree.add(i);
	}
	unsigned long end_time = clock(); // конечное время
	unsigned long time = end_time - start_time;
	if(N < 32) tree.show(N);
	std::cout << "time=" << ' ' << time <<std::endl;
}

// Тест процедуры Heapify. 
void testHeapify(long *a, long N){
	std::cout << "////// Test Heapify ///////" << std::endl;

	//создаем кучу из массива. 
	// В конструкторе работает процедура Heapify
	unsigned long start_time =  clock(); // начальное время
	THeap <long> tree = THeap <long> (a, N);

	unsigned long end_time = clock(); // конечное время
	unsigned long time = end_time - start_time;
	std::cout << "time=" << ' ' << time <<std::endl;
	if(N < 32) tree.show(N);
}

// Тест Extract Max element
void testExtractMax(long *a, long N){
	std::cout << "////// Test Extract Max ///////" << std::endl;

	// make heap
	THeap <long> tree = THeap <long> (a, N);
	if(N < 32) tree.show(N);
	tree.extractMax();	
	if(N < 32) tree.show(N);
	tree.extractMax();	
	if(N < 32) tree.show(N);
}

// Тест сортировки
void testSort(long *a, long N){
	std::cout << "////// Test Sort ///////" << std::endl;

	// heap
	THeap <long> tree = THeap <long> (a, N);

	unsigned long start_time =  clock(); // начальное время
	for( long i = 0; i < N; i++){
		a[N-i-1] = tree.extractMax();
	}	
	unsigned long end_time = clock(); // конечное время
	long time = end_time - start_time;
	//for( long i=0; i< N; i++){
	//	std::cout << a[i] <<std::endl;
	//}
	std::cout << "time=" << ' ' << time <<std::endl;
}
// Тест changeKey
void testChange(long N, long ind, long key){
	std::cout << "////// Test Change Key " << ind << ' ' << key << std::endl;

	THeap <long> tree = THeap <long> (N);
	for( long i = 0; i < N; i++){
		tree.add(i);
	}
	if(N < 32) tree.show(N);
	tree.changeKey(ind, key);
	if(N < 32) tree.show(N);
}

//////////////////////////////////
int main(int argc, char** argv) {
	long N = 500000;
	long a[N];
/*
	testAdd(N);
	testChange(N, 13, 3);	

	for( long i = 0; i < N; i++){
		a[i] = i;
	}
	testHeapify(a, N);
	testExtractMax(a, N);
*/	
	for( long i = 0; i < N; i++){
		a[i] = rand() % 1000;
	}
	testSort(a, N);
	
		
	system("pause");
	return 0;
}
