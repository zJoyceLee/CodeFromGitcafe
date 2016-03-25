#pragmam once
//Current Project
#include "LinkedList.hpp"

template <typename T>
class SeqQueue {
private:
    LinkedList<T> m_lst;
public:
    SeqQueue();
    SeqQueue(const SeqQueue & rhs);
    ~SeqQueue();

    bool isEmpty() const;

    void eQueue(const T & element);
    void dQueue();

};

#include "SeqQueue.tcc"
