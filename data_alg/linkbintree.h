#ifndef __LINKBINTREE_H__
#define __LINKBINTREE_H__
#include "bintree.h"

void (*Visit)(BTNode<T>* n);
template<class T>
class LinkBinTree::public BinTree<T>
{
public:
	virtual LinkBinTree()size_(0), root_(nullptr){};
	virtual ~LinkBinTree(){};
	virtual bool empty() const{return size_ == 0;};
	virtual int size() const{ return size_; };
	virtual void invisit(Visit visit) = 0;
	virtual void previsit() = 0;
	virtual void postvisit() = 0;
	virtual void levelvisit() = 0;
private:
	int size_;
	BinTree<T> *root_;
	Visit visit_;
};

#endif
