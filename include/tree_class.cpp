#include <iostream>
template <typename T>
class tree_t
{
private:

	struct node_t {
		node_t * left;
		node_t * right;
		T  key;
		node_t() {
			left = nullptr;
			right = nullptr;
			T key = 0;

		}
		~node_t() {

			delete left;


			delete right;



		}
		void insertrec(T key) {
			if (this->key > key) {
				if (this->left != nullptr) {
					this->left->insertrec(key);
				}
				else {
					this->left = new node_t();
					this->left->key = key;
				}
			}
			if (this->key < key) {
				if (this->right != nullptr) {
					this->right->insertrec(key);
				}
				else {
					this->right = new node_t();
					this->right->key = key;
				}
			}
			return;
		}
		void printrec(std::ostream & stream, int minus_num)  const {

			if (this->right != nullptr) {
				this->right->printrec(stream, minus_num + 4);
			}
			for (int i = 0; i < minus_num + 4; i++) {
				stream << '-';
			}
			stream << key << '\n';
			if (this->left != nullptr) {
				this->left->printrec(stream, minus_num + 4);
			}

			return;
		}
		bool findrec(T key) const {
			if (this->key > key) {
				if (this->left != nullptr) {
					return this->left->findrec(key);
				}
				return false;
			}
			if (this->key < key) {
				if (this->right != nullptr) {
					return this->right->findrec(key);
				}
				return false;
			}
			if (this->key == key) {
				return true;
			}
		}
		auto operator==(node_t &source) const {
			if (left == nullptr&&source.left != left|| source.left == nullptr&&left != source.left) {
				return false;
			}
			if (right == nullptr&&source.right != right || source.right == nullptr&&right != source.right) {
				return false;
			}

			if (right == nullptr&&left == nullptr&&key==source.key) {

				return true;
			}
			if (right == nullptr && left!=nullptr&&key == source.key&&*(left) == *(source.left)){
				return true;
            }
			if (left == nullptr && right != nullptr && key == source.key&&*(right) == *(source.right)) {
				return true;
			}
			if ( left!=nullptr&&right!=nullptr&& key == source.key&&*(left) == *(source.left) && *(right) == *(source.right)) {
					return true;
			}
			return false;
		    }
			bool removerec(T key) {
				if (this->key > key) {
					if (this->left != nullptr) {
						if (this->left->right == nullptr&&this->left->left == nullptr&&this->left->key==key) {
							delete this->left;
							this->left = nullptr;
							return true;
						}
						return this->left->removerec(key);
					}
					else {
						return false;
						
					}
				}
				if (this->key < key) {
					if (this->right != nullptr) {
						if (this->right->right == nullptr&&this->right->left == nullptr&&this->right->key == key) {
							delete this->right;
							this->right = nullptr;
							return true;
						}
						return this->right->removerec(key);
					}
					else {
						return false;
					}
				}
				if (this->key == key) {
					if (this->left == nullptr&&this->right!=nullptr)
					{
						this->key = this->right->key;
						node_t *hp=this->right;
						
						this->left = this->right->left;
						this->right = this->right->right;
						hp->left = nullptr;
						hp->right = nullptr;
						delete hp;
						return true;
					}
					if (this->right == nullptr && this->left != nullptr)
					{
						this->key = this->left->key;
						node_t *hp = this->left;

						this->right = this->left->right;
						this->left = this->left->left;
						hp->left = nullptr;
						hp->right = nullptr;
						delete hp;
						return true;
					}
					if (this->right != nullptr && this->left != nullptr) {
						node_t *premostleft = this->right;
						if (premostleft->left == nullptr) {
							this->key = premostleft->key;
						    this->right = premostleft->right;
							
							premostleft->left = nullptr;
							premostleft->right = nullptr;
						    delete premostleft;

							return true;
						}
						while (premostleft->left->left!=nullptr) {
							premostleft = premostleft->left;
						}
						this->key = premostleft->left->key;
						return this->right->removerec(this->key);
						
						
						
					}
					
				}


			}


		
	};
private:
	node_t * root_;

public:
	tree_t() {
		root_ = nullptr;
		
	}
	~tree_t() {
		delete root_;
	}
	tree_t(std::initializer_list<T> keys);
	auto operator==(tree_t const & other)const ;
	void insert(T key);
	bool find(T key) const;
	bool remove(T key) ;
	void print(std::ostream & stream)const ;
};
template <typename T>
tree_t<T>::tree_t(std::initializer_list<T> keys) {
	root_=nullptr;
    for (T i : keys) {
		this->insert(i);
	}
}
template <typename T>
void tree_t<T>::insert(T key) {
	if (root_ == nullptr) {
		root_ = new node_t;
		root_->key = key;
	
		return;

	}
	root_->insertrec(key);
	
	return;
}
template <typename T>
void tree_t<T>::print(std::ostream & stream) const {
	if (root_ != nullptr)
	{
		root_->printrec(stream, 0);
	}
	return;
}
template <typename T>
bool tree_t<T>::find(T key) const {
	if (root_ != nullptr) {
		return root_->findrec(key);
	}
	return false;
}
template <typename T>
auto tree_t<T>::operator==(tree_t<T> const  & other) const {
	if (root_ == nullptr&&other.root_ == nullptr) {
		return true;
	}
	if (root_ == nullptr||other.root_ == nullptr) {
		return false;
	}

	return *(root_)==*(other.root_);
}
template <typename T>
bool tree_t<T>::remove(T key)  {
	if (root_ != nullptr&&(root_->left!=nullptr||root_->right!=nullptr)) {
		return root_->removerec(key);
	}
	if (root_ != nullptr && root_->left == nullptr && root_->right == nullptr) {
		delete root_;
		root_ = nullptr;
		return true;
	}
	if (root_ == nullptr) {
		
		return false;
	}
}
