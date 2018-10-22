#ifndef __BINTREE_H__
#define __BINTREE_H__
#include <assert.h>
#include <iostream>

using namespace std;

template<class T>
struct BTNode
{
	T _v;
	BTNode *l, *r;
	BTNode():l(nullptr), r(nullptr){}
	BTNode(const T& v):_v(v), l(nullptr), r(nullptr){}
};


template<class T>
class BinTree
{
typedef void (*Visit)(const T &n);
public:
	BinTree():_size(0), _root(nullptr){};
	BinTree(const T* arr_t, int size, const T& invalid)
	{
		assert(arr_t != nullptr && size > 0);
		int index = 0;
		_root = create(arr_t, size, index, invalid);
	};
	virtual ~BinTree(){};
	virtual bool empty() const{return _size == 0;};
	virtual int size() const{return _size;};
	virtual void inorder(Visit visit)
	{
		inorder(_root, visit);
	};
	virtual void preorder(Visit visit)
	{
		preorder(_root, visit);
	};
	virtual void postorder(Visit visit)
	{
		postorder(_root, visit);
	};
	virtual void levelorder(Visit visit)
	{
	};
	virtual int high()
	{
		return high(_root);	
	};

private:
	int high(BTNode<T>* t)
	{
		if (t == nullptr) return 0;
		int lh = high(t->l) + 1;
		int rh = high(t->r) + 1;
		return lh > rh?lh:rh;
	}
	BTNode<T>* create(const T* arr_t, int size, int& index, const T& invalid)
	{
		cout << index;
		BTNode<T>* n = nullptr;
		if (index < size && arr_t[index] != invalid)
		{
			cout << " create " << arr_t[index] << endl;
			_size++;
			n = new BTNode<T>(arr_t[index]);
			if (++index < size)	
				n->l = create(arr_t, size, index, invalid);		
			if (++index < size)
				n->r = create(arr_t, size, index, invalid);		
		}
		else
			cout << endl;
		return n;
	}

	

	void preorder(BTNode<T> *n, Visit visit)
	{
		if (n != nullptr)
		{
			visit(n->_v);
			preorder(n->l, visit);
			preorder(n->r, visit);
		}
	};
	void inorder(BTNode<T> *n, Visit visit)
	{
		if (n != nullptr)
		{
			inorder(n->l, visit);
			visit(n->_v);
			inorder(n->r, visit);
		}
	};
	void postorder(BTNode<T> *n, Visit visit)
	{
		if (n != nullptr)
		{
			postorder(n->l, visit);
			postorder(n->r, visit);
			visit(n->_v);
		}
	};
private:
	BTNode<T> *_root;
	int       _size;
};

#endif
