#ifndef LAKLOK_CUSTOM_ARRAY_H
#define LAKLOK_CUSTOM_ARRAY_H

#include <functional>

template<class DataType>
class Node {
	Node *previousNode = nullptr;
	Node *nextNode = nullptr;
	DataType nodeData;
	int ID = 0;
	int value = 0;

public:
	Node(int ID, DataType nodeData, int value = 0) {
		this->nodeData = nodeData;
		this->value = value;
		this->ID = ID;
	}

	Node<DataType> *operator-(int shift) {
		if (shift == 0) return this;
		if (shift == 1) return this->previousNode;
		if (this->previousNode) return *( this->previousNode ) - ( shift - 1 );
		return nullptr;
	}

	Node<DataType> *operator+(int shift) {
		if (shift == 0) return this;
		if (shift < 0) return this - ( -shift );
		if (shift == 1) return this->nextNode;
		if (this->nextNode) return *( this->nextNode ) + ( shift - 1 );
		return nullptr;
	}

	DataType getNodeData( ) {
		return this->nodeData;
	}

	int getID( ) {
		return this->ID;
	}

	int getValue( ) {
		return this->value;
	}

	Node<DataType> *setValue(int value) {
		this->value = value;
		return this;
	}

	Node<DataType> *setNextNode(Node<DataType> *nextNode) {
		this->nextNode = nextNode;
		return this;
	}

	Node<DataType> *setPreviousNode(Node<DataType> *previousNode) {
		this->previousNode = previousNode;
		return this;
	}

	Node<DataType> *setNodeData(DataType data) {
		this->nodeData = data;
		return this;
	}
};

template<class DataType>
class Array {
	Node<DataType> *first = nullptr;
	Node<DataType> *last = nullptr;
	int size = 0;
	int IDCounter = 0;

	void swap(Node<DataType> *firstElement, Node<DataType> *secondElement) {
		Node<DataType> *fPrev = *firstElement - 1;
		Node<DataType> *fNext = *firstElement + 1;
		Node<DataType> *sPrev = *secondElement - 1;
		Node<DataType> *sNext = *secondElement + 1;

		if (firstElement == sPrev && secondElement == fNext) {
			firstElement->setNextNode(sNext);
			firstElement->setPreviousNode(secondElement);

			secondElement->setNextNode(firstElement);
			secondElement->setPreviousNode(fPrev);

			if (fPrev) fPrev->setNextNode(secondElement);
			else this->first = secondElement;
			if (sNext) sNext->setPreviousNode(firstElement);
			else this->last = firstElement;
		} else if (secondElement == fPrev && firstElement == sNext) {
			firstElement->setNextNode(secondElement);
			firstElement->setPreviousNode(sPrev);

			secondElement->setNextNode(fNext);
			secondElement->setPreviousNode(firstElement);

			if (sPrev) sPrev->setNextNode(firstElement);
			else this->first = firstElement;
			if (fNext) fNext->setPreviousNode(secondElement);
			else this->last = secondElement;
		} else {
			firstElement->setNextNode(sNext);
			firstElement->setPreviousNode(sPrev);

			secondElement->setNextNode(fNext);
			secondElement->setPreviousNode(fPrev);

			if (fPrev) fPrev->setNextNode(secondElement);
			else this->first = secondElement;
			if (fNext) fNext->setPreviousNode(secondElement);
			else this->last = secondElement;
			if (sPrev) sPrev->setNextNode(firstElement);
			else this->first = firstElement;
			if (sNext) sNext->setNextNode(firstElement);
			else this->last = firstElement;
		}
	}

public:
	Array( ) {
		this->size = 0;
		this->IDCounter = 0;
	}

	~Array( ) {
		for (Node<DataType> *currentNode = this->first, *temp; currentNode; currentNode = temp) {
			temp = *currentNode + 1;
			delete currentNode;
		}
	}

	int getSize( ) {
		return this->size;
	}

	Array<DataType> *push(DataType nodeData, int value = 0) {
		auto *newNode = new Node<DataType>(this->IDCounter++, nodeData, value);

		if (!this->first) this->first = newNode;

		if (this->last) {
			this->last->setNextNode(newNode);
			newNode->setPreviousNode(this->last);
		}
		this->last = newNode;
		this->size++;

		return this;
	}

	DataType pop( ) {
		if (!this->last) return ( DataType ) nullptr;

		DataType nodeData = this->last->getNodeData();
		Node<DataType> *lastNode = this->last;
		Node<DataType> *newLastNode = *this->last - 1;

		if (!newLastNode) this->first = nullptr;
		else newLastNode->setNextNode(nullptr);

		this->last = newLastNode;
		this->size--;

		delete lastNode;

		return nodeData;
	}

	Array<DataType> *unshift(DataType nodeData, int value = 0) {
		auto *newNode = new Node<DataType>(this->IDCounter++, nodeData, value);

		if (this->first) {
			this->first->setPreviousNode(newNode);
			newNode->setNextNode(this->first);
		}
		this->first = newNode;

		if (!this->last) this->last = newNode;
		this->size++;

		return this;
	}

	DataType shift( ) {
		if (!this->first) return ( DataType ) nullptr;

		DataType nodeData = this->first->getNodeData();
		Node<DataType> *firstNode = this->first;
		Node<DataType> *newFirstNode = *this->first + 1;

		if (!newFirstNode) this->last = nullptr;
		else newFirstNode->setNextNode(nullptr);

		this->first = newFirstNode;
		this->size--;

		delete firstNode;

		return nodeData;
	}

	Array<DataType> *insert(DataType nodeData, int value) {
		auto *newNode = new Node<DataType>(this->IDCounter++, nodeData, value);
		Node<DataType> *currentNode = this->first;
		Node<DataType> *previousNode = nullptr;
		for (; currentNode; previousNode = currentNode, currentNode = *currentNode + 1) {
			if (currentNode->getValue() > value) break;
		}

		if (!currentNode) {
			this->last = newNode;
		} else {
			currentNode->setPreviousNode(newNode);
			newNode->setNextNode(currentNode);
		}

		if (!previousNode) {
			this->first = newNode;
		} else {
			previousNode->setNextNode(newNode);
			newNode->setPreviousNode(previousNode);
		}

		this->size++;

		return this;
	}

	Array<DataType> *forEach(std::function<void(int index, int ID, DataType data)> callback) {
		Node<DataType> *currentNode = this->first;
		for (int i = 0; currentNode; currentNode = *currentNode + 1, i++) {
			callback(i, currentNode->getID(), currentNode->getNodeData());
		}
		return this;
	}

	Node<DataType> *getFirstNode( ) {
		return this->first;
	}

	Node<DataType> *getLastNode( ) {
		return this->last;
	}

	Node<DataType> *operator[](int index) {
		Node<DataType> *currentNode = this->first;
		for (int i = 0; currentNode; currentNode = *currentNode + 1, i++) {
			if (i == index) return currentNode;
		}
		return nullptr;
	}

	Node<DataType> *getNodeByID(int id) {
		for (Node<DataType> *currentNode = this->first; currentNode; currentNode = *currentNode + 1) {
			if (currentNode->getID() == id) return currentNode;
		}
		return nullptr;
	}

	DataType operator()(int index) {
		return ( *this )[index]->getNodeData();
	}

	DataType operator()( ) {
		return this->getNodeData();
	}

	DataType getByID(int id) {
		return this->getNodeByID(id)->getNodeData();
	}

	DataType removeByIndex(int index) {
		Node<DataType> *currentNode = this->first;
		Node<DataType> *previousNode = nullptr;
		for (int i = 0; currentNode; previousNode = currentNode, currentNode = *currentNode + 1, i++) {
			if (i == index) {
				if (!previousNode) this->first = *currentNode + 1;
				else previousNode->setNextNode(*currentNode + 1);

				if (!*currentNode + 1) this->last = previousNode;
				else ( *currentNode + 1 )->setPreviousNode(previousNode);

				DataType data = currentNode->getNodeData();
				delete currentNode;
				this->size--;
				return data;
			}
		}
		return nullptr;
	}

	DataType removeByID(int id) {
		for (Node<DataType> *currentNode = this->first, *previousNode = nullptr; currentNode; previousNode = currentNode, currentNode =
				                                                                                                                  *currentNode +
				                                                                                                                  1) {
			if (currentNode->getID() == id) {
				if (!previousNode) this->first = *currentNode + 1;
				else previousNode->setNextNode(*currentNode + 1);

				if (!( *currentNode + 1 )) this->last = previousNode;
				else ( *currentNode + 1 )->setPreviousNode(previousNode);

				DataType data = currentNode->getNodeData();
				delete currentNode;
				this->size--;
				return data;
			}
		}
		return nullptr;
	}

	Array<DataType> *sort(std::function<bool(Node<DataType> *, Node<DataType> *)> compare) {
		bool swapped = false;
		for (int i = this->size - 1; i > 0; swapped = false, i--) {
			Node<DataType> *fNode = this->first;
			Node<DataType> *temp = ( *fNode ) + 1;
			for (int j = 0; j < i; j++, fNode = temp) {
				Node<DataType> *sNode = ( *fNode ) + 1;
				if (!compare(fNode, sNode)) {
					this->swap(fNode, sNode);
					swapped = true;
				}
			}
			if (!swapped) break;
		}
		return this;
	}
};

#endif //LAKLOK_CUSTOM_ARRAY_H
