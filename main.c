//----------------------------------------------------
//АНТИДЕМИН LITE

//проверяем строку на не латинские буквы
int check(char* str){ 
    int flag = 0;

    for (int i = 0; i < strlen(str); i++){
        if (!(('a' <= str[i] && str[i] <= 'z')  || str[i]==' ')){
            flag = 1;
            break;
        }
    }
    return flag;
}


//функция для замены \n на \0 в конце слова
void replace(char * word){
    for(int i=0; i<strlen(word);i++){
        if (word[i]=='\n'){word[i]='\0';}
    }
}//вызов: replace(word);


//функция считывает все лишние символы после слова
void eater(char* word){    
    char* pn = strchr(word, '\n');  //ищем \n в слове
    if (pn == NULL && strlen(word)!=0) {        //если нет \n в слове и его длина не 0, то получаем символы
        while((getchar())!='\n');
    }
}//вызов: eater(word);


//----------------------------------------------------
//ПОЛЕЗНОЕ ДЛЯ СОРТИРОВОК


//структура
typedef struct{
    char name[20];
    char color[20];
    char country[20];
    int count;
}flower;


//функция, которая переворачивает отсортированный список
void reverse(flower * array, int end){
    flower temp;
    int start=0; 
    while(start < end){ 
        temp = array[start]; 
        array[start] = array[end]; 
        array[end] = temp; 
        start++; 
        end--; 
    } 
}


//сравнивает структуры, возвращает: 1, если результат str1 > str2; 0, если = ; -1, если <
int comparator(flower struct_1,flower struct_2){
    int flag=-1;

    int cmp = strcmp(struct_1.name, struct_2.name);
    if (cmp > 0){//сравниваем названия
        flag=1;}
    
    else if(cmp == 0){//если они одинаковые, то сравниваем цвета

        cmp = strcmp(struct_1.color, struct_2.color);
        if (cmp > 0){
        flag=1;}

        else if(cmp == 0){//сравниваем страны

            cmp = strcmp(struct_1.country, struct_2.country);
            if (cmp > 0){
            flag=1;}

            else if(cmp == 0){//сравниваем количество
                if(struct_1.count > struct_2.count){
                    flag=1;
                }
                else if(struct_1.count == struct_2.count){
                    flag=0;
                }
            }
        }
    }
    return flag;
}


//-----------------------------------------------------
//СОРТИРОВКИ (ВСЕ ИЗ ЛЕКЦИЙ, ЕСЛИ ПО КАКОЙ-ТО ПРИЧИНЕ НЕ РАБОТАЕТ, ТО СМОТРЕТЬ В РАСПИСАННЫЕ БИЛЕТЫ 
//https://file.notion.so/f/f/e1411409-93fa-4a77-a9c0-315bdd1a4d48/202979c8-6ed9-4dc4-975c-b6e02a750f7f/AiP_raspisannye_bilety.pdf?id=6c85de6e-5c84-4e64-9ef9-6758cd382379&table=block&spaceId=e1411409-93fa-4a77-a9c0-315bdd1a4d48&expirationTimestamp=1719050400000&signature=QYNpATJQr8q2bqPTpCi4XL_mle29Q0ML3FOZCW6-SZY&downloadName=AiP_raspisannye_bilety.pdf


//ПУЗЫРЕК
void bubble(int* a, int n){
    for (int i=n-1; i>=0; i--){
        for (int j=0; j<i; j++){
            if (a[j] > a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    //Краткое описание пузырька: Сравниваются попарно два элемента. Если они стоят в неправильном порядке, то они меняются местами. 
    //Проходы по массиву повторяются n-1 раз.
}


//ШЕЙКЕР
void shakerSort(int a[], long size){
    long j, k = size-1;
    long lb=1, ub = size-1; //границы несортированной части массива
    int x;

    do{//проход снизу вверх
        for(j=ub; j>0; j--){
        if( a[j-1] > a[j] ){
        x=a[j-1]; a[j-1]=a[j]; a[j]=x;
        k=j;
        }
    }

    lb = k+1;

   
    for (j=1; j<=ub; j++){ //проход сверху вниз
        if( a[j-1] > a[j] ){
        x=a[j-1]; a[j-1]=a[j]; a[j]=x;
        k=j;
      }
    }

    ub = k-1;
  }
  while( lb < ub );

    //Краткое описание шейкера: По сути это пузырек, но улучшенный: сначала мы двигаемся слева направо и перемещаем больший элемент вправо. 
    //Потом двигаемся справа налево и перемещаем меньший элемент вправо. 
    //Потом повторяем то же самое, но уже рассматриваем массив без крайних элементов
}


//ВСТАВКАМИ
void insert_sort(int *a, int n){
    int i, j, value;

    for(i = 1; i < n; i++){
        value = a[i];
        for (j = i - 1; j >= 0 && a[j] > value; j--){
            a[j + 1] = a[j];
        }
        a[j + 1] = value;
    }
    //Краткое описание вставок: Выбираем первый элемент из неотсортированной части и двигаем его по 
    //отсортированной части, пока элемент справа от него больше, чем этот элемент.
}


//ВЫБОРОМ
void select_sort(int *a, int length){
    for (int i = 0; i < length - 1; i++){
        int min_i = i;//находим индекс минимального элемента

        for (int j = i + 1; j < length; j++){
            if (a[j] < a[min_i]){
            min_i = j;}
        }
        //меняем значения местами
    int temp = a[i];
    a[i] = a[min_i];
    a[min_i] = temp;
    }
    //Описание сортировки выбором: Берем минимальный элемент из списка и ставим на первую неотсортированную позицию. 
    //Потом берем список уже после этого минимального элемента, в этом списке ищем минимальный и ставим на первую неотсортированную позицию. 
    //И тд.
}


//СЛИЯНИЕМ(тут нужна еще библиотека #include <stdlib.h> )
void merge(int *a, int low, int mid, int high){
    int *b = (int*) malloc((high+1-low)*sizeof(int));
    int h,i,j,k;
    h=low;
    i=0;
    j=mid+1;
    while((h<=mid)&&(j<=high)){
        if(a[h]<=a[j]){
            b[i]=a[h];
            h++;
        }
        else{
            b[i]=a[j];
            j++;
        }
        i++;
    }

    if(h>mid){
        for(k=j;k<=high;k++){
            b[i]=a[k];
            i++;
        }
    }

    else{
        for(k=h;k<=mid;k++){
            b[i]=a[k];
            i++;
        }
    }

    for(k=0;k<=high-low;k++){
        a[k+low]=b[k];
    }
    free(b);
}

void merge_sort(int *a, int low, int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        merge_sort(a, low, mid);
        merge_sort(a, mid+1,high);
        merge(a, low, mid, high);
    }
    //Краткое описание: Рекурсивно разбиваем массив на равные части(до тех пор пока размер массива неравен 1, такой массив считается отсортированным). 
    //Далее происходит слияние массивов(пусть массивы отсортированы по возр):  
    //из каждого подмассива берем первый элемент и из этих элементов выбираем меньший и записываем его в результирующий массив, и тд.
}


//БЫСТРАЯ СОРТИРОВКА
void qSort(int *a, int first, int last){
    if (first < last){
        int left = first, right = last, middle = a[(left + right) / 2];

    do{
        while (a[left] < middle) left++;
        while (a[right] > middle) right--;

    if (left <= right){
        int tmp = a[left];
        a[left] = a[right];
        a[right] = tmp;
        left++;
        right--;
    }

    }while(left <= right);

    qSort(a, first, right);
    qSort(a, left, last);
    }
}

void quickSort(int *a, int n){
    qSort(a, 0, n-1);
    //Краткое описание: Из массива выбирается элемент X в его середине. 
    //Далее разделяем массив на две части, где: слева от элемента Х помещаются все элементы меньшие или равные Х, а справа помещаются большие или равные. 
    //Теперь массив состоит из двух подмножеств, причем левое меньше, либо равно правого. 
    //Для обоих подмассивов: если в подмассиве более двух элементов, рекурсивно запускаем для него ту же процедуру
}


//ПИРАМИДАЛЬНАЯ СОРТИРОВКА
void downHeap(int *a, long k, long n){
	long child;
	int new_elem = a[k];
	
	while(k <= n/2){
		child = 2*k;
		if( child < n && a[child] < a[child+1]){
			child++;
		}
		if( new_elem >= a[child]){
			break;
		}
		a[k] = a[child];
		k = child;
	}
	a[k] = new_elem;
}

void heapSort(int *a, long size){
	long i;
	int tmp;

	for(i = size/2; i >= 0; i--){
		downHeap(a, i, size-1);
	}

	for(i = size-1; i > 0; i--){
		tmp = a[i];
		a[i] = a[0];
		a[0] = tmp;
		downHeap(a, 0, i-1);
	}
    //Краткое описание: https://www.youtube.com/watch?v=0NwapWP_dKs
    //Сначала проходимся по массиву(начиная с (n/2-1) элемента) и делаем так, что каждый родительский элемент больше или равен, чем дети.
    //После такой процедуры у нас вверху стоит наибольший элемент, меняем его с последним. 
    //Теперь рассматриваем массив без этого последнего элемента. Вытаскиваем из него таким же образом больший элемент и опять меняем его местами с n-1. 
    //И так до делаем до первого элемента.
}


//ЗАСЕКАЕМ ВРЕМЯ
{//скобки для того, чтобы свернуть можно было
    #include <sys/time.h>

    struct timeval start, end;
    long long time;

    gettimeofday(&start, NULL);//время начала сортировки
    gettimeofday(&end, NULL);//время окончания сортировки

    time = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);//определяем время работы сортировки
    printf("\nВремя работы сортировки: %lld мкс\n\n",time);
}


//-----------------------------------------------------
//ОДНОСВЯЗННЫЙ СПИСОК
//ПЕРВУЮ И ПОСЛЕДНЮЮ ФИГУРНЫЕ СКОБКИ НАДО УДАЛИТЬ
{

#include <stdio.h>
#include <stdlib.h> 


typedef struct Node{    //структура элемента списка
    int data;
    struct Node *next;  //указатель на следующий элемент списка
} Node;


Node * add_start();
void print(Node * L1);


Node* create(Node * L1){    //создание списка
    int a[] = {1, 4, 6, 8};
    
    for(int i = 0; i <= 3; i++){
        L1 = add_start(L1, a[i]);
    }
    return L1;
}


Node * add_start(Node* head, int data){  //добавление нового элемента в начало
    Node* newNode = (Node*)malloc(sizeof(Node));    //создаем элемент списка и добавляем в него значения
    newNode->data = data;

    if(head){
        newNode->next = head;
    }
    else{
        newNode->next = NULL;
    }
    
    return newNode;
}


Node * add_end(Node* head, int data){  //добавление нового элемента в конец
    Node* newNode = (Node*)malloc(sizeof(Node));    //создаем элемент списка и добавляем в него значения
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL){ //для добавления нулевого элемента
        return newNode;}
    
    Node* current = head;
    while (current->next != NULL){  //двигаемся в конец списка для добавления элемента
        current = current->next;}
    current->next = newNode;
    return head;
}


Node * add_on_pos(Node* head, int data, int pos){  //добавление нового элемента на заданную позицию
    Node* newNode = (Node*)malloc(sizeof(Node));    //создаем элемент списка и добавляем в него значения
    newNode->data = data;
    newNode->next = NULL;
    
    if(pos == 0){   //добавление в начало(просто код для добавления в начало)
        if (head == NULL){ //для добавления нулевого элемента
        return newNode;}
    
        Node* current = head;
        while (current->next != NULL){  //двигаемся в конец списка для добавления элемента
            current = current->next;}
        current->next = newNode;
        return head;
    }

    Node* prev = head, *curr = head->next;
    for(int i = 1; i<pos; i++){
        prev = curr;
        curr = curr -> next;
        if(curr = NULL){
            printf("Позиции с таким номером нет");
            return;
        }
    }

    prev -> next = newNode;
    newNode -> next = curr;
    return head;
}


Node * del_from_pos(Node* head, int pos){  //удаление нового элемента с позиции
    
    if(pos == 0){   //удаление из начала
        Node* head = head->next;
        free(head);
        return head;
    }

    Node* prev = head, *curr = head->next;
    for(int i = 1; i<pos; i++){
        prev = curr;
        curr = curr -> next;
        if(curr == NULL){
            printf("Позиции с таким номером нет");
            return;
        }
    }

    prev -> next = curr -> next;
    free(curr);
    return head;
}


void print(Node * L1){  //вывод списка
    Node * current = L1;
    puts("");
    while(current){
        printf("%d ",current -> data);
        current = current -> next;
    }
}


Node * delete_start(Node * L1){   //удаление из начала
    Node * current = L1;
    Node * head = current -> next; //новая голова, это второй элемент

    free(current);
    return head;
}


void search(Node * L1){ //поиск
    int find;
    printf("\nВведите значение, которое надо найти: ");
    scanf("%d", &find);

    Node * current = L1;
    while(current){
        if(find == current -> data){
            printf("Значение %d найдено", find);
            return;
        }
        current = current -> next;
    }

    printf("Значение %d НЕ найдено", find);
    return;
}


int main(){
    Node * L1 = NULL;
    L1 = create(L1);
    
    print(L1);
    L1 = delete_start(L1);
    print(L1);

    search(L1); //поиск по значению

    print(L1);
    add_on_pos(L1, 5, 1); //нумерация идет с 0
    print(L1);
    del_from_pos(L1, 2);//удаление элемента под номером
    print(L1);
    
    return 0;
}

}


//-----------------------------------------------------
//ДВУСВЯЗННЫЙ СПИСОК
//ПЕРВУЮ И ПОСЛЕДНЮЮ ФИГУРНЫЕ СКОБКИ НАДО УДАЛИТЬ
{

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{    //структура элемента списка
    int data;
    struct Node *next;  //указатель на следующий элемент
    struct Node *prev;
} Node;

typedef struct DBLLinked{  //структура, содержащая информацию о списке
    unsigned int size;  //кол-во элементов в списке
    Node *head;
    Node *tail; //указатель на конец списка
} DBLLinked;


void add_end(DBLLinked *list, int data);
void add_start(DBLLinked *list, int data);


DBLLinked* createDBLLinked(){   //создание пустого списка
    
    DBLLinked *list = (DBLLinked*) malloc(sizeof(DBLLinked));
    list -> size = 0;
    list -> head = NULL;
    list -> tail = NULL;

    return list;
}

void add_end(DBLLinked *list, int data){    //добавление элемента в конец
    Node *tmp = (Node*) malloc(sizeof(Node));
    
    tmp->data = data;
    tmp->next = NULL;   //изменяем поля элемента
    tmp->prev = list->tail;

    if (list->tail){   //изменяем указатель в предпоследнем элементе
        list->tail->next = tmp;}

    list->tail = tmp;   //изменяем указатель на конец списка
 
    if (list->head == NULL){    //если список пустой, то указатель на начало = указатель на этот элемент
        list->head = tmp;}

    list->size++;
}

void add_start(DBLLinked *list, int data){    //добавление элемента в начало
    Node *tmp = (Node*) malloc(sizeof(Node));
    
    tmp->data = data;
    tmp->prev = NULL;   //изменяем поля элемента
    tmp->next = list->head;

    list->head = tmp;   //изменяем указатель на начало списка

    list->size++;
}

void delete_start(DBLLinked *list){    //удаление элемента из начала
    Node *head = list->head;

    list -> head = head -> next;    //голова теперь второй элемент
    head -> next -> prev = NULL;    //во втором элементе списка поле prev теперь null
    free(head);

    list->size--;
}

void delete_end(DBLLinked *list){    //удаление элемента из конца
    Node *tail = list->tail;

    list -> tail = tail -> prev;    //предпоследний элемент стал последним
    tail -> prev -> next = NULL;    //во втором элементе списка поле prev теперь null
    free(tail);

    list->size--;
}

void add_on_pos(DBLLinked *list, int data, int pos){    //добавление элемента на позицию
    Node *tmp = (Node*) malloc(sizeof(Node));
    
    tmp->data = data;
    tmp->prev = NULL;   //изменяем поля элемента
    tmp->next = NULL;

    if(pos == 0){   //если позиция ноль, то просто код из добавления в начало
        tmp->next = list->head;
        list->head = tmp;   //изменяем указатель на начало списка
        list->size++;//увеличиваем кол-во элементов в списке
        return;
    }

    if(pos == list->size){  //если нужно добавить после последнего элемента
        tmp->prev = list -> tail;   // в текущем элементе меняет указатель на предыдущий
        list -> tail -> next = tmp; //в элементе, который теперь будет предпоследним, меняем указатель на след. элемент
        list -> tail = tmp; //новый хвост = текущий элемент
        list->size++;//увеличиваем кол-во элементов в списке
        return;
    }

    Node* prev = list -> head, *curr = prev->next;
    for(int i = 1; i<pos; i++){
        prev = curr;
        curr = curr -> next;
        if(curr == NULL){
            printf("Позиции с таким номером нет");
            return;
        }
    }

    prev->next = tmp;   //для предыдущего элемента следующий = новый
    curr->prev = tmp;   //для следующиего элемента предыдущий = новый
    tmp -> prev = prev; //для текущего предыдущий = предыдущий 
    tmp -> next = curr; //для текущего следующий = следующий

    list->size++;//увеличиваем кол-во элементов в списке
}

void delete_from_pos(DBLLinked *list, int pos){    //удаление элемента с позиции

    if(pos == 0){   //если надо удалить голову
        Node *head = list->head;
        list->head = head->next;  //обновляем голову
        list->head->prev = NULL; //и в обновленной голове обновляем указатель на предыдущий элемент

        free(head);
        list->size--;   //уменьшаем кол-во эдементов в списке
        return;
    }


    if(pos == list->size - 1){  //если удаляем хвост
        Node *tail = list->tail;
        list->tail = tail->prev;    //новый хвост = предпоследний элемент
        list->tail->next = NULL;    //в новом хвосте обнуляем указатель на след. элемент

        free(tail);
        list->size--;   //уменьшаем кол-во эдементов в списке
        return;
    }


    Node *curr = list -> head -> next;  //сейчас мы на первой позиции (после нулевой)
    for(int i = 1; i<pos; i++){
        curr = curr -> next;
        if(curr == NULL){
            printf("Позиции с таким номером нет");
            return;
        }
    }

    Node *prev = curr->prev;
    Node *next = curr->next;

    prev->next = curr->next;    //в предыдущем меняем указатель на следующий
    next->prev - curr->prev;    //а в слкдующем на предыдущий

    free(curr);
    list->size--;   //уменьшаем кол-во эдементов в списке
}

void printDBLLinked(DBLLinked *list){   //вывод списка
    if(list->size == 0){printf("Пустой список"); return;}

    Node *tmp = list->head; //получаем указатель на первый элемент списка
    while(tmp){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
   puts(""); 
}

void deleteDBLLinked(DBLLinked **list){ //удаление списка
    Node *tmp = (*list)->head;
    Node *next;
    while(tmp){
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
}


void main(){
    DBLLinked* list = createDBLLinked();

    int a[] = {8, 6, 3, 1}; //заполняем список
    for(int i=0; i < 4; i++){
        add_end(list, a[i]);
    }

    printDBLLinked(list);

    add_start(list, 11);    //просто тестирую всё, это необязательно
    add_end(list, 55);
    printDBLLinked(list);

    delete_start(list);
    delete_end(list);
    printDBLLinked(list);

    add_on_pos(list, 52, 0);
    add_on_pos(list, 78, 2);
    add_on_pos(list, 33, 6);
    printDBLLinked(list);

    delete_from_pos(list, 0);
    delete_from_pos(list, 2);
    delete_from_pos(list, 4);
    printDBLLinked(list);

    deleteDBLLinked(&list);
    return;
}

}


//-----------------------------------------------------
//БИНАРНОЕ ДЕРЕВО ПОИСКА
{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>


typedef struct tnode{                
  int value;       // указатель на структуру
  struct tnode* left;      // левый потомок
  struct tnode* right;     // правый потомок
}tree;


tree* addtree(tree* p, int new){//функция добавления узла к дереву
  int cmp;
  if (p == NULL){//если дерево пустое или предыдущий элемент не имел потомков, то создаем элемент
    p = (tree*)malloc(sizeof(tree));
    p->value = new;
    p->left = (p->right = NULL);
  }

  else if (new < p->value){ //перемещаемся по дереву, пока не найдем свободное место(NULL)
    p->left = addtree(p->left, new);}//если элемент меньше, то перемещаемся в левое поддерево
  
  else{
    p->right = addtree(p->right, new);}//иначе в правое
  return p;
}


void treeprint(tree* p){//функция вывода дерева
  if (p != NULL){
    treeprint(p->left);//сначала печатаем левое поддерево
    printf("%d ", p->value);
    treeprint(p->right);//потом правое
  }
}


tree* search(tree *root, int find){ //поиск элемента, равного find
  if ((root == NULL) || (root -> value == find) ){//если поддерево пусто, то достигнут конец ветки
    return root;}   //или если зачение равно find, то возвращается указатель на корень
  
  if (root -> value > find ){//поиск нужного узла: если find меньше, чем значение в узле, то идем в левое поддерево
    return search(root -> left, find);}
  else{ 
    return search(root -> right, find);}
}


void searchAll(tree * root, int find){//поиск всех элементов, равных find
  tree *cur = NULL, *tmp = root;
  int flag = 0;

  puts("\nРезультаты поиска:");
  do{
    cur = search(tmp, find);
    if (!cur){break;}   //если достигли конца ветки, то поиск окончен

    printf("%d ", cur->value);
    flag++;
    tmp = cur -> right; //перемещаемся в правую часть дерева, тк нас интересуют равные элементы
  }while(tmp);

  if(!flag){printf("такого элемента нет\n");}
}


void freemem(tree* tr){ //очистка дерева
  if (tr != NULL)
  {
    freemem(tr->left);
    freemem(tr->right);
    free(tr);
  }
}


int min_tree(tree * root){  //функция поиска минимального элемента
    tree *tmp = root;

    while(tmp->left){   //такой элемент находится в самой левой ветке
        tmp = tmp->left;
    }
    
    return tmp->value;
}


int max_tree(tree* tr){ //функция поиска макс. элемента
    tree *tmp = tr;
    while(tmp->right){
        tmp = tmp->right;   //такой элемент находится в самой правой ветке
    }
    
    return tmp->value;
}


tree* deleteNode(tree* root, int k){    //удаление узла
    if (root == NULL){  //на случай если такой элемент не будет найден
        return root;}

    
    if (k < root->value){//если удаляемый элемент меньше, чем в корень, то он находится в левом поддереве
        root->left = deleteNode(root->left, k);
        return root;
    }

    else if (k > root->value){//если удаляемый элемент больше, чем в корень, то он находится в правом поддереве
        root->right = deleteNode(root->right, k);
        return root;
    }

    //если мы дошли до этой строки, то k == root->key и этот узел нажо удалить
    if (root->left == NULL){//если нет левого поддерева, то возращаем указатель на правое(если нет и правого, то вернется NULL)
        tree* temp = root->right;
        free(root);
        return temp;
    }
    else if(root->right == NULL){   //если нет правого, то возвращаем левое
        tree* temp = root->left;
        free(root);
        return temp;
    }

    tree* parent = root;
    tree* child = root->right;  //спускаемся в правое поддерево
    while (child->left != NULL) {   //и двигаемся по левой ветке(ищем минимальный элем.)
        parent = child;
        child = child->left;
    }

    root->value = child->value; //вместо значения удаляемого элемента вставляем найденное значение

    if (parent->left == child){ //к родителю прикрепляем правое поддерево ребенка(левого поддерева у ребенка не было)
        parent->left = child->right;}
    else{   //на случай, если у root->right нет левого поддерева
        parent->right = child->right;}

    free(child);
    return root;
}


void preOrder(tree* root){//прямой обход
    if(root){
        printf("%d ", root->value);  //корень -> левое -> правое
        preOrder(root->left);
        preOrder(root->right);
    }
}


void inOrder(tree* root){   //симметричный обход
    if (root){
        inOrder(root->left);    //левое -> корень -> правое
        printf("%d ", root->value);
        inOrder(root->right);
    }
}


void postOrder(tree* root){  //обратный обход
    if (root){
        postOrder(root->left);  //левое -> правое -> корень
        postOrder(root->right);
        printf("%d ", root->value);
    }
}



int main(){
    int len = 10;   //массив обязательно должен быть заполнен полностью, иначе среди элементов будут выводиться указатели

    int* array = (int*)malloc(len * sizeof(int));  //создаем массив
    for(int i = 0; i < 10; i++){    //9,8,7,...
        array[10 - i - 1] = i; 
    }


    tree* root = NULL;  //создаем и 
    for(int i=0; i < len; i++){ //заполняем дерево
        root = addtree(root, array[i]);}

    deleteNode(root, 4);    //удалим 4

    treeprint(root);//выводим дерево


    int find = 2; //то, что будем искать
    searchAll(root, find); //выполняем поиск

    printf("min: %d\n", min_tree(root));
    printf("max: %d\n", max_tree(root));


    //обходы в глубину
    puts("Обходим деревья в глубину");
    preOrder(root);
    puts("");
    inOrder(root);
    puts("");
    postOrder(root);


    freemem(root);  //очищаем память
    free(array);
       
    return 0;
}

}


//-----------------------------------------------------
//БИНАРНОЕ ДЕРЕВО ПОИСКА: ОБХОД В ШИРИНУ

{

#include <stdio.h>
#include <stdlib.h>


struct Node {   //структура узла бин дерева
    int data;
    struct Node* left;
    struct Node* right;
};


struct QueueNode {  //структура элемента очереди
    struct Node* data;
    struct QueueNode* next;
};


struct Queue{   //структура очереди
    struct QueueNode *front, *rear; //front - указатель на первый элемент, rear - на последний
};


struct Node* newNode(int data){ //функция создания узла бин дерева
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}


struct QueueNode* newQueueNode(struct Node* data){  //создание элемента очереди
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->data = data;  //в data сохраняем узел дерева
    temp->next = NULL;
    return temp;
}


struct Queue* createQueue(){    //создание очереди
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}


void enQueue(struct Queue* q, struct Node* data){   //добавление элемента в очередь
    struct QueueNode* temp = newQueueNode(data);
    
    if(q->rear == NULL){    //если очередь была пустая
        q->front = q->rear = temp;
        return;
    }
    
    q->rear->next = temp;   //поле next в последнем элементе теперь указывает на новый элемент  
    q->rear = temp; //последний элемент = текущий
}


struct Node* deQueue(struct Queue* q){  //удаление элемента из очереди
    if (q->front == NULL){  //если пустая очередь, то нечего удалять
        return NULL;
    }
    
    struct Node* temp = q->front->data; //получаем узел дерева
    struct QueueNode* tempNode = q->front;  //и первый элемент очереди
    
    q->front = q->front->next;  //следующий элемент теперь является началом очереди
    
    if (q->front == NULL){  //если следующего элемента нет, то очередь пуста
        q->rear = NULL;
    }
    
    free(tempNode);
    
    return temp;
}


void width_travel(struct Node* root) {//обход бинарного дерева в ширину
    if (root == NULL){
        return;
    }
    
    struct Queue* queue = createQueue();    //создаем очередь
    
    enQueue(queue, root);   //добавляем корень дерева
    
    while (queue->front != NULL) {  //пока в очереди есть элементы
        struct Node* current = deQueue(queue);  //получаем ее первый элемент
        printf("%d ", current->data);
        
        if (current->left != NULL) {    //добавляем в очередь двух потомков, если они есть
            enQueue(queue, current->left);
        }
        
        if (current->right != NULL) {
            enQueue(queue, current->right);
        }
    }
}


int main() {
    struct Node* root = newNode(1); //заполняем дерево (1)(2 3) (4 5 - -)
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    
    printf("Обход в ширину: ");
    width_travel(root);
    
    return 0;
}

}


//-----------------------------------------------------
//РАБОТА С БИН ФАЙЛАМИ

{

#include <stdio.h>

void main(){
    FILE *f = fopen("test.bin", "ab");    //создаем файл с возможностью редакт.

    int a = 10, b = 25,c;
    fwrite(&a, sizeof(int), 1, f);//записываем в файл
    fwrite(&b, sizeof(int), 1, f);//записываем в файл
    fclose(f);

    f = fopen("test.bin", "rb");    //открываем для чтения
    if (!f){
		printf("Ошибка открытия файла\n");
		return;
	}

    fseek(f, sizeof(int), SEEK_SET);    //сдвигаемся на int
    while(!feof(f)){
        if (!fread(&c, sizeof(int), 1, f)){break;}
        
        printf("%d %d ",c, ftell(f));
    }

    rewind(f);  //смещение в начало
    printf("\nПоложение: %d ", ftell(f));
    fseek(f, sizeof(int), SEEK_END);
    printf("\nПоложение: %d ", ftell(f));

    fclose(f);
}

}


//-----------------------------------------------------
//РАБОТА С TXT ФАЙЛАМИ

{

#include <stdio.h>

void main(){
    FILE *f = fopen("test.txt", "w");

    char * str = "Pupsik";
    fputs(str, f); //записываем в файл
    fclose(f);
    
    char buffer[2];
    f = fopen("test.txt", "r");

    while((fgets(buffer, 2, f))!=NULL){
        printf("%s ", buffer);
    }
    fclose(f);

    f = fopen("test.txt", "w"); //стираем и открываем файл

    int tmp = 1;
    puts("\nВведите числа; чтобы закончить ввод, введите 0");
    while(tmp){
        scanf("%d", &tmp);
        fprintf(f, "%d ", tmp);
    }
    fclose(f);

    f = fopen("test.txt", "r"); //читаем файл

    while(!feof(f)){
        fscanf(f, "%d ", &tmp);
        printf("%d ", tmp);
    }
    fclose(f);
}

}

//------------------------------------------------------------
//35 БИЛЕТ. ФУНК. НЕСКОЛЬКИХ ПЕРЕМЕННЫХ

{

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdarg.h>
 
#define UNSIGNED_OVERFLOW -4
 
int summ(int num, ...) {
    va_list args; //переменная для хранения аргументов
    va_start(args, num); //инициализирует args для извлечения дополнительных аргументов

    int sum = 0;
    for (int i = 0; i < num; i++){
        sum += va_arg(args, int); //получение следующего аргумента и добавление его к сумме
    }

    va_end(args); //завершение работы функции
    return sum;
}

unsigned summ2(unsigned char num, ...) {
    unsigned sum = 0;
    unsigned testsum = 0;
    unsigned *p = (unsigned*)(&num+4);  //получаем указатель на первое слагаемое
    while (num--){  
        testsum += *p;  //прибавляем к сумме
        if (testsum >= sum){
            sum = testsum;
        } 
        else{   //если сумма вышла меньше, значит мы вышли за предел unsigned
            exit(UNSIGNED_OVERFLOW);
        }
        p++;    //переходим к след. слагаемому
    }
    return sum;
}
 
void main(){
    printf("Сумма = %d\n", summ(5, 1u, 2u, 3u, 4u, 5u) ); //15
    printf("Сумма =  %d\n", summ(7, 0u, 27u, 0u, 4u, 5u, 60u, 33u) ); //129

    printf("Сумма 2 = %u\n", summ2(5, 1u, 2u, 3u, 4u, 5u) );  
    printf("Сумма 2 = %u\n", summ2(7, 0u, 27u, 0u, 4u, 5u, 60u, 33u)); 
}

}

