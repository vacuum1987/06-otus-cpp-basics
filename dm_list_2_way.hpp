#pragma once
#include <iostream>

template <typename T>
struct DataBlock2Way {
	DataBlock2Way( T initialValue) {
        data_item_ = initialValue;
        next_data_block_ = nullptr;
        prev_data_block_ = nullptr;
		
        //std::cout << "ctor: " << data_item_ << " " << this << std::endl;
	};

 	DataBlock2Way() {
        //data_item_ = initialValue;
        next_data_block_ = nullptr;
        prev_data_block_ = nullptr;
		
        //std::cout << "ctor: " << data_item_ << " " << this << std::endl;
	};   

    // конструктор копирования для блока данных
    DataBlock2Way (const DataBlock2Way & other_data_block) {
        data_item_ = other_data_block.data_item_;
        next_data_block_ = other_data_block.next_data_block_;
        prev_data_block_ = other_data_block.prev_data_block_;
    };

	~DataBlock2Way() {
		//std::cout << "dtor: " << data_item_ << " " << this << std::endl;
        next_data_block_ = nullptr;
        prev_data_block_ = nullptr;
	};
	
	T data_item_;   // пользовательские данные (хранимый объект)
    DataBlock2Way *next_data_block_;    // указатель на следующий элемент
    DataBlock2Way *prev_data_block_;    // указатель на предыдущий элемент
};


template <typename T>
class Dm_list_2_way {
    public:
        Dm_list_2_way () {
            head_node_ = new DataBlock2Way<T> (T()); // Создаем начальный пустой узел (блок данных) для хранения адреса начала контейнера
            current_node_ = head_node_; // Устанавливаем указатель текущий узел на только что созданный узел
            last_node_ = head_node_; // Устанавливаем указатель последний узел на только что созданный узел
            
            //std::cout << "Dm_list_2_way ctor last node " << last_node_ << std::endl;    // Выводим адрес последнего узла в консоль для отладки
        };
        // конструктор копирования
        Dm_list_2_way (const Dm_list_2_way & other) {
            m_size = other.m_size; // копируем размер списка
            head_node_ = new DataBlock2Way<T> (T());
            *head_node_ = *other.head_node_; // копируем head_node_ (головной блок данных) исходного списка 
            
            current_node_ = head_node_->next_data_block_; // двигаем  указатель текущего узла дальше по исходному списку - готовимся копировать остальные
            last_node_ = head_node_; // Устанавливаем указатель последний узел на только что созданный узел
            //std::cout << std::endl << "head node copied. old next node address: " << other.head_node_->next_data_block_ << " new next node address " << current_node_ << std::endl;
            if (current_node_) { // если у нас вообще что-то есть после head_node, то переходим к копированию нод
                for (int i=0; i<m_size ; i++) {
                    DataBlock2Way<T> *new_data_block_tmp = new DataBlock2Way<T>(T());
                    T data_item_tmp = current_node_->data_item_; // копируем сами данные во временную переменную
                    //std::cout << std::endl << "copied data_item_tmp = " << data_item_tmp << std::endl;
                    new_data_block_tmp->data_item_ = data_item_tmp; // копируем  данные в новый блок
                    new_data_block_tmp->next_data_block_=nullptr; // следующего блока пока нет
                    new_data_block_tmp->prev_data_block_=last_node_; // ставим указатель на предыдущую ноду
                    //std::cout << std::endl << "new_data_block_tmp data = " << new_data_block_tmp->data_item_;
                    //std::cout << std::endl << "new_data_block_tmp prev address = " << new_data_block_tmp->prev_data_block_;
                    last_node_->next_data_block_=new_data_block_tmp;   // для бывшего последнего узла новый узел станет следующим
                    last_node_ = new_data_block_tmp; // обновляем указатель на последний
                    if (current_node_->next_data_block_) { // если у копируемой ноды есть указатель на следующую, то двигаем current node указатель дальше по копируемому списку
                        current_node_ = current_node_->next_data_block_ ; 
                    }
                    else {break;}; // если это был последний элемент, то выходим из цикла
                    
                };
            };
            //std::cout << std::endl << "last data block data = " << last_node_->data_item_ << std::endl;
            //std::cout << std::endl << "new list size  = " << m_size << std::endl;
        };

        ~Dm_list_2_way () {
            //std::cout << "Dm_list_2_way dtor " << std::endl;
            current_node_=head_node_->next_data_block_;
            for (int i=0; i<=m_size; i++) {
                DataBlock2Way<T> *current_deleting_node = current_node_;
                
                if (current_node_->next_data_block_) { // если у копируемой ноды есть указатель на следующую, то двигаем current node указатель дальше по копируемому списку
                    current_node_ = current_node_->next_data_block_ ; 
                    delete current_deleting_node;
                    //std::cout <<  std::endl << "Node number " << i << "was deleted" ;
                }
                else {
                    delete current_deleting_node;
                    //std::cout <<  std::endl << "Node number " << i << "was deleted (end node)" ;
                    break; // если это был последний элемент, то выходим из цикла
                }; 
            };
            
            delete head_node_;
		    head_node_ = nullptr;
		    current_node_ = nullptr;
            last_node_ = nullptr;
                        
        };
        void push_back(const T &item) {
            DataBlock2Way<T> *new_data_block = new DataBlock2Way<T>(item); // создание нового узла (ячейки), кот. инициал-ся значением item
            //new_data_block->data_item_ = item; // значение item присваивается члену data_item_ объекта new_data_block
            new_data_block->next_data_block_ = nullptr; // следующего элемента пока нет
            new_data_block->prev_data_block_ = last_node_;  // предыдущим элементом станет бывший последним
            last_node_->next_data_block_ = new_data_block;  // для бывшего последнего узла новый узел станет следующим
            //current_node_ = new_data_block; // указатель current_node_ обновляется, чтобы указывать на новый блок данных, который только что был добавлен
            last_node_ = new_data_block; // обновляем указатель на последний
            m_size += 1; // обновляем размер списка
            //std::cout << "m_size " << m_size <<std::endl;
        };

        // array size returning for external purposes
        int size () const {
            //length = sizeof(values) / sizeof(T);
            return m_size;
        };

        class Iterator {
            public:
                Iterator() noexcept {
                    itr_node_ = nullptr;
                };
                Iterator (DataBlock2Way<T> *node) noexcept{
                    itr_node_ = node;
                };
                
                // перегружаем Префиксный оператор инкремента ++ для итератора
                Iterator &operator++ () {
                    if (itr_node_)
				        itr_node_ = itr_node_->next_data_block_;
        			return *this;
                };

                // перегружаем Постфиксный оператор инкремента ++ для итератора
                Iterator operator++ (int) {
                    Iterator iterator = *this;
                    ++(*this);
                    return iterator;
                };

                // перегрузка Оператора неравенства: вернет true, если интераторы не указывают на тот же объект 
                bool operator!=(const Iterator &iterator) {
			        return itr_node_ != iterator.itr_node_;
		        };

                // перегрузка Оператора разыменования: возвращает ссылку на элемент данных
                T &operator*() {
			        return itr_node_->data_item_;
		        };

                // return current itr_node_ pointer
                DataBlock2Way<T> *itr_get () const {
                    return itr_node_;
                };

            private:
		        DataBlock2Way<T> *itr_node_;
        };

        // возвращает итератор на начало контейнера (к первому элементу)
        Iterator begin() {
		    return Iterator(head_node_->next_data_block_);
	    };

        // возвращает итератор на конец контейнера, т.е. в никуда (для последовательного обращения к элементам)
        Iterator end() {
		    return Iterator(nullptr);
	    };

        // access to the array member by the index 
        T &operator[](size_t index) {
		    Iterator itr = begin ();
            for (int i=0; i < index; ++i) {  // двигаем итератор до нужной позиции
                ++itr;
	        };
            return (*itr);
	    };

        // inserting new element into the array at the target  position
        void insert (const T inserting_item, int target_position ) {
            Iterator itr = begin ();
            if (target_position == 0) {
                //std::cout <<  "target position = 0" << std::endl;
                DataBlock2Way<T> *new_data_block = new DataBlock2Way<T>(inserting_item); // создание нового узла (ячейки), кот. инициал-ся значением item
                new_data_block->next_data_block_ = head_node_->next_data_block_;
                ++itr;
                current_node_ = itr.itr_get();
                current_node_->prev_data_block_ = new_data_block;
                head_node_->next_data_block_ = new_data_block;
                m_size += 1; // обновляем размер списка
            }
            else if (target_position > 0 && target_position <= m_size) {
                
                for (int i=0; i < (target_position-1); ++i) {   // двигаем итератор до N-1 элемента
                    ++itr;
	            };

                //std::cout <<  "current element = " << (*itr) << std::endl;

                DataBlock2Way<T> *new_data_block = new DataBlock2Way<T>(inserting_item); // создание нового узла (ячейки), кот. инициал-ся значением item
                //new_data_block->data_item_ = item; // значение item присваивается члену data_item_ объекта new_data_block
                current_node_ = itr.itr_get(); 

                new_data_block->next_data_block_ = current_node_->next_data_block_;   // устанавливаем для новой ноды указатель на N+1 ноду такой, какой был у итерируемой ноды
                current_node_->next_data_block_ = new_data_block;  // устанавливаем для ноды, на которую сейчас показывает итератор, указатель на новую ноду в качестве следующей 
                new_data_block->prev_data_block_ = current_node_;   // новая нода будет указывать на выбранную ноду как на предыдущую 
                ++itr; ++itr; // переходим к N+1 ноде
                current_node_ = itr.itr_get(); 
                if (current_node_ != nullptr) {
                   current_node_->prev_data_block_ = new_data_block; // установили для N+1 ноды указатель на новую предыдущую ноду
                };                   
                m_size += 1; // обновляем размер списка
                //std::cout << "m_size " << m_size <<std::endl;
            }
            else {
                std::cout << "The requested position is out of container! Actual container size is " << m_size <<std::endl;
            };
        };

        // erasing target element
        void erase (int target_position ) {
            if (target_position <= m_size) {
                // ставим временные указатели
                Iterator itr = begin ();
                for (int i=0; i < (target_position-1); ++i) {   // двигаем итератор до N-1 элемента
                    ++itr;
                };
                DataBlock2Way<T> *node_previous_ = itr.itr_get();   // указатель на  элемент перед удаляемым
                ++itr;
                DataBlock2Way<T> *node_erasing_ = itr.itr_get();   // указатель на удаляемый элемент
                ++itr;
                DataBlock2Way<T> *node_next_ = itr.itr_get();   // указатель на следующий за удаляемым элемент (если он есть)

                if (node_next_ != nullptr) {
                    node_previous_->next_data_block_ = node_next_;
                    node_next_->prev_data_block_ = node_previous_;
                }
                else {
                    node_previous_->next_data_block_ = nullptr;
                };
                delete node_erasing_;
                m_size -= 1; // обновляем размер списка
            }
            else {
                std::cout << "The requested position is out of container! Actual container size is " << m_size <<std::endl;
            };
        };

        void printValue()  {
            Iterator itr = begin ();
            for (; itr != end(); ++itr) {
	            std::cout << (*itr) << ' ' ;
            };
        };


    private:
	DataBlock2Way<T> *head_node_; // указатель на первую ноду
	DataBlock2Way<T> *current_node_; // указатель на текущую ноду
    DataBlock2Way<T> *last_node_; // указатель на последнюю ноду
    int m_size = 0; // размер (количество элементов) списка

};