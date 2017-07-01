// Copyright [2016] <Jonathan F. Kuntz>

#include <cstdint>
#include <stdexcept>
namespace structures {

/**
 * @brief Does
 *
 * @return Returns
 */
template<typename T>
class LinkedStack {
 public:
    /**
     * @brief Does
     *
     * @return Returns
     */
    LinkedStack() {
        top_ = nullptr;
        size_ = 0;
    }
    /**
     * @brief Does
     *
     * @return Returns
     */
    ~LinkedStack() {
        clear();
    }
    /**
     * @brief Does
     *
     * @return Returns
     */
    void clear() {	 	  	 	  	      	  	      	    	 	        	 	
        Node* before;
        Node* current = top_;
        current = top_;
        top_ = nullptr;
        while (current != nullptr) {
            before = current;
            current = current->next();
            delete before;
        }
        size_ = 0u;
    }
    /**
     * @brief Does
     *
     * @return Returns
     */
    void push(const T& data) {
        Node* new_node = new Node(data, top_);
        if (new_node == nullptr) {
            throw std::out_of_range("Stack is full.");
        } else {
            top_ = new_node;
            ++size_;
        }
    }
    /**
     * @brief Does
     *
     * @return Returns
     */
    T pop() {
        Node* to_delete;
        T data_bckp;
        if (empty()) {
            throw std::out_of_range("Stack is empty.");
        } else {	 	  	 	  	      	  	      	    	 	        	 	
            to_delete = top_;
            data_bckp = to_delete->data();
            top_ = to_delete->next();
            --size_;
            delete to_delete;
            return data_bckp;
        }
    }
    /**
     * @brief Does
     *
     * @return Returns
     */
    T& top() const {
        if (empty()) {
            throw std::out_of_range("Stack is empty.");
        } else {
            return top_->data();
        }
    }
    /**
     * @brief      Checks if the stack is empty 
     *
     * @return     boolean
     */
    bool empty() const {
        if (size_ == 0) {
            return true;
        } else {
            return false;
        }
    }
    /**
     * @brief Does
     *
     * @return Returns
     */
    std::size_t size() const {	 	  	 	  	      	  	      	    	 	        	 	
        return size_;
    }

 private:
    /**
     * @brief Does
     *
     * @return Returns
     */
    class Node {
     public:
        /**
         * @brief Does
         *
         * @return Returns
         */
        explicit Node(const T& data):
            data_{data}
        {}
        /**
         * @brief Does
         *
         * @return Returns
         */
        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}
        /**
         * @brief Does
         *
         * @return Returns
         */
        T& data() {
            return data_;
        }	 	  	 	  	      	  	      	    	 	        	 	
        /**
         * @brief Does
         *
         * @return Returns
         */
        const T& data() const {
            return data_;
        }
        /**
         * @brief Does
         *
         * @return Returns
         */
        Node* next() {
            return next_;
        }
        /**
         * @brief Does
         *
         * @return Returns
         */
        const Node* next() const {
            return next_;
        }
        /**
         * @brief Does
         *
         * @return Returns
         */
        void next(Node* node) {
            next_ = node;
        }
     private :
        T data_;
        Node* next_;
    };
        /**
     * @brief Does
     *
     * @return Returns
     */
    Node* top_;  // nodo-topo
        /**
     * @brief Does
     *
     * @return Returns
     */
    std::size_t size_;  // tamanho
};
}  // namespace structures
	 	  	 	  	      	  	      	    	 	        	 	
