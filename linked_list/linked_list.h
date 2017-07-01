#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>
#include <cstdlib>
#include <stdexcept>

#define ERROR_LACKING_MEMORY

namespace structures {

    /**
     * @brief Finds the element by data
     *
     * @return Size of list
     */
template<typename T>
class LinkedList {
 public:
     /**
     * @brief Finds the element by data
     *
     * @return Size of list
     */
    class Node {  // Elemento
     public:
        /**
         * @brief Finds the element by data
         *
         * @return Size of list
         */
        explicit Node(const T& data):
            data_{data}
        {}
        /**
         * @brief Finds the element by data
         *
         * @return Size of list
         */
        Node(const T& data, Node* next):
            data_{data},
            next_{next}	 	  	 	  	      	  	      	    	 	        	 	
        {}
        /**
         * @brief Finds the element by data
         *
         * @return Size of list
         */
        T& data() {  // getter: dado
            return data_;
        }
        /**
         * @brief Finds the element by data
         *
         * @return Size of list
         */
        const T& data() const {  // getter const: dado
            return data_;
        }
        /**
         * @brief Finds the element by data
         *
         * @return Size of list
         */
        Node* next() {  // getter: próximo
            return next_;
        }
        /**
         * @brief Finds the element by data
         *
         * @return Size of list
         */
        const Node* next() const {  // getter const: próximo
            return next_;
        }
        /**
         * @brief Finds the element by data
         *
         * @return Size of list
         */
        void next(Node* node) {  // setter: próximo
            next_ = node;
        }	 	  	 	  	      	  	      	    	 	        	 	

     private:
        T data_;
        Node* next_{nullptr};
    };
        /**
         * @brief Finds the element by data
         *
         * @return Size of list
         */
    Node* end() {  //  último nodo da lista
        auto it = head;
        for (auto i = 1u; i < size_; ++i) {
            it = it->next();
        }
        return it;
    }
    /**
     * @brief Finds the element by data
     *
     * @return Size of list
     */
    Node* head{nullptr};
    /**
     * @brief Finds the element by data
     *
     * @return Size of list
     */
    std::size_t size_{0u};
    /**
     * @brief Finds the element by data
     *
     * @return Size of list
     */
    LinkedList() = default;
    /**
     * @brief Finds the element by data
     *
     * @return Size of list
     */
    ~LinkedList() {	 	  	 	  	      	  	      	    	 	        	 	
        clear();
    }
    /**
     * @brief Finds the element by data
     *
     * @return Size of list
     */
    void clear() {
        Node* current;
        Node* before;
        current = head;
        head = nullptr;
        while (current != nullptr) {
            before = current;
            current = current->next();
            delete before;
        }
        size_= 0u;
    }
    /**
     * @brief Finds the element by data
     *
     * @return Size of list
     */
    void push_back(const T& data) {
        insert(data, size_);
    }
    /**
     * @brief Finds the element by data
     *
     * @return Size of list
     */
    void push_front(const T& data) {
        Node *new_node = new Node(data, head);
        if (new_node == nullptr) {
            throw(std::out_of_range("List is full."));
        }	 	  	 	  	      	  	      	    	 	        	 	
        head = new_node;
        ++size_;
    }
    /**
     * @brief Finds the element by data
     *
     * @return Size of list
     */
    void insert(const T& data, std::size_t index) {
        if (index > size_) {
            throw(std::out_of_range("Position invalid."));
        } else if (index == 0) {
            return push_front(data);
        }
        Node *before = head;
        int i;
        for (i = 0; i < index-1; ++i) {
            before = before->next();
        }
        Node* temp_node = new Node(data, before->next());
        before->next(temp_node);
        ++size_;
    }
    /**
     * @brief Finds the element by data
     *
     * @return Size of list
     */
    void insert_sorted(const T& data) {
        Node *current;
        if (empty()) {
            return push_front(data);
        } else {
            current = head;
            int i = 0;
            while (current->next() != nullptr && data > current->data()) {	 	  	 	  	      	  	      	    	 	        	 	
                current = current->next();
                ++i;
            }
            if (data > current->data()) {
                return(insert(data, i+1));
            } else {
                return(insert(data, i));
            }
        }
    }
    /**
     * @brief Finds the element by data
     *
     * @return Size of list
     */
    T& at(std::size_t index) {
        if (index >= size_) {
            throw(std::out_of_range("Position invalid."));
        }
        Node* current;
        current = head;
        int i;
        for (i = 0; i < index; ++i) {
            current = current->next();
        }
        return current->data();
    }
    /**
     * @brief Finds the element by data
     *
     * @return Size of list
     */
    T pop(std::size_t index) {
        if (empty()) {
            throw(std::out_of_range("List is empty."));
        } else if (index >= size_) {	 	  	 	  	      	  	      	    	 	        	 	
            throw(std::out_of_range("Position invalid."));
        } else if (index == 0) {
            return pop_front();
        }
        Node* to_delete;
        Node* before;
        before = head;
        int i;
        for (i = 0; i < index - 1; ++i) {
            before = before->next();
        }
        to_delete = before->next();
        T data_bckp;
        data_bckp = to_delete->data();
        before->next(to_delete->next());
        --size_;
        delete to_delete;
        return data_bckp;
    }
    /**
     * @brief Finds the element by data
     *
     * @return Size of list
     */
    T pop_back() {
        return pop(size_ - 1);
    }
    /**
     * @brief Finds the element by data
     *
     * @return Size of list
     */
    T pop_front() {
        if (empty()) {
            throw(std::out_of_range("List is empty."));
        }	 	  	 	  	      	  	      	    	 	        	 	
        T data_bckp = head->data();
        Node* head_bckp = head;
        head = head->next();
        delete head_bckp;
        --size_;
        return data_bckp;
    }
    /**
     * @brief Finds the element by data
     *
     * @return Size of list
     */
    void remove(const T& data) {
        if (head->data() == data) {
            pop_front();
            return;
        }
        Node* to_delete;
        Node* current = head;
        while (current->next()->data() != data) {
            if (current->next() == nullptr) {
                return;
            }
            current = current->next();
        }
        to_delete = current->next();
        current->next(current->next()->next());
        delete to_delete;
        --size_;
    }
    /**
     * @brief Finds the element by data
     *
     * @return Size of list
     */
    bool empty() const {	 	  	 	  	      	  	      	    	 	        	 	
        return (size_ == 0);
    }
     /**
     * @brief Finds the element by data
     *
     * @return Size of list
     */
    bool contains(const T& data) const {
        if (empty()) {
            throw(std::out_of_range("List is empty."));
        }
        if (find(data) == size_) {
            return false;
        } else {
            return true;
        }
    }
    /**
     * @brief Finds the element by data
     *
     * @return Size of list
     */
    std::size_t find(const T& data) const {
        if (empty()) {
            throw std::out_of_range("Empty find");
        }
        Node* current = head;
        int i;
        for (i = 0; i < size_; ++i) {
            if (current->data() == data) {
                return i;
            }
            current = current->next();
        }
        return size_;
    }	 	  	 	  	      	  	      	    	 	        	 	
    /**
     * @brief Finds the element by data
     *
     * @return Size of list
     */
    std::size_t size() const {
        return size_;
    }
    /**
     * @brief Finds the element by data
     *
     * @return Size of list
     */
    void destroy_list() {
        clear();
        delete head;
        delete size_;
    }

 private:
};
}  //  namespace structures

#endif
	 	  	 	  	      	  	      	    	 	        	 	
