#pragma once

template <typename T>
class Dm_vector {
    public:
        Dm_vector () {};
        Dm_vector (T v) {
            length = 1;
            *values = v;            
        };
        // конструктор копирования
        Dm_vector (const Dm_vector & other) {
            length = other.length;     // copy number of elements in the array
            capacity = other.capacity;   // copy capacity of the array (allocated memory)

            T * new_region_copy =  new T [capacity]; // new tmp region in memory
            for (size_t i = 0; i <= length; ++i) {
                new_region_copy[i] = other.values[i]; // copy elements from the old array
            };
            
            values = new_region_copy; // save new region values as array values
            
            
        };

        ~Dm_vector () {
            delete [] values;
        };
          
        // array size returning for external purposes
        int size () const {
            //length = sizeof(values) / sizeof(T);
            return length;
        };
        
        void push_back (T v) {
            int new_size = length + 1;
            capacity_check_and_increase (new_size);
            T * new_region =  new T [capacity]; // new tmp region in memory
            for (size_t i = 0; i < length; ++i) {
                new_region[i] = values[i]; // copy elements from the old array
            };
            new_region[length] = std::move(v); // add new element as the last element of array
            //delete [] values; // delete old array (old region)
            values = new_region; // save new region values as array values
            length += 1; // length updating 
            // delete new_region;
        };

        // inserting new element into the array at the target  position
        void insert (const T new_element, int target_position ) {
            int new_size = length + 1;
            capacity_check_and_increase (new_size);
            T * new_region =  new T [capacity]; // new tmp region in memory
            // copy elements before target position
            for (size_t i = 0; i < target_position; ++i) {
                new_region[i] = values[i]; // copy elements from the old array
            };

            // copy elements after target position
            for (size_t i = target_position; i < length; ++i) {
                new_region[i+1] = values[i]; // copy elements from the old array
            }; 

            // add new element to target position 
            new_region[target_position] = std::move(new_element);

            values = new_region; // save new region values as array values
            length += 1; // length updating 

        };

        void erase (int target_position) {
            T * new_region =  new T [capacity]; // new tmp region in memory
            // copy elements before target position
            for (size_t i = 0; i < target_position; ++i) {
                new_region[i] = values[i]; // copy elements from the old array
            };

            // copy elements after target position
            for (size_t i = target_position; i < length; ++i) {
                new_region[i] = values[i+1]; // copy elements from the old array
            }; 

            values = new_region; // save new region values as array values
            length -= 1; // length updating 

        };


        void printValue()  {
            //length = sizeof(values) / sizeof(T);
            for (size_t i = 0; i < length; ++i) {
                std::cout << values[i] << " ";
            };
        };

        // access to the array member by the index 
        T &operator[](size_t i) {
		return values[i];
	    }  ;

    private:
       
        int length = 0;     // number of elements in the array
        int capacity = 0;   // capacity of the array (allocated memory)
        T * values = new T [length];

        // internal function to check and increase array capacity in case of lower than (or equal to) new_size
        void capacity_check_and_increase ( int new_size) {
            if (capacity <= new_size) {
                capacity = new_size * 1.5;
                //std::cout << "Array capacity was increased. New capacity = " << capacity << std::endl;
            };
        };
};