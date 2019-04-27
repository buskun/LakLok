//
// Created by buskun0 on 07/04/19.
//

#ifndef LAKLOK_CUSTOM_ARRAY_H
#define LAKLOK_CUSTOM_ARRAY_H

#include <functional>

template<class DataType>
class Node {
	Node *previous;
	DataType nodeData;
	Node *next;
	int ID;
	int _comparingIndex;

public:
	Node(int id, DataType data, int comparingIndex = 0) :
			previous(nullptr), next(nullptr), ID(id), nodeData(data),
			_comparingIndex(comparingIndex) { }

	Node<DataType> *nextNode( ) {
		return next;
	}

	Node<DataType> *previousNode( ) {
		return previous;
	}

	DataType getNodeData( ) {
		return nodeData;
	}

	int getID( ) {
		return ID;
	}

	int getComparingIndex( ) {
		return _comparingIndex;
	}

	void setComparingIndex(int comparingIndex) {
		_comparingIndex = comparingIndex;
	}

	void setNextNode(Node<DataType> *nextNode) {
		next = nextNode;
	}

	void setPreviousNode(Node<DataType> *previousNode) {
		previous = previousNode;
	}

	void setNodeData(DataType data) {
		nodeData = data;
	}
};

template<class DataType>
class Array {

	Node<DataType> *first;
	Node<DataType> *last;

	int _size;

	int idCount;

	void swap(Node<DataType> *firstElement, Node<DataType> *secondElement) {
		Node<DataType> *fPrev = firstElement->previousNode();
		Node<DataType> *fNext = firstElement->nextNode();
		Node<DataType> *sPrev = secondElement->previousNode();
		Node<DataType> *sNext = secondElement->nextNode();

		if (firstElement == sPrev && secondElement == fNext) {
			firstElement->setNextNode(sNext);
			firstElement->setPreviousNode(secondElement);

			secondElement->setNextNode(firstElement);
			secondElement->setPreviousNode(fPrev);

			if (fPrev) fPrev->setNextNode(secondElement);
			else first = secondElement;
			if (sNext) sNext->setPreviousNode(firstElement);
			else last = firstElement;
		} else if (secondElement == fPrev && firstElement == sNext) {
			firstElement->setNextNode(secondElement);
			firstElement->setPreviousNode(sPrev);

			secondElement->setNextNode(fNext);
			secondElement->setPreviousNode(firstElement);

			if (sPrev) sPrev->setNextNode(firstElement);
			else first = firstElement;
			if (fNext) fNext->setPreviousNode(secondElement);
			else last = secondElement;
		} else {
			firstElement->setNextNode(sNext);
			firstElement->setPreviousNode(sPrev);

			secondElement->setNextNode(fNext);
			secondElement->setPreviousNode(fPrev);

			if (fPrev) fPrev->setNextNode(secondElement);
			else first = secondElement;
			if (fNext) fNext->setPreviousNode(secondElement);
			else last = secondElement;
			if (sPrev) sPrev->setNextNode(firstElement);
			else first = firstElement;
			if (sNext) sNext->setNextNode(firstElement);
			else last = firstElement;
		}
	}

public:
	Array( ) {
		first = nullptr;
		last = nullptr;
		_size = 0;
		idCount = 0;
	}

	int size( ) {
		return _size;
	}

	void push(DataType nodeData, int comparingIndex = 0) {
		auto *newNode = new Node<DataType>(idCount++, nodeData, comparingIndex);

		if (!first) first = newNode;

		if (last) {
			last->setNextNode(newNode);
			newNode->setPreviousNode(last);
		}
		last = newNode;

		_size++;
	}

	DataType pop( ) {
		if (!last) return ( DataType ) nullptr;

		DataType nodeData = last->getNodeData();
		Node<DataType> *lastNode = last;
		Node<DataType> *newLastNode = last->previousNode();

		if (!newLastNode) first = nullptr;
		else newLastNode->setNextNode(nullptr);

		last = newLastNode;
		_size--;

		delete lastNode;

		return nodeData;
	}

	void unshift(DataType nodeData, int comparingIndex = 0) {
		auto *newNode = new Node<DataType>(idCount++, nodeData, comparingIndex);

		if (first) {
			first->setPreviousNode(newNode);
			newNode->setNextNode(first);
		}
		first = newNode;

		if (!last) last = newNode;

		_size++;
	}

	DataType shift( ) {
		if (!first) return ( DataType ) nullptr;

		DataType nodeData = first->getNodeData();
		Node<DataType> *firstNode = first;
		Node<DataType> *newFirstNode = first->nextNode();

		if (!newFirstNode) last = nullptr;
		else newFirstNode->setNextNode(nullptr);

		first = newFirstNode;
		_size--;

		delete firstNode;

		return nodeData;
	}

	void insert(DataType nodeData, int comparingIndex) {
		auto *newNode = new Node<DataType>(idCount++, nodeData, comparingIndex);
		Node<DataType> *currentNode = first;
		Node<DataType> *previousNode = nullptr;
		for (; currentNode; previousNode = currentNode, currentNode = currentNode->nextNode()) {
			if (currentNode->getComparingIndex() > comparingIndex) break;
		}

		if (!currentNode) {
			last = newNode;
		} else {
			currentNode->setPreviousNode(newNode);
			newNode->setNextNode(currentNode);
		}

		if (!previousNode) {
			first = newNode;
		} else {
			previousNode->setNextNode(newNode);
			newNode->setPreviousNode(previousNode);
		}

		_size++;
	}

	void forEach(std::function<void(int index, int id, DataType data)> callback) {
		Node<DataType> *currentNode = first;
		for (int i = 0; currentNode; currentNode = currentNode->nextNode(), i++) {
			callback(i, currentNode->getID(), currentNode->getNodeData());
		}
	}

	Node<DataType> *getFirst( ) {
		return first;
	}

	Node<DataType> *getLast( ) {
		return last;
	}

	Node<DataType> *getNodeByIndex(int index) {
		Node<DataType> *currentNode = first;
		for (int i = 0; currentNode; currentNode = currentNode->nextNode(), i++) {
			if (i == index) return currentNode;
		}
		return nullptr;
	}

	Node<DataType> *getNodeByID(int id) {
		for (Node<DataType> *currentNode = first; currentNode; currentNode = currentNode->nextNode()) {
			if (currentNode->getID() == id) return currentNode;
		}
		return nullptr;
	}

	DataType getByIndex(int index) {
		return getNodeByIndex(index)->getNodeData();
	}

	DataType getByID(int id) {
		return getNodeByID(id)->getNodeData();
	}

	DataType removeByIndex(int index) {
		Node<DataType> *currentNode = first;
		Node<DataType> *previousNode = nullptr;
		for (int i = 0; currentNode; previousNode = currentNode, currentNode = currentNode->nextNode(), i++) {
			if (i == index) {
				if (!previousNode) first = currentNode->nextNode();
				else previousNode->setNextNode(currentNode->nextNode());

				if (!currentNode->nextNode()) last = previousNode;
				else currentNode->nextNode()->setPreviousNode(previousNode);

				DataType data = currentNode->getNodeData();
				delete currentNode;
				_size--;
				return data;
			}
		}
		return nullptr;
	}

	DataType removeByID(int id) {
		for (Node<DataType> *currentNode = first, *previousNode = nullptr; currentNode; previousNode = currentNode, currentNode = currentNode->nextNode()) {
			if (currentNode->getID() == id) {
				if (!previousNode) first = currentNode->nextNode();
				else previousNode->setNextNode(currentNode->nextNode());

				if (!currentNode->nextNode()) last = previousNode;
				else currentNode->nextNode()->setPreviousNode(previousNode);

				DataType data = currentNode->getNodeData();
				delete currentNode;
				_size--;
				return data;
			}
		}
		return nullptr;
	}

	Array<DataType> *sort(std::function<bool(Node<DataType> *, Node<DataType> *)> comparingFunction) {
		bool swapped = false;
		for (int i = _size - 1; i > 0; swapped = false, i--) {
			for (int j = 0; j < i; j++) {
				Node<DataType> *fNode = getNodeByIndex(j);
				Node<DataType> *sNode = fNode->nextNode();
				if (!comparingFunction(fNode, sNode)) {
					swap(fNode, sNode);
					swapped = true;
				}
			}
			if (!swapped) break;
		}
		return this;
	}
};

#endif //LAKLOK_CUSTOM_ARRAY_H
